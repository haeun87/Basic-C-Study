#include <stdio.h>
/*
Exercise 12-1
*/

// Problem 1
int pointer1(void)
{
    int num=10;
    int* ptr1=&num;
    int* ptr2=ptr1; // ptr2->ptr1->num(X) ptr1->num & ptr2->num(O);
    int** ptr3=&ptr1; // ptr3->ptr1->num (Pointer to Pointer)

    (*ptr1)++;
    (*ptr2)++;
    printf("%d \n", num);

    return 0;

}

// Problem 2
int pointer2(void)
{
    int num1=10, num2=20;
    int* ptr1=&num1;
    int* ptr2=&num2;
    int* temp;

    (*ptr1)+= 10; // num1: 10 -> 20
    (*ptr2)-= 10; // num2: 20 -> 10

    temp=ptr1;
    ptr1 = ptr2;
    ptr2 = temp;

    printf("num1: %d num2: %d \n", num1, num2);
    printf("ptr1: %d ptr2: %d \n", *ptr1, *ptr2);

    return 0;

}

int main(void)
{
    pointer1();
    printf("\n");
    pointer2();
    printf("\n");
    
    return 0;
}