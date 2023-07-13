#include <stdio.h>
/*
Exercise 18-1
*/

// Problem 1
int problem1(void)
{
    int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int* arr1[5] = {&arr[0], &arr[1], &arr[2], &arr[3], &arr[4]};
    int* arr2[3][5] = 
    {
        &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], 
        &arr[5], &arr[6], &arr[7], &arr[8], &arr[9],
        &arr[10], &arr[11], &arr[12], &arr[13], &arr[14]
    };

    int** parr1 = arr1;
    printf("parr1[3]: %d, arr1[3]: %d \n", *parr1[3], *arr1[3]);
    int* (*parr2)[5] = arr2;
    printf("parr2[2][2]: %d, arr2[2][2]: %d \n", *parr2[2][2], *arr2[2][2]);

    return 0;
}

// Problem 2
void SimpleFunctionOne(int* arr1, int* arr2){
    printf("arr1: ");
    for(int i=0; i<3; i++) printf("%d ", arr1[i]);
    printf("\narr2: ");
    for(int i=0; i<4; i++) printf("%d ", arr2[i]);
    printf("\n\n");    
}

void SimpleFunctionTwo(int (*arr3)[4], int (*arr4)[4]){
    printf("arr3: \n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<4; j++) printf("%d ", arr3[i][j]);
        printf("\n");
    }
    printf("arr4: \n");
    for(int i=0; i<2; i++) {
        for(int j=0; j<4; j++) printf("%d ", arr4[i][j]);
        printf("\n");
    } 
    printf("\n\n");   
}

int problem2(void)
{
    int arr1[3] = {1, 2, 3};
    int arr2[4] = {1, 2, 3, 4};
    int arr3[3][4] = {11, 12, 13, 14, 21, 22, 23, 24, 31, 32, 33, 34};
    int arr4[2][4] = {11, 12, 13, 14, 21, 22, 23, 24};

    SimpleFunctionOne(arr1, arr2);
    SimpleFunctionTwo(arr3, arr4);

    return 0;
}

// Problem 3
void ComplexFuncOne(int* *arr1, int* (*arr2)[5]){
    printf("%d %d \n", *arr1[2], *arr2[0][2]); // 3
};

void ComplexFuncTwo(int** *arr3, int*** (*arr4)[5]){
    printf("%d %d \n", **arr3[2], ***arr4[0][2]); // 3
};

int problem3(void)
{
    int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int* arr1[5] = {&arr[0], &arr[1], &arr[2], &arr[3], &arr[4]};
    int* arr2[3][5] = 
    {
        &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], 
        &arr[5], &arr[6], &arr[7], &arr[8], &arr[9],
        &arr[10], &arr[11], &arr[12], &arr[13], &arr[14]
    };

    int** arr3[5] = {&arr1[0], &arr1[1], &arr1[2], &arr1[3], &arr1[4]};
    int*** arr4[3][5] = 
    {
        &arr3[0], &arr3[1], &arr3[2], &arr3[3], &arr3[4], 
        &arr3[0], &arr3[1], &arr3[2], &arr3[3], &arr3[4], 
        &arr3[0], &arr3[1], &arr3[2], &arr3[3], &arr3[4], 
    };

    ComplexFuncOne(arr1, arr2);
    ComplexFuncTwo(arr3, arr4);

}

// Problem 4
int problem4(void)
{
    int arr[3][2] = { {1, 2}, {3, 4}, {5, 6}};
    printf("%d %d \n", arr[1][0], arr[0][1]); // 3 2
    printf("%d %d \n", *(arr[2]+1), *(arr[1]+1)); // 6 4
    printf("%d %d \n", (*(arr+2))[0], (*(arr+0))[1]); // 5 2
    printf("%d %d \n", **arr, *(*(arr+0)+0)); // 1 1 
}

// Problem 5
int problem5(void)
{
    int arr[2][2][2]= {1, 2, 3, 4, 5, 6, 7, 8};
    printf("%d \n", arr[1][0][1]); // 6

    printf("%d \n", (*(arr+1))[0][1]); // 6
    printf("%d \n", (*(*(arr+1)+0))[1]); // 6
    printf("%d \n", *(*(*(arr+1)+0)+1)); // 6
    printf("%d \n", *(**(arr+1)+1)); // 6
    printf("%d \n", (**(arr[1])+1)); // 6
}

int main(void)
{
    problem1();
    printf("\n");
    problem2();
    printf("\n");
    problem3();
    printf("\n");
    problem4();
    printf("\n");
    problem5();
    printf("\n");

    return 0;
}