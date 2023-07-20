/*
    Title: Macro and Preprocessor
    Description: Learning about Macro and Preprocessor.
    FileName: Macro.c
    Modified: July 20th 2023
    Writer: Haeun Suh
*/
// Below is a typical preprocessor command!
#include <stdio.h> // Append the contents of stdio.h to this code.

/*
    Chapter 26 Macro and Preprocessor.
    * Preprocessing comes before the compiling. e.g. preprocessor -> compiler -> linker
    * Generally, it is regarded as being included in the compiling process and rarely mentioned separately.
    * The C preprocessor is the macro preprocessor for several computer programming languages, 
    such as C, Objective-C, C++, and a variaty of Fortran languages. The preprocessor provides inclusiont of header files,
    macro expansions, conditional compilation, and line control.(Wikipedia)
    * The preprocessor modifies some parts of the programming code and most of them are in the form of simple substitution.
    * The preprocessor commands start as character #, and there is no need to add semicolons since those are processed separately by the processor.
    * Structure of preprocessing command: (indicators) (macro name) (macro body) 
    * '#define: Object-like' macro: Macro type that defines a constant value.
        e.g. #define PI 3.1415 => Substitute all macro named 'PI' into 3.1415.
        => Also refer to as macro constant.
        => Generally, a macro name is defined as the capital.
    * '#define: Function-like' macro: Macro type that defines a function with its arguments. 
        e.g. #define SQUARE(X) X*X => Substitute all macro named 'SQUERE(X)' into X*X.
        => Also refer to as macro expansion.
        => It is also possible to define the macro in the form of a compound function.
    * Pros and Cons of macro function:
        Pros:
            - Macro functions are faster than general functions.
            => No need to allocate the stack memory. 
            => No need to move to its execusion point.
            => No need to pass arguments to parameters.
            => No need to return the value by the return statement.
            - No need to specify data type for the macro function's arguments.
            => It is simply substituted literally.
        Cons:
            - Relatively hard to define.
            - Uneasy to debug the macro codes.
    * When to use a macro function:
        - When defining a relatively small size function.
        - When defining a function with high frequency of function calls.
    * '#if...#endif' macro: A macro for conditional compilation.
        e.g. #if macro(true/false) / code to compile / #endif
        => Only compiles the code embraced in the active(true) condition.
        => Also, we can add the '#else' and '#elif' indicator to add other conditions.
    * '#ifdef...#endif' macro: A macro for conditional compilation.
        e.g. #ifdef macro / code to compile / #endif
        => Only compiles the code embraced when the macro condition has been defined.
        => Also, we can add the '#else' indicator to add another condition.
    * '#ifndef...#endif' macro: A macro for conditional compilation.
        e.g. #ifndef macro / code 'not' to be compiled / #endif
        => This is the opposite of '#ifdef...#endif' macro
        => Normally used to prevent the duplication of header files.
        => Also, we can add the '#else' indicator to add another condition.
    * No substitution of parameters within the string variable is allowed.
        => Need to specify parameter A as '#A'
            e.g. #define STR(ABC) #ABC = > STR(12) = "12"
    * Macro '##' : Macro that allows a literal concatenation of its parameters.
        e.g. #define CON(UPP, LOW) UPP ## 00 ## LOW => (int) CON(22, 77) = (int) 220077
        => The result can even be the number type if no char is included.
*/

// '#define: Object-like' macro
#define NAME    "Gagamel Cat"
#define AGE 24
#define PRINT_ADDR  puts("Address: Wildlife USA\n");

// '#define: Function-like' macro
// #define SQUARE(X) X*X
// #define SQUARE(X) (X)*(X) // Improved version
#define SQUARE(X) \
    (X)*(X) // Multiple lines
#define PI 3.14
#define PRODUCT(X, Y) ((X)*(Y))
#define CIRCLE_AREA(R) (PRODUCT(R, R)*PI) // Compound function
// #define DIFF_ABS(X, Y) ( (x)>(y) ? (x) - (y) : (y) - (x) ) // ERROR!
#define DIFF_ABS(X, Y) ( (X)>(Y) ? (X) - (Y) : (Y) - (X) )

// '#if...#endif' macro
#define ADD 1 // TRUE
#define SUB 0 // FALSE
// #define NONDEFINED 1 // TRUE BUT NOT DEFINED
#define DEFINED // DEFINED with no body

// Add '#else' and '#elseif'
#define HIT_NUM 7

// Define a string function using arguments
#define STR(ABC) #ABC
#define STRING_JOB(A, B) "NAME: " #A ", #JOB: " #B 

// #define STNUM(Y, S, P) YSP // Error
// #define STNUM(Y, S, P) Y S P // Error
// #define STNUM(Y, S, P) ((Y)*100000 + (S)*1000 + (P)) // Sometimes, also error occurs!
#define STNUM(Y, S, P) Y ## S ## P // Literally connects the parameters!

int macroConst(void){
    printf("Name: %s \n", NAME);
    printf("Age: %d \n", AGE);
    PRINT_ADDR;

    return 0;
}

int macroFunction(void)
{
    int num=20;

    printf("Square of num %d \n", SQUARE(num));
    printf("Square of -5 %d \n", SQUARE(-5));
    printf("Square of 2.5 %d \n", SQUARE(2.5));

    // printf("Square of 3+2 %d \n", SQUARE(3+2)); // This works wrong => 3+2*3+2 = 3+6+2 = 11
    printf("Square of 3+2 %d \n", SQUARE((3+2))); // This works right  => (3+2)*(3+2) = 5*5 = 25
    return 0;     
}

int macroUseMacro(void)
{
    double rad=2.1;
    printf("The Area of a circle with a radius of %g: %g \n", rad, CIRCLE_AREA(rad));

    return 0;
}

int macroFunctionWeakness(void)
{
    printf("The Difference of two number(5, 7): %d \n", DIFF_ABS(5, 7));
    printf("The Difference of two number(1.8, -1.4): %g \n", DIFF_ABS(1.8, -1.4));

    return 0;
}

int if_endif(void){
    int num1, num2;
    printf("Enter two decimal numbers: ");
    scanf("%d %d", &num1, &num2);

#if ADD // Only compiles this!
    printf("%d + %d = %d \n", num1, num2, num1+num2);
#endif

#if SUB // This will be ignored!
    printf("%d - %d = %d \n", num1, num2, num1-num2);
#endif

    return 0;
}

int ifdef_endif(void){
    int num1, num2;
    printf("Enter two decimal numbers: ");
    scanf("%d %d", &num1, &num2);

#ifdef NONDEFINED // Do not compile this!
    printf("%d + %d = %d \n", num1, num2, num1+num2);
#endif

#ifdef DEFINED // Will compile this!
    printf("%d - %d = %d \n", num1, num2, num1-num2);
#endif

    return 0;
}

int else_endif(void)
{
#if HIT_NUM == 5 // NOT active
    puts("Current macro constant is 5");
#else // Active
    puts("Current macro constant is NOT 5");
#endif   
    return 0;
}

int elif_endif(void)
{
#if HIT_NUM == 5 // NOT active
    puts("Current macro constant is 5");
#elif HIT_NUM == 6 // NOT active
    puts("Current macro constant is 6");
#elif HIT_NUM == 7 // Active
    puts("Current macro constant is 7");
#else // NOT cctive
    puts("Current macro constant is NOT 5 or 6 or 7!");
#endif   
    return 0;
}

int macroOpToString(void)
{
    // printf("%s \n", 12); // Error. This is not a String!
    printf("%s \n", STR(12)); // Succefully converted as String!
    printf("%s \n", STRING_JOB("Gildong Hong","Thief"));
    printf("%s \n", STRING_JOB("Gagamel","Pet"));

    return 0;    
}

int univStdNum(void)
{
    printf("StudentID: %d \n", STNUM(10, 65, 175));
    printf("StudentID: %d \n", STNUM(10, 65, 075)); // octal 075 -> Decimal 61  
    return 0;
}

int main(void)
{
    macroConst();
    printf("\n");
    macroFunction();
    printf("\n");
    macroUseMacro();
    printf("\n");
    macroFunctionWeakness();
    printf("\n");    
    if_endif();
    printf("\n");    
    ifdef_endif();
    printf("\n");      
    else_endif();
    printf("\n");     
    elif_endif();
    printf("\n");     
    macroOpToString();
    printf("\n");
    univStdNum();
    printf("\n");

    return 0;
}