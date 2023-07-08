#include <stdio.h>
/*
Exercise 11-2
*/

int len(char *str)
{
    int i = 0;
    while(str[i] != 0)
    {
        i++;
    } 

    return i;
}

// Problem 1
void lenOfString(void)
{
    char str[50];

    printf("Enter a String: ");
    scanf("%s",str);

    printf("The length of String: %d \n", len(str));
}

// Problem 2
void reverse(void)
{
    char str[50], rev[50];
    printf("Enter a String: ");
    scanf("%s",str);
    int length = len(str);
    int j = 0;
    for(int i=length-1; i >= 0; i--)
    {
        rev[j] = str[i];
        j++;
    }

    printf("%s",rev);
}


// Problem 3
void maxASCII(void)
{
    char str[50];
    printf("Enter a String: ");
    scanf("%s",str);

    int i = 0;
    char max;
    while(str[i] != 0)
    {
        if(max < str[i]) max = str[i];
        i++;
    } 

    printf("The Letter which has maximum number of ASCII: %c", max);
}

int main(void)
{
    lenOfString();
    printf("\n");
    reverse();
    printf("\n");
    maxASCII();
    printf("\n");

    return 0;   
}