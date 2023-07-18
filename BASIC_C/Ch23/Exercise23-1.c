#include <stdio.h>
/*
Exercise 23-1
*/

typedef struct
{
    int xpos;
    int ypos;
} Point;

void SwapPoint(Point* pos1, Point* pos2){
    Point temp = *pos1;

    *pos1 = *pos2;
    *pos2 = temp;
}

// Problem
int problem(void)
{
    Point pos1 = {2, 4};
    Point pos2 = {5, 7};

    printf("pos1: [%d, %d], pos2: [%d, %d] \n",pos1.xpos, pos1.ypos, pos2.xpos, pos2.ypos);
    SwapPoint(&pos1, &pos2);
    printf("pos1: [%d, %d], pos2: [%d, %d] \n",pos1.xpos, pos1.ypos, pos2.xpos, pos2.ypos);
    
    return 0;
}

int main(void)
{
    problem();
    printf("\n");

    return 0;
}