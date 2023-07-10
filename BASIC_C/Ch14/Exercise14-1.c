#include <stdio.h>
/*
Exercise 14-1
*/

int cbv(int val)
{
    return val*val;
}

void cbp(int* val)
{
    *val = (*val)*(*val);
}

// Problem 1
int sqrtNum(void)
{
    int num = 5;
    
    printf("CBV(num): %d -> %d \n", num, cbv(num));

    printf("CBP(num): %d -> ", num);
    cbp(&num);
    printf("%d \n", num);

    return 0;
}

void Swap3(int* num1, int* num2, int*num3)
{
    int temp = *num3;
    *num3 = *num2;
    *num2 = *num1;
    *num1 = temp;
}

// Problem 2
int swapNums(void)
{
    int num1 = 1, num2 = 2, num3 = 3;

    printf("Swap3(%d, %d, %d): -> ", num1, num2, num3);
    Swap3(&num1, &num2, &num3);
    printf("%d, %d, %d \n", num1, num2, num3);

    return 0;
}


int main(void)
{
    sqrtNum();
    printf("\n");
    swapNums();
    printf("\n");

    return 0;
}