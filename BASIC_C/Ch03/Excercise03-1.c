#include <stdio.h>
/*
Exercise 03-1
*/

// Problem 1
void binaryCal(void)
{
    int num1, num2;

    printf("Number 1: ");
    scanf("%d",&num1);
    printf("Number 2: ");
    scanf("%d",&num2);

    printf("%d - %d = %d \n",num1, num2, num1-num2);   
    printf("%d X %d = %d \n",num1, num2, num1*num2);  
}

// Problem 2
void ternaryCal1(void)
{
    int num1, num2, num3;

    printf("Enter Three Integer Numbers: ");
    scanf("%d %d %d",&num1, &num2, &num3);

    printf("%dX%d+%d = %d\n",num1, num2, num3, num1*num2+num3);   
}

// Problem 3
void sqrt(void)
{
    int num1;

    printf("Enter an Integer: ");
    scanf("%d", &num1);

    printf("%d^2 = %d\n",num1, num1*num1);   
}

// Problem 4
void division(void)
{
    int num1, num2;

    printf("Enter Two Integer Numbers: ");
    scanf("%d %d",&num1, &num2);

    printf("Quotient of %d DIV %d = %d\n",num1, num2, num1/num2);
    printf("Remainder of %d DIV %d = %d\n",num1, num2, num1%num2);
}


// Problem 5
void ternaryCal2(void)
{
    int num1, num2, num3;

    printf("Enter Three Integer Numbers: ");
    scanf("%d %d %d",&num1, &num2, &num3);
    int result = (num1-num2)*(num2+num3)*(num3%num1);
    printf("Result: %d\n", result);   
}

int main(void)
{
    binaryCal();
    printf("\n");
    ternaryCal1();
    printf("\n");
    sqrt();
    printf("\n");  
    division();
    printf("\n");  
    ternaryCal2(); 
    printf("\n");

    return 0;   
}