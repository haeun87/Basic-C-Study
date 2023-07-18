#include <stdio.h>
#include <string.h>
/*
Exercise 24-2
*/

int getfs(FILE* fp){
    long fpos, fsize;
    fpos = ftell(fp); // the current position indicator

    fseek(fp, 0, SEEK_END); // EOF
    fsize=ftell(fp); // the maximum index + 1 == the size of file.
    fseek(fp, fpos, SEEK_SET);

    return fsize;
}

// problem
int problem(void)
{
    char str[100];
    FILE* fp = fopen("BASIC_C/Ch24/problem.txt", "rt");

    fgets(str, 100, fp);
    fputs(str, stdout);
    printf("\n");
    printf("Size of the file: %ld \n", getfs(fp));

    fgets(str, 100, fp);
    fputs(str, stdout);
    printf("\n");
    printf("Size of the file: %ld \n", getfs(fp));
    
    fgets(str, 100, fp);
    fputs(str, stdout);
    printf("\n");
    fclose(fp);

    return 0;
}

int main(void)
{
    problem();
    printf("\n");

    return 0;
}