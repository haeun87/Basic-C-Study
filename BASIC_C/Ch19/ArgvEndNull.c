#include <stdio.h>
/*
    main function argument passing example2
*/

int main(int argc, char *argv[])
{
    int i=0;
    printf("Total number of elements: %d \n", argc);
    
    while(argv[i] != NULL) {
        printf("String %d: %s \n", i+1, argv[i]);
        i++;
    }
    return 0;
}