#include <stdio.h>

/*
Exercise 24-1
*/

// problem 1
int problem1(void)
{
    FILE * fp = fopen("BASIC_C/Ch24/mystory.txt","wt");
    if(fp==NULL){
        puts("FILE OPEN ERROR!");
        return -1;
    }

    fputs("#NAME: Gagamel Cat \n", fp);
    fputs("#SSN: 901010-304678 \n", fp);
    fputs("#PHONE: +1-917-6541-5642 \n", fp);
    
    fclose(fp);

    return 0;
}

// Problem 2
int problem2(void)
{
    FILE * fp = fopen("BASIC_C/Ch24/mystory.txt","at");
    if(fp==NULL){
        puts("FILE OPEN ERROR!");
        return -1;
    }

    fputs("#FOOD: Salmon, Shicken \n", fp);
    fputs("#HOBBY: Grooming \n", fp);
    
    fclose(fp);

    return 0;
}

// Problem 3
int problem3(void)
{
    FILE * fp = fopen("BASIC_C/Ch24/mystory.txt","rt");
    char str[30];
    if(fp==NULL){
        puts("FILE OPEN ERROR!");
        return -1;
    }

    while(fgets(str, sizeof(str), fp) != NULL) printf("%s", str);

    fclose(fp);

    return 0;
}

int main(void)
{
    problem1();
    printf("\n");
    problem2();
    printf("\n");
    problem3();
    printf("\n");

    return 0;
}