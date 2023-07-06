/*
    Title: Data representation.
    Description: Understanding the concept of data representations.
    FileName: DataRepresentation.c
    Modified: July 5th 2023
    Writer: Haeun Suh
*/
#include <stdio.h>
/*
Chapter 04 Understanding the concept of data representation.
    * Representating numbers:
        Binary(2): 0bXXXX - Not in standard C, but GCC supports as extension.
        Decimal(10): XXXX 
        Hexadecimal(16): 0xXXXX
        Octal(8): 0XXXX
    * Representing Integer & Real number:
        Most Significant Bit(MSB): Bit representing Sign(+/-)
        2's complement: 
            1) Reverse all the bits 1<->0
            2) Add 1
            3) If earned a number of higher digit place -> drop the number!
                ex> 00000101 + 11111011 = 100000000 => 00000000
        Representing Real number[floating-point method]: 
            R = (+/-)(1.m)X2^(e-k) -> Error may exist in floating-point numbers.
    * Bitwise operator:
        AND(&): 1&1 -> 1 | 1&0 or 0&1 or 0&0 -> 0
        OR(|): 1&1 or 1&0 or 0&1 -> 1 | 0&0 -> 0
        XOR(^): 1&1 or 0&0 -> 0 | 1&0 or 0&1 -> 1
        NOT(~): 1 -? 0 | 0 -> 1
        Left shift(<<n): = *(2^n) (Drop the higher place than 4 byte)
        Right shift(>>n): = /(2^n) (Fill the leftmost n bits as the sign number of original number)
            ex> Sign number was 1 -> Fill with 1's 
                Sign number was 0 -> Fill with 0's
            
*/

void notation(void)
{
    int num1= 0xA7, num2= 0x43; // Equivalent to initiating with decimal.
    int num3= 032, num4= 024; // Equivalent to initiating with decimal.
    int num5= 0b1010;  // Supported by GNU C extenstion

    printf("Decimal value of 0xA7: %d \n", num1); // 167
    printf("Decimal value of 0x43: %d \n", num2); // 67
    printf("Decimal value of 032: %d \n", num3); // 26
    printf("Decimal value of 024: %d \n", num4); // 20
    printf("Decimal value of 0b1010: %d \n", num5); // 10

    printf("%d-%d=%d \n", num1, num2, num1-num2); // 100
    printf("%d+%d=%d \n", num3, num4, num3+num4); // 46
    printf("%d-%d=%d \n", num1, num4, num1-num4); // 147, Also available!
    printf("%d+%d=%d \n", num3, num5, num3+num5); // 36, Also available!
}

void floatError(void)
{
    int i;
    float num=0.0;

    for(i=0; i<100; i++){
        num += 0.1; // loop 100 times
    }

    printf("Result: %f \n", num); // != 10.0
}

void bitOperation(void)
{
    int num1 = 15; // 00000000 00000000 00000000 00001111
    int num2 = 20; // 00000000 00000000 00000000 00010100
    int num3 = num1 & num2; // AND -> 00000000 00000000 00000000 00000100
    int num4 = num1 | num2; // OR -> 00000000 00000000 00000000 00011111
    int num5 = num1 | num2; // COR -> 00000000 00000000 00000000 00011011
    int num6 = ~num1; // NOT -> 11111111 11111111 11111111 11110000
    printf("AND operation result: %d \n", num3); // 4
    printf("OR operation result: %d \n", num4); // 31
    printf("XOR operation result: %d \n", num5); // 27
    printf("NOT operation result: %d \n", num6); // -16
}

void bitShift(void)
{
    int num1 = 15; // 00000000 00000000 00000000 00001111

    int left1 = num1<<1; // 00000000 00000000 00000000 00011110
    int left2 = num1<<2; // 00000000 00000000 00000000 00111100
    int left3 = num1<<3; // 00000000 00000000 00000000 01111000

    printf("Left Shift +1: %d \n", left1); // 30
    printf("Left Shift +2: %d \n", left2); // 60
    printf("Left Shift +3: %d \n", left3); // 120

    int num2 = -16; // 11111111 11111111 11111111 11110000

    int right1 = num2>>2; // 11111111 11111111 11111111 11111100
    int right2 = num2>>3; // 11111111 11111111 11111111 11111110

    printf("Right Shift +2: %d \n", right1); // -4
    printf("Right Shift +3: %d \n", right2); // -2
}

int main(void)
{
    notation();
    printf("\n");
    floatError();
    printf("\n");
    bitOperation();
    printf("\n");
    bitShift();
    printf("\n");
}