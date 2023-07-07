/*
    Title: Conditional statement
    Description: Understanding the concept of the Conditional statement
    FileName: Contitional.c
    Modified: July 7th 2023
    Writer: Haeun Suh
*/

#include <stdio.h>
/*
    Chapter 08 Branching of Flows Based on Conditionss
    * if~else if~else is equivalent to nested form of if~else.
    * goto: A keyword used to move the flow of a program to a desired location.
        => requires a specific label used for positioning.
    * Futher detail will be skipped except practice codes.
*/

void ifBasic(void)
{
    int num;
    printf("Enter any integer: ");
    scanf("%d", &num);
    if(num < 0) printf("Smaller than 0! \n");
    if(num > 0) printf("Bigger than 0! \n");
    if(num == 0) printf("It is 0!! \n");
}

void calOne(void)
{
    int opt;
    double num1, num2, result;
    while (1){
        printf("[Menu] (1) ADD (2) SUB (3) MUL (4) DiV (0) Exit \n");
        printf("[SELECT]: ");
        scanf("%d", &opt);
        if (opt < 0 || opt > 4) {
            printf("Please select from Menu!! \n");
            continue;
        }
        else if (opt == 0) break;
        printf("Enter two real numbers: ");
        scanf("%lf %lf", &num1, &num2);
        switch(opt){
            case 1:
                result = num1 + num2;
                break;
            case 2:
                result = num1 - num2;
                break;
            case 3:
                result = num1 * num2;
                break;
            case 4:
                result = num1 / num2;
                break;
            default:
                result = -1;
                break;
        }
        printf("Result: %f \n", result);      
    }
}

void mul3mul4(void)
{
    int num;
    for(num=1; num<100; num++){
        if( num%3==0 || num%4==0 ) // Since '==' has higher priority than '||' parenthesis can be omitted.
        printf("%d is Multiples of 3 or 4! \n", num);
    }
}

void ifElseBasic(void)
{
    int num;
    printf("Enter integer: ");
    scanf("%d", &num);
    if(num<0) printf("Smaller than 0! \n");
    else printf("Not smaller than 0! \n");
    // In conditional ternary operator form
    num > 0 ? printf("Bigger than ZERO! \n") : printf("Not bigger than ZERO! \n"); 
}

void ternaryOp(void)
{
    int num, abs;
    printf("Enter integer: ");
    scanf("%d", &num);
    abs = num > 0 ? num : num*(-1);
    printf("ABS of %d: %d \n", num, abs);
}

void whenOver5000(void)
{
    int sum=0, num=0;
    while(1)
    {
        sum+=num;
        if(sum>5000) break;
        num++;
    }
    printf("sum: %d, num: %d \n", sum, num);
}

void mul2mul3(void)
{
    int num;
    printf("BEGIN ");
    for(num=1; num<20; num++){
        if( num%2==0 || num%3==0 ) continue;
        printf("%d ", num);
    }
    printf("END \n");
}

void englishSchool(void)
{
    int num;
    printf("Enter integer range[1,5]: ");
    scanf("%d", &num);
    switch(num){
        case 1:
            printf("1 is ONE \n");
            break;
        case 2:
            printf("2 is TWO \n");
            break;
        case 3:
            printf("3 is THREE \n");
            break;
        case 4:
            printf("4 is FOUR \n");
            break;
        case 5:
            printf("5 is FIVE \n");
            break;
        default:
            printf("Error due to wrong input! \n");
    }
}

void advancedEnglishSchool(void)
{
    char sel;
    printf("M Morning, A Afternoon, E Evening \n");
    printf("SELECT: ");
    scanf("%c", &sel);
    switch(sel){
        case 'M':
        case 'm':
            printf("Morning \n"); // For both 'M' and 'm'
            break;
        case 'A':
        case 'a':
            printf("Afternoon \n"); // For both 'A' and 'a'
            break;
        case 'E':
        case 'e':
            printf("Evening \n"); // For both 'E' and 'e'
            break;
        default:
            printf("Error due to wrong input! \n");
    }
}

void goToBasic(void)
{
    int num;
    printf("Enter positive integer: ");
    scanf("%d", &num);
    if(num == 1) goto ONE;
    else if(num==2) goto TWO;
    else goto OTHER;
    ONE:
        printf("ENTERED 1 \n");
        goto END;
    TWO:
        printf("ENTERED 2 \n");
        goto END; 
    OTHER:
        printf("ENTERED %d \n", num);
        goto END;
    END:
        printf("Back to normal!! \n");
}

int main(void)
{
    ifBasic();
    printf("\n");
    calOne();
    printf("\n");
    mul3mul4();
    printf("\n");
    ifElseBasic();
    printf("\n");
    ternaryOp();
    printf("\n");
    whenOver5000();
    printf("\n");
    mul2mul3();
    printf("\n");
    englishSchool();
    printf("\n"); 
    advancedEnglishSchool();
    printf("\n"); 
    goToBasic();
    printf("\n");   

    return 0;
}