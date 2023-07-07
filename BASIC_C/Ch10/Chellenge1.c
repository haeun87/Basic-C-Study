#include <stdio.h>
/*
Exercise 10 Chellenge Excercise 1
    * Euclidean algorithm:
        If two number A B have a GCD C, then the remainder A mod B also has a GCD C 
*/

void problem1(void)
{
    int dNum;
    printf("Enter Decimal integer: ");
    scanf("%d", &dNum);
    printf("Hexadecimal of %d: %x", dNum, dNum);
}

void problem2(void)
{
    int num1, num2;
    printf("Enter Two Decimal integer(1 ~ 9): ");
    scanf("%d %d", &num1, &num2);
    int start = (num1 < num2) ? num1: num2;
    int end = (num1 < num2) ? num2: num1;
    printf("Mutiplication Table from %d to %d: \n", start, end);
    for(start; start<= end; start++){
        for(int i=1; i<10; i++) printf("%d X %d = %d \n", start, i, start*i);
        printf("\n");
    }
}

int GCD(int a, int b)
{
    return b ? GCD(b, a % b): a;
}

void problem3(void)
{

    int num1, num2, gcd;
    printf("Enter Two Decimal integer(1 ~ 9): ");
    scanf("%d %d", &num1, &num2);
    int min = (num1 < num2) ? num1: num2;
    for(int i= 1; i<= min; i++) if(num1%i == 0 && num2%i==0) gcd = i;
    printf("GCD of %d and %d: %d \n", num1, num2, gcd);
    printf("GCD of %d and %d: %d \n", num1, num2, GCD(num1, num2));
}

void problem4(void)
{
    int balance;
    int uCR = 500, uS = 700, uC = 400;
    int mCR = 3500/500, mS= 3500/700, mC = 3500/400;
    printf("Enter your balance: ");
    scanf("%d", &balance);
    printf("Available Selections\n");
    printf("============================\n");
    for(int s=1; s<mS; s++){
        int left1 = 3500 - s*uS;
        if(left1 < uCR + uC) continue; // You should buy at leat one each!
        for(int cr= 1; cr < mCR; cr++){
            int left2 = left1 - cr*uCR;
            if(left2 < uC || left2 % uC > 0) continue; // You should buy at least one each!
            printf("Cream: %d, Shrimp: %d, Cola: %d \n", cr, s, left2 / uC);
        }
    }
    printf("============================\n");
}

void problem5(void)
{
    int cnt = 0, num= 2;
    while (cnt < 10){
        int isPrime = 1;
        for(int i=2; i < num; i++){
            if(num % i == 0){
                isPrime--;
                break;
            } 
        }
        if(isPrime) {
            printf("%d ", num);
            cnt++;
        }
        num++;
    }
    printf("\n");
}

void problem6(void)
{
    int seconds, h, m, s;
    printf("Enter a total seconds: ");
    scanf("%d", &seconds);
    s = seconds % 60;
    m = ((seconds / 60) % 60);
    h = (seconds / 60 / 60) % 60;
    printf("[h: %d, m:%d, s:%d]", h, m, s);
}

void problem7(void)
{
    int num, maxnum=1, times=0;
    printf("Enter a number: ");
    scanf("%d", &num);
    while(maxnum < num){
        times++;
        maxnum *= 2;
    }
    printf("Maximun k of 2 is: %d \n", times);
}

int pow(int n)
{
    return (n == 0) ? 1 : 2*pow(n-1); 
}

void problem8(void)
{
    int times;
    printf("Enter n for 2^n: ");
    scanf("%d", &times);
    printf("2^%d = %d \n", times, pow(times));
}

int main(void)
{
    problem1();
    printf("\n");
    problem2();
    printf("\n");
    problem3();
    printf("\n");
    problem4();
    printf("\n");
    problem5();
    printf("\n");
    problem6();
    printf("\n");
    problem7();
    printf("\n");
    problem8();
    printf("\n");

    return 0;   
}