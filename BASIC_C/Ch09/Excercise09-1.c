#include <stdio.h>
/*
Exercise 09-1
*/

int max(int num1, int num2, int num3)
{
    if(num1 > num2) return (num3 > num1) ? num3: num1;
    else return (num3 > num2) ? num3: num2;

}
int min(int num1, int num2, int num3)
{
    if(num1 > num2) return (num2 > num3) ? num3: num2;
    else return (num1 > num3) ? num3: num1;

}

// Problem 1
void maxMin(void)
{
    int num1, num2, num3;

    printf("Enter 3 integer: ");
    scanf("%d %d %d",&num1, &num2, &num3);

    printf("MAX: %d, MIN: %d", max(num1, num2, num3), min(num1,num2,num3));
}

double CelToFah(double temp)
{
    return 1.8*temp+32;
}

double FahToCel(double temp)
{
    return (temp-32)/1.8;
}

// Problem 2
void tempTrans(void)
{
    double cTemp, fTemp;

    printf("Enter current Celsious: ");
    scanf("%lf",&cTemp);

    printf("%fC = %fF \n", CelToFah(cTemp), cTemp);

    printf("Enter current Fahrenheit: ");
    scanf("%lf",&fTemp);

    printf("%fF = %fC \n", fTemp, FahToCel(fTemp));
}

int fib(int num)
{
    return (num <= 1) ? num : fib(num-1) + fib(num-2);
}

// Problem 3
void fibbonachi(void)
{
    int nums;

    printf("Enter numbers: ");
    scanf("%d",&nums);
    printf("0");
    for(int i=1; i<nums; i++) {
        printf(", ");
        printf("%d", fib(i));
    }
    printf("\n");
}

int main(void)
{
    maxMin();
    printf("\n");
    tempTrans();
    printf("\n");
    fibbonachi();
    printf("\n");

    return 0;   
}