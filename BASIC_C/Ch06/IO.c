/*
    Title: Printf & Scanf
    Description: Understanding the usage of printf and scanf functions.
    FileName: IO.c
    Modified: July 6th 2023
    Writer: Haeun Suh
*/

#include <stdio.h>
/*
Chapter 05 Understanding the printf and scanf functions.
    * Escape sequences:
        \a, \b, \f, \n, \r, \t, \v, \', \", \?, \\
    * Format specifiers:
        %d: signed char, short, decimal int
        %ld: signed decimal long
        %lld: signed decimal long long
        %u: unsinged decimal int
        %o: unsinged octal int - To print identifier -> %#o
        %x, %X: unsinged hexadecimal int- To print identifier -> %#x, %#X
        %f: signed float, double
        (%lf: signed double - scanf)
        %Lf: signed long double - %Lf is not valid for scanf. Use %Le instead
        %e, %E: Signed float, double(e or E format)
        %c: char - Not recommended (It can read as 'null' or '\n'!)
        %s: string, char * - Recommended
        %p: void * - Address of pointer
        %g: choose a format between %f and %e depending on its number of digits
    * String alignments:
        %-nD: left alignment for n bits:
        %nD: right alignment for n bits:
    * %f & %e & %g are equivalent in the scanf function.
*/

void stringPrintf(void)
{
    printf("I like programming:) \n");
    printf("I love gagamel cat! \n");
    printf("What does not kill me makes me stronger. \n");
}

void formPrintf(void)
{
    int myAge=17;
    printf("I'm %d years old in decimal, %x years old in hexadecimal!", myAge, myAge);
}

void octHex(void)
{
    int num1=7, num2=13;
    printf("%o %#o \n", num1, num1);
    printf("%x %#x \n", num2, num2);
}

void realNumOutput(void)
{
    printf("%f \n", 0.1234);
    printf("%e \n", 0.1234); // format using e
    printf("%f \n", 0.12345678);
    printf("%E \n", 0.12345678); // format using E
}

void usingPG(void)
{
    double d1=1.23e-3; // 0.00123
    double d2=1.23e-4; // 0.000123
    double d3=1.23e-5; // 0.0000123
    double d4=1.23e-6; // 0.00000123

    printf("%g \n", d1); // format using PG
    printf("%g \n", d2); // format using PG
    printf("%g \n", d3); // format using PG -> format e
    printf("%g \n", d4); // format using PG -> format e
}

void usingPS(void)
{
    printf("%s, %s, and %s \n", "Power", "Money", "Peace");
}

void fieldWidth(void)
{
    printf("%-12s %5s %10s \n", "Name", "Major", "Year");
    printf("%-12s %5s %10s \n", "Gildong Hong", "EE", "Junior");
    printf("%-12s %5s %10s \n", "Haeun Suh", "CS", "sophomore");
    printf("%-12s %5s %10s \n", "Ddochi Kim", "Art", "Senior");
}

void scanfConvOne(void)
{
    int num1, num2, num3;
    printf("Enter 3 int values: ");
    scanf("%d %o %x", &num1, &num2, &num3);// 12 12 12

    printf("Entered values in decimal: ");
    printf("%d %d %d \n", num1, num2, num3);// 12 10 18
}

void scanfConvTwo(void)
{
    float num1;
    double num2;
    long double num3;

    printf("Enter real number1(format e): ");
    scanf("%f", &num1); // float
    printf("Entered: %f \n", num1);
    printf("Enter real number2(format e): ");
    scanf("%lf", &num2); // double
    printf("Entered: %f \n", num2);
    printf("Enter real number3(format e): ");
    scanf("%Lf", &num3); // long double
    printf("Entered: %Le \n", num3);
}

int main(void)
{
    // printf
    stringPrintf();
    printf("\n");
    formPrintf();
    printf("\n");
    octHex();
    printf("\n");
    realNumOutput();
    printf("\n");
    usingPG();
    printf("\n");
    usingPS();
    printf("\n");
    fieldWidth();
    printf("\n");

    //scanf
    scanfConvOne(); 
    printf("\n");
    scanfConvTwo(); 
    printf("\n");

    return 0;
}