/*
    Title: Structures and user-defined data types(1/2)
    Description: Learning about structures and user-defined data types in C languages.
    FileName: Struct1.c
    Modified: July 13th 2023
    Writer: Haeun Suh
*/

#include <stdio.h>
#include <math.h>
/*
    Chapter 22 Structures and user-defined data types(1/2).
    * To be continued
    * PP. 451
*/

struct point // Definition of structure point
{
    int xPos, yPos;
}; // Structure needs the end point!

double diff(int x1, int x2)
{
    return (double)(x2-x1);
}

int twoPointDistance(void)
{
    struct point pos1, pos2;
    double distance;

    fputs("point 1 pos: ", stdout);
    scanf("%d %d", &pos1.xPos, &pos1.yPos);

    fputs("point 2 pos: ", stdout);
    scanf("%d %d", &pos2.xPos, &pos2.yPos);

    /* distance between two points */
    distance = 
        sqrt(pow(diff(pos1.xPos,pos2.xPos), 2.0)+pow(diff(pos1.yPos,pos2.yPos), 2.0));
    printf("Distance between two points is: %g \n", distance); 
}

int main(void)
{
    twoPointDistance();
    printf("\n");

    return 0;
}