/*
    Title: Print Hello World
    Description: Print out the desinated String value.
    FileName: Hello.c
    Modified: July 3rd 2023
    Writer: Haeun Suh
*/
#include <stdio.h> // Header Declaration
/*
Chapter 01 ~ Chapter 02 Basics of C Programming
    * Basic of Function Structure:
        Output[Return] Name (Input[Argument])
    * Header should be always on the top.
    * studion.h: Header File which includes the 'printf' function
    * printf(String): Standard (Function)Library
    * \n: Change Line - Escape Sequence
    * Return 0 to the main function means normal termination. 
    * Return Other than 0 to the main function means abnormal termination.
    * Conversion specifier:
        %d: Integer
        %s: String
        
*/

//
int main(void) // Begin of main function
{
    /*
        This function prints a String value to the console. 
    */
    // Function Body
    printf("Hello world\n");// Print a String value
    printf("\n");

    printf("Hello Everybody\n");// Print a full String value
    printf("%d\n", 1234);// Format and print a Single value
    printf("%d %d\n", 10, 20);// Format and print Multiple values
    return 0; // Returns the value 0 to the calling area
}// End of main function