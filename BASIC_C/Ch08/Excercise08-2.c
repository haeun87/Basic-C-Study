#include <stdio.h>
/*
Exercise 08-2
*/

// Problem 1
void mulTable(void)
{
    int num;

    // With for
    for(int r=1; r<10; r++){// outer for
        if (r%2 != 0) continue;
        for(int c=1; c<10; c++) {
            printf("%d X %d = %d \n", r, c, r*c); // inner for
            if(c==r) break;
        }
        printf("\n");
    }
}

// Problem 2
void addSet(void)
{
    int a,z;

    for(int a=0; a<10; a++){
        for(int z=0;z<10;z++){
            if(a+z==9){ 
                printf("%d + %d = %d\n", a*10+z, z*10+a, a*10+z+z*10+a);
                break;
            } 
        }
    }
}

int main(void)
{
    mulTable();
    printf("\n");
    addSet();
    printf("\n");

    return 0;   
}