//====================================================== file = hypo1.c =====
//=  Program to perform a hypothesis test for two groups with different     =
//=  group size, means, and variances.  One sided 95% and 90% test for      =
//=  mean of group #1 is greater than mean of group #2.                     =
//===========================================================================
//=  Notes:                                                                 =
//=    1) Input from input file "in.dat" to stdin (see example below)       =
//=        * Comments are bounded by "&" characters at the beginning and    =
//=          end of the comment block                                       =
//=    2) Output is to stdout                                               =
//=    3) First value in input is, N1, the number of values is group #1     =
//=    4) The following N1 values are group #1 samples                      =
//=    5) The following N2 = N - N1 - 1 values are group #2 samples         =
//=-------------------------------------------------------------------------=
//= Example "in.dat" file:                                                  =
//=                                                                         =
//=   & This is data from group #1 and group #2 &                           =
//=   5       & N1 &                                                        =
//=   10.0    & Group #1 values &                                           =
//=   11.0                                                                  =
//=   11.6                                                                  =
//=   12.1                                                                  =
//=   11.5                                                                  =
//=   10.1    & Group #2 values &                                           =
//=   9.0                                                                   =
//=   12.6                                                                  =
//=   12.1                                                                  =
//=   9.5                                                                   =
//=   8.8                                                                   =
//=   8.8                                                                   =
//=-------------------------------------------------------------------------=
//= Example output (for above "in.dat"):                                    =
//=                                                                         =
//=   ------------------------------------------------- hypo1.c -----       =
//=   -   n1 = 5   mean1 = 11.240000  var1 = 0.506400                       =
//=   -   n2 = 7   mean2 = 10.128571  var2 = 2.170612                       =
//=   -   t_statistic = 1.561733                                            =
//=   -   t_score 90% = 1.372184                                            =
//=   -   t_score 95% = 1.812462                                            =
//=   -                                                                     =
//=   -   Significant that mean1 > mean2 for 90% confidence                 =
//=   -   NOT significant that mean1 > mean2 for 95% confidence             =
//=   ---------------------------------------------------------------       =
//=-------------------------------------------------------------------------=
//=  Build: gcc hypo1.c -lm, bcc32 hypo1.c, cl hypo1.c                      =
//=-------------------------------------------------------------------------=
//=  Execute: hypo1 < in.dat                                                =
//=-------------------------------------------------------------------------=
//=  Author: Kenneth J. Christensen                                         =
//=          University of South Florida                                    =
//=          WWW: http://www.csee.usf.edu/~christen                         =
//=          Email: christen@csee.usf.edu                                   =
//=-------------------------------------------------------------------------=
//=  History: KJC (10/23/00) - Genesis                                      =
//===========================================================================

//----- Include files -------------------------------------------------------
#include <stdio.h>                 // Needed for printf() and feof()
#include <math.h>                  // Needed for pow() and sqrt()
#include <stdlib.h>                // Needed for exit() and atof()
#include <string.h>                // Needed for strcmp()

//----- Defines -------------------------------------------------------------
#define MAX_VALUES   1000L         // Maximum number of values in X array

//----- Globals -------------------------------------------------------------
double     X[MAX_VALUES];          // Values read from file
long int   N;                      // Total number of elements in X

double     T_table_95[151] =
{0.0, 6.313748599, 2.919987310, 2.353363016, 2.131846486, 2.015049176,
      1.943180905, 1.894577508, 1.859548320, 1.833113856, 1.812461505,
      1.795883691, 1.782286745, 1.770931704, 1.761309250, 1.753051038,
      1.745884219, 1.739606432, 1.734063062, 1.729131327, 1.724718004,
      1.720743512, 1.717144187, 1.713870006, 1.710882316, 1.708140189,
      1.705616341, 1.703288035, 1.701130259, 1.699127097, 1.697260359,
      1.695518677, 1.693888407, 1.692360456, 1.690923455, 1.689572855,
      1.688297289, 1.687094482, 1.685953066, 1.684875315, 1.683852133,
      1.682878974, 1.681951289, 1.681071353, 1.680230071, 1.679427442,
      1.678658919, 1.677926775, 1.677224191, 1.676551165, 1.675905423,
      1.675284693, 1.674688974, 1.674115993, 1.673565748, 1.673033694,
      1.672522103, 1.672028702, 1.671553491, 1.671091923, 1.670648544,
      1.670218808, 1.669804988, 1.669402536, 1.669013727, 1.668636287,
      1.668270215, 1.667915512, 1.667572178, 1.667237939, 1.666915068,
      1.666599019, 1.666294338, 1.665996479, 1.665707714, 1.665425771,
      1.665150648, 1.664884621, 1.664625415, 1.664370757, 1.664125193,
      1.663884177, 1.663647708, 1.663420335, 1.663197509, 1.662979230,
      1.662765499, 1.662556315, 1.662353952, 1.662156137, 1.661960596,
      1.661771876, 1.661585429, 1.661403530, 1.661226179, 1.661051101,
      1.660882845, 1.660714588, 1.660550879, 1.660391717, 1.660234830,
      1.660080216, 1.659930149, 1.659782356, 1.659636837, 1.659495865,
      1.659354893, 1.659218469, 1.659086593, 1.658954716, 1.658822839,
      1.658697784, 1.658572728, 1.658449946, 1.658329438, 1.658211204,
      1.658095243, 1.657981556, 1.657870143, 1.657758730, 1.657649591,
      1.657544999, 1.657440407, 1.657335815, 1.657235771, 1.657135726,
      1.657035682, 1.656940185, 1.656844688, 1.656751465, 1.656658242,
      1.656567292, 1.656478616, 1.656389941, 1.656303539, 1.656219411,
      1.656135282, 1.656053428, 1.655971573, 1.655889719, 1.655810138,
      1.655732831, 1.655655524, 1.655580490, 1.655503183, 1.655430424,
      1.655357664, 1.655284905, 1.655214419, 1.655143933, 1.655075721};
double     T_table_90[151] =
{0.0, 3.077684596, 1.885618985, 1.637745299, 1.533205705, 1.475884801,
      1.439755124, 1.414923645, 1.396815605, 1.383028803, 1.372184215,
      1.363430329, 1.356218036, 1.350172170, 1.345031251, 1.340605422,
      1.336757123, 1.333379487, 1.330390660, 1.327728114, 1.325340691,
      1.323187462, 1.321236596, 1.319460807, 1.317835086, 1.316345788,
      1.314972451, 1.313703706, 1.312525910, 1.311434517, 1.310415882,
      1.309463187, 1.308573019, 1.307737421, 1.306950708, 1.306211743,
      1.305513706, 1.304854322, 1.304230182, 1.303637873, 1.303076260,
      1.302544206, 1.302034889, 1.301551720, 1.301090151, 1.300650183,
      1.300227268, 1.299824817, 1.299438281, 1.299068799, 1.298712959,
      1.298371899, 1.298044481, 1.297730705, 1.297426024, 1.297134986,
      1.296853043, 1.296580194, 1.296318715, 1.296066330, 1.295820766,
      1.295584298, 1.295355787, 1.295134098, 1.294920366, 1.294711183,
      1.294511094, 1.294315553, 1.294125695, 1.293941523, 1.293763034,
      1.293589094, 1.293419700, 1.293255991, 1.293096830, 1.292942216,
      1.292789875, 1.292643219, 1.292498837, 1.292360139, 1.292223715,
      1.292090701, 1.291961098, 1.291834906, 1.291712124, 1.291591616,
      1.291473382, 1.291357421, 1.291246008, 1.291136869, 1.291028866,
      1.290923137, 1.290820819, 1.290720775, 1.290623004, 1.290526370,
      1.290432010, 1.290341061, 1.290250111, 1.290161435, 1.290075033,
      1.289989768, 1.289906777, 1.289824922, 1.289745342, 1.289665761,
      1.289588454, 1.289513420, 1.289439524, 1.289366764, 1.289295142,
      1.289224656, 1.289156444, 1.289088232, 1.289022293, 1.288956355,
      1.288892690, 1.288829026, 1.288767635, 1.288706244, 1.288645990,
      1.288588010, 1.288528892, 1.288472049, 1.288416343, 1.288360636,
      1.288306066, 1.288253770, 1.288200338, 1.288149178, 1.288096882,
      1.288046860, 1.287997975, 1.287949090, 1.287901341, 1.287853593,
      1.287808118, 1.287761506, 1.287717168, 1.287671694, 1.287628493,
      1.287585292, 1.287542091, 1.287498890, 1.287457962, 1.287417035,
      1.287376108, 1.287337454, 1.287297664, 1.287259010, 1.287221494};

//----- Function prototypes -------------------------------------------------
void   load_X_array(void);         // Load X array

//===========================================================================
//=  Main program                                                           =
//===========================================================================
void main(void)
{
  long int   n1, n2;            // Number of samples for group #1 and #2
  double     x1[MAX_VALUES];    // X1 values (group #1)
  double     x2[MAX_VALUES];    // X2 values (group #2)
  double     mean1, mean2;      // Mean of samples for group #1 and group #2
  double     s2_1, s2_2;        // Sample variance for group #1 and group #2
  long int   df;                // Degrees of freedom
  double     t_stat;            // Computed t statistic
  double     sum, mom1, mom2;   // Sum and first and second moments
  double     temp1, temp2;      // Temporary double values
  long int   i;                 // Loop counter

  // Load the sample means into X and determine global variable N
  printf("------------------------------------------------- hypo1.c -----\n");
  load_X_array();

  // Compute n1 and n2
  n1 = (long int) X[0];
  n2 = N - n1 - 1;

  // Load x1 and x2 arrays from X
  for (i=0; i<n1; i++)
    x1[i] = X[i+1];
  for (i=0; i<n2; i++)
    x2[i] = X[n1+i+1];

  // Compute mean and variance for group #1
  sum = mom1 = mom2 = 0.0;
  for (i=0; i<n1; i++)
  {
    sum = sum + x1[i];
    mom1 = mom1 + (x1[i] / n1);
    mom2 = mom2 + (pow(x1[i], 2.0) / n1);
  }
  mean1 = mom1;
  s2_1 = mom2 - pow(mom1, 2.0);

  // Compute mean and variance for group #2
  sum = mom1 = mom2 = 0.0;
  for (i=0; i<n2; i++)
  {
    sum = sum + x2[i];
    mom1 = mom1 + (x2[i] / n2);
    mom2 = mom2 + (pow(x2[i], 2.0) / n2);
  }
  mean2 = mom1;
  s2_2 = mom2 - pow(mom1, 2.0);

  // Compute t statistic
  temp1 = (mean1 - mean2);
  temp2 = ((n1 * s2_1) + (n2 * s2_2)) / (n1 + n2);
  temp2 = temp2 * ((1.0 / n1) + (1.0 / n2));
  t_stat = temp1 / sqrt(temp2);

  // Compute degrees of freedom
  df = n1 + n2 - 2;

  // Output results
  //  - For table lookup we consider any df > 150 to be df = 150
  printf("-   n1 = %d  mean1 = %f  var1 = %f \n", n1, mean1, s2_1);
  printf("-   n2 = %d  mean2 = %f  var2 = %f \n", n2, mean2, s2_2);
  printf("-   degrees of freedom = %d \n", df);
  printf("-   t_statistic = %f \n", t_stat);
  if (df > 150) df = 150;           // <--- This for table look-up
  printf("-   t_score 90%% = %f \n", T_table_90[df]);
  printf("-   t_score 95%% = %f \n", T_table_95[df]);
  printf("- \n");
  if (T_table_90[df] <= t_stat)
    printf("-   Significant that mean1 > mean2 for 90%% confidence \n");
  else
    printf("-   NOT significant that mean1 > mean2 for 90%% confidence \n");
  if (T_table_95[df] <= t_stat)
    printf("-   Significant that mean1 > mean2 for 95%% confidence \n");
  else
    printf("-   NOT significant that mean1 > mean2 for 95%% confidence \n");
  printf("---------------------------------------------------------------\n");
}

//===========================================================================
//=  Function to load X array from stdin and determine N                    =
//===========================================================================
void load_X_array(void)
{
  char      temp_string[1024];     // Temporary string variable

  // Read all values into X
  N = 0;
  while(1)
  {
    scanf("%s", temp_string);
    if (feof(stdin)) goto end;

    // This handles a comment bounded by "&" symbols
    while (strcmp(temp_string, "&") == 0)
    {
      do
      {
        scanf("%s", temp_string);
        if (feof(stdin)) goto end;
      } while (strcmp(temp_string, "&") != 0);
      scanf("%s", temp_string);
      if (feof(stdin)) goto end;
    }

    // Enter value in array and increment array index
    X[N] = atof(temp_string);
    N++;

    // Check if MAX_VALUES data values exceeded
    if (N > MAX_VALUES)
    {
      printf("*** ERROR - greater than %ld values \n", MAX_VALUES);
      exit(1);
    }
  }

  // End-of-file escape
  end:

  return;
}
