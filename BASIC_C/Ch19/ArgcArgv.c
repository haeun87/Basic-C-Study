#include <stdio.h>
/*
    main function argument passing example1
*/

int main(int argc, char *argv[])
{
    printf("Total number of elements: %d \n", argc);

    for(int i=0; i<argc; i++) printf("String %d: %s \n", i+1, argv[i]);

    return 0;
}