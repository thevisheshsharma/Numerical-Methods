#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define f(x) ((x*x*x)+(2*(x*x))+(10*x)-20)

void Muller(float a, float b, float c, float MAX_ITERATIONS)
{
    int i;
    float res;

    for (i = 0;;++i)
    {
        float f1 = f(a) , f2 = f(b) , f3 = f(c);
        float d1 = f1 - f3;
        float d2 = f2 - f3;
        float h1 = a - c;
        float h2 = b - c;
        float a0 = f3;
        float a1 = (((d2*pow(h1, 2)) - (d1*pow(h2, 2)))
                    / ((h1*h2) * (h1-h2)));
        float a2 = (((d1*h2) - (d2*h1))/((h1*h2) * (h1-h2)));
        float x = ((-2*a0) / (a1 + fabs(sqrt(a1*a1-4*a0*a2))));
        float y = ((-2*a0) / (a1 - fabs(sqrt(a1*a1-4*a0*a2))));

        if (x >= y)
            res = x + c;
        else
            res = y + c;

        float m = res*100;
        float n = c*100;
        m = floor(m);
        n = floor(n);
        if (m == n)
            break;
        a = b;
        b = c;
        c = res;
        if (i > MAX_ITERATIONS)
        {
            printf("Huh! I am dumb! Can't find this"); 
            break;
        }
    }
    if (i <= MAX_ITERATIONS)
         printf("What is it that I can't do! Here is your root: %f",res);
}

int main()
{
    float a,b,c,maxItr;
    printf("Do your work! Define a, b, c .. \n");
    printf("Define a: ");
    scanf("%f",&a);
    printf("Define b: ");
    scanf("%f",&b);
    printf("Define c: ");
    scanf("%f",&c);
    printf("what number of max iterations should I go?: ");
    scanf("%f",&maxItr);
    Muller(a, b, c, maxItr);
    return 0;
}