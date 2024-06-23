//====================================================== file = ztest.c =====
//=  Program to compute confidence interval using standard Z test           =
//=    - Hardcoded for 90, 95, and 99 percent confidence intervals          =
//===========================================================================
//=  Notes:                                                                 =
//=    1) Input from input file "in.dat" to stdin (see example below)       =
//=        * Comments are bounded by "&" characters at the beginning and    =
//=          end of the comment block                                       =
//=    2) Output is to stdout                                               =
//=    3) Minimum number of samples should be 30 for a valid result         =
//=    4) Assumes sample means, so variance is computed with (N-1)          =
//=-------------------------------------------------------------------------=
//= Example "in.dat" file:                                                  =
//=                                                                         =
//=  Input is values 1, 2, 3, ... 30 (one value per line)                   =
//=-------------------------------------------------------------------------=
//= Example output (for above "in.dat"):                                    =
//=                                                                         =
//=  ------------------------------------------------- ztest.c -----        =
//=    Number of samples       =     30                                     =
//=    Sample mean             =     15.500000                              =
//=    Sample variance         =     77.500000                              =
//=    90% confidence interval = +/-  2.643807                              =
//=    95% confidence interval = +/-  3.150259                              =
//=    99% confidence interval = +/-  4.140019                              =
//=  ---------------------------------------------------------------        =
//=-------------------------------------------------------------------------=
//=  Build: bcc32 ztest.c                                                   =
//=-------------------------------------------------------------------------=
//=  Execute: ztest < in.dat                                                =
//=-------------------------------------------------------------------------=
//=  Author: Ken Christensen                                                =
//=          University of South Florida                                    =
//=          WWW: http://www.csee.usf.edu/~christen                         =
//=          Email: christen@csee.usf.edu                                   =
//=-------------------------------------------------------------------------=
//=  History: KJC (07/26/06) - Genesis  (from ttest.c)                      =
//===========================================================================
//----- Include files -------------------------------------------------------
#include <stdio.h>                 // Needed for printf()
#include <math.h>                  // Needed for pow() and sqrt()
#include <stdlib.h>                // Needed for exit() and feof()
#include <string.h>                // Needed for strcmp()

//----- Defines -------------------------------------------------------------
#define MAX_SAMPLES  2000000       // Maximum number of samples
#define MIN_SAMPLES       30       // Minimum number of samples (this is 30)
#define Z_SCORE90         1.6449   // Z-score for 90% confidence interval
#define Z_SCORE95         1.9600   // Z-score for 95% confidence interval
#define Z_SCORE99         2.5758   // Z-score for 99% confidence interval

//----- Globals -------------------------------------------------------------
double     X[MAX_SAMPLES];         // Array of samples read from "in.dat"
int        N;                      // Number of samples

//----- Function prototypes -------------------------------------------------
void   load_X_array(void);                // Load X array
double compute_mean(void);                // Compute sample means
double compute_sample_var(double mean);   // Compute sample variance

//===========================================================================
//=  Main program                                                           =
//===========================================================================
void main(void)
{
  double   mean;                   // Mean of samples
  double   sample_variance;        // Sample variance
  double   ci_value90;             // Computed 90% confidence interval value
  double   ci_value95;             // Computed 95% confidence interval value
  double   ci_value99;             // Computed 99% confidence interval value

  // Load the samples into X and determine global variable N
  printf("------------------------------------------------- ztest.c -----\n");
  load_X_array();

  // Make sure than N is at least MIN_SAMPLES
  if (N < MIN_SAMPLES)
  {
    printf("*** ERROR - not enough samples (minimum is %d) \n", MIN_SAMPLES);
    exit(1);
  }

  // Compute mean, sample_variance, and CI values for X
  mean = compute_mean();
  sample_variance = compute_sample_var(mean);
  ci_value90 = Z_SCORE90 * sqrt(sample_variance / N);
  ci_value95 = Z_SCORE95 * sqrt(sample_variance / N);
  ci_value99 = Z_SCORE99 * sqrt(sample_variance / N);

  // Output results
  printf("  Number of samples       =     %d    \n", N);
  printf("  Sample mean             =     %f    \n", mean);
  printf("  Sample variance         =     %f    \n", sample_variance);
  printf("  90%% confidence interval = +/-  %f  \n", ci_value90);
  printf("  95%% confidence interval = +/-  %f  \n", ci_value95);
  printf("  99%% confidence interval = +/-  %f  \n", ci_value99);
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

    // Check if MAX_SAMPLES data values exceeded
    if (N > MAX_SAMPLES)
    {
      printf("*** ERROR - greater than %ld values \n", MAX_SAMPLES);
      exit(1);
    }
  }

  // End-of-file escape
  end:

  return;
}

//===========================================================================
//=  Function to compute mean for a series X                                =
//===========================================================================
double compute_mean(void)
{
  double   mean;                 // Computed mean value
  int      i;                    // Loop counter

  // Loop to compute mean
  mean = 0.0;
  for (i=0; i<N; i++)
    mean = mean + (X[i] / N);

  return(mean);
}

//===========================================================================
//=  Function to compute sample variance for a series X                     =
//===========================================================================
double compute_sample_var(double mean)
{
  double   sample_var;           // Computed sample variance value
  int      i;                    // Loop counter

  // Loop to compute sample variance
  sample_var = 0.0;
  for (i=0; i<N; i++)
    sample_var = sample_var + (pow((X[i] - mean), 2.0) / (N - 1));

  return(sample_var);
}
