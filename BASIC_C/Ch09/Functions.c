/*
    Title: The Functions
    Description: Understand the nature of functions.
    FileName: Functions.c
    Modified: July 7th 2023
    Writer: Haeun Suh
*/

#include <stdio.h>
/*
    Chapter 09 Functions, the core of the C language.
    * The Printf function returns the length of its input, string.
    * local variables are allocated in an area of memory called the 'stack'.
    * Local variables are also called as 'automatic variable'.  
    * Variable shadowing / Name masking occurs in C/C++ languages.
    * The global variable will be shadowed by the local variable within the same scope level.
    * Parameters also regarded as sort pf local variables.
    * The global/statoc variable will initialize as 0 by default.
    * The global variable will be allocated in static memory(not heap!).
    * The static local variable is a scope restricted type of the global variable.
    * register variable: the variable that is allocated in CPU register directly.
    * register variable uses for a highly frequently used and timely access needed variable.
    * The declaration of register variable will be determined by the compiler, since it is a performance-critical decision.
    * register variables are much more concerned with system(e.g. UNIX) programming rather than general programming.
    * Global variable cannot be assigned as register variable.
    * Unlike C++, since C is not an OOP language, C does not support function overloading.
    * In C language, if a recursive function is called again in the middle of executing a recursive function, 
      another copy of the recursive function will be created and the copy will be executed.
    * For that reason, it might result in the occurrence of a stack overflow in case of very deep recursion, where function copies occupy too much memory.
    * Unlike other functional language, there are no references in C language, 
    but can be achieve the similiar funcationality by using pointers.
    
    * Futher detail will be skipped except practice codes.

*/

void Add1(int val);
int gNum; // Global variable

void printfOutput(void)
{
    int num1, num2;
    num1=printf("12345\n");
    num2=printf("I love my cat\n");
    printf("%d %d \n", num1, num2);
}

int Add(int num1, int num2)
{
    return num1 + num2;
}

void ShowAddResult(int num)
{
    printf("Result Add: %d \n", num);
}

void HowToUseThisProg(void)
{
    printf("Description: Enter Two integers, then result of sum will appear. \n");
    printf("Please enter the two number now! \n");
}

int ReadNum(void)
{
    int num;
    scanf("%d", &num);
    return num;
}

void simpeAddFunc(void)
{
    int result;
    result = Add(3, 4);
    printf("Result Add1: %d \n", result);
    result = Add(5, 8);
    printf("Result Add2: %d \n", result);
}

void smartAddFunc(void)
{
    int result, num1, num2;
    HowToUseThisProg();
    num1=ReadNum();
    num2=ReadNum();
    result = Add(num1, num2);
    ShowAddResult(result);
}

int NumCompare(int num1, int num2); // Declare first

void numCompare(void)
{
    printf("max(3, 4) = %d \n", NumCompare(3, 4));
    printf("max(7, 2) = %d \n", NumCompare(7, 2));
}

int NumCompare(int num1, int num2) // Define later
{
    return (num1 > num2) ? num1 : num2;
}

int AbsoCompare(int num1, int num2); // Declae first
int GetAbsoValue(int num); // Declae first

void absoCompare(void)
{
    int num1, num2;
    printf("Enter two integer: ");
    scanf("%d %d", &num1, &num2);
    printf("max(%d, %d) = %d", num1, num2, AbsoCompare(num1, num2));
}

int AbsoCompare(int num1, int num2) // Define later
{
   return (GetAbsoValue(num1) > GetAbsoValue(num2)) ? num1 : num2;
}

int GetAbsoValue(int num) // Define later
{
    return (num < 0) ? num*(-1) : num;
}

int SimpleFuncOne(void)
{
    int num=10;
    num++;
    printf("SimpleFuncOne num: %d \n", num); // 10
    return 0;
}

int SimpleFuncTwo(void)
{
    int num1=10, num2=30;
    num1++, num2--;
    printf("num1 & num2: %d %d \n", num1, num2);
    return 0;
}

void localVariable(void)
{
    int num=17;
    SimpleFuncOne();
    SimpleFuncTwo();
    printf("localVariable num: %d \n", num); // 17
}

void anotherLocalVal(void)
{
    int cnt;
    for(cnt=0; cnt<3; cnt++){
        int num = 0;// local variable for loop
        num++;
        printf("Loop %d: local variable num is %d. \n", cnt+1, num);
    }
    if(cnt == 3)
    {
        int num = 7; // local variable for if
        num++;
        printf("If: local variable num is %d. \n", num);
    }
}

void valShadowing(void)
{
    int num=1;
    if(num==1)
    {
        int num=7; // variable shadowind occurred!
        num += 10;
        printf("inner if: local variable num: %d \n", num);// 17
    }
    printf("outer if: local variable num: %d \n", num); // 1
}

void globalVariable(void)
{
    printf("num: %d \n", gNum);
    Add1(3);
    printf("num: %d \n", gNum);
    gNum++;
    printf("num: %d \n", gNum);
}

void Add1(int val)
{
    gNum += val; // Add val to global variable. 
}

int Add2(int val)
{
    int gNum=9;
    gNum += val;
    return gNum;
}

void gValShadowing(void)
{
    int gNum=5;
    printf("num: %d \n", Add2(3));// shadowed
    printf("num: %d \n", gNum+9);//shadowed
}

void SimpleFunc(void)
{
    static int num1=0; // Only accessable within this function
    int num2 = 0;// If not be initialized, junk value assigned to this variable.
    num1++; num2++;
    printf("static: %d, local: %d \n", num1, num2);
}

void staticLocalVariable(void)
{
    for(int i=0; i<3; i++) SimpleFunc();
}

void Recursive(int num)
{
    if(num <=0) return;
    printf("Recursive call! %d \n", num);
    Recursive(num-1);
}

void recursiveFunc(void)
{
    Recursive(3);
}

int Factorial(int num)
{
    return (num==0) ? 1 : num * Factorial(num-1);
}

void recursiveFactorial(void)
{
    printf("1! = %d \n", Factorial(1));
    printf("2! = %d \n", Factorial(2));
    printf("3! = %d \n", Factorial(3));
    printf("4! = %d \n", Factorial(4));
    printf("9! = %d \n", Factorial(9));
}

int main(void)
{
    printfOutput();
    printf("\n");   
    simpeAddFunc();
    printf("\n");
    smartAddFunc();
    printf("\n"); 
    numCompare();
    printf("\n");
    absoCompare();
    printf("\n");
    localVariable();
    printf("\n");
    anotherLocalVal();
    printf("\n");    
    valShadowing();
    printf("\n"); 
    globalVariable();
    printf("\n");
    gValShadowing();
    printf("\n");  
    staticLocalVariable();
    printf("\n");   
    recursiveFunc();
    printf("\n");   
    recursiveFactorial();
    printf("\n");

    return 0;
}