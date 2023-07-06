/*
    Title: Loop statement
    Description: Understanding the concept of the Loop statement
    FileName: Loop.c
    Modified: July 6th 2023
    Writer: Haeun Suh
*/

#include <stdio.h>
/*
    Chapter 05 The loop statement that commands repeated execution
    * Futher detail will be skipped except practice codes.
*/

void simpleWhile(void)
{
    int num=0;

    while(num<5) printf("Hell! %d \n", num++);// inline while

    while(1){// using break;
        printf("Hello again! %d \n", num++);
        if(num == 4) break;
    }

}

void mulTable(void)
{
    // With while
    int i = 1;
    while(i<10)// outer while
    {
        int j = 1;
        while(j<10) printf("%d X %d = %d \n", i, j++, i*j); // inner while
        i++;
        printf("\n");
    }

    // With for
    for(int r=1; r<10; r++){// outer for
        for(int c=1; c<10; c++) printf("%d X %d = %d \n", r, c, r*c); // inner for
        printf("\n");
    }
}

void usefulDoWhile(void)
{
    int total=0, num=0;

    do
    {
        printf("Enter Integer(0 to quit): ");
        scanf("%d", &num);
        total += num;
    } while (num != 0);
    printf("Total: %d \n", total);
}

void addToNum(void)
{
    int num1, total=0;
    printf("Enter the maximum number: ");
    scanf("%d", &num1);
    for(int i=0; i<= num1; i++) total += i;
    printf("Sum from 0 to %d: %d \n", num1, total);
}

void realMean(void)
{
    double input= 0.0, total=0.0;
    int num = 0;
    for( ; input>= 0.0 ; ){// Practically while statement
        total += input;
        printf("Enter positive real number(negative to quit): ");
        scanf("%lf", &input);
        num++;
    }
    printf("Average: %f \n", total/(num-1));
}

int main(void)
{
    simpleWhile();
    printf("\n");
    mulTable();
    printf("\n");
    usefulDoWhile();
    printf("\n");
    addToNum();
    printf("\n");
    realMean();
    printf("\n");

    return 0;
}