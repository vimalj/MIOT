#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAX_SAMPLES 10000   //Declaration for array x[i] sample size
int N2=0;   // Global Variable

/*function for uniformly distributed random number*/

double Random()
{
  return ( (double)(rand()) + 1 )/( (double)(RAND_MAX) + 1 );
}

/* function to convert uniformly distributed random number to normally distributed random number */
double normalRandom()
{
  double r1=Random();
  double r2=Random();
  return cos(2*3.14*r2)*sqrt(-2*log(r1));
}

/* function to calculate confidence interval including functions and 
function call to generate normally disrtributed random numbers first 
and also calculating the sample mean and sample standard deviation */

double Confidence_Interval()
{
    srand(time(0));
    float x[MAX_SAMPLES];
    int  i, n;
    float sample_mean, sample_variance, sample_std_deviation, sum = 0, sum1 = 0;
    float sigma, Mi;
    
    printf("\nEnter the value of sigma σ for generating Normally distributed samples: \n");
    scanf("%f", &sigma);

    printf("\nEnter the value of True mean μ for Normally distributed samples: \n");
    scanf("%f", &Mi);

    printf("\nEnter the value of N (number of samples): \n");
    scanf("%d", &n);
    
    { 
    if((n<2) || (n>10000))
        {   printf("\n ** Invalid n choose b/w 2-10000\n ");    exit(0);   }
    
    else{   printf("****n value entered should be at lest 2 and less than 10000****\n");    }

    }

    printf("Normally Distributed  %d Random numbers = \n", n);
    for (i = 0; i < n; i++)
        {
        x[i]= normalRandom()*sigma+Mi;
        printf("%f\n", x[i]);
        }

    /* Loop to Compute the mean of all elements */
    for (i = 0; i < n; i++)
    {
        sum = sum + x[i];
    }
    sample_mean = sum / (float)n;

    /*  Loop to Compute  sample_variance  and sample_standard deviation  */
    for (i = 0; i < n; i++)
    {
        sum1 = sum1 + pow((x[i] - sample_mean), 2);
    }
    sample_variance = sum1 / ((float)n-1);
    sample_std_deviation = sqrt(sample_variance);

    printf("\n***** Calculation of Sample Mean, Sample Standard_Deviation and Confidence Interval***** \n");
    
    int alpha;
    printf("\nChoose level of significance 0.10 (type 90), 0.05 (type 95) or for 0.01 (type 99)=");
    scanf("%d", &alpha);

    printf("\nMean of all elements = %.2f\n", sample_mean);
    printf("Sample variance of all elements = %.2f\n", sample_variance);
    printf("Sample Standard deviation = %.2f\n", sample_std_deviation);

    float CIL, CIU;

    if (alpha==90) 
     {  CIL = sample_mean - ((1.645*sample_std_deviation)/sqrt(n));
    CIU = sample_mean + ((1.645*sample_std_deviation)/sqrt(n));
    printf("C.I. Lower bound = %.2f\n", CIL);
    printf("C.I.Upper bound = %.2f\n", CIU);}

    else if (alpha==95) 
    {  CIL = sample_mean - ((1.96*sample_std_deviation)/sqrt(n));
    CIU = sample_mean + ((1.96*sample_std_deviation)/sqrt(n));
    printf("C.I. Lower bound = %.2f\n", CIL);
    printf("C.I.Upper bound = %.2f\n", CIU);}


    else if (alpha==99) 
    { CIL = sample_mean - ((2.58*sample_std_deviation)/sqrt(n));
    CIU = sample_mean + ((2.58*sample_std_deviation)/sqrt(n));
    printf("C.I. Lower bound = %.2f\n", CIL);
    printf("C.I. Upper bound = %.2f\n", CIU);}

    else { printf("****alpha value entered is invalid****\n"); exit(0);    }

    if ((Mi>=CIL)&&(Mi<=CIU))	{   N2++;   printf("The number of times C.I. value inside mean= %d\n" , N2);    }
    else{  printf("The number of times CI value inside mean= %d\n" , N2);  }
    
}


void main()
{
    int c,N1=5;
    
    printf("\n***** Random Number Generation which are Normally distributed***** \n");
    for (c=0; c<N1; c++)
    {
    Confidence_Interval();
    }
    
    float p = (float)N2/(float)N1;
    printf("\nProportion of times the mean is inside the confidence interval =");
    printf("%.2f\n" , p);
}


