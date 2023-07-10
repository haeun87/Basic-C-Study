/*
    Title: Multi-Dimensional Array
    Description: Understand the operation of Multi-Dimensional Array.
    FileName: MulDimArray.c
    Modified: July 10th 2023
    Writer: Haeun Suh
*/

#include <stdio.h>
/*
    Chapter 16 Multi-Dimensional Array
    * Partial initialization is also available for multi-dimentional arrays.
    * When initialization a multi-dimentional array as an one-dimentional array,
      each element of the one-dimentional array will be assigned as sequentially to the multi-dimentional array.
      e.g. int arr[2][2] = {1, 2, 3}
        => arr[0][0] = 1, arr[0][1]=2, arr[1][0]=3, arr[1][1] = 0
    * When initializing an array, only colum size can be omitted.
        e.g. int arr[][4](O) but int arr[2][] or int arr[][](X) 
    * Futher detail will be skipped except practice codes.
*/

int twoDimArraySize(void)
{
    int arr1[3][4];
    int arr2[7][9];
    printf("3 Rows, 4 Columns: %d \n", sizeof arr1); // 3 * 4 * 4 = 48
    printf("7 Rows, 9 Columns: %d \n", sizeof arr2); // 7 * 9 * 4 = 252

    return 0;   
}

int popuResearch(void)
{
    int villa[4][2];

    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            printf("The Population of a Room No. %d of a Floor %d: ", i+1, j+1);
            scanf("%d", &villa[i][j]);
        }
    }
    for(int i=0; i<4; i++){
        int pTotal = 0;
        for(int j=0; j<2; j++) pTotal += villa[i][j];
        printf("Total Population of the Floor %d: %d \n", i+1, pTotal);
    }
}

int twoDimArrayAddr(void)
{
    int arr[3][2];
    for(int i=0; i<3; i++) for(int j=0; j<2; j++) printf("%p \n", &arr[i][j]);

    return 0;
}

int twoDimArrayInit(void)
{
    int arr1[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    int arr2[3][3] = {{1},{4, 5},{7, 8, 9}};
    int arr3[3][3] = {1, 2, 3, 4, 5, 6, 7};

    printf("Array1: \n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) printf("%d ", arr1[i][j]);
        printf("\n");
    }

    printf("\nArray 2: \n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) printf("%d ", arr2[i][j]);
        printf("\n");
    }
    
    printf("\nArray 3: \n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) printf("%d ", arr3[i][j]);
        printf("\n");
    }
}

int threeDimArraySize(void)
{   
    int arr1[2][3][4]; // 2*3*4*4 = 96
    double arr2[5][5][5]; // 5*5*8 = 1000

    printf("(sizeof) Height 2 Depth 3 Width 4 integer: %d \n", sizeof arr1);
    printf("(sizeof) Height 5 Depth 5 Width 5 Double: %d \n", sizeof arr2);
}

int threeDimArrayAccess(void)
{   
    int record[3][3][2] = {
        {{70, 80}, {94, 90}, {70, 85}},
        {{83, 90}, {95, 60}, {90, 82}},
        {{98, 89}, {99, 94}, {91, 87}}
    };

    for(int i=0; i<3; i++){
        int mean = 0;
        for(int j=0; j<3; j++) for(int k=0; k<2; k++) mean += record[i][j][k];
        printf("Class %d Average: %g \n", i+1, (double)mean/6);
    } 

}

int main(void)
{
    twoDimArraySize();
    printf("\n");
    popuResearch();
    printf("\n");
    twoDimArrayAddr();
    printf("\n");
    twoDimArrayInit();
    printf("\n");
    threeDimArraySize();
    printf("\n");
    threeDimArrayAccess();
    printf("\n");

    return 0;
}