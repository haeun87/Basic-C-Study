#include <stdio.h>
/*
Exercise 09-2
*/

int AddToTotal(int num)
{
    static int total = 0;
    total += num;
    return total;
}
int main(void)
{
    int num;
    for(int i=0; i<3; i++)
    {
        printf("ENTER NUMBER(%d): ", i);
        scanf("%d", &num);
        printf("Total: %d \n", AddToTotal(num));
    }

    return 0;   
}