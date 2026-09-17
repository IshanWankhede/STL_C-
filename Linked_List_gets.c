#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

struct StudentInfo
{
    unsigned int rollNo;
    char name[50];
    char email[50];
    struct StudentInfo *next;
};

struct StudentInfo *head = NULL;

unsigned int choice, roll;

int isNumber(const char *str)
{
    if (*str == '\0')
        return 0;

    while (*str)
    {
        if (!isdigit((unsigned char)*str))
            return 0;

        str++;
    }

    return 1;
}


int isValidUnsignedInt(const char *str)
{
    char *endPtr;
    unsigned long value;

    if (*str == '\0')
        return 0;

    if (!isNumber(str))
        return 0;

    errno = 0;

    value = strtoul(str, &endPtr, 10);

    if (errno == ERANGE || value > UINT_MAX)
        return 0;

    if (*endPtr != '\0')
        return 0;

    return 1;
}


int isValidName(const char *str)
{
    if (*str == '\0')
        return 0;

    while (*str)
    {
        if (!isalpha((unsigned char)*str) && *str != ' ')
            return 0;

        str++;
    }

    return 1;
}


int isValidEmail(const char *str)
{
    char *at = strchr(str, '@');

    if (!at)
        return 0;

    if (strchr(at + 1, '@'))
        return 0;

    char *dot = strchr(at, '.');

    if (!dot)
        return 0;

    if (at == str)
        return 0;

    if (dot == at + 1)
        return 0;

    if (*(dot + 1) == '\0')
        return 0;

    size_t domainLen = dot - (at + 1);

    char domain[20];

    if (domainLen >= sizeof(domain))
        return 0;

    strncpy(domain, at + 1, domainLen);

    domain[domainLen] = '\0';

    if (strcmp(domain, "gmail") != 0 &&
        strcmp(domain, "vit") != 0)
    {
        return 0;
    }

    if (strcmp(dot + 1, "com") == 0 ||
        strcmp(dot + 1, "in") == 0 ||
        strcmp(dot + 1, "edu") == 0)
    {
        return 1;
    }

    return 0;
}

void createStudents();
void displayStudents();
void updateStudent(unsigned int searchRollNo);
void deleteStudent(unsigned int deleteRollNo);
void freeStudents();

int main()
{
    char input[100];

    while (1)
    {
        printf("\n========== STUDENT MENU ==========\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter Choice : ");

        gets(input);

        if (!isNumber(input))
        {
            printf("Invalid input! Please enter a valid number.\n");
            continue;
        }

        choice = (unsigned int)atoi(input);

        switch (choice)
        {
            case 1:

                createStudents();

                break;


            case 2:

                displayStudents();

                break;


            case 3:

                do
                {
                    printf("Enter Roll Number to Update : ");

                    gets(input);

                    if (isValidUnsignedInt(input))
                    {
                        roll = (unsigned int)strtoul(input, NULL, 10);

                        updateStudent(roll);

                        break;
                    }
                    else
                    {
                        printf("Invalid Roll Number! Please enter a value between 0 and %u.\n",
                               UINT_MAX);
                    }

                } while (1);

                break;


            case 4:

                do
                {
                    printf("Enter Roll Number to Delete : ");

                    gets(input);

                    if (isValidUnsignedInt(input))
                    {
                        roll = (unsigned int)strtoul(input, NULL, 10);

                        deleteStudent(roll);

                        break;
                    }
                    else
                    {
                        printf("Invalid Roll Number! Please enter a value between 0 and %u.\n",
                               UINT_MAX);
                    }

                } while (1);

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

    char buffer[100];

    student = (struct StudentInfo *)malloc(sizeof(struct StudentInfo));

    if (student == NULL)
    {
        printf("Memory Allocation Failed.\n");
        return;
    }

    do
    {
        printf("\nEnter Roll Number : ");

        gets(buffer);

        if (isValidUnsignedInt(buffer))
        {
            (*student).rollNo =
                (unsigned int)strtoul(buffer, NULL, 10);

            break;
        }
        else
        {
            printf("Invalid Roll No! Please enter a value between 0 and %u.\n",
                   UINT_MAX);
        }

    } while (1);

    do
    {
        printf("Enter Name : ");

        gets(buffer);

        if (isValidName(buffer))
        {
            strcpy((*student).name, buffer);

            break;
        }
        else
        {
            printf("Invalid Name! Only letters and spaces allowed.\n");
        }

    } while (1);

    do
    {
        printf("Enter Email : ");

        gets(buffer);

        if (isValidEmail(buffer))
        {
            strcpy((*student).email, buffer);

            break;
        }
        else
        {
            printf("Invalid Email!\n");
        }

    } while (1);


    (*student).next = NULL;


    if (head == NULL)
    {
        head = student;
    }
    else
    {
        last = head;

        while ((*last).next != NULL)
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

    if (head == NULL)
    {
        printf("\nNo Student Found.\n");
        return;
    }

    last = head;

    printf("\n========== STUDENT LIST ==========\n");

    while (last != NULL)
    {
        printf("\nRoll Number : %u", (*last).rollNo);
        printf("\nName        : %s", (*last).name);
        printf("\nEmail       : %s\n", (*last).email);

        last = (*last).next;
    }

    printf("\n");
}


void updateStudent(unsigned int searchRollNo)
{
    struct StudentInfo *last;

    char buffer[100];

    if (head == NULL)
    {
        printf("\nNo Student Found.\n");
        return;
    }

    last = head;

    while (last != NULL)
    {
        if ((*last).rollNo == searchRollNo)
        {

            do
            {
                printf("\nEnter New Name : ");

                gets(buffer);

                if (isValidName(buffer))
                {
                    strcpy((*last).name, buffer);

                    break;
                }
                else
                {
                    printf("Invalid Name! Only letters and spaces allowed.\n");
                }

            } while (1);

            do
            {
                printf("Enter New Email : ");

                gets(buffer);

                if (isValidEmail(buffer))
                {
                    strcpy((*last).email, buffer);

                    break;
                }
                else
                {
                    printf("Invalid Email! Must contain '@' and '.'\n");
                }

            } while (1);


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

    if (head == NULL)
    {
        printf("\nNo Student Found.\n");
        return;
    }

    current = head;
    previous = NULL;

    while (current != NULL)
    {
        if ((*current).rollNo == deleteRollNo)
        {
            if (previous == NULL)
            {
                head = (*current).next;
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
    struct StudentInfo *current = head;
    struct StudentInfo *next;

    while (current != NULL)
    {
        next = (*current).next;

        free(current);

        current = next;
    }

    head = NULL;

    printf("\nAll Student Records Free From Memory.\n");
}