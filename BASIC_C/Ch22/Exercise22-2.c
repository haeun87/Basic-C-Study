#include <stdio.h>
/*
Exercise 22-2
*/

struct employee {
    char name[20];
    char ssn[20];
    int salary;
};

// Problem
int problem(void)
{
    struct employee emp[3];

    for(int i=0; i<3; i++){
        printf("The name of Employee: ");
        scanf("%s", emp[i].name);
        printf("The SSN of Employee: ");
        scanf("%s", emp[i].ssn);
        printf("The Salary of Employee: ");
        scanf("%d", &emp[i].salary);
    }
    printf("\n");
    for(int i=0; i<3; i++){
        printf("Employee's Name: %s \n", emp[i].name);
        printf("Employee's SSN: %s \n", emp[i].ssn);
        printf("Employee's Salary: %d \n", emp[i].salary);
    }

    return 0;
}

int main(void)
{
    problem();
    printf("\n");

    return 0;
}