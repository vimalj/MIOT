#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAXSIZE 10000   // num[i] sample size
int N2=0; //global varible
float ConfidenceInterval()     // calculating confidence interval 
{
    
    float uniform()
    {
    return ( (double)(rand()) + 1 )/( (double)(RAND_MAX) + 1 );
    }   //function for uniform random numbers


    float normal()  
    {
    double u=uniform();
    double v=uniform();
    return cos(2*3.14*v)*sqrt(-2*log(u));
    }   //function to convert to normally distributed random numbers by Box Muller Transform

    srand(time(0));
    float num[MAXSIZE];
    int  i, N;
    float sigma, tmean, s_mean, s_variance, s_std_deviation, sum1 = 0, sum2 = 0;
    
    printf("\nEnter sigma to generate Normally distributed samples: \n");
    scanf("%f", &sigma);

    printf("\nEnter True mean for Normally distributed samples: \n");
    scanf("%f", &tmean);

    printf("\nEnter the value of N-samples: \n");
    scanf("%d", &N);
    
    { 
    if((N<2) || (N>10000))
        {   printf("\n *ERROR N range is 2-10000* \n ");   { exit(0);}   }

        }

    printf("%d Normally Distributed Random Numbers:\n", N);
    for (i = 0; i < N; i++)
        {
        num[i]= normal()*sigma+tmean;
        printf("%f\n", num[i]);
        }

    // Calculate the mean of all elements
    for (i = 0; i < N; i++)
    {
        sum1 = sum1 + num[i];
    }
    s_mean = sum1 / (float)N;

    //sample variance  and sample standard deviation
    for (i = 0; i < N; i++)
    {
        sum2 = sum2 + pow((num[i] - s_mean), 2);
    }
    s_variance = sum2 / ((float)N-1);
    s_std_deviation = sqrt(s_variance);

    printf("\n*Sample Mean, Sample Standard Deviation and Confidence Interval Calculation........* \n");
    
    int alpha;
    printf("\nChoose level of significance 0.05 or 0.01 (enter 5 or 1)=");
    scanf("%d", &alpha);

    printf("\n Sample Mean of all numbers = %.2f\n", s_mean);
    printf("Sample variance = %.2f\n", s_variance);
    printf("Sample Standard deviation = %.2f\n", s_std_deviation);

    float L, U;

     if (alpha==5) 
    {  L = s_mean - ((1.96*s_std_deviation)/sqrt(N));
    U = s_mean + ((1.96*s_std_deviation)/sqrt(N));
    printf("Lower bound for CI = %.2f\n", L);
    printf("Upper bound for CI = %.2f\n", U);}
    
    else if (alpha==1) 
    { L = s_mean - ((2.58*s_std_deviation)/sqrt(N));
    U = s_mean + ((2.58*s_std_deviation)/sqrt(N));
    printf("Lower bound for CI = %.2f\n", L);
    printf("Upper bound for CI = %.2f\n", U);}

    else { printf("ERROR INVALID LEVEL OF SIGNIFICANCE Alpha \n"); exit(0);    }

    if ((tmean>L)&&(tmean<U)){N2++;}
}

int main()
{
    int N1=4;
    printf("\n=Normally distributed Random Number Generation=\n");
    
    for (int i=0; i<N1; i++)
    {
    ConfidenceInterval();
    }
    
    float t = (float)N2/(float)N1;
    printf("\nProportion of times the mean lies in CI:");
    printf("%.2f\n" , t);
}


