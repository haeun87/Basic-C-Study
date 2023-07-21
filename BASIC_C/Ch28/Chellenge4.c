#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
    Exercise 28 Chellenge Excercise 4
*/

// Problem 1
typedef struct
{
    char author[10];
    char title[50];
    int page;
} Book;

int problem1(void)
{
    Book book[3]; 
    char str[20];

    printf("[Enter book information] \n");
    for(int i=0; i<3; i++){
        fputs("Author: ", stdout); 
        fgets(book[i].author, sizeof(book[i].author), stdin);
        fputs("Title: ", stdout); 
        fgets(book[i].title, sizeof(book[i].title), stdin);
        fputs("Page: ", stdout); 
        fgets(str, sizeof str, stdin);
        book[i].page = atoi(str);
    }
    
    printf("\n");
    
    printf("[Print book information] \n");
    for(int i=0; i<3; i++){
        printf("Author: %s", book[i].author);
        printf("Title: %s", book[i].title);
        printf("Page: %d \n", book[i].page);
    }
    printf("\n");
    
    return 0;
}

// Problem 2
int problem2(void)
{
    Book* book[3]; 
    char str[20];

    printf("[Enter book information] \n");
    for(int i=0; i<3; i++){
        book[i] = (Book*)malloc(sizeof(Book)); // Set size
        fputs("Author: ", stdout); 
        fgets(book[i]->author, sizeof(book[i]->author), stdin);
        fputs("Title: ", stdout); 
        fgets(book[i]->title, sizeof(book[i]->title), stdin);
        fputs("Page: ", stdout); 
        fgets(str, sizeof str, stdin);
        book[i]->page = atoi(str);
    }
    
    printf("\n");
    
    printf("[Print book information] \n");
    for(int i=0; i<3; i++){
        printf("Author: %s", book[i]->author);
        printf("Title: %s", book[i]->title);
        printf("Page: %d \n", book[i]->page);
    }
    printf("\n");
    
    return 0;
}

// Problem 3 
typedef struct
{
    double real;
    double imaginary;

} Complex;

Complex add(Complex n1, Complex n2){
    Complex comp;

    comp.real = n1.real+n2.real;
    comp.imaginary = n1.imaginary+n2.imaginary;

    return comp;
}

Complex mul(Complex n1, Complex n2){
    Complex comp;
    
    comp.real = n1.real*n2.real - n1.imaginary*n2.imaginary;
    comp.imaginary = n1.imaginary*n2.real + n1.real*n2.imaginary;

    return comp;
}

int problem3(void)
{
    Complex num1, num2, addC, mulC;

    printf("Enter Complex number 1[Real imaginary]: ");
    scanf("%lf %lf", &num1.real, &num1.imaginary);
    printf("Enter Complex number 2[Real imaginary]: ");
    scanf("%lf %lf", &num2.real, &num2.imaginary);    

    addC = add(num1, num2);
    mulC = mul(num1, num2);
    printf("Add Result => Real: %g, Imaginary: %g \n", addC.real, addC.imaginary);
    printf("Multiply Result => Real: %g, Imaginary: %g \n", mulC.real, mulC.imaginary);

    return 0;
}

// Problem 4
int problem4(void)
{
    int cntA=0, cntP=0;
    char str[30];

    FILE * fp = fopen("BASIC_C/Ch28/text.txt","rt");
    

    if(fp==NULL){
        puts("FILE OPEN ERROR!");
        return -1;
    }

    while(fscanf(fp, "%s", str) == 1) {
        if (str[0] == 'A') cntA++;
        else if(str[0] == 'P') cntP++;
    }

    fclose(fp);

    printf("The number of words start with 'A': %d \n", cntA);
    printf("The number of words start with 'P': %d \n", cntP);

    return 0;
}

int getfs(FILE* fp){
    long fpos, fsize;
    fpos = ftell(fp); // the current position indicator

    fseek(fp, 0, SEEK_END); // EOF
    fsize=ftell(fp); // the maximum index + 1 == the size of file.
    fseek(fp, fpos, SEEK_SET);

    return fsize;
}

int compare(FILE* f1, FILE* f2)
{
    while(1){

        if(fgetc(f1) != fgetc(f2)) return 0;
        else if((feof(f1) !=0) && (feof(f2) != 0)) break;
    }

    return 1;
}

// Problem 5
int problem5(void)
{
    FILE* f1 = fopen("BASIC_C/Ch28/file1.txt", "rt");
    FILE* f2 = fopen("BASIC_C/Ch28/file2.txt", "rt");
    FILE* f3 = fopen("BASIC_C/Ch28/file3.txt", "rt");
    FILE* f4 = fopen("BASIC_C/Ch28/file4.txt", "rt");
    if(f1 == NULL || f2 == NULL || f3 == NULL || f4 == NULL){
        puts("FILE OPEN ERROR!");
        return -1;
    }   

    // Compare file1 and file2
    if(compare(f1, f2) == 1) printf("File 1 file 2 is the same! \n");
    else printf("File 1 file 2 is NOT the same! \n");
    
    fseek(f1, 0, SEEK_SET); // init position
    // Compare file1 and file3
    if(compare(f1, f3) == 1) printf("File 1 file 3 is the same! \n");
    else printf("File 1 file 3 is NOT the same! \n");
    
    fseek(f1, 0, SEEK_SET); // init position
    // Compare file1 and file4   
    if(compare(f1, f4) == 1) printf("File 1 file 4 is the same! \n");
    else printf("File 1 file 4 is NOT the same! \n");
    
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);

    return 0; 
}

// Problem 6 & Problem 7
typedef struct {
    char name[10];
    char phone[20];
} DATA;

void ClearLineFromReadBuffer(void)
{
    while(getchar() != '\n'); // Remove until '\n'
}

int problem6(void)
{
    FILE* db;
    int ret, sel, idx=0;
    char dName[10];
    DATA* data[100];

    db = fopen("BASIC_C/Ch28/database.txt", "rt");

    if(db != NULL){
        while(1)
        {
            ret = fscanf(db, "%s %s", data[idx]->name, data[idx]->phone);
            if(ret==EOF) break;
            idx++;
        }

        fclose(db);
    }

    while(1){
        printf("***** MENU ***** \n");
        printf("1. Insert \n2. Delete \n3. Search \n4. Print All \n5. Exit \n");
        printf("Choose the item: ");
        scanf("%d", &sel);
        switch(sel){
            case 1:
                fputs("[INSERT] \n", stdout); 
                ClearLineFromReadBuffer();
                data[idx] = (DATA*)malloc(sizeof(DATA)); // Set size
                fputs("Input Name: ", stdout); 
                fgets(data[idx]->name, sizeof(data[idx]->name), stdin);
                data[idx]->name[strlen(data[idx]->name)-1] = 0;
                fputs("Input Tel Number: ", stdout); 
                fgets(data[idx]->phone, sizeof(data[idx]->phone), stdin);
                data[idx]->phone[strlen(data[idx]->phone)-1] = 0;
                fputs("                 Data Inserted \n", stdout); 
                idx++;
                break;
            case 2:
                fputs("[DELETE] \n", stdout); 
                ClearLineFromReadBuffer();
                fputs("Delete Name: ", stdout); 
                fgets(dName, sizeof(dName), stdin);
                dName[strlen(dName)-1] = 0;
                for(int i=0; i<idx; i++){
                    if(strcmp(dName, data[i] -> name) == 0){
                        for (int j = i; j < idx; j++){
                            strcpy(data[j]->name, data[j+1] -> name);
                            strcpy(data[j]->phone, data[j+1] -> phone);
                        }
                        idx--;
                        printf("Name '%s' deleted! \n", dName);
                        goto LOOP_END;
                    }
                }
                printf("[Search Result] No data Exist! \n");
                break;
            case 3:
                fputs("[SEARCH] \n", stdout);
                ClearLineFromReadBuffer();
                fputs("Search Name: ", stdout); 
                fgets(dName, sizeof(dName), stdin);
                dName[strlen(dName)-1] = 0;
                for(int i=0; i<idx; i++){
                    if(strcmp(dName,data[i] -> name) == 0){
                        printf("[Search Result] Name: %s Phone: %s \n", data[i] -> name, data[i] -> phone);
                        goto LOOP_END;
                    }
                }
                printf("[Search Result] No data Exist! \n");
                break;
            case 4:
                fputs("[PRINT ALL DATA] \n", stdout);
                for(int i=0; i<idx; i++){
                    printf("Name: %s Phone: %s \n", data[i] -> name, data[i] -> phone);
                }
                break;
            case 5:
                printf("[EXIT] \n");
                goto PROGRAM_END;
            default:
                printf("Please Select number from 1 ~ 5! \n");
        }
        LOOP_END:
            continue;
        PROGRAM_END:
            break;
    }
    
    db = fopen("BASIC_C/Ch28/database.txt", "wt");
    

    for(int i=0; i<idx; i++){
        fprintf(db, "%10s %20s \n", data[i]->name, data[i]->phone);
    }


    printf("[Program Termination] Good bye...\n");

    fclose(db);

    return 0;
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