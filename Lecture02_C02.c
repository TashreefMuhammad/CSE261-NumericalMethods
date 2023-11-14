#include <stdio.h>
#include <math.h>

void printEquation(int n, double a[]);
double hornerEvaluation(int n, double x, double a[]);
double derivativeCalculation(int n, double x, double a[]);
double rootFindingOpenEndMethod(double x1, int n, double a[], double stop);

int main(void)
{
    int i, n;
    double result, guess, stop = 0.000000001;

    printf("Enter the highest order of polynomial equation: ");
    scanf("%d", &n);

    double a[n + 1];

    printf("Please provide the value of the following co-efficients: \n");

    for(i = n; i >= 0; --i)
    {
        printf("a%d = ", i);
        scanf("%lf", &a[i]);
    }

    printEquation(n, a);

    guess = -(a[n-1] / a[n]);

    result = rootFindingOpenEndMethod(guess, n, a, stop);

    printf("Solution Root: %lf", result);

    return 0;
}

void printEquation(int n, double a[])
{
    int i;

    printf("The provided function is following:\n");
    for(i = n; i > 0; --i)
    {
        if(a[i] >= 0)
            printf("%lf", a[i]);
        else
            printf("- %lf", -a[i]);
        if(i > 1)
            printf("x^%d ", i);
        else
            printf("x ");
    }
    if(a[0] >= 0)
        printf("+ %lf = 0\n\n", a[0]);
    else
        printf("- %lf = 0\n\n", -a[0]);
    printf("\n");

    printf("The function using horner's equation:\n");

    for(i = 0; i < n - 1; ++i)
        printf("(");
    printf("%lfx", a[n]);

    for(i = n - 1; i > 0; --i)
    {
        if(a[i] >= 0)
            printf("+ %lf)x ", a[i]);
        else
            printf("- %lf)x ", -a[i]);
    }

    if(a[0] >= 0)
        printf("+ %lf = 0\n\n", a[0]);
    else
        printf("- %lf = 0\n\n", -a[0]);

    printf("\n");
}

double hornerEvaluation(int n, double x, double a[])
{
    double result = a[n];
    int i;

    for(i = n - 1; i >= 0; --i)
        result = result * x + a[i];

    return result;
}

double derivativeCalculation(int n, double x, double a[])
{
    double result = a[n] * n;
    int i;

    for(i = n - 1; i > 0; --i)
        result = result * x + a[i] * (double)i;

    return result;
}

double rootFindingOpenEndMethod(double x1, int n, double a[], double stop)
{
    double x0, f, fd;

    f = hornerEvaluation(n, x1, a);
    fd = derivativeCalculation(n, x1, a);


    printf("========================================================================\n");
    printf("|   x1              x0                f             fd             E   |\n");
    printf("------------------------------------------------------------------------\n");

    f = hornerEvaluation(n, x1, a);
    fd = derivativeCalculation(n, x1, a);

    // Update rule for Newton-Raphson Method
    x0 = x1 - (f / fd);

    printf("|%+3.4lf \t %+3.4lf \t %+3.4lf \t %+3.4lf \t %+3.4lf|\n", x1, x0, f, fd, fabs((x1 - x0) / (x1 == 0 ? 1 : x1)));

    while(fabs((x1 - x0) / (x1 == 0 ? 1 : x1)) >= stop)
    {
        x1 = x0;
        f = hornerEvaluation(n, x0, a);
        fd = derivativeCalculation(n, x0, a);

        // Update rule for Newton-Raphson Method
        x0 = x1 - (f / fd);

        printf("|%+3.4lf \t %+3.4lf \t %+3.4lf \t %+3.4lf \t %+3.4lf|\n", x1, x0, f, fd, fabs((x1 - x0) / (x1 == 0 ? 1 : x1)));
    }
    printf("=========================================================================\n");

    printf("Final Error: %lf\n", fabs((x1 - x0) / (x1 == 0 ? 1 : x1)));

    return (x1 + x0) / 2.0;
}
