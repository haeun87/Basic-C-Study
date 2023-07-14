#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
Exercise 22-1
*/

/* 
    * wage: paid by the hour, salary: paid a fixed amount per pay period
    * salary is the amount of money an employee is contracted to earn in a year,
      while payroll and payroll infrastructure is used to keep track of how much
      each employee erns and what they pay in tax.
*/
struct employee {
    char name[20];
    char ssn[20];
    int salary;
};

// Problem
int problem(void)
{
    struct employee emp1;
    char str[10];

    fputs("The name of Employee: ", stdout);
    gets(emp1.name);
    fputs("The SSN of Employee: ", stdout);
    gets(emp1.ssn);
    fputs("The Salary of Employee: ", stdout);
    gets(str);
    emp1.salary = atoi(str);

    printf("Employee's Name: %s \n", emp1.name);
    printf("Employee's SSN: %s \n", emp1.ssn);
    printf("Employee's Salary: %d \n", emp1.salary);

    return 0;
}

int main(void)
{
    problem();
    printf("\n");

    return 0;
}