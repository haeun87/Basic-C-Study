#include <stdio.h>
/*
Exercise 21-1
*/
int conv(int ch)
{
    if(ch>=65 && ch<=90) return ch+32;
    else if(ch>=97 && ch<=122) return ch-32;
    else return -1;
}

// Problem
int problem(void)
{
    int ch;

    ch=getchar();
    ch = conv(ch);

    if(ch == -1)
    {   
        printf("Not a valid Input!\n");
        return -1;
    }
    
    putchar(ch);
    return 0;
}

int main(void)
{
    problem();
    printf("\n");

    return 0;
}