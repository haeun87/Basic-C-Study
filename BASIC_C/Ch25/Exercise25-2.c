#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Exercise 25-2
*/

// problem 1
int problem1(void)
{
    int maxlen, len;
    char* str;
    printf("Maximum length of str: ");
    scanf("%d", &maxlen);
    getchar(); // remove newline
    str = (char*)malloc(sizeof(char)*(maxlen+1));

    printf("Enter string: ");
    fgets(str, maxlen+1, stdin);
    str[strlen(str)-1] = 0; // remove newline
    len=strlen(str);

    for(int i=len; i>0; i--){// read as the opposite order of words
        if(str[i]== ' ') // One word
        {
            printf("%s ", &str[i+1]);
            str[i]=0; // remove the read word
        }
    }
    printf("%s", &str[0]); // For the last word
    
    free(str);

    return 0;
}

// Problem 2
int problem2(void)
{
    int arrlen = 5; // initial size
    int idx=0;
    int* arr = (int*)malloc(sizeof(int)*arrlen);

    while(1)
    {
        printf("Enter Decimal number: ");
        scanf("%d", &arr[idx]);
        if(arr[idx]==-1) break; // terminate when entered -1
        if(arrlen == idx+1) // Require expansion
        {
            arrlen+3;
            arr=(int*)realloc(arr, sizeof(int)*arrlen); // expand
        }
    }

    for(int i=0; i<idx; i++) printf("%d ", arr[i]);
    free(arr);

    return 0;
}

int main(void)
{
    problem1();
    printf("\n");
    problem2();
    printf("\n");

    return 0;
}