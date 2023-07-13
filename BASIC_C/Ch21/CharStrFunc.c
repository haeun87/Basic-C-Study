/*
    Title: Functions for Characters and String
    Description: Learning about functions related with char and String.
    FileName: CharStrFunc.c
    Modified: July 13th 2023
    Writer: Haeun Suh
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
    Chapter 21 Functions for Characters and String.
    * Definitions of a stream:
        An one-directional data flow.
        A medium that acts as a (virtual) bridge between data input and output.
        A sequence of data elements made available over time.(Wikipedia)
        Refers to the data that is transmitted when the content is consumed.
        A channel connecting a processor or logic unit.
        A channel through which data flows to/from a disk, keyboard, printer, etc.
        A kind of object used to denote sources and sinks of data in most high-level programming languages.
    * ‘Input stream' and 'output stream', which are used for console input and output, 
        are automatically created when the program starts and automatically destroyed when the program ends.
        => They are the standard steam.
    * Standard stream: Stream provided by default.
        stdin(Keyboard Input) - Standard Input Stream
        stdout(Monitor Output) - Standard Ouput Stream
        stderr(Monitor Output) - Standard Error Stream
    * Char output function: Output One character
        int putchar(int c);
        int fputc(int c, FILE * stream); -> Target stream can be specified e.g. file
        => Return Char in succeed, EOF in failure.
        => In order to avoid junk data(due to EOF == -1), use int rather than char.
            (Some compilers might uses char as unsigned char!)
    * Char input function: Input One character
        int getchar(void);
        int fgetc(FILE * stream); -> Target stream can be specified e.g. file
        => Return Char in succeed, EOF in failure.
        => In order to avoid junk data(due to EOF == -1), use int rather than char.
            (Some compilers might uses char as unsigned char!)
    * End Of File(EOF): A defined constant that represents the file end.
        => EOF == -1
    * Functions return EOF when: 
        => a function call fails.
        => CTRL+Z (in Windows) or CTRL+D (in Linux) commands are entered.
    * Unit char function can be useful for some performance enhancing.
    * String output function: Output multiple characters(or String)
        int puts(const char * s);
        int fputs(const char * s, FILE * stream);
        => Return Non-negative value in succeed, EOF in failure.
    * String input function: Input multiple characters(or String)
        int gets(const char * s);
        int fgets(const char * s, int n, FILE * stream);
        => Return a NULL pointer when reach end of the File or function call has failed.
        => To avoid a run-time error, it is better to use the fgets function to specify the maximum size rather than the gets function.
        => If an input string size is larger than n in fgets 
            => Only n-1 characters will be read (remain 1 for NULL)
            => The remainder can be read by calling another fgets.
    * gets/fgets can read a text with whitespace and includes \n within its reading.
    * (Data) Buffer is a region of a memory used to temporarily store data while it is being moved from one place to another.(Wikipedia)
    * The data using the standard IO functions passes through a 'Memory Buffer' which is provided by the OS.(a.k.a. buffering)
    * Point of buffering: When pressing the 'ENTER' key in a keyboard.
    * The purpose of Buffering: Data is bundled together in a memory buffer and transmitted all at once => Enhances the Data transfer efficiency.
        => Lazy data transferation.
    * Emptying output buffer: fflush function. e.g. int fflush(FILE * stream);
        => Return 0 in succeed, EOF in failure.
        => Force the data to be transferred to its destination.
        => The point of data flushing varies from system to system.
    * Emptying input buffer: 
        => Some compiler flush the buffer when function is fflush called but not always.
        => Flushing the input buffer means canceling stored data. (Not transferring!)
    * Further detail will be skipped except practice codes.
    * Length of String: strlen function(string.h) e.g. size_t strlen(const char * s);
        => Returns total length except null character.
        => typedef unsigned int size_t;(Non negative)
        => size_t can serve as 'unsigned int', vice versa.
    * Copying function of String: strcpy, strncpy
        char* strcpy(char* dest, const char* src);
        char* strncpy(char* dest, const char* src, size_t n);
        => Returns the address of the copied String.
    * Concatenate function of String: strcat, strncat
        char* strcat(char* dest, const char* src);
        char* strncat(char* dest, const char* src, size_t n);
        => Returns the address of the concatenated String.
        => Unlike a strncpy function, a strncat function automatically deals with Null leters.
    * Comparing function of String: strcmp, strncmp
        char* strcmp(const char* s1, const char* s2);
        char* strncmp(const char* s1, const char* s2, size_t n);
        => Returns zero if two strings are the same, otherwise returns non-zero value.
        => Compare as a lexicographical order.  
        => s1>s2 => bigger than 0, s1<s2 => smaller than 0, s1==s2 => 0
    * Other String functions: atoi, atol, atof 
        int atoi(const char* str); => Convert String to int cf. Integer.parseInt(str);
        long atol(const char* str); => Convert String to long cf. Long.parseLong(str);
        double atof(const char* str); => Convert String to double cf. Double.parseDouble(str);
*/

int readWriteChar(void)
{
    int ch1, ch2;

    ch1=getchar(); // Char
    ch2=fgetc(stdin); // Enter

    putchar(ch1); // Char
    fputc(ch2, stdout); // Enter

    return 0;
}

int consoleEOF(void)
{
    int ch;

    while(1)
    {
        ch=getchar(); // Text can also be entered!
        if(ch==EOF) break; // CTRL+Z
        putchar(ch);
    }

    return 0;
}

int writeString(void)
{
    char* str = "Simple String!";

    printf("1. puts test ----- \n");
    puts(str); // No need to add \n
    puts("Soooo Simple String!!");

    printf("2. fputs test ----- \n");
    fputs(str, stdout); // Shoud add \n
    printf("\n");
    fputs("Soooo Simple String!!", stdout);  // Shoud add \n
    printf("\n");

    printf("3. end of test ----- \n");

}

int readString(void)
{
    char str[7];

    // e.g. 12345678901234567890
    for(int i=0;i<3; i++){
        fgets(str, sizeof(str), stdin); // 123456 789012 345678 (90 are still unread!)
        printf("Read %d: %s \n", i+1, str);
    }

    return 0;
}

void ClearLineFromReadBuffer(void)
{
    while(getchar() != '\n'); // Remove until '\n'
}

int needInputBufFlush(void)
{
    char perID[7];
    char name[10];

    fputs("ENTER the first 6 digits of your SSN: ", stdout);
    fgets(perID, sizeof perID, stdin);
    ClearLineFromReadBuffer(); // Empty input buffer

    fputs("ENTER your name: ", stdout);
    fgets(name, sizeof name, stdin);

    printf("SSN: %s \n", perID);
    printf("Name: %s \n", name);
}

void RemoveBSN(char str[])
{
    // == size_t len==strlen(str);
    // == unsigned int len=strlen(str);
    int len=strlen(str); // type cast to signed int
    str[len-1]=0;
}

int removeBSN(void)
{
    char str[100];

    printf("Enter String: ");
    fgets(str, sizeof(str), stdin);
    printf("Length: %d, Content: %s \n", strlen(str), str); // With \n

    RemoveBSN(str);
    printf("Length: %d, Content: %s \n", strlen(str), str); // Without \n

   return 0;
}

int stringCopyCase(void)
{
    char str1[20] = "1234567890";
    char str2[20];
    char str3[5];

    /**** case 1 ****/
    strcpy(str2, str1);
    puts(str2);

    /**** case 2 ****/
    strncpy(str3, str1, sizeof str3); // Junk letters are included!
    puts(str3);

    /**** case 3 ****/
    strncpy(str3, str1, sizeof(str3)-1); // Remove Null
    str3[sizeof(str3)-1]=0; // Set as Null
    puts(str3);

    return 0;
}

int stringConcatCase(void)
{
    char str1[20] = "First~";
    char str2[20] = "Second";

    char str3[20] = "Simple num: ";
    char str4[20] = "1234567890";

    /**** case 1 ****/  
    strcat(str1, str2);
    puts(str1);

    /**** case 2 ****/
    strncat(str3, str4, 7); // Junk letters are included!
    puts(str3);

    return 0;
}

int stringCompCase(void)
{
    char str1[20];
    char str2[20];
    printf("Enter str1: ");
    scanf("%s", str1);
    printf("Enter str2: ");
    scanf("%s", str2); 

    if(!strcmp(str1, str2)) {
        puts("Those are the same!");
    }
    else {
        puts("Those are not the same!");

        if(!strncmp(str1, str2, 3)) puts("But first 3 chars are the same!");  
    } 

    return 0;
}

int convStringToPrimitive(void)
{
    char str[20];
    printf("Enter Decimal number: ");
    scanf("%s", str);
    printf("%d \n", atoi(str));

    printf("Enter Real number: ");
    scanf("%s", str);
    printf("%g \n", atof(str));    

    return 0;
}

int main(void)
{
    readWriteChar();
    printf("\n");
    consoleEOF();
    printf("\n");
    writeString();
    printf("\n");
    readString();
    printf("\n");
    needInputBufFlush();
    printf("\n");   
    removeBSN();
    printf("\n");   
    stringCopyCase();
    printf("\n");   
    stringConcatCase();
    printf("\n");   
    stringCompCase();
    printf("\n");      
    convStringToPrimitive();
    printf("\n"); 

    return 0;
}