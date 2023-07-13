/*
    Title: Pointers and functions
    Description: Understand the operation of pointers and functions.
    FileName: PointerFunction.c
    Modified: July 10th 2023
    Writer: Haeun Suh
*/

#include <stdio.h>
/*
    Chapter 14 Understanding pointers and functions.
    * The way to pass arguments from the function is to copy them by value. 
        => In other words, when a function is called, the value of the argument will be copied to the parameter.
        => That is, the original arguments will not be affected by the modification of the function.(No side effect the arguments!)
    * Arrays themselves cannot be sent as function arguments in C, since arguments declared as array are converted to pointers the point at the element of array.
        => Therefore, if arrays should be sent as function arguments, it should be sent as a form of pointer variable(or the names of the arrays).
            e.g. void SimpleFunc(int arr[]) or void SimpleFunc(int* arr) (Thease are equivalent!)
    * Unlike other type of arguments, since arrays use the form of pointers, the modification by a function can affect the elements of the arrays.
        => That is, a side effect may occur!
    * Call-by-value VS Call-by-reference:
        Call-by-reference(passes addresses): Side Effect O
        Call-by-value(Passes copied values): Side Effect X
    * Technically, even C language has been designed of its all functions as Call-by-value system.
        => However, C(also ML) can 'simulate call by reference' by using pointer object.
        => This is because, even though pointers can access their addresses, pointers themselves will not change by the function.
        => Sometimes it is referred to as call by address(or pass by address, call by pointer)
    * Standard C language doesn't support overloading but compiler g++ allows it.(not gcc!)
    * A function 'scanf' also uses call-by-pointer.
        => Basically, input value will be assigned to somewhere different place.
        => Should link this value to the designated variable.
        => It is more memory efficient to use pointer rather than to declare another variable!
        => So use '&input' rather than just 'input'!
        => In case of String(or char Array), no need to add '&'.(It is already a pointer variable!)
    * Further detail will be skipped except practice codes.
*/

// void ShowArrayElem(int param[], int len)
void ShowArrayElem(int* param, int len)
{
    for(int i=0; i<len; i++) printf("%d ", param[i]);
    printf("\n");
}

// void AddArrayElem(int param[], int len, int add) // This is valid, too.
void AddArrayElem(int* param, int len, int add)
{
    for(int i=0; i<len; i++) param[i] += add;// side effect!
}

int arrayParam(void)
{
    int arr1[3] = {1, 2, 3};
    int arr2[5] = {4, 5, 6, 7, 8};
    ShowArrayElem(arr1, sizeof arr1 / sizeof(int));
    ShowArrayElem(arr2, sizeof arr2 / sizeof arr2[0]);

    return 0;
}

void Swap(int n1, int n2)
{
    int temp=n1;
    n1=n2;
    n2=temp;
    printf("n1 n2: %d %d \n", n1, n2);
}

void SwapPtr(int* ptr1, int* ptr2)
// void Swap(int* ptr1, int* ptr2) // Not working in gcc
{
    int temp= *ptr1;
    *ptr1= *ptr2;
    *ptr2=temp;
}

int callByValueSwap(void)
{
    int num1=10;
    int num2=20;
    printf("num1 num2: %d %d \n", num1, num2);

    Swap(num1, num2);
    printf("num1 num2: %d %d \n", num1, num2); // Unchanged
    
    return 0;
}

int callByPointerSwap(void)
{
    int num1=10;
    int num2=20;
    printf("num1 num2: %d %d \n", num1, num2);

    SwapPtr(&num1, &num2);
    printf("num1 num2: %d %d \n", num1, num2); // Changed
    
    return 0;
}

int arrayParamAccess(void)
{
    int arr[3] = {1, 2, 3};
    int* ptr=arr; 
    // int ptr[]=arr; // In this case, the statement is an Error!
    
    AddArrayElem(arr, sizeof arr / sizeof(int), 1);
    ShowArrayElem(arr, sizeof arr / sizeof(int));
    AddArrayElem(arr, sizeof arr / sizeof(int), 2);
    ShowArrayElem(arr, sizeof arr / sizeof(int));
    AddArrayElem(arr, sizeof arr / sizeof(int), 3);
    ShowArrayElem(arr, sizeof arr / sizeof(int));

    return 0;
}

int main(void)
{
    arrayParam();
    printf("\n");
    arrayParamAccess();
    printf("\n");
    callByValueSwap();
    printf("\n");
    callByPointerSwap();
    printf("\n");

    return 0;
}