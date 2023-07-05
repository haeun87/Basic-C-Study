#include <stdio.h>
/*
Exercise 04-4
*/

// Problem 1
void signConverter(void)
{
    int num1, num2;

    printf("Enter the integer number: ");
    scanf("%d",&num1);
    num2 = ~num1 + 1;

    printf("Coverted from %d => %d\n", num1, num2);   
}

// Problem 2
void bitCalculation(void)
{
    int num1 = 3, num2 = 8, num3 = 4;
    int result = (num1<<3)>>2;

    printf("%dX%d/%d = %d\n",num1, num2, num3, result);   
}

int main(void)
{
    signConverter();
    printf("\n");
    bitCalculation();
    printf("\n");

    return 0;   
}