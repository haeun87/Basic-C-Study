/*
    Title: Multi-dimentional Array and Pointer
    Description: Understand the relationship between a Multi-dimentional Array and a Pointer.
    FileName: PointerMultiDimArray.c
    Modified: July 12th 2023
    Writer: Haeun Suh
*/

#include <stdio.h>
/*
    Chapter 18 Relationship between a Multi-dimentional Array and a Pointer.
    * The name of an array and the first element of an array are actually differrent!
    (Even though they are pointing the same address!)
    * 2 Dimentional array's pointer type will be determined by:
        The object to point(Data Type) e.g. <datatype> *ptr
        The size of each row : e.g. n => sizeof <datatype> X n
        int (*ptr) [n]
    * An array of pointers: int* whoA[4];
      A pointer of an Array: int (*whoB) [4];
    * int (*parr)[n] = int parr[][n] (But these are only equivalent when it comes to declaration!)
    * *(*(arr+n)+m) == *(arr+n)[m] == *(arr[n]+m) == arr[n][m]
    * Further detail will be skipped except practice codes.
*/

int twoDArrayAddress(void)
{
    int arr2d[3][3];
    printf("%d \n", arr2d);
    printf("%d \n", arr2d[0]); // arr2d == arr2d[0]
    printf("%d \n\n", &arr2d[0][0]);

    printf("%d \n", arr2d[1]);
    printf("%d \n\n", &arr2d[1][0]);

    printf("%d \n", arr2d[2]);
    printf("%d \n\n", &arr2d[2][0]);

    // The size of the first element of the array. sizeof arr2d != sizeof arr2d[0]
    printf("sizeof(arr2d): %d \n", sizeof arr2d); // Total size of the array: 4*3*3 = 36
    printf("sizeof(arr2d[0]): %d \n", sizeof arr2d[0]); // Total size of the arr2d[0]: 4*1*3 = 12
    printf("sizeof(arr2d[1]): %d \n", sizeof arr2d[1]); // Total size of the arr2d[1]: 4*1*3 = 12
    printf("sizeof(arr2d[2]): %d \n", sizeof arr2d[2]); // Total size of the arr2d[2]: 4*1*3 = 12

    return 0;
}

int twoDArrayPointerOp(void)
{
    int arr1[3][2];
    int arr2[2][3];

    printf("arr1: %p \n", arr1);
    printf("arr1+1: %p \n", arr1+1); // +8 = 4*2
    printf("arr1+2: %p \n", arr1+2); // +16 = 4*2*2

    printf("arr2: %p \n", arr2);
    printf("arr2+1: %p \n", arr2+1); // +12 = 4*3

    return 0;    
}

int twoDArrayNameAndArrayPtr(void)
{
    int arr1[2][2] = { {1, 2}, {3, 4} };
    int arr2[3][2] = { {1, 2}, {3, 4}, {5, 6} }; 
    int arr3[4][2] = { {1, 2}, {3, 4}, {5, 6}, {7, 8} };

    int (*ptr)[2];

    ptr=arr1;
    printf("** show 2, 2 arr1 **\n");
    for(int i=0; i<2; i++) printf("%d %d \n", ptr[i][0], ptr[i][1]);

    ptr=arr2;
    printf("** show 3, 2 arr2 **\n");
    for(int i=0; i<3; i++) printf("%d %d \n", ptr[i][0], ptr[i][1]);

    ptr=arr3;
    printf("** show 4, 2 arr3 **\n");
    for(int i=0; i<4; i++) printf("%d %d \n", ptr[i][0], ptr[i][1]);

    return 0;
}

int arrPtrAndPtrArr(void)
{
    int num1=10, num2=20, num3=30, num4=40;
    int arr2d[2][4]={1, 2, 3, 4, 5, 6, 7, 8};

    int* whoA[4] = {&num1, &num2, &num3, &num4}; // An array of pointers
    int (*whoB)[4] = arr2d; // A pointer of an 2D Array
    int (*whoC) = arr2d[0]; // A pointer of a row of 2D Array

    printf("%d %d %d %d \n", *whoA[0], *whoA[1], *whoA[2], *whoA[3]);
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++) printf("%d ", whoB[i][j]);
        printf("\n");
    }
    for(int k=0; k<4; k++)  printf("%d ", whoC[k]);
    printf("\n");

    return 0;
}

void ShowArr2DStyle(int (*arr)[4], int column)
{
    for(int i=0; i<column; i++)
    {
        for(int j=0; j<4; j++) printf("%d ", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}

int Sum2DArr(int arr[][4], int column)
{
    int sum = 0;
    for(int i=0; i<column; i++) for(int j=0; j<4; j++) sum += arr[i][j];
    return sum;
}

int twoDArrParam(void)
{
    int arr1[2][4] = {1, 2, 3, 4, 5, 6, 7, 8};
    int arr2[3][4] = {1, 1, 1, 1, 3, 3, 3, 3, 5, 5, 5, 5};

    ShowArr2DStyle(arr1, sizeof arr1/ sizeof arr1[0]);
    ShowArr2DStyle(arr2, sizeof arr2/ sizeof arr2[0]);
    printf("SUM(arr1): %d \n", Sum2DArr(arr1,  sizeof arr1/ sizeof arr1[0]));
    printf("SUM(arr2): %d \n", Sum2DArr(arr2,  sizeof arr2/ sizeof arr2[0]));

    return 0;
}

int twoDArrAccessType(void)
{
    int a[3][2] = {{1, 2}, {3, 4}, {5, 6}};

    printf("a[0]: %p \n", a[0]);
    printf("*(a+0): %p \n", *(a+0));

    printf("a[1]: %p \n", a[1]);
    printf("*(a+1): %p \n", *(a+1));

    printf("a[2]: %p \n", a[2]);
    printf("*(a+2): %p \n", *(a+2));

    printf("%d, %d \n", a[2][1], (*(a+2))[1]);
    printf("%d, %d \n", a[2][1], *(a[2]+1));
    printf("%d, %d \n", a[2][1], *(*(a+2)+1));

    return 0;    
}

int main(void)
{
    twoDArrayAddress();
    printf("\n");
    twoDArrayPointerOp();
    printf("\n");
    twoDArrayNameAndArrayPtr();
    printf("\n");
    arrPtrAndPtrArr();
    printf("\n");
    twoDArrParam();
    printf("\n");
    twoDArrAccessType();
    printf("\n");

    return 0;
}