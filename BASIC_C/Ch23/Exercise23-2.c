#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Exercise 23-2
*/
typedef struct
{
    int xpos;
    int ypos;
} Point;
typedef struct 
{
    Point* pos1;
    Point* pos2;

} Rectangle;

void showCoordinates(Rectangle* rec){
    int startX = ((rec->pos1->xpos) > (rec->pos2->xpos)) ? (rec->pos2->xpos) : (rec->pos1->xpos);
    int startY = ((rec->pos1->ypos) > (rec->pos2->ypos)) ? (rec->pos2->ypos) : (rec->pos1->ypos);
    int width = (rec->pos1->xpos)-(rec->pos2->xpos);
    int height = (rec->pos1->ypos)-(rec->pos2->ypos);
    
    width = width > 0 ? width : (-1)*width; 
    height = height > 0 ? height : (-1)*height; 
    
    printf("[%d, %d] ", startX, startY);
    printf("[%d, %d] ", startX, startY+height);
    printf("[%d, %d] ", startX+width, startY);
    printf("[%d, %d] \n", startX+width, startY+height);  
}

void recSize(Rectangle* rec){
    int size = ((rec->pos1->xpos)-(rec->pos2->xpos))*((rec->pos1->ypos)-(rec->pos2->ypos));
    printf("Area of The Rectangle: %d \n", size);
}

// Problem
int problem(void)
{
    Point pos1 = {0, 0}, pos2 = {100, 100};
    Rectangle rec = {&pos1, &pos2};
    
    showCoordinates(&rec);
    recSize(&rec);

    return 0;
}

int main(void)
{
    problem();
    printf("\n");

    return 0;
}