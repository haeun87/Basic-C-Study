#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
    Exercise 20 Chellenge Excercise 3
*/

void printArr(int (*arr)[4])
{
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) printf("%d ", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}

void rotateArr(int (*arr)[4], int (*new)[4]){
    for(int i=0; i<4; i++) for(int j=0; j<4; j++) new[j][3-i] = arr[i][j];
}

// Problem 1
void problem1(void)
{
    int arr1[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}; 
    printArr(arr1);
    int arr2[4][4];
    rotateArr(arr1, arr2);
    printArr(arr2);
    rotateArr(arr2, arr1);
    printArr(arr1);
    rotateArr(arr1, arr2);
    printArr(arr2);
}

// Problem 2
void problem2(void)
{
    int num;
    int count= 1, row = 0, col = -1, inc=1;
    printf("Enter n: ");
    scanf("%d", &num);
    int arr[100][100];
    int n = num;
    while(n > 0)
    {
        for(int i=0; i<n; i++) // Moving horizontal
        {
            col += inc;
            arr[row][col] = count++;
        }
        n--; // 1 row finished
        if (n == 0) break; // No more left behind!
        for(int j=0; j<n; j++) // Moving vertical
        {
            row += inc;
            arr[row][col] = count++;
        }
        inc *= -1; // Change direction
    }

    for(int i=0; i<num; i++) {
        for(int j=0; j<num; j++) printf("%d ", arr[i][j]);
        printf("\n");
    }

}
void srand(unsigned int see);

void getRandNum(void){
    for(int i=0; i<5; i++) printf("Random %d: %d \n", i+1, rand());
    printf("\n");
}

// Problem 3 - pseudo-random number(Fixed random seed)
void problem3(void)
{
    printf("5 Random Number: From 0 to %d \n", RAND_MAX); // default RAND_MAX: 32767
    getRandNum();
}

void manualSeedRandomNum(void){ // user input seed
    int seed;
    printf("ENTER the seed number: ");
    scanf("%d", &seed);
    srand(seed);
    getRandNum();
}

void timeSeedRandomNum(void) // Using time function to get random seed
{
    srand((int)time(NULL));
    getRandNum();
}

// Problem 4
void problem4(void)
{
    manualSeedRandomNum();
    timeSeedRandomNum();

    int dice1, dice2;

    srand((int)time(NULL)); // set seed

    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    printf("Dice 1: %d, Dice 2: %d \n", dice1, dice2);
}

// Problem 5
void problem5(void)
{
    int comp, you;
    char* select[3] = {"Rock", "Scissors", "Paper"};
    int win=0,tied=0;
    srand((int)time(NULL)); // set seed

    while(1){
        comp = rand() % 3 + 1;
        printf("[CHOOSE] Rock(1) Scissors(2) Paper(3): ");
        scanf("%d", &you);
        printf("[Result] Computer: %s, You: %s => ", select[comp-1], select[you-1]);
        if(comp == you) {
            printf("We tied!!\n");
            tied++;
        }
        else if(comp == 1 && you == 2 
        || comp == 2 && you == 3 
        || comp == 2 && you == 3 ){
            printf("You lose...\n");
            break;
        }
        else{
            printf("You win!!\n");
            win++;
        }
    }
    printf("[Final Result] WIN: %d TIED: %d", win, tied);
}

// Problem 6
void problem6(void)
{
    srand((int)time(NULL)); // set seed
    int trials=0;
    int pnum[3];
    int cnum[3]= {rand() % 10, rand() % 10, rand() % 10};
    printf("%d %d %d\n",cnum[0], cnum[1], cnum[2]);
    int strike, ball;
    printf("Start Game! \n");
    while(strike < 3){
        trials++;
        strike=ball=0;
        printf("Select 3 numbers: ");
        scanf("%d %d %d", &pnum[0], &pnum[1], &pnum[2]);
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(pnum[i] == cnum[j]){
                    if(i == j) strike++; // Same position, Same value
                    else ball++; // Diff position, Same calue
                }
            }
        }
        printf("Trial %d : %d strike, %d ball!! \n", trials, strike, ball);
    }
    printf("Game Over!(Total Trials: %d) \n", trials);
}


int main(void)
{
    problem1();
    printf("\n");
    problem2();
    printf("\n");   
    problem3();
    printf("\n");
    problem4();
    printf("\n");
    problem5();
    printf("\n");
    problem6();
    printf("\n");

    return 0;   
}