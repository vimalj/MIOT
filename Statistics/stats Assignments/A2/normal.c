//===================================================== file = normal.c =====
//=  Random number generator for normal(0, 1)                               =
//===========================================================================
//=  Notes:                                                                 =
//=    1) This program is a "driver program" for the function normal().     =
//=       See the header of normal() for a full description.                =
//=    2) The function normal() uses the polar method to generate           =
//=       normal(0, 1) from uniform(0, 1).                                  =
//=    3) Can generate X' = Normal(mean, sigma^2) by setting                =
//=       X' = mean + sigma * Normal(0, 1)                                  =
//=    4) Compile will generate a warning something like,                   =
//=        - Warning X.C 90: 'X2' is assigned a value that is never used    =
//=          in function normal                                             =
//=-------------------------------------------------------------------------=
//= Example output:                                                         =
//=                                                                         =
//=   ------------------------------------------------ normal.c -----       =
//=   1.601592                                                              =
//=   0.174768                                                              =
//=   -0.302023                                                             =
//=                                                                         =
//=   <SNIP SNIP>                                                           =
//=                                                                         =
//=   -0.859291                                                             =
//=   0.494700                                                              =
//=   1.403386                                                              =
//=   ---------------------------------------------------------------       =
//=-------------------------------------------------------------------------=
//=  Build: gcc normal.c, bcc32 normal.c, cl normal.c                       =
//=-------------------------------------------------------------------------=
//=  Execute: normal                                                        =
//=-------------------------------------------------------------------------=
//=  Author: Kenneth J. Christensen                                         =
//=          University of South Florida                                    =
//=          WWW: http://www.csee.usf.edu/~christen                         =
//=          Email: christen@csee.usf.edu                                   =
//=-------------------------------------------------------------------------=
//=  History: KJC (01/21/99) - Genesis                                      =
//===========================================================================

//----- Include files -------------------------------------------------------
#include <stdio.h>          // Needed for printf()
#include <math.h>           // Needed for log() and sqrt()

//----- Function prototypes -------------------------------------------------
double normal(void);        // Function to generate normal(0, 1)
double rand_val(void);      // Function to generate uniform(0, 1)

//===========================================================================
//=  Main program                                                           =
//===========================================================================
void main(void)
{
  long i;      // Loop counter

  // Output a banner
  printf("------------------------------------------------ normal.c -----\n");

  // Output 10000 random values between 0.0 and 1.0
  for (i=0; i<10000; i++)
    printf("%f \n", normal());

  // Output a tailer
  printf("---------------------------------------------------------------\n");
}

//=========================================================================
//= Generate a normal(0, 1) using the polar method as described in        =
//= A. Law and W. Kelton, "Simulation Modeling and Analysis," McGraw      =
//= Hill, 1991 (Page 491).                                                =
//=   - Uses rand_val() (see unif.c for description of rand_val())        =
//=   - Computes a pair of normal(0, 1) per the polar method, but         =
//=     returns only the first value generated                            =
//=========================================================================
double normal(void)
{
  double V1, V2, W, Y;         // V1, V2, W, and Y variables for polar method
  double X1, X2;               // X1 and X2 variables for polar method

  // Step #1 from Law and Kelton (Page 491)
  do
  {
    V1 = 2.0 * rand_val() - 1.0;
    V2 = 2.0 * rand_val() - 1.0;
    W = (V1 * V1) + (V2 * V2);
  }
  while (W > 1.0);

  // Step #2 from Law and Kelton (Page 491)
  //  - Cannot easily return two values, so X2 is never used
  Y = sqrt((-2 * log(W)) / W);
  X1 = V1 * Y;
  X2 = V2 * Y;

  return(X1);
}

//=========================================================================
//= Multiplicative LCG for generating uniform(0.0, 1.0) random numbers    =
//=   - x_n = 7^5*x_(n-1)mod(2^31 - 1)                                    =
//=   - With x seeded to 1 the 10000th x value should be 1043618065       =
//=   - From R. Jain, "The Art of Computer Systems Performance Analysis," =
//=     John Wiley & Sons, 1991. (Page 443, Figure 26.2)                  =
//=========================================================================
double rand_val(void)
{
  const long  a =      16807;  // Multiplier
  const long  m = 2147483647;  // Modulus
  const long  q =     127773;  // m div a
  const long  r =       2836;  // m mod a
  static long x = 1;           // Random int value (seed is set to 1)
  long        x_div_q;         // x divided by q
  long        x_mod_q;         // x modulo q
  long        x_new;           // New x value

  // RNG using integer arithmetic
  x_div_q = x / q;
  x_mod_q = x % q;
  x_new = (a * x_mod_q) - (r * x_div_q);
  if (x_new > 0)
    x = x_new;
  else
    x = x_new + m;

  // Return a random value between 0.0 and 1.0
  return((double) x / m);
}
