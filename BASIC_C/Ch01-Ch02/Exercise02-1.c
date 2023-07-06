#include <stdio.h>
/*
Exercise 02-1
*/

// Problem 1
void printName(void)
{
    printf("HaeunSuh\nHae Un Suh\nHae\tUn\tSuh\n");
}

// Problem 2
void printInfo(void)
{
    printf("NAME: Haeun Suh\n");
    printf("ADDRESS: 200 18th ST S, Birmingham AL 35233\n");
    printf("PHONE NUMER: +1-205-XXXX\n");
}

int main(void)
{
    printName();
    printf("\n");
    printInfo();
    
    return 0;   
}