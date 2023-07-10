#include <stdio.h>
/*
Exercise 16-1
*/

// Problem 1
int mulTable(void)
{
    int table[3][9];
    
    for(int i=0; i<3; i++) for(int j=0; j<9; j++) table[i][j] = (i+2)*(j+1);

    for(int i=0; i<3; i++) for(int j=0; j<9; j++) printf("%d X %d = %d \n", i+2, j+1, table[i][j]);

    return 0;
}

// Problem 2
int mulDimInit(void)
{
    int arr1[][4] = {1, 2, 3, 4, 5, 6, 7, 8};

    int arr2[4][2];
    for(int i=0; i<4; i++) for(int j=0; j<2; j++) arr2[i][j] = arr1[j][i];

    for(int i=0; i<4; i++) {
        for(int j=0; j<2; j++) printf("%d ", arr2[i][j]);
        printf("\n");
    }
    return 0;
}

// Probelm 3
int studyMgm(void)
{
    char* name[5] = {"GilDong", "YunGi", "EnYoung", "Ddochi", "Total"};
    char* subject[5] = {"Literature", "English", "Math", "History", "Total"};
    int table[5][5];

    table[4][4] = 0;
    for(int i=0; i<4; i++) {
        table[i][4] = 0;
        printf("Name of the student: %s \n", name[i]);
        for(int j=0; j<4; j++) {
            printf("Enter the score of %s: ", subject[j]);
            scanf("%d", &table[i][j]);
            table[4][j] += table[i][j];
            table[i][4] += table[i][j];

        }
        printf("\n");
        table[4][4] += table[i][4];    
    }

    for(int i=0; i<5; i++) {
        printf("%s ", name[i]);
        for(int j=0; j<5; j++) printf("%s: %d ", subject[j], table[i][j]);
        printf("\n");
    }
}

int main(void)
{
    mulTable();
    printf("\n");
    mulDimInit();
    printf("\n");
    studyMgm();
    printf("\n");

    return 0;
}