#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Exercise 21-2
*/

// Problem 1
int problem1(void)
{
    char str[50];
    int len;
    int sum=0;

    printf("Enter String: ");
    fgets(str, sizeof(str), stdin); // A15#43
    len=strlen(str);

    for(int i=0;i<len;i++) if(48<=str[i] && str[i]<= 59) sum += str[i] - 48;
  
    printf("SUM: %d \n", sum); // 13
    return 0;
}

// Problem 2
int problem2(void)
{
    char str1[20], str2[20], str3[40];
    printf("Enter String 1: ");
    fgets(str1, sizeof(str1), stdin); // Simple
    str1[strlen(str1)-1]=0; // Set as Null

    printf("Enter String 2: ");
    fgets(str2, sizeof(str2), stdin); // String
    str2[strlen(str2)-1]=0; // Set as Null

    // strcpy(str3, str1);
    // strcat(str3, str2);
    strncpy(str3, str1, sizeof(str3)-1); // Remove Null
    strncat(str3, str2, 7);

    // printf("String 3: %s \n", str3);
    puts(str3);

    return 0;
}

// Problem 3
int idxOfWS(char str[])
{
    int len = strlen(str);
    for(int i=0; i<len; i++) if(str[i] == ' ') return i;
    return -1;
}

int problem3(void)
{
    char str1[20], str2[20];

    printf("[1st] Enter  (Name Age): ");
    fgets(str1, sizeof str1, stdin);
    str1[strlen(str1)-1] = 0;

    printf("[2nd] Enter  (Name Age): ");
    fgets(str2, sizeof str2, stdin);
    str2[strlen(str2)-1] = 0;

    int idx1= idxOfWS(str1);
    int age1=atoi(&str1[idx1+1]);
    int idx2= idxOfWS(str1);
    int age2=atoi(&str2[idx2+1]);

    (idx1 != idx2 || strncmp(str1, str2, idx1))
    ? puts("Their names are different!")
    : puts("Their names are the same!");

    (age1==age2) 
    ? puts("Their ages are the same!")
    : puts("Their ages are different!");

    return 0;
}

int main(void)
{
    problem1();
    printf("\n");
    problem2();
    printf("\n");
    problem3();
    printf("\n");

    return 0;
}