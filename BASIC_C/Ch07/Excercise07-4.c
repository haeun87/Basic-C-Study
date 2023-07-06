#include <stdio.h>
/*
Exercise 07-4
*/

// Problem 1
void sumBTW(void)
{
    int num1, num2=-1, total=0;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    while(num1 >= num2){
        printf("Enter the second number: ");
        scanf("%d", &num2);
    }

    for(int i = num1; i <= num2; i++){
        total += i;
    }
    printf("Total from %d to %d: %d", num1, num2, total);
}

// Problem 2
void factorial(void)
{
    int num=-1, total=1;

    while(num <= 0){
        printf("Enter the n of n!: ");
        scanf("%d", &num);
    }

    for(int i=2; i <= num; i++) total *= i;

    printf("%d! = %d", num, total);
}


int main(void)
{
    sumBTW();
    printf("\n");
    factorial();
    printf("\n");

    return 0;   
}