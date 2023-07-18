/*
    Title: A Memory management and its dynamic allocation.
    Description: Learning about memory management in C programming.
    FileName: Memory.c
    Modified: July 18th 2023
    Writer: Haeun Suh
*/

#include <stdio.h>
#include <stdlib.h> // For malloc and free functions
/*
    Chapter 25 Memory management and dynamic memory allocation.
    * Each of the memory space is allocated by the OS.
    * Each of the Memory space is gathered with those having similar property to ensure the ease of management and improved memory access.
    * Types of data stored by memory area
        Code Area: Area for the codes and commands to be executed.
        Data Area: Area for the global and static variables that remains until the program termination.
        Heap Area: Area for a specific variable that can be controlled by its creation and destruction by the programmer.
        Stack Area: Area for the local variable and arguments that will be destroyed after the function executions.
    * Memory allocation and releasing for heap area: malloc, free, calloc, realloc functions.
        => malloc function: A function that allocates a specific memory space in the heap area.
        e.g. void* malloc(size_t size);
            => Return the address of the allocated memory space; otherwise return null.
            => The size counts as the total size for the pointer.
        => free function: A function that returns memory to the heap area.
        e.g. free(void* ptr);
        => calloc function: A function that allocates a specific memory space in the heap area.
        e.g. void* calloc(size_t elt_count, size_t elt_size);
            => Return the address of the allocated memory space; otherwise return null.
            => The size counts as the multiplication of the number of data(elt_count) and the unit size(elt_size) for the pointer.
            => Unlike malloc, calloc initialize all the allocated memory space as 0 rather than a junk value.
        => realloc function: A function reallocate the previous allocated pointer for expansion.
        e.g. void* realloc(void* ptr, size_t size);
            => Return the new address of the allocated memory space; otherwise return null.
            => If the space for expansion is large enough, the address will remain unchanged; otherwise, it will reallocate its address, too.
            => In case of being updated of its address, compiler will free the memory space in the previous address. (No need to manually perform the free function!)
    * The heap area is only accessible with the pointers, since the malloc function only returns the addresses of the allocated memory.
    * The malloc function returns a form of void pointer, since no specific data type has been determined. 
        => It returns genetic data type of the pointer.
        => Should perform a type casting for the actual usage.
        e.g. int* ptr1 = (int*)malloc(sizeof(int));
*/
// char name[30]; // global variable

char* ReadUserName(void)
{   

    /*
        ReadStringFault 1
        The code below returns the address of a 'local' variable,
        which will be destoyed immediately after this function! 
    */
    // char name[30]; // local variable
    /*
        ReadStringFault 2
        When using the address of the 'global' variable above this function,
        it will overwrite the variable when modifying!
    */
    /*
        ReadStringRight
        The code below returns the address of a variable allocated in heap area.
    */
    char* name = (char*)malloc(sizeof(char)*30); // char name[30]
    
    // Commmon code
    printf("What's your name: ");
    gets(name);
    
    return name;
}

int readString(void)
{
    char* name1;
    char* name2;

    name1 = ReadUserName();
    printf("name1: %s \n", name1);
    name2 = ReadUserName();
    printf("name2: %s \n", name2);    
    
    printf("name1: %s \n", name1);
    printf("name2: %s \n", name2);    

    return 0;
}

int dynamicMemoryAllocation(void)
{
    int* ptr1 = (int*)malloc(sizeof(int)); // int ptr1
    int* ptr2 = (int*)malloc(sizeof(int)*7); // int ptr2[7]

    *ptr1 = 20;
    for(int i=0; i<7; i++) ptr2[i] = i+1;

    printf("%d \n", *ptr1);

    for(int i=0; i<7; i++) printf("%d ", ptr2[i]);

    free(ptr1);
    free(ptr2);

    return 0;
}

int main(void)
{
    readString();
    printf("\n");
    dynamicMemoryAllocation();
    printf("\n");

    return 0;
}