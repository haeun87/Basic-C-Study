#include <stdio.h>
/*
Exercise 07-1
*/

// Problem 1
void helloLoop(void)
{
    int num,time;

    printf("Loop time(n): ");
    scanf("%d",&time);
    num = 1;
    while(num <= time) printf("Hello world! %d \n", num++);
}

// Problem 2
void mulOfThree(void)
{
    int num,time;

    printf("Number of multiple numbers(n): ");
    scanf("%d",&time);
    num = 1;
    while(num <= time) printf("%d \n", (num++)*3);
}

// Problem 3
void calSum(void)
{
    int sum = 0;
    int num = -1;
    while(num != 0){
        printf("Enter the number: ");
        scanf("%d",&num);
        sum += num;
    }
    printf("Sum: %d \n", sum);
}


// Problem 4
void revMulTable(void)
{
    // With while
    int i = 9;
    while(i>0)
    {
        int j = 9;
        while(j>0) printf("%d X %d = %d \n", i, j--, i*j);
        i--;
        printf("\n");
    }
}

// Problem 5
void calAvg(void)
{
    int nums, num;

    printf("Enter the total number of integers: ");
    scanf("%d", &nums);
    int sum = 0;
    int i = 0;
    while(i < nums){
        printf("Enter the number: ");
        scanf("%d",&num);
        sum += num;
        i++;
    }
    printf("Average: %f \n", (double)sum/nums);   
}

int main(void)
{
    helloLoop();
    printf("\n");
    mulOfThree();
    printf("\n");
    calSum();
    printf("\n");
    revMulTable();
    printf("\n");
    calAvg();
    printf("\n");

    return 0;   
}