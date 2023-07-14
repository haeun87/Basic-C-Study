/*
    Title: Structures and user-defined data types(1/2)
    Description: Learning about structures and user-defined data types in C languages.
    FileName: Struct1.c
    Modified: July 14th 2023
    Writer: Haeun Suh
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
/*
    Chapter 22 Structures and user-defined data types(1/2).
    * Structure is a tool that defines a new data type by binding one or more variables(Including pointers and Arrays).
    * A struct in the C programming language(and many derivatives) is a composite data type(or record) declaration that defines
      a physically grouped list of variables under one name in a block of memory, allowing the different variables to be accessed 
      via a single pointer or by the struct declared name which returns the same address.(Wikipedia)
    * Basically, a struct is merely a simple structure to bind variables but lacks other features, unlike structures such as a class in OOP languages.
    * Only fully formed functions would not need the semicolon at the end; While other forms should have semicolons to tell the compiler that the definition is complete.
    * The access methods for arrarys and pointers are the same as the way without a struct.
    * Just like a class in an OOP, the data-type struct variable can be both declared and initialized simultaneously within the function.
    * A struct can also be declared as an array.
    * Arraw Operator: (*pptr).xPos = 10; == pptr->xPos = 10; (These two act the same!)
    * A struct type pointer variable can be placed as a member of a struct type structure variable.
    * The address value of a structure variable is the same as the address value of the first member of the structure variable.
     => The addresses of the following members are sequentially stacked with each of their data sizes.
*/

struct point // Definition of a struct point
{
    int xPos, yPos; // Members of the struct point
    struct point* ptr; // Declar of pointer variable of struct point
}; // struct needs a semicolon at its end point!(Because its's a declaration!)

struct person{
    char name[20];
    char phonenum[20];
    int age;
} man1, man2; // Also available!

struct circle // Compound Structure of a struct point
{
    double radious;
    struct point* center;
};

double diff(int x1, int x2); // A function prototype also needs a semicolon!

double diff(int x1, int x2)
{
    return (double)(x2-x1);
} // functions do not need a semicolon at its end since their forms have been defined. 

int twoPointDistance(void)
{
    struct point pos1, pos2; // Declare as if it is a primitive data type!
    double distance;

    fputs("point 1 pos: ", stdout);
    scanf("%d %d", &pos1.xPos, &pos1.yPos); // The access to members is similar to that of a class in OOP.

    fputs("point 2 pos: ", stdout);
    scanf("%d %d", &pos2.xPos, &pos2.yPos);

    /* distance between two points */
    distance = 
        sqrt(pow(diff(pos1.xPos,pos2.xPos), 2.0)+pow(diff(pos1.yPos,pos2.yPos), 2.0));
    printf("Distance between two points is: %g \n", distance); 
}

int telephoneInfo(void)
{
    // struct person man1, man2;
    strcpy(man1.name, "Jaimy Kim");
    strcpy(man1.phonenum, "010-1111-2222");
    man1.age=25;

    printf("Enter Name: ");
    scanf("%s", man2.name);
    printf("Enter Phone Number: ");
    scanf("%s", man2.phonenum);
    printf("Enter age: ");
    scanf("%d", &man2.age);

    printf("Name: %s \nPHONE: %s \nAGE: %d \n", man1.name, man1.phonenum, man1.age);
    printf("Name: %s \nPHONE: %s \nAGE: %d \n", man2.name, man2.phonenum, man2.age);
}

int initStructVal(void)
{
    struct point pos={10, 20}; // Initialization like class
    struct person man={"McDonald K", "010-9777-8080", 59}; // Initialization like class
    printf("X: %d Y: %d \n", pos.xPos, pos.yPos);
    printf("Name: %s PHONE: %s AGE: %d \n", man.name, man.phonenum, man.age);

    return 0;
}

int structArray(void)
{
    struct point arr[3];

    for(int i=0; i<3; i++)
    {
        printf("Enter the X,Y coordinate: ");
        scanf("%d %d", &arr[i].xPos, &arr[i].yPos);
    }

    for(int i=0; i<3; i++) printf("[%d, %d] ", arr[i].xPos, arr[i].yPos);
    printf("\n");

    return 0;
}

int initStructArray(void)
{
    struct person arr[3] =
    {
        {"Jenny", "010-1111-2222", 23},
        {"Paul", "010-3333-4444", 32},
        {"Laura", "010-5555-6666", 67}
    };

    for(int i=0; i<3; i++) printf("Name: %s PHONE: %s AGE: %d \n", arr[i].name, arr[i].phonenum, arr[i].age);

    return 0;
}

int structPointer(void)
{
    struct point pos1 = {1, 2};
    struct point pos2 = {100, 100};
    struct point* pptr = &pos1;

    (*pptr).xPos +=4;
    (*pptr).yPos +=5;
    printf("[%d, %d] \n", pptr->xPos, pptr->yPos);

    pptr= &pos2;
    pptr->xPos +=1;
    pptr->yPos +=2;
    printf("[%d, %d] \n", (*pptr).xPos, (*pptr).yPos);   

    return 0;
}

int structPointerMem(void)
{
    struct point cen = {2, 7};
    double rad=5.5;

    struct circle ring={rad, &cen};
    
    printf("A radius of the circle: %g \n", ring.radious);
    printf("A center of the circle: [%d, %d] \n", (ring.center)->xPos, (ring.center)->yPos);

    return 0;
}

int pointRelation(void)
{
    struct point pos1={1, 1};
    struct point pos2={2, 2};
    struct point pos3={3, 3};   

    pos1.ptr = &pos2;
    pos2.ptr = &pos3;
    pos3.ptr = &pos1;

    printf("*** A relation of the points *** \n");
    printf("(%d, %d) -> (%d, %d) \n", pos1.xPos, pos1.yPos, pos1.ptr->xPos, pos1.ptr->yPos);  
    printf("(%d, %d) -> (%d, %d) \n", pos2.xPos, pos2.yPos, pos2.ptr->xPos, pos2.ptr->yPos);    
    printf("(%d, %d) -> (%d, %d) \n", pos3.xPos, pos3.yPos, pos3.ptr->xPos, pos3.ptr->yPos);      
    
    return 0;
}

int structValAddress(void)
{
    struct point pos = {10, 20};
    struct person man = {"Jenny", "010-3231-8888", 25};

    printf("%p %p \n", &pos, &pos.xPos); // The Same!
    printf("%p %p \n", &pos, &pos.yPos); // Address of second variable + 4(int)

    printf("%p %p \n", &man, &man.name);

    return 0;
}

int main(void)
{
    twoPointDistance();
    printf("\n");
    telephoneInfo();
    printf("\n");
    initStructVal();
    printf("\n");
    structArray();
    printf("\n");
    initStructArray();
    printf("\n");
    structPointer();
    printf("\n");
    structPointerMem();
    printf("\n");
    pointRelation();
    printf("\n");
    structValAddress();
    printf("\n");

    return 0;
}