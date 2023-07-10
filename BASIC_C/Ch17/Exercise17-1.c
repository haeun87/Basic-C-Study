#include <stdio.h>
/*
Exercise 17-1
*/

void MaxAndMin(int* arr, int len, int** minPtr, int** maxPtr)
{
    int min=0, max=0;
    for(int i=0; i<len; i++){
        if(arr[max] < arr[i]) max = i;
        if(arr[min] > arr[i]) min = i;    
    }
    *minPtr = &arr[min];
    *maxPtr = &arr[max];
}

// Problem
int minMax(void)
{
    int* maxPtr;
    int* minPtr;
    int arr[5] = {1, 2, 3, 4, 5};
    MaxAndMin(arr, 5, &minPtr, &maxPtr);
    
    printf("MAX: %d MIN: %d", *maxPtr, *minPtr);
    return 0;
}

int main(void)
{
    minMax();
    printf("\n");

    return 0;
}