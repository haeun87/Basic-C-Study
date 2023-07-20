#include <stdio.h>
/*
Exercise 26-1
*/
#define ADD(A,B,C) ((A)+(B)+(C))
#define MUL(A,B,C) ((A)*(B)*(C))

#define PI 3.1415
#define AREA(X) ((X)*(X)*PI)

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

// problem 1
int problem1(void)
{
    int num1, num2, num3;

    printf("Enter Three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    
    printf("ADD(%d, %d, %d) = %d \n", num1, num2, num3, ADD(num1,num2,num3));
    printf("MUL(%d, %d, %d) = %d \n", num1, num2, num3, MUL(num1,num2,num3));

    return 0;
}

// problem 2
int problem2(void)
{
    double rad;

    printf("Enter The radius: ");
    scanf("%lf", &rad);

    printf("Area of a circle(rad: %g) = %g \n", rad, AREA(rad));

    return 0;
}

// problem 3
int problem3(void)
{
    int num1, num2;

    printf("Enter Two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("MAX(%d, %d) = %d \n", num1, num2, MAX(num1,num2));

    return 0;
}

int main(void)
{
    problem1();
    printf("\n");
    problem2();
    printf("\n");
    problem3();
    printf("\n");
    
    return 0;
}