#include <stdio.h>
/*
Exercise 07-2
*/

// Problem 1
void input5(void)
{
    int inputs = 1;
    while(inputs <= 5){
        int num = -1;
        while(num < 1) {
            printf("Enter the number: ");
            scanf("%d", &num);
        }
        printf("%d input: %d \n", inputs++,num);
    }

}

// Problem 2
void printTree(void)
{
    int row=0;

    while(row < 5)
    {
        int col = 0;
        while(col < row) {
            printf("o");
            col++;
        }
        printf("*\n");
        row++;
    }
}


int main(void)
{
    input5();
    printf("\n");
    printTree();
    printf("\n");

    return 0;   
}