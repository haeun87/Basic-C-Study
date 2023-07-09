#include <stdio.h>
/*
Exercise 13-1
*/

// Problem 1
int pointer1(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = &arr[0];

    printf("%p \n", ptr);

    for(int i=0; i<5; i++){
        printf("%d => ",arr[i]);
        *(ptr++) += 2;
        printf("%d \n", arr[i]);
    }
    printf("%p \n", ptr); // Chaged

    return 0;
}

// Problem 2
int pointer2(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = &arr[0];

    printf("%p \n", ptr);

    for(int i=0; i<5; i++){
        printf("%d => ", arr[i]);
        *(ptr+i) += 2;
        printf("%d \n",  arr[i]);
    }


    printf("%p \n", ptr);// Unchanged

    return 0;
}

// Problem 3
int pointer3(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = &arr[4];
    int sum = 0;

    for(int i=0; i<5; i++) sum += *(ptr--);
    
    printf("TOTAL: %d \n", sum);

    return 0;
}

// Problem 4
int pointer4(void)
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int* sPtr = &arr[0]; int* ePtr = &arr[5];

    for(int i=0; i<3; i++)
    {
        int temp = *sPtr;
        *(sPtr++) = *ePtr;
        *(ePtr--) = temp;
    }

    for(int i=0; i<6; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

int main(void)
{
    pointer1();
    printf("\n");
    pointer2();
    printf("\n");
    pointer3();
    printf("\n");
    pointer4();
    printf("\n");

    return 0;
}