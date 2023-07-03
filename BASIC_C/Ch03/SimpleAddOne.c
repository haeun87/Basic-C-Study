/*
    Title: Variable and Operator.
    Description: Basic of Operator and Variable.
    FileName: SimpleAddOne.c
    Modified: July 3rd 2023
    Writer: Haeun Suh
*/
#include <stdio.h>
/*
Chapter 03 Variable and Operator.
    * If variable not initialized, the compiler automatically assigns 0
    to avoid nullpointer error.(But )
    *  Priciple of Naming variable
      1> The name of a variable consists of Alphabets, Numbers, and underbars.
      2> C language is case sensitive. 
      3> The name of a variable should not start with Numbers or use keywords.
      4> No whitespace allowed for naming a variable. 
    * Binary Operators: 
        * Assignment operator: (=)
        * Arithmetic operator: (+,-,*,/,%)
        * Bitwise operator: (&,|,^,<<,>>,~)
        * Compound Assignment Operator: [Arithmetic Op | Bitwise Op] + Assigment Op
        * Sign operator[Unary operator]: Can be Simply applied as [+|-] + Value
        * Increment/Decrement Operator[Unary operator]: [++|--] + Value or Value + [++|--]
        * Relational operator: (<,>,==,!=,<=,>=)
        * Logical operator: (&&, ||, !)
        * Comma operator: (,)
    * Operation Priority[Precedence]
        C Operator Precedence.(2022, June 10).cppreference.com.https://en.cppreference.com/w/c/language/operator_precedence
*/
void simpleAddOne(void)
{
    int num; // Declaration of a variable
    num = 3 + 4; // Store value to the variable or Initialization
    printf("%d\n", num); // Print the reference of the variable
}

void varDeclAndInit(void)
{
    int num1, num2; // Declaration and Not assigned
    int num3= 30, num4 = 40; //Declaration and Initialization

    printf("num1: %d, num2: %d \n",num1, num2);// Automatically assigned 0
    num1=10;// Assigned
    num2=20;// Assigned

    printf("num1: %d, num2: %d \n", num1, num2);
    printf("num3: %d, num4: %d \n", num3, num4);
}

void simpleAddTwo(void)
{
    int num1 = 5;
    int num2 = 29;
    int result = num1 + num2;
    printf("Result of Sum: %d\n", result);
    printf("%d + %d = %d \n", num1, num2, result);
    printf("The sum of %d and %d is %d\n", num1, num2, result);   
}

void operatorOne(void)
{
    int num1=9, num2=2;
    printf("%d + %d = %d\n",num1, num2, num1+num2);
    printf("%d - %d = %d\n",num1, num2, num1-num2);
    printf("%d * %d = %d\n",num1, num2, num1*num2);
    printf("Quotient of %d DIV %d = %d\n",num1, num2, num1/num2);
    printf("Remainder of %d DIV %d = %d\n",num1, num2, num1%num2);
}

void operatorTwo(void)
{
    int num1=2, num2=4, num3=6;
    num1 += 3; // num1 = num1 + 3;
    num2 *= 4; // num2 = num2 * 4;
    num3 %= 5; // num3 = num3 % 5;
    printf("Result: %d, %d, %d \n", num1, num2, num3);
}

void operatorThree(void)
{
    int num1= +2, num2= -4;
    num1 = -num1;
    printf("num1: %d \n", num1);
    num2 = -num2;
    printf("num2: %d \n", num2);
}

void operatorFour(void)
{
    int num1= 12, num2= 12;

    printf("num1: %d \n", num1);
    printf("num1++: %d \n", num1++); // Postfix increment - Original Value
    printf("num1: %d \n", num1);

    printf("num2: %d \n", num2);
    printf("++num2: %d \n", ++num2); // Prefix increment - Modified Value
    printf("num2: %d \n", num2);
}

void operatorFive(void)
{
    int num1= 10;
    int num2= (num1--)+2; // Postfix decrement - Original Value

    printf("num1: %d \n", num1); // Modified num1
    printf("num2: %d \n", num2); // Original num1 + 2 * Assignment first, Operation later
}

void operatorSix(void)
{
    int num1= 10;
    int num2= 12;
    int result1, result2, result3;

    result1=(num1==num2);
    result2=(num1<=num2);
    result3=(num1>num2);

    // 0 or 1 (Not Boolean!)
    printf("result1: %d \n", result1); 
    printf("result2: %d \n", result2); 
    printf("result3: %d \n", result3); 
}

void operatorSeven(void)
{
    int num1= 10;
    int num2= 12;
    int result1, result2, result3;

    result1=(num1==10 && num2==12);
    result2=(num1<12 || num2>12);
    result3=(!num1);

    // 0 or 1 (Not Boolean!)
    printf("result1: %d \n", result1); 
    printf("result2: %d \n", result2); 
    printf("result3: %d \n", result3); 
}

void commaOp(void)
{
    int num1=1, num2=2; // Available for variable declarations and assignments
    printf("Hello "), printf("world! \n"); // Also available for function calls
    num1++, num2++;// Also available for unary operations
    printf("%d ", num1), printf("%d ", num2), printf("\n");
}

void simpleAddThree(void)
{
    int result;
    int num1, num2;

    printf("Integer one: ");
    scanf("%d", &num1);
    printf("Integer two: ");
    scanf("%d", &num2);

    result = num1+num2;
    printf("%d + %d = %d \n", num1, num2, result);
}

void simpleAddFour(void)
{
    int result;
    int num1, num2, num3;

    printf("Please Enter the 3 integer number: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    result = num1+num2+num3;
    printf("%d + %d + %d = %d \n", num1, num2, num3, result);
}

int main(void)
{
    simpleAddOne();
    printf("\n");
    varDeclAndInit();
    printf("\n");   
    simpleAddTwo();
    printf("\n");   
    operatorOne();
    printf("\n");
    operatorTwo();
    printf("\n");
    operatorThree();
    printf("\n");
    operatorFour();
    printf("\n");
    operatorFive();
    printf("\n");
    operatorSix();
    printf("\n");
    operatorSeven();
    printf("\n");
    commaOp();
    printf("\n");
    simpleAddThree();
    printf("\n");
    simpleAddFour();
    
    return 0;
}