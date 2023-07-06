#include <stdio.h>
/*
Exercise 07-3
*/

// Problem 1
void calSum(void)
{
    int total = 0, num = -1;
    while(num != 0){
        printf("Enter the number: ");
        scanf("%d",&num);
        total += num;
    }
    printf("Total: %d \n", total);
}

// Problem 2
void calSumEven(void)
{
    int total=0, num=0;

    do
    {
        total += num;
        num += 2;
    } while (num <= 100);
    printf("Total: %d \n", total);
}

// Problem 3
void mulTable(void)
{
    // With while
    int i = 1;
    do// outer while
    {
        int j = 1;
        do{
            printf("%d X %d = %d \n", i, j++, i*j); // inner while
        } while(j<10);
        i++;
        printf("\n");
    } while (i<10);
}

int main(void)
{
    calSum();
    printf("\n");
    calSumEven();
    printf("\n");
    mulTable();
    printf("\n");

    return 0;   
}