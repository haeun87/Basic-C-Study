/*
    Title: Function pointers and void pointers
    Description: Learning about functional pointers and void pointers.
    FileName: FuncPtrVoidPtr.c
    Modified: July 12th 2023
    Writer: Haeun Suh
*/

#include <stdio.h>
/*
    Chapter 19 Function pointers and void pointers.
    * Not only variables, but also functions are loaded to the memory space as binary forms.
      => The pointers storing those functions address are called function pointers.
    * With function pointer, code reusability can be improved! (Serve as genetic type supports).
        => That is, function pointers in C can be used to achieve a form of polymorphism, specifically a rudimentary form of ad-hoc polymorphism.
        => But not that C has its own built-in support for polymorphism.
    * Polymorphism is a principle in programming that allows a single interface to represent different types of data.
    * A void pointer is a pointer which has no specific data type; therefore, it can store any kind of pointer.
    * Pointer operation, value modification, and value referencing are not allowed to the void pointer.
        => Only to use for the lazy type declarations. (Determine later.)
    * Further detail will be skipped except practice codes.
*/

void SimpleAdder(int n1, int n2){
    printf("%d + %d = %d \n", n1, n2, n1+n2);
}

void ShowString(char* str){
    printf("%s \n", str);
}

int functionPointer(void)
{
    char* str = "Function Pointer";
    int num1=10, num2=20;

    void (*fptr1)(int, int) = SimpleAdder;
    void (*fptr2)(char *) = ShowString;

    fptr1(num1, num2);
    fptr2(str);

    return 0;
};

int WhoIsFirst(int age1, int age2, int (*cmp)(int n1, int n2))
{
    return cmp(age1, age2);
}

int OlderFirst(int age1, int age2)
{
    return (age1 > age2) ? age1: (age1 < age2) ? age2: 0;
}

int YoungerFirst(int age1, int age2)
{
    return (age1 < age2) ? age1: (age1 > age2) ? age2: 0;
}

int usefulFunctionPointer(void)
{
    int age1=20, age2=30, first;

    printf("Enter 1 \n");
    first = WhoIsFirst(age1, age2, OlderFirst);
    printf("'%d years old' or '%d years old' ? => %d years old! \n\n", age1, age2, first);

    printf("Enter 2 \n");
    first = WhoIsFirst(age1, age2, YoungerFirst);
    printf("'%d years old' or '%d years old' ? => %d years old! \n\n", age1, age2, first);
    
    return 0;
}

void SoSimpleFunc(void)
{
    printf("I'm Sooooo Simple!!");
}

int voidTypePointer(void)
{
    int num=20;
    void* ptr;

    ptr=&num;
    printf("%p \n", ptr);

    ptr=SoSimpleFunc;
    printf("%p \n",  ptr);

    return 0;
}

void ShowAllString(int argc, char* argv[])
{
    for(int i=0; i<argc; i++) printf("%s \n", argv[i]);
}

int argvParamType(void)
{
    char* str[3] = {"C Programming", "C++ Programming", "Java Programming"};

    ShowAllString(3, str);

    return 0;
}

int main(void)
{
    functionPointer();
    printf("\n");
    usefulFunctionPointer();
    printf("\n");
    voidTypePointer();
    printf("\n");
    argvParamType();
    printf("\n");
    
    return 0;
}