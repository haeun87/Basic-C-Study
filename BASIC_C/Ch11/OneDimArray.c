/*
    Title: One-dimensional array
    Description: Understand the basics of arrau.
    FileName: OneDimArray.c
    Modified: July 8th 2023
    Writer: Haeun Suh
*/

#include <stdio.h>
/*
    Chapter One-dimensional array.
    * Array is a data structure consisting of a collection of elements (values or variables),
      of same memory size, each identified by at least one array index or key. (Wikipedia)
    * C doesn't check array boudaries. Therefore, it will compile normally with out of boundary assignment.
      A segmentation fault will only occur if there is a trial to dereference a pointer to the inadequate assignment.
    * Partial initialization for array: the unassigned element value will be automatically assigned as 0.
    * The ways to use an array data type to a parameter:
         1) void myFunction(int *param); // as a pointer type
         2) void myFunction(int param[10]); // as a fixed sized array type
         3) void myFunction(int param[]); // as a non-fixed sized array type
    * Standard C language doesn't have a 'for each' form.
    * char array can accept String data type e.g. char str[]="Good morning!"
    * For the char array, should count at least one space for NULL letter.
    * For the char array, the unassigned element value will be automatically assigned as NULL instead of 0.(But actually is ASCII 0)
    * No & operator needed for string type inputs!
    * No NULL at the end -> char array, NULL at the end -> String
    * The C compiler will determine the end of string with the NULL letter.
    * The scanf function distinguishes data with white spaces.
    * Futher detail will be skipped except practice codes.

*/

int arrayAccess(void)
{
    /* 
        The size of the array should be constant only!
        int len = 5;
        int arr[len]; <= Error
    */
    int arr[5];
    int sum = 0;

    arr[0]=10, arr[1]=20, arr[2]=30, arr[3]=40, arr[4]=50;
    
    /*
        There's no out of boudary warnings in C compiler.
        arr[6]=60; <= This works normal 
        printf(arr[6]); <= Error Occurs
    */

    for(int i=0; i < 5; i++) sum += arr[i];

    printf("Sum of the value of each element: %d \n", sum);
    
    return 0;
}

int arrayInit(void)
{
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[ ] = {1, 2, 3, 4, 5, 6, 7}; // This is possible since it has been fully initialized.
    int arr3[5] = {1, 2}; // Partial initialization
    int ar1Len, ar2Len, ar3Len;

    printf("Size of Array arr1: %d \n", sizeof arr1); // 4*5 = 20
    printf("Size of Array arr2: %d \n", sizeof arr2); // 4*7 = 20
    printf("Size of Array arr3: %d \n", sizeof arr3); // 4*5 = 20

    ar1Len = sizeof arr1 / sizeof(int);
    ar2Len = sizeof arr2 / sizeof(int);
    ar3Len = sizeof arr3 / sizeof(int);   

    for(int i=0; i<ar1Len; i++) printf("%d ", arr1[i]);
    printf("\n");
    for(int i=0; i<ar2Len; i++) printf("%d ", arr2[i]);
    printf("\n");
    for(int i=0; i<ar3Len; i++) printf("%d ", arr3[i]);
    printf("\n");

    return 0;
}

int arrayString(void)
{
    char str[14] = "Good morning!";
    printf("Size of Array str: %d \n", sizeof str); // 14
    printf("NULL letter in char: %c \n", str[13]); // Nothing appears!
    printf("Null letter in integer: %d \n", str[13]); // 0

    str[12] = '?'; // Modify 13th char
    printf("Print Array str: %s \n", str);

    return 0;
}

int readString(void)
{
    char str[50];
    int idx = 0;

    printf("Enter a String: ");
    scanf("%s", str);// No & letter!
    printf("The entered String: %s \n", str);

    printf("Print one by one as a char each: ");
    while(str[idx] != '\0')
    {
        printf("%c", str[idx]);
        idx++;
    }
    printf("\n");

    return 0;
}

int startEndString(void)
{
    char str[50]= "I like C programming";
    printf("string: %s \n", str);

    str[8] = '\0'; 
    printf("string: %s \n", str);

    str[6] = '\0'; 
    printf("string: %s \n", str);

    str[1] = '\0'; 
    printf("string: %s \n", str);

    return 0;
}

int main(void)
{
    arrayAccess();
    printf("\n");
    arrayInit();
    printf("\n");
    arrayString();
    printf("\n");
    readString();
    printf("\n");
    startEndString();
    printf("\n");

    return 0;
}