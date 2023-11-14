#include <stdio.h>
#include <math.h>
#include <windows.h>

COORD cursor = {0, 0};

void gotoPosition(int x, int y);
void printEquation(int n, double a[]);
double hornerEvaluation(int n, double x, double a[]);
double rootFindingBracketingMethod(double x1, double x2, int n, double a[], double stop);

int main(void)
{
    int i, n;
    double result, guess1, guess2, stop = 0.000000001;

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

    guess1 = -fabs(sqrt((pow(a[n-1] / a[n], 2.0)) - 2.0 * (a[n-2] / a[n])));
    guess2 = fabs(sqrt((pow(a[n-1] / a[n], 2.0)) - 2.0 * (a[n-2] / a[n])));

    result = rootFindingBracketingMethod(guess1, guess2, n, a, stop);

    printf("Solution Root: %lf", result);

    return 0;
}

void gotoPosition(int x, int y)
{
    cursor.X = x;
    cursor.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
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

double rootFindingBracketingMethod(double x1, double x2, int n, double a[], double stop)
{
    double x0, f0, f1, f2;

    f1 = hornerEvaluation(n, x1, a);
    f2 = hornerEvaluation(n, x2, a);


    printf("=========================================================================================================\n");
    printf("|   x2               x1              x0             f2                f1             f0             E   |\n");
    printf("---------------------------------------------------------------------------------------------------------\n");

    while(fabs((x2 - x1) / (x2 == 0 ? 1 : x2)) >= stop)
    {
        // Update rule for Bisection Method
        // x0 = (x2 + x1) / 2.0;

        // Update rule for False Position Method
        x0 = x1 - f1 * ((x2 - x1) / (f2 - f1));

        f0 = hornerEvaluation(n, x0, a);

        printf("|%+3.4lf \t %+3.4lf \t %+3.4lf \t %+3.4lf \t %+3.4lf \t %+3.4lf \t %+3.4lf|\n", x2, x1, x0, f2, f1, f0, fabs((x2 - x1) / (x2 == 0 ? 1 : x2)));

        if(f0 == 0)
        {
            x2 = x1 = x0;
            break;
        }

        else if(f2 * f0 < 0)
        {
            x1 = x0;
            f1 = f0;
        }
        else
        {
            x2 = x0;
            f2 = f0;
        }
    }
    printf("=========================================================================================================\n");

    printf("Final Error: %lf\n", (fabs(x2 - x1) / x2));

    return (x1 + x2) / 2.0;
}
