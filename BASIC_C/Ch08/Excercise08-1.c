#include <stdio.h>
/*
Exercise 08-1
*/

// Problem 1
void mul7mul8(void)
{
    int num;

    for(num=1; num<100; num++){
        if( num%7==0 || num%9==0 ) // Since '==' has higher priority than '||' parenthesis can be omitted.
        printf("%d is Multiples of 7 or 9! \n", num);
    }
}

// Problem 2 & Problem 4
void calSub(void)
{
    int num1,num2;

    printf("Enter 2 integer: ");
    scanf("%d %d",&num1, &num2);


    printf("|%d - %d| = %d \n", num1, num2, (num1 < num2) ? num2 - num1: num1 - num2);
    if(num1 < num2) printf("RESULT: %d \n", num2 - num1);
    else printf("RESULT: %d", num1 - num2);
}

// Problem 3
void calGrade(void)
{
    int lit, eng, math;

    printf("Enter the Literature, English, Math score: ");
    scanf("%d %d %d", &lit, &eng, &math);
    double score = (lit+eng+math)/3.0;

    if(score >= 90) printf("Grade: A\n");
    else if(score >= 80) printf("Grade: B\n");
    else if(score >=70) printf("Grade: C\n");
    else if(score >= 50) printf("Grade: D\n");
    else printf("Grade: F\n");
}

int main(void)
{
    mul7mul8();
    printf("\n");
    calSub();
    printf("\n");
    calGrade();
    printf("\n");

    return 0;   
}