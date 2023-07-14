/*
    Title: Structures and user-defined data types(2/2)
    Description: Learning about structures and user-defined data types in C languages.
    FileName: Struct2.c
    Modified: July 14th 2023
    Writer: Haeun Suh
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
/*
    Chapter 23 Structures and user-defined data types(2/2).
    *  'typedef is essentially used as an alias for existing data types. 
        => It is used to give a new name to an existing type. 
        => The purpose of typedef is to simplify complex declarations and improve readability of the code.
            e.g. typedef struct point Point;
        => Use the alias like Class name in OOP. 
            e.g. point => Point
        => Also can emit the structure's name when typedef has applied.
            e.g. typedef struct { ... } Class;
    * A struct variable can be used as the same as other primitive variables.
        e.g. Point func(){... return point} // return as a struct
        e.g. void ShowPoint(Point pos){...} // argument as a struct
    * As a result of assignment operations between struct variables, member-to-member copies can be made.
    * Other operation for the struct variable should be defined by the user.
    * Union Type
      => While a struct type assigns memories to each member, 
      a union type assigns the memories to the largest sized variable, 
      only then let share those memories with all members.
      => Whenever a value is assigned to one of the members, all members share the same value with the assigned member.
      => By using, union type a single memory space can be accessed in more than one way.
      => That is, it is available to declare a value once then reinterpretation with various types of data.
    * Emumerated Type: A.K.A. Enum type.
      => Actually it works as the same as other Enum in different programming languages.
      => Easy to apply swith statements.
      => By default, enum starts from 0. But can be assigned manually.
      => A non-assigned enum member will be assigned +1 from its previous memeber.
*/

typedef int INT;
typedef int* PTR_INT;
typedef unsigned int UNIT;
typedef unsigned int* PTR_UNIT;
typedef unsigned char UCHAR;
typedef unsigned char* PTR_UCHAR;
struct point
{
    int xpos;
    int ypos;
};
typedef struct point Point;
typedef struct person
{
    char name[20];
    char phoneNum[20];
    int age;
} Person;
typedef struct
{
    char name[20];
    char id[20];
    char school[20];
    char major[20];
    int year;
} Student;
typedef struct 
{
    Point cen;
    double rad;
} Circle;
typedef struct 
{
    int mem1;
    int mem2;
    double mem3;
} Sbox;
typedef union 
{
    int mem1;
    int mem2;
    double mem3;
} Ubox;
typedef struct
{
    unsigned short lower;
    unsigned short upper;
} DBShort;
typedef union
{
    int iBuf;
    char bBuf[4];
    DBShort sBuf;
} RDBuf;
typedef enum
{
    Do=1, Re=2, Mi=3, Fa=4, So=5, La=6, Ti=7 // No semicolon needed!
} Syllable;

int typeNameTypedef(void)
{
    INT num1 = 120; // int num1 = 120;
    PTR_INT pnum1 = &num1; // int* pnum1 = &num1'

    UNIT num2 = 190; // unsigned int num2 = 190;
    PTR_UNIT pnum2 = &num2; // unsigned int* pnum2 = &num2;

    UCHAR ch = 'Z'; // unsigned char ch = 'Z';
    PTR_UCHAR pch = &ch; // unsigned ch* pch = &ch;

    printf("%d, %u, %c \n", *pnum1, *pnum2, *pch);

    return 0;
}

int structTypedef(void)
{
    Point pos = {10, 20};
    // struct point pos2; // Still Available!
    Person man = {"Jessy", "205-385-5550", 24};
    
    printf("%d %d \n", pos.xpos, pos.ypos);
    printf("%s %s %d \n", man.name, man.phoneNum, man.age);

    return 0;
}

void ShowPosition(Point pos){
    printf("[%d, %d] \n", pos.xpos, pos.ypos);
}

Point GetCurrentPosition(void){
    Point cen;

    printf("Input current pos: ");
    scanf("%d %d", &cen.xpos, &cen.ypos);

    return cen;
}

int structValAndFunction(void)
{
    Point curPos=GetCurrentPosition();
    ShowPosition(curPos);

    return 0;
}

void ShowPersonInfo(Person man)
{
    printf("Name: %s \nPHONE: %s \nAGE: %d \n", man.name, man.phoneNum, man.age);
}

Person ReadPersonInfo(void)
{
    Person man;

    printf("Name: "); scanf("%s", man.name);
    printf("PhoneNum: "); scanf("%s", man.phoneNum);
    printf("Age: "); scanf("%d", &man.age);

    return man;
}

int structMemArrCopy(void)
{
    Person man = ReadPersonInfo();
    ShowPersonInfo(man);

    return 0;
}

void GetPointSymmetry(Point* ptr)
{
    ptr->xpos = (ptr->xpos)*-1;
    ptr->ypos = (ptr->ypos)*-1;
}

int structFunctionCallByAdd(void)
{
    Point pos = {7, -5};
    GetPointSymmetry(&pos);
    ShowPosition(pos);
    GetPointSymmetry(&pos);
    ShowPosition(pos);

    return 0;
}

int structOperation(void)
{
    Point pos1={1, 2};
    Point pos2;
    pos2=pos1; // copy

    printf("Size: %d \n", sizeof pos1);
    ShowPosition(pos1);
    printf("Size: %d \n", sizeof pos2);
    ShowPosition(pos2);  

    return 0;  
}   

Point AddPoint(Point pos1, Point pos2)
{
    Point pos = {pos1.xpos+pos2.xpos, pos1.ypos+pos2.ypos};

    return pos;
}

Point SubPoint(Point pos1, Point pos2)
{
    Point pos = {pos1.xpos-pos2.xpos, pos1.ypos-pos2.ypos};

    return pos;
}

int structAddSub(void)
{
    Point pos1={5, 6};
    Point pos2={2, 9};
    Point result;

    result = AddPoint(pos1, pos2);
    printf("After ADD: [%d, %d] \n", result.xpos, result.ypos);
    result = SubPoint(pos1, pos2);
    printf("After SUBSTRACT: [%d, %d] \n", result.xpos, result.ypos);

    return 0;
}

void ShowStudentInfo(Student* sptr)
{
    printf("Student Name: %s \n", sptr->name);
    printf("Student ID: %s \n", sptr->id);
    printf("Student School: %s \n", sptr->school);
    printf("Student Major: %s \n", sptr->major);
    printf("Student Year: %d \n", sptr->year);
    printf("\n");
}

int structImportant(void)
{
    Student arr[7];
    
    for(int i=0;i<7;i++){
        printf("Enter Name: "); scanf("%s", arr[i].name);
        printf("Enter ID: "); scanf("%s", arr[i].id);
        printf("Enter School: "); scanf("%s", arr[i].school);
        printf("Enter Major: "); scanf("%s", arr[i].major);
        printf("Enter Year: "); scanf("%d", &arr[i].year);
    }

    for(int i=0;i<7;i++) ShowStudentInfo(&arr[i]);
}

void ShowCircleInfo(Circle* cptr)
{
    printf("CENTER OF CIRCLE: [%d, %d] \n", (cptr->cen).xpos, (cptr->cen).ypos);
    printf("RADIUS OF CIRCLE: %g \n", cptr->rad);
    printf("\n");
}

int circleIncludePoint(void)
{
    Circle c1={{1, 2}, 3.5};
    Circle c2={2, 4, 3.9}; // Sequentially assigned from Point to double.
    ShowCircleInfo(&c1);
    ShowCircleInfo(&c2);

    return 0;
}

int unionMemAlloc(void)
{
    Sbox sbx;
    Ubox ubox;

    printf("%p %p %p \n", &sbx.mem1, &sbx.mem2, &sbx.mem3); // show the different address
    printf("%p %p %p \n", &ubox.mem1, &ubox.mem2, &ubox.mem3); // show the same address
    printf("%d %d \n", sizeof sbx, sizeof ubox);
    return 0;
}

int unionValAccess(void)
{
    Ubox ubox; // 8 byte due to double variable.
    ubox.mem1=20;
    printf("%d \n", ubox.mem2);

    ubox.mem3=7.15;
    printf("%d \n", ubox.mem1);
    printf("%d \n", ubox.mem2);
    printf("%g \n", ubox.mem3);    

    return 0;
}

int usefulUnionAccess(void)
{
    RDBuf buf;
    printf("Enter Decimal number: ");
    scanf("%d", &(buf.iBuf)); // 1145258561 => 01000100 01000011 01000010 01000001

    // Because the byte will be stored from right to left, the lower byte will be stored first, and the upper byte will be stored later.
    printf("Upper 2 byte: %u \n", buf.sBuf.upper); // 01000100 01000011 => 17475 
    printf("Lower 2 byte: %u \n", buf.sBuf.lower); // 01000010 01000001 => 16961
    // Because the array stores data 0->3, the bytes will be stored in opposite order.
    printf("Upper 1 byte ASCII Code: %c \n", buf.bBuf[3]); // 01000100 => 68 D
    printf("Lower 1 byte ASCII Code: %c \n", buf.bBuf[0]); // 01000001 => 65 A 

}

void Sound(Syllable sy)
{
    switch (sy)
    {
    case Do:
        puts("Do! (a deer, a female deer)"); return;
    case Re:
        puts("Re! (a drop of golden sun)"); return;
    case Mi:
        puts("Mi! (a name I call myself)"); return;
    case Fa:
        puts("Fa! (a long, long way to run)"); return;
    case So:
        puts("So! (a needle pulling thread)"); return;
    case La:
        puts("La! (a note to follow so)"); return;
    case Ti:
        puts("Ti! (a drink with jam and bread)"); return;
    default:
        puts("That will bring us back to do~");
    }
}

int enumTypeTone(void)
{
    Syllable tone;
    
    for(tone=Do; tone<=Ti; tone++) Sound(tone);
    
    return 0;
}

int main(void)
{
    typeNameTypedef();
    printf("\n");
    structTypedef();
    printf("\n");
    structValAndFunction();
    printf("\n");
    structMemArrCopy();
    printf("\n");
    structFunctionCallByAdd();
    printf("\n");
    structOperation();
    printf("\n");
    structAddSub();
    printf("\n");
    structImportant();
    printf("\n");
    circleIncludePoint();
    printf("\n");
    unionMemAlloc();
    printf("\n");
    unionValAccess();
    printf("\n");
    usefulUnionAccess();
    printf("\n");
    enumTypeTone();
    printf("\n");

    return 0;
}