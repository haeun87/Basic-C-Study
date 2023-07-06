#include <stdio.h>
/*
Exercise 05-1
*/

// Problem 1
void calCoordinate(void)
{
    int x1, x2, y1, y2;

    printf("Enter the Starting point(x1 y1): ");
    scanf("%d %d",&x1, &y1);
    printf("Enter the End point(x2 y2): ");
    scanf("%d %d",&x2, &y2);

    printf("Area of the rectangle: %d\n", (x2-x1)*(y2-y1));   
}

// Problem 2
void calRealNums(void)
{
    double num1, num2;

    printf("Enter the two real number: ");
    scanf("%lf %lf",&num1, &num2);

    printf("%lf + %lf = %lf\n",num1, num2, num1+num2);   
    printf("%lf - %lf = %lf\n",num1, num2, num1-num2);   
    printf("%lf * %lf = %lf\n",num1, num2, num1*num2);  
    printf("%lf / %lf = %lf\n",num1, num2, num1/num2); 
}

// Problem 3
void rangeASCII(void)
{
    char aUpper = 'A', zUpper = 'Z', alower = 'a';

    printf("Range of ASCII code: [^@(0) , DEL(127)]\n");   
    printf("size of range ['A','Z']: (%d)\n", zUpper-aUpper);
    printf("diff of range ['A','a']: (%d)\n", alower-aUpper);
}


// Problem 4, Problem 5
void printASCII(void)
{
    int num1, char1;

    printf("Enter the ASCII number: ");
    scanf("%d", &num1);
    printf("ASCII character of %d is %c \n",num1, num1);  
        
    printf("Enter the ASCII Character: ");
    scanf("%s", &char1);// Should use %s rather than %c (Null character)
    printf("ASCII number of %c is %d \n", char1, char1);     
}

int main(void)
{
    calCoordinate();
    printf("\n");
    calRealNums();
    printf("\n");
    rangeASCII();
    printf("\n");
    printASCII();
    printf("\n");

    return 0;   
}