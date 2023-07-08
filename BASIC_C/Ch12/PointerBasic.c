/*
    Title: Understanding of Pointers
    Description: Understand the basics of Pointers in C languages.
    FileName: PointerBasic.c
    Modified: July 8th 2023
    Writer: Haeun Suh
*/

#include <stdio.h>
/*
    Chapter 12 Understanding Pointers.
    * A pointer is a variable that stores the memory address of another variable as its value.
    * Declaration of pointer variable: e.g. int *pnum or int* pnum(these are equivalent)
    * Accessing to the value of the address of which the pointer is pointing: e.g. &pnum
    * Referencing to the memory that the pointer is pointing: e.g. *pnum=29;
      (Accessing to the variable that pointer is pointing.) 
    * The size of pointer will be dependent of the compiler and the system.
      e.g. 64bit => 8byte, 32bit => 4byte (Size of Address)
    * If not initialize the pointer variable, a junk value can be assigned as a result! Therefore:
      => int* ptr1;(x) int* ptr=0; or int* ptr=NULL; (0)
    * 
    * Futher detail will be skipped except practice codes.

*/

int pointerOperation(void)
{
    int num1=100, num2=100;
    int* pnum;

    pnum=&num1; // pnum -> num1 -> 100
    (*pnum) += 30; // Same as num1 +=30;

    pnum=&num2; // pnum -> num2 -> 100
    (*pnum) -=30; // Same as num2 -= 30;

    printf("num1: %d, num2:%d \n", num1, num2);// 130, 70
    
    return 0;

}

int main(void)
{
    pointerOperation();
    printf("\n");

    return 0;
}