#include <stdio.h>
/*
Exercise 15 Chellenge Excercise 2
*/

void printOdd(int arr[], int len)
{
    printf("Odd Numbers: ");
    for(int i=0; i< len; i++) if(arr[i] % 2 != 0) printf("%d ", arr[i]);
    printf("\n");
}
void printEven(int* arr, int len)
{
    printf("Even Numbers: ");
    for(int i=0; i< len; i++) if(arr[i] % 2 == 0) printf("%d ", arr[i]);
    printf("\n");
}

void problem1(void)
{
    int arr[10];
    
    printf("Please enter the 10 Integer numbers! \n");

    for(int i=0;i<10;i++) {
        printf("Enter: "); 
        scanf("%d", &arr[i]);
    }

    printOdd(arr, 10);
    printEven(arr, 10);
    
}

int binary(int num)
{
    int bNum = 0, digit=1;

    while(num > 0){
        int rem = num % 2;
        bNum += rem*digit;
        num = (num-rem)/2; 
        digit*= 10;
    }

    return bNum;
}

void problem2(void)
{
    int dNum;
    printf("Enter a decimal number: ");
    scanf("%d", &dNum);
    printf("%d", binary(dNum));
}

void problem3(void)
{
    int arr[10];
    int start=0;
    int end=9;
    printf("Please enter the 10 Integer numbers! \n");
    for(int i=0;i<10;i++) {
        int num = 0;
        printf("Enter: "); 
        scanf("%d", &num);
        if(num % 2 != 0) arr[start++] = num;
        else arr[end--] = num;
        
    }
    printf("Array sorted: ");
    for(int i=0;i<10;i++) printf("%d ", arr[i]);
    printf("\n");
}

int isPalindrome(char* word, int len)
{    
    int range = (len % 2 == 0) ? len/2 : (len - 1)/2;
    
    for(int i=0; i<range; i++) if(word[i] != word[len-1-i]) return 0;
    
    return 1;
}

void problem4(void)
{
    char word[50];

    printf("Enter the word: ");
    scanf("%s", word);

    int len = 0;

    while(word[len] != 0) len++;

    if(isPalindrome(word, len)) printf("It is Palindrome!");
    else printf("It is Not Palindrome!");

}

void bubleSort(int arr[], int len)
{
    for(int i=0; i<len-1; i++){
        for(int j=0; j<(len-i)-1; j++){
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void problem5(void)
{
    int arr[10];

    printf("Please enter the 10 Integer numbers! \n");
    
    for(int i=0;i<10;i++) {
        printf("Enter: "); 
        scanf("%d", &arr[i]);
    }

    bubleSort(arr, 10);

    for(int i=0;i<10;i++) printf("%d ", arr[i]);

    printf("\n");
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

    return 0;   
}