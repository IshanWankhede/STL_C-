#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StudentInfo
{
    unsigned int rollNo;
    char name[50];
    char email[50];

    struct StudentInfo *next;
};

struct StudentInfo *syc = NULL;

void createStudents();
void displayStudents();
void updateStudent(unsigned int searchRollNo);
void deleteStudent(unsigned int deleteRollNo);
void freeStudents();

int main()
{
    int choice;
    unsigned int roll;

    while(1)
    {
        printf("\n========== STUDENT MENU ==========\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");

        printf("Enter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                createStudents();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                printf("Enter Roll Number to Update : ");
                scanf("%u",&roll);
                updateStudent(roll);
                break;

            case 4:
                printf("Enter Roll Number to Delete : ");
                scanf("%u",&roll);
                deleteStudent(roll);
                break;

            case 5:
                freeStudents();
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}

void createStudents()
{
    struct StudentInfo *student;
    struct StudentInfo *last;

    student = (struct StudentInfo *)malloc(sizeof(struct StudentInfo));

    if(student == NULL)
    {
        printf("Memory Allocation Failed.\n");
        return;
    }

    printf("\nEnter Roll Number : ");
    scanf("%u",&(*student).rollNo);

    printf("Enter Name : ");
    scanf("%s",(*student).name);

    printf("Enter Email : ");
    scanf("%s",(*student).email);

    (*student).next = NULL;

    if(syc == NULL)
    {
        syc = student;
    }
    else
    {
        last = syc;

        while((*last).next != NULL)
        {
            last = (*last).next;
        }

        (*last).next = student;
    }

    printf("\nStudent Added Successfully.\n");
}

void displayStudents()
{
    struct StudentInfo *last;

    if(syc == NULL)
    {
        printf("\nNo Student Found.\n");
        return;
    }

    last = syc;

    printf("\n========== STUDENT LIST ==========\n");

    while(last != NULL)
    {
        printf("\nRoll Number : %u",(*last).rollNo);
        printf("\nName        : %s",(*last).name);
        printf("\nEmail       : %s",(*last).email);

        last = (*last).next;
    }

    printf("\n");
}

void updateStudent(unsigned int searchRollNo)
{
    struct StudentInfo *last;

    if(syc == NULL)
    {
        printf("\nNo Student Found.\n");
        return;
    }

    last = syc;

    while(last != NULL)
    {
        if((*last).rollNo == searchRollNo)
        {
            printf("\nEnter New Name : ");
            scanf("%s",(*last).name);

            printf("Enter New Email : ");
            scanf("%s",(*last).email);

            printf("\nStudent Updated Successfully.\n");
            return;
        }

        last = (*last).next;
    }

    printf("\nStudent Not Found.\n");
}

void deleteStudent(unsigned int deleteRollNo)
{
    struct StudentInfo *current;
    struct StudentInfo *previous;

    if(syc == NULL)
    {
        printf("\nNo Student Found.\n");
        return;
    }

    current = syc;
    previous = NULL;

    while(current != NULL)
    {
        if((*current).rollNo == deleteRollNo)
        {
            if(previous == NULL)
            {
                syc = (*current).next;
            }
            else
            {
                (*previous).next = (*current).next;
            }

            free(current);

            printf("\nStudent Deleted Successfully.\n");
            return;
        }

        previous = current;
        current = (*current).next;
    }

    printf("\nStudent Not Found.\n");
}

void freeStudents()
{
    struct StudentInfo *current = syc;
    struct StudentInfo *next;

    while(current != NULL)
    {
        next = (*current).next;
        free(current);
        current = next;
    }

    syc = NULL;

    printf("\nAll Student Records Free From Memory.\n");
}