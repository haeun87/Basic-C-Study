/*
    Title: File segmentation and header file design
    Description: Learning about file segmentation and header.
    FileName: Header.c
    Modified: July 21st 2023
    Writer: Haeun Suh
*/

#include <stdio.h> // This format is for standard libraries

/*
    Chapter 27 File segmentation and header file design.
    * The C compiler compiles file by file.
    * In order to segment one file into multiple files, an external reference command must be defined.
        e.g. extern int num; extern void Increment(void);
        => There is no need to inform the compiler of where the items are located precisely.
    * To prevent access to that variable from other files, define it as a global static variable.
        => This confines the variable as a private variable.
        e.g. static int num=0;
    * For VScode: To add external files, one should configure the 'tasks.json' to group files to be compiled together.
    * '#include' indicator simply includes code from the target file.
        => Even if the target files are not completed, if those are completed when collected, then it will work as normal!
    * Header files can be served as an index or interface of external functions.
        => Just include header once rather than include functions by one by one!
    * Compiler warns when founded duplicated code from the headers.
    * Use '#ifndef~#endif' conditional indicator to avoid duplicates.
*/

// CASE 1: All relevent functions included in one file. 
/*
int num=0;
void Increment(void){num++;}
int GetNum(void){return num;}
*/

// CASE 2: All relevent functions included in one file.
extern void Increment(void);
extern int GetNum(void);

int simpleIncluding(void)
{
    printf("num: %d \n", GetNum()); Increment();
    printf("num: %d \n", GetNum()); Increment();
    printf("num: %d \n", GetNum());
    
    return 0;
}

// CASE 3: Include Headers
int getherHeader(void)
#include "header1.h" // This format is for all libraries. Relative path
#include "C:\Users\cetun\Documents\Basic-C-Study\BASIC_C\Ch27\header2.h" // Absolute Path

// CASE 4: Multilayer Header Reference
#include "areaArith.h"
#include "roundArith.h"

int multiHeader(void)
{
    printf("The area of a triangle(W: 4, H: 2): %g \n", TriangleArea(4, 2));
    printf("The area of a circle(R: 3): %g \n", CircleArea(3));

    printf("The perimeter of a rectangle(W: 2.5, H: 5.2): %g \n", RectangleRound(2.5, 5.2));
    printf("The perimeter of a square(W: 3): %g \n", SquareRound(3));    
    return 0;
}

// CASE 5: Define the struct to header. 
#include "stdiv.h" // Duplicated!
#include "intdiv.h"

int structHeader(void)
{
    Div val= IntDiv(5, 2);
    printf("quotient: %d \n", val.quotient);
    printf("remainder: %d \n", val.remainder);

    return 0;
}

int main(void)
{
    simpleIncluding();
    printf("\n");
    getherHeader();
    printf("\n");
    multiHeader();
    printf("\n");
    structHeader();

    return 0;
}