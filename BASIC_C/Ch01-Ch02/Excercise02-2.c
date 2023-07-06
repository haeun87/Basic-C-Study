#include <stdio.h>
/*
Exercise 02-2
*/

// Problem 1
void printInfo(void)
{
    printf("My Name is %s.\n","Gildong Hong");
    printf("I'm %d years old.\n",20);    
    printf("My Address is '%d-%d'.\n",123,456);   
}

// Problem 2
void printCal(void)
{
    printf("%dX%d=%d\n",4,5,4*5);
    printf("%dX%d=%d\n",7,9,7*9);
}

int main(void)
{
    printInfo();
    printf("\n");
    printCal();
    
    return 0;   
}