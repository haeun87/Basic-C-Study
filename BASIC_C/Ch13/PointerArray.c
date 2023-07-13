/*
    Title: Pointer and Array
    Description: Understand the operation of pointers related to array data types.
    FileName: PointerArray.c
    Modified: July 9th 2023
    Writer: Haeun Suh
*/

#include <stdio.h>
/*
    Chapter 13 Pointer and Array.
    * The name of an array is a constant form of a pointer(a.k.a. constant pointer).
        => It represents the starting point of an array.
        => It's actually the same as the address of the first element in the array.
    * Constant pointer VS Pointers to constant VS Constant pointers to constants:
        Constant pointer: A Pointer that points to a fixed memory location, but its value can be changed unless it is not a constant. 
            e.g. <type of pointer>* const <name of the pointer>
            e.g. int arr[4] <= Even without the const keyword!
        Pointers to constant: General pointer, but pointing to the constant.
            e.g. const <type of pointer>* <name of the pointer>
        Constant pointers to constants: Both memory location and value will be fixed for these type of pointers.
            e.g. const <type of pointer>* const <name of the pointer>;
    * By assigning the address of the first element of an array, the newly assigned pointer has the same effect as pointing the entire array itself.
            e.g. (int* ptr = arr) == (int* ptr = &arr[0])
    * arr[i] == *(arr+1)
    * Declaration of String:
        Variable form of String: Cannot change the pointing object. Can modify each element.
        e.g. char st1[] = "My String";
        Constant form of String: Can change the pointing object. Cannot modify each element.
        e.g. char* str1 = "My String";
    * Compiling below Error will occur when using g++(Should use gcc instead!):
        e.g. char* str1 = "My String"; (pointer to constant) => const char* str = "My String"
    * The printf function acts as: printf(char* str) => printf(pointing address)
    * Further detail will be skipped except practice codes.
*/

int arrayNameType(void)
{
    int arr[3]= {0, 1, 2};
    printf("Pointer value of arr: %p \n", arr); // Address of the starting point of arr = arr[0]
    printf("Pointer value of First Element: %p \n", &arr[0]); // Address of arr[0]
    printf("Pointer value of Second Element: %p \n", &arr[1]); // Address of arr[1]
    printf("Pointer value Third Element: %p \n", &arr[2]); // Address of arr[2]
    // arr = & arr[i] // Compile Error
    return 0;
}

int arrayNamePointerOperation(void)
{
    int arr1[3] = {1, 2, 3};
    double arr2[3] = {1.1, 2.2, 3.3};

    printf("%d %g \n", *arr1, *arr2);

    *arr1 += 100;
    *arr2 += 120.5;

    printf("%d %g \n", arr1[0], arr2[0]); // Affected
    printf("%d %g \n", arr1[1], arr2[1]); // Not affected

    return 0;
}

int arrayNameIsPointer(void)
{
    int arr[3] = {15, 25, 35};
    // int* ptr= &arr;  // Error
    int* ptr = arr;
    // int* ptr=&arr[0]; // Equivalent to assign arr itself!

    printf("%d %d \n", ptr[0], arr[0]);
    printf("%d %d \n", ptr[1], arr[1]);
    printf("%d %d \n", ptr[2], arr[2]);
    printf("%d %d \n", *ptr, *arr);

    return 0;
}

int pointerOperationResult(void)
{
    int a=1;
    double b=0.0;
    int* ptr1= &a;
    double* ptr2= &b;

    printf("%p %p \n", ptr1+1, ptr1+2); // +4 +8
    printf("%p %p \n", ptr2+1, ptr2+2); // +8 +16

    printf("%p %p \n", ptr1, ptr2);
    ptr1++;
    ptr2++;    
    printf("%p %p \n", ptr1, ptr2); // +4 +8

    return 0;
}

int pointerBaseArrayAccess(void)
{
    int arr[3] = {11, 22, 33};
    int* ptr=arr;
    printf("%d %d %d \n", *ptr, *(ptr+1), *(ptr+2)); // arr[0] arr[1] arr[2]

    printf("%d ", *ptr); // arr[0], pointer value not changed
    ptr++; // pointer value changed
    printf("%d ", *ptr); // arr[1]
    ptr++; // pointer value changed
    printf("%d ", *ptr); // arr[2]
    ptr--; // pointer value changed
    printf("%d ", *ptr); // arr[1]
    ptr--; // pointer value changed
    printf("%d ", *ptr); // arr[0]
    printf("\n");

    return 0;   
}

int twoStringType(void)
{
    char str1[] = "My String";
    char* str2 = "Your String"; // Compile error in g++
    // const char* str2 = "Your String"; // Use this for g++
    printf("%s %s \n", str1, str2);

    str2 = "Our String"; // Change the pointing object  // Compile error in g++
    printf("%s %s \n", str1, str2);

    str1[0]='X'; // Changed
    // str2[0]='X'; // Unchanged & Runtime error when compiled in g++
    printf("%s %s \n", str1, str2);

    return 0;
}

int pointerArray(void)
{
    int num1=10, num2=20, num3=30;
    int* arr[3]={&num1, &num2, &num3};

    printf("%p \n", arr[0]); // Address of num1
    printf("%d \n", *arr[0]);
    printf("%d \n", *arr[1]);
    printf("%d \n", *arr[2]);

    return 0;   
}

int stringArray(void)
{
    char* strArr[3] = {"Simple", "String", "Array"};

    printf("%p \n", strArr[0]); // Address of "Simple"(char* [])
    printf("%s \n", strArr[0]); // Since the string itself is a pointer, no need dereferencing
    printf("%s \n", strArr[1]); // Since the string itself is a pointer, no need dereferencing
    printf("%s \n", strArr[2]); // Since the string itself is a pointer, no need dereferencing

    return 0;   
}

int main(void)
{
    arrayNameType();
    printf("\n");
    arrayNamePointerOperation();
    printf("\n");
    arrayNameIsPointer();
    printf("\n");
    pointerOperationResult();
    printf("\n");
    pointerBaseArrayAccess();
    printf("\n");
    twoStringType();
    printf("\n");
    pointerArray();
    printf("\n");
    stringArray();
    printf("\n");

    return 0;
}