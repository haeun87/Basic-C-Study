#include <stdio.h>

/*
Exercise 25-1

Stack(left->right == bottom->top):
    -> [] // Start program
    -> [int num1=20, ...]   // init of num1
    -> [int num1=20, n=20, ...] // enter func1
    -> [int num1=20, n=20, int num2=21, ...] // init of num2
    -> [int num1=20, n=20, int num2=21, n=21, ...] // enter func2
    -> [int num1=20, n=20, int num2=21, n=21, int num3 = 22, ...] // init num3 
    -> [int num1=20, n=20, int num2=21, ...] // exit func2
    -> [int num1=20, ...] // exit func1
    -> [] // End program
*/

void func2(int n)
{
    int num3= n + 1;
}

void func1(int n)
{
    int num2 = n + 1;
    func2(num2);
}

int main(void)
{
    int num1=20;
    func1(num1);

    return 0;
}