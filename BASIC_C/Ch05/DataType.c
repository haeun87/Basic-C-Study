/*
    Title: Data Types.
    Description: Understanding concepts of the constant and primitive data type.
    FileName: DataType.c
    Modified: July 6th 2023
    Writer: Haeun Suh
*/
#include <stdio.h>
/*
Chapter 05 Constants and Primitive data types.
    * Primitive data types: For different representation & memory optimization
        char: 1 byte
        short: 1 type
        int&long&float: 4 byte
        long long&double: 8 byte
        long double: above 8 type (Varies from compiler to compiler)
    * sizeof is not a function. It is an operator that calculates size of the datatype.
    * Unless the data type of the result value is not explicitly specified, 
      data smaller than int will be converted to an int type for operation efficiency, as well as the result value.
    * Use int variables operation efficiency and use char/short variables for memory optimization.
    * The most important factor in choosing a real data type is precision.
    * General datatype for integer number => int (operation efficiency)
      General datatype for real number => double (precision)
    * Decimal precision of each datatype(=the maximum range without errors)
        float: 6 digits
        double: 15 digits
        long doulbe: 18 digits
    * Format specifiers:
        %d: decimal integer(+/-)
        %f: float
        %lf: double
        %c: char - Not recommended (It can read as 'null' or '\n'!)
        %s: string - Recommended
        %o: octal integer(+)
        %x: hexadecimal integer(+)
        %u: decimal integer(+)
    * Unsigned ~: -n ~ (n-1) => 0 ~ (2n-1)
        => Only available for integer data types.
        => Use MSB to represent data size.
        => twice larger range than signed data types.
    * Character representation: Mapping numbers to chars(ASCII)
    * For character variable, it is more suitable to use char type(No operation!).
    * Technically, char type is an integer data type(Rather than character data type!). 
    * Constants also expressed based on data types.
    * Literal constant: No-named (with the memory space) constant which is the subject of operations.
    * Specifying data types for constants:
        unsigned int: XXXXu | XXXXU
        long&long double: XXXXl | XXXXL
        unsigned long: XXXXul | XXXXUL
        long long: XXXXll | XXXXLL
        unsigned long long: XXXXull | XXXXULL
        float: XXXXf | XXXXF
    * Symbolic constant(const): Use keyword 'const' to fix the value.
        => Same as 'final' in JAVA
        => Should be declared in upper case and connected with underbars.
            ex> const int FINAL_MAX = 10000;
        => It is possible to separate declaration and initialization but it results in junk value.
    * Type Casting and Type Conversion:
        Type Casting(explicit): ex> float b = 35.33; int a = (int) b;
        Type Conversion(implicit): ex> int a = 10, float b = a;
    * Integral Promotion(for operation efficiency) -> implicit type conversion.
    * Data matching(for data consistency) -> implicit type conversion.
        => Conversion rule: Match with most biggest data type!
        => Exception: long long(8 byte but integer number) < float(4 byte but real number)
        
*/

void sizeOfOperator(void)
{
    char ch=9;
    int inum=1052;
    double dnum=3.1415;
    
    //sizeof for variables: Can be executed without parentheses!
    printf("sizeof(ch): %d \n", sizeof ch); // 1 byte
    printf("sizeof(inum): %d \n", sizeof inum); // 4 byte
    printf("sizeof(dnum): %d \n", sizeof dnum); // 8 byte

    //sizeof for primitive datatypes: Should be enclosed in parentheses!   
    printf("sizeof(char): %d \n", sizeof(char)); // 1 byte
    printf("sizeof(short): %d \n", sizeof(short)); // 2 byte
    printf("sizeof(int): %d \n", sizeof(int)); // 4 byte
    printf("sizeof(long): %d \n", sizeof(long)); // 4 byte
    printf("sizeof(long long): %d \n", sizeof(long long)); ; // 8 byte
    printf("sizeof(float): %d \n", sizeof(float)); ; // 4 byte
    printf("sizeof(double): %d \n", sizeof(double)); // 8 byte
    printf("sizeof(long double): %d \n", sizeof(long double)); // 16 byte
}

void charShortBaseAdd(void)
{
    char num1=1, num2=2, result1=num1 + num2;
    short num3=300, num4=400, result2=num3 + num4;

    printf("size of num1 & num2(char): %d, %d \n", sizeof num1, sizeof num2);
    printf("size of num3 & num4(short): %d, %d \n", sizeof num3, sizeof num4);
    printf("size of num1 + num2(int): %d\n", sizeof (num1 + num2)); // int
    printf("size of num3 + num4(int): %d\n", sizeof (num3 + num4)); // int
    printf("size of num1 + num2(char): %d\n", sizeof result1); // char
    printf("size of num3 + num4(short): %d\n", sizeof result2); // short
}

void circleArea(void)
{
    double rad, area;
    printf("Enter the radius of a Circle: ");
    scanf("%lf", &rad);// lf = long float = double

    area = rad*rad*3.1415;
    printf("Area of Circle: %f \n", area);// Also available as %lf
}


void howChar(void)
{
    char ch1='A', ch2=65;
    int ch3='Z', ch4=90;// a character can be initiated as an int type!

    printf("%c %d \n", ch1, ch1);
    printf("%c %d \n", ch2, ch2);
    printf("ch1 == ch2? %d \n", ch1 == ch2); // True
    printf("%c %d \n", ch3, ch3);
    printf("%c %d \n", ch4, ch4);
    printf("ch3 == ch4? %d \n", ch3 == ch4); // True
}

void literalSize(void)
{
    printf("literal int(7) size: %d \n", sizeof(7)); // 4
    printf("literal double(7.14) size: %d \n", sizeof(7.14)); // 8
    printf("literal char('A') size: %d \n", sizeof('A')); // 1
}

void autoConvOne(void)
{
    double num1=245;
    int num2=3.1415;
    int num3=129;
    char ch=num3;

    printf("from int 245 to double a: a= %f \n", num1); // 245.000000 -> No loss but error exists
    printf("from double 3.1415 to int b: b= %d \n", num2); // 3 -> Data loss
    printf("from int 129 to char c: c= %d \n", ch); // -127 -> Data loss & Juck data
}

void convDiv(void)
{
    int num1=3, num2=4;
    double divResult;
    // divResult = num1 / num2; // 0.75 => 0.0000 (integer)
    divResult = (double)num1 / num2; // Type casting
    printf("result of the division: %f \n", divResult);
}

int main(void)
{
    sizeOfOperator();
    printf("\n");
    charShortBaseAdd();
    printf("\n");
    circleArea();
    printf("\n");
    howChar();
    printf("\n");
    literalSize();
    printf("\n");
    autoConvOne();
    printf("\n");
    convDiv();
    printf("\n");
}