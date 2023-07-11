/*
    Title: Multi-dimentional Array and Pointer
    Description: Understand the relationship between a Multi-dimentional Array and a Pointer.
    FileName: PointerMultiDimArray.c
    Modified: July 10th 2023
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
    * Continue from pp. 382
    * Futher detail will be skipped except practice codes.
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

int twoDArrayAndArrayPtr(void)
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

int 
int main(void)
{
    twoDArrayAddress();
    printf("\n");
    twoDArrayPointerOp();
    printf("\n");
    twoDArrayAndArrayPtr();
    printf("\n");

    return 0;
}