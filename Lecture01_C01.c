/****
    * Different Operators in
    * C Programming Language
    * Many parts of the code contain
    * some features that are not required
    * for now. They are only used for
    * better output format. They are not needed.
****/

#include <stdio.h>
#include <windows.h>

COORD cursor = {0, 0};

void gotoPosition(int x, int y)
{
    cursor.X = x;
    cursor.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

int main(void)
{
    /// Arithmetic Operator
    gotoPosition(18, 0);
    printf("======================\n");
    gotoPosition(18, 1);
    printf("|Arithmetic Operation|\n");
    gotoPosition(18, 2);
    printf("======================\n");
    printf("____________________________________________________________________\n");
    printf("|Operand 1     Operator     Operand 2 = Result     Operation Name  |\n");
    printf("====================================================================\n");
    printf("|%4d             + %12d      = %3d          Addition      |\n", 5, 2, 5 + 2);
    printf("|%4d             - %12d      = %3d          Subtraction   |\n", 5, 2, 5 - 2);
    printf("|%4d             * %12d      = %3d          Multiplication|\n", 5, 2, 5 * 2);
    printf("|%4d             / %12d      = %3d          Division      |\n", 5, 2, 5 / 2);
    printf("|%4d             %% %12d      = %3d          Modulus       |\n", 5, 2, 5 % 2);
    printf("====================================================================\n");
    printf("\n");

    /// Assignment Operator

    gotoPosition(8, 13);
    printf("======================\n");
    gotoPosition(8, 14);
    printf("|Assignment Operation|\n");
    gotoPosition(8, 15);
    printf("======================\n");

    int val;

    printf("_______________________________________\n");
    val = 5;
    printf("When I write val  = 5; val becomes: %2d\n", val);
    val += 7;
    printf("When I write val += 7; val becomes: %2d\n", val);
    val -= 6;
    printf("When I write val -= 6; val becomes: %2d\n", val);
    val *= 3;
    printf("When I write val *= 3; val becomes: %2d\n", val);
    val /= 5;
    printf("When I write val /= 5; val becomes: %2d\n", val);
    val %= 2;
    printf("When I write val %= 2; val becomes: %2d\n", val);
    printf("=======================================\n");
    printf("\n");

    /// Increment/Decrement Operator
    int i = 0;

    gotoPosition(3, 25);
    printf("===============================\n");
    gotoPosition(3, 26);
    printf("|Increment/Decrement Operation|\n");
    gotoPosition(3, 27);
    printf("===============================\n");
    printf("_____________________________________________\n");
    printf("The value of i started as: %d\n", i);
    printf("The value when prefix increment is done : %d\n", ++i);
    printf("The value after prefix increment is done: %d\n", i);
    printf("The value when postfix increment is done: %d\n", i++);
    printf("The value after postfix increment is done: %d\n", i);
    printf("The value when postfix decrement is done: %d\n", i--);
    printf("The value after postfix decrement is done: %d\n", i);
    printf("The value when postfix decrement is done : %d\n", --i);
    printf("The value after postfix decrement is done: %d\n", i);
    printf("=============================================\n");
    printf("\n");

    /// Relational Operator
    int operand1 = 5;
    int operand2 = 8;

    gotoPosition(0, 30);
    printf("======================\n");
    gotoPosition(0, 31);
    printf("|Relational Operation|\n");
    gotoPosition(0, 32);
    printf("======================\n");
    printf("_______________________________________________\n");
    printf("|Operand 1     Operator     Operand 2 | Result|\n");
    printf("==============================================|\n");
    printf("|%4d             == %11d      | %3d   |\n", operand1, operand2, operand1 == operand2);
    printf("|---------------------------------------------|\n");
    printf("|%4d             >= %11d      | %3d   |\n", operand1, operand2, operand1 >= operand2);
    printf("|---------------------------------------------|\n");
    printf("|%4d             <= %11d      | %3d   |\n", operand1, operand2, operand1 <= operand2);
    printf("|---------------------------------------------|\n");
    printf("|%4d              > %11d      | %3d   |\n", operand1, operand2, operand1 > operand2);
    printf("|---------------------------------------------|\n");
    printf("|%4d              < %11d      | %3d   |\n", operand1, operand2, operand1 < operand2);
    printf("|---------------------------------------------|\n");
    printf("|%4d             != %11d      | %3d   |\n", operand1, operand2, operand1 != operand2);
    printf("===============================================\n");

    printf("\n");

    /// Logical Operator
    int n = 0, p = 1;

    gotoPosition(0, 35);
    printf("===================\n");
    gotoPosition(0, 36);
    printf("|Logical Operation|\n");
    gotoPosition(0, 37);
    printf("===================\n");
    printf("_____________________\n");
    printf("|A|B|!A|!B|A&&B|A||B|\n");
    printf("=====================\n");
    printf("|%d|%d| %d| %d|   %d|   %d|\n", n, n, !n, !n, n&&n, n||n);
    printf("|-------------------|\n");
    printf("|%d|%d| %d| %d|   %d|   %d|\n", n, p, !n, !p, n&&p, n||p);
    printf("|-------------------|\n");
    printf("|%d|%d| %d| %d|   %d|   %d|\n", p, n, !p, !n, p&&n, p||n);
    printf("|-------------------|\n");
    printf("|%d|%d| %d| %d|   %d|   %d|\n", p, p, !p, !p, p&&p, p||p);
    printf("=====================\n");

    return 0;
}
