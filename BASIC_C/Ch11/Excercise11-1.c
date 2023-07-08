#include <stdio.h>
/*
Exercise 11-1
*/

// Problem 1
void arrayTest(void)
{
    int arr[5];
    int max, min, sum=0;
    for(int i=0; i < 5; i++){
        printf("Enter an integer: ");
        scanf("%d",&arr[i]);
    }
    
    int len = sizeof arr / sizeof(int);

    min=max=arr[0];

    for(int i=0; i < len; i++) {
        if(arr[i] >= max) max = arr[i];
        else if (arr[i] <= min) min = arr[i];
        sum += arr[i];
    }

    printf("Maximum number from Array arr: %d \n", max);
    printf("Minimum number from Array arr: %d \n", min);
    printf("The sum of the value of each element: %d\n", sum);
}

// Problem 2
void arrayStr(void)
{

    char str[] = {'G', 'o', 'o','d',' ','t','i','m','e'};

    int arrLen = sizeof str / sizeof(char);

    for(int j=0; j < arrLen; j++) printf("%c", str[j]); // should not use %s for this...
    printf("%s", str); // Also possible with no error!!  should use %s to print at once!
    printf("\n");
}    

int main(void)
{
    arrayTest();
    printf("\n");
    arrayStr();
    printf("\n");

    return 0;   
}