#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

void create();
void read();
void update(unsigned int searchId);
void deleteData(unsigned int deleteId);

int isNumber(const char *str);
int isValidUnsignedInt(const char *str);
int isValidName(const char *str);

unsigned int choice;
unsigned int userId;


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


int main()
{
    char input[100];

    while (1)
    {
        printf("\n=================================\n");
        printf("       FILE HANDLING CRUD\n");
        printf("=================================\n");
        printf("1. Create\n");
        printf("2. Read\n");
        printf("3. Update\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        gets(input);

        choice = (unsigned int)atoi(input);

        switch (choice)
        {
            case 1:
                create();
                break;

            case 2:
                read();
                break;

            case 3:
                printf("\nEnter ID to update: ");
                gets(input);

                if (!isValidUnsignedInt(input))
                {
                    printf("Invalid ID! Please enter a value between 0 and %u.\n",
                           UINT_MAX);
                    break;
                }

                userId = (unsigned int)strtoul(input, NULL, 10);
                update(userId);
                break;

            case 4:
                printf("\nEnter ID to delete: ");
                gets(input);

                if (!isValidUnsignedInt(input))
                {
                    printf("Invalid ID! Please enter a value between 0 and %u.\n",
                           UINT_MAX);
                    break;
                }

                userId = (unsigned int)strtoul(input, NULL, 10);
                deleteData(userId);
                break;

            case 5:
                printf("\nProgram terminated.\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please enter 1-5.\n");
        }
    }

    return 0;
}


// CREATE
void create()
{
    FILE *fp;
    FILE *check;
    unsigned int id;
    char input[100];
    char name[50];

    printf("\nEnter ID: ");
    gets(input);

    // Validate ID
    if (!isValidUnsignedInt(input))
    {
        printf("Invalid ID!\n");
        printf("Please enter an unsigned integer between 0 and %u.\n",
               UINT_MAX);
        return;
    }

    id = (unsigned int)strtoul(input, NULL, 10);

    // Check duplicate ID
    check = fopen("data.txt", "r");

    if (check != NULL)
    {
        unsigned int existingId;
        char existingName[50];

        while (fscanf(check, "ID: %u, Name: %[^\n]\n",
                      &existingId, existingName) == 2)
        {
            if (existingId == id)
            {
                printf("ID already exists!\n");
                fclose(check);
                return;
            }
        }

        fclose(check);
    }

    // Enter name
    printf("Enter Name: ");
    gets(name);

    if (!isValidName(name))
    {
        printf("Invalid name! Use only alphabets and spaces.\n");
        return;
    }

    // Open file
    fp = fopen("data.txt", "a");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "ID: %u, Name: %s\n", id, name);

    fclose(fp);

    printf("\nRecord created successfully!\n");
}


// READ
void read()
{
    FILE *fp;
    unsigned int id;
    char name[50];

    fp = fopen("data.txt", "r");

    if (fp == NULL)
    {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n=================================\n");
    printf("          ALL RECORDS\n");
    printf("=================================\n");

    while (fscanf(fp, "ID: %u, Name: %[^\n]\n",
                  &id, name) == 2)
    {
        printf("ID: %u\n", id);
        printf("Name: %s\n", name);
        printf("---------------------------------\n");
    }

    fclose(fp);
}


// UPDATE
void update(unsigned int searchId)
{
    FILE *fp;
    FILE *temp;

    unsigned int id;
    char name[50];
    char newName[50];

    int found = 0;

    fp = fopen("data.txt", "r");

    if (fp == NULL)
    {
        printf("\nNo records found.\n");
        return;
    }

    temp = fopen("temp.txt", "w");

    if (temp == NULL)
    {
        printf("\nError creating temporary file.\n");
        fclose(fp);
        return;
    }

    while (fscanf(fp, "ID: %u, Name: %[^\n]\n",
                  &id, name) == 2)
    {
        if (id == searchId)
        {
            found = 1;

            printf("Current Name: %s\n", name);
            printf("Enter New Name: ");
            gets(newName);

            if (!isValidName(newName))
            {
                printf("Invalid name! Use only alphabets and spaces.\n");

                fprintf(temp, "ID: %u, Name: %s\n",
                        id, name);
            }
            else
            {
                fprintf(temp, "ID: %u, Name: %s\n",
                        id, newName);

                printf("Record updated successfully!\n");
            }
        }
        else
        {
            fprintf(temp, "ID: %u, Name: %s\n",
                    id, name);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("data.txt");
    rename("temp.txt", "data.txt");

    if (!found)
    {
        printf("ID %u not found.\n", searchId);
    }
}


// DELETE
void deleteData(unsigned int deleteId)
{
    FILE *fp;
    FILE *temp;

    unsigned int id;
    char name[50];

    int found = 0;

    fp = fopen("data.txt", "r");

    if (fp == NULL)
    {
        printf("\nNo records found.\n");
        return;
    }

    temp = fopen("temp.txt", "w");

    if (temp == NULL)
    {
        printf("\nError creating temporary file.\n");
        fclose(fp);
        return;
    }

    while (fscanf(fp, "ID: %u, Name: %[^\n]\n",
                  &id, name) == 2)
    {
        if (id == deleteId)
        {
            found = 1;
            printf("Record deleted successfully!\n");
        }
        else
        {
            fprintf(temp, "ID: %u, Name: %s\n",
                    id, name);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("data.txt");
    rename("temp.txt", "data.txt");

    if (!found)
    {
        printf("ID %u not found.\n", deleteId);
    }
}
