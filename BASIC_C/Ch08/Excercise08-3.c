#include <stdio.h>
/*
Exercise 08-3
*/

// Problem 1
void ifToSwitch(void)
{
    int num;

    printf("Enter Number: ");
    scanf("%d", &num);

    switch(num / 10){
        case 0:
            printf("0 <= num < 10 \n");
            break;
        case 1:
            printf("10 <= num < 20 \n");
            break;
        case 2:
            printf("20 <= num < 30 \n");
            break;
        default:
            printf("30 <= num \n");
    }
}


int main(void)
{
    ifToSwitch();
    printf("\n");

    return 0;   
}