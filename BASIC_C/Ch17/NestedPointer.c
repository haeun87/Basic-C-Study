/*
    Title: Pointer to Pointer
    Description: Understand the operation of nested or double pointer.
    FileName: NestedPointer.c
    Modified: July 10th 2023
    Writer: Haeun Suh
*/

#include <stdio.h>
/*
    Chapter 17 Pointer tp Pointer
    * A pointer to a pointer refers to another pointer variable that points to a pointer variable.
    * Also referred as a 'double pointer' or 'nested pointer'.
    * Example of double pointer
      e.g. int* ptr = &num; int** dPtr = &ptr; // dPtr-> ptr-> num
      c.f. int* ptr = &num; int* ptr2 = ptr; // ptr-> num, ptr2-> num
    * As C is a call-by-value evaluation system: 
        => Swapping with a single pointer will result in swapping the copied value of the pointer. 
        => That is, still nothing to do with the pointer itself! 
    * Practically, an array of pointers is equivalent to a double pointer.
    * Triple pointers, or multiple nested pointers are also available. 
    * Basically, a pointer system provides a way to access variables declared outside the function from within the function. 
    * Further detail will be skipped except practice codes.
*/

int doublePointerAccess(void)
{
    double num = 3.14;
    double *ptr = &num;
    double **dPtr = &ptr;
    double *ptr2;

    printf("%16p %16p \n", ptr, *dPtr);
    printf("%16g %16g \n", num, **dPtr);
    ptr2 = *dPtr; // ptr2 = ptr
    *ptr2 = 10.99;
    printf("%16g %16g \n", num, **dPtr);

    return 0;
}

void SwapIntPtr(int* p1, int* p2)
{
    int* temp = p1;
    p1 = p2;
    p2 = temp;
}

void SwapIntPtr2(int** dp1, int** dp2)
{
    int* temp = *dp1;
    *dp1 = *dp2;
    *dp2 = temp;
}

int pointerSwapFail(void)
{
    int num1=10, num2=20;
    int* ptr1; 
    int* ptr2;
    ptr1=&num1; ptr2=&num2;
    printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2);
    SwapIntPtr(ptr1, ptr2);
    printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2);

    return 0;
}

int pointerSwapSuccess(void)
{
    int num1=10, num2=20;
    int* ptr1; 
    int* ptr2;
    ptr1=&num1; ptr2=&num2;
    printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2);
    SwapIntPtr2(&ptr1, &ptr2);
    printf("*ptr1, *ptr2: %d %d \n", *ptr1, *ptr2);

    return 0;
}

int pointerArrayType(void)
{
    int num1=10, num2=20, num3=30;
    int *ptr1=&num1;
    int *ptr2=&num2;
    int *ptr3=&num3;

    int* ptrArr[] = {ptr1, ptr2, ptr3};
    int** dptr = ptrArr;

    printf("%d %d %d \n", *(ptrArr[0]), *(ptrArr[1]), *(ptrArr[2]));
    printf("%d %d %d \n", *(dptr[0]), *(dptr[1]), *(dptr[2]));
}

int triplePointer(void)
{
    int num=100;
    int* ptr = &num;
    int** dptr = &ptr;
    int*** tptr = &dptr;

    printf("%d %d \n", **dptr, ***tptr);

    return 0;
}

int main(void)
{
    doublePointerAccess();
    printf("\n");
    pointerSwapFail();
    printf("\n");
    pointerSwapSuccess();
    printf("\n");
    pointerArrayType();
    printf("\n");
    triplePointer();
    printf("\n");

    return 0;
}