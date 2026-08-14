#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void create();
void read();
void update(unsigned int searchId);
void deleteData(unsigned int deleteId);

unsigned int choice, userId;

int isNumber(const char *str)
{
    if (*str == '\0')
        return 0;
    while (*str)
    {
        if (!isdigit(*str))
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
        printf("\n1. Create");
        printf("\n2. Read");
        printf("\n3. Update");
        printf("\n4. Delete");
        printf("\n5. Exit");

        printf("\n\nEnter Your Choice: ");

        if (!fgets(input, sizeof(input), stdin))
        {
            printf("Input error!\n");
            continue;
        }

        input[strcspn(input, "\n")] = '\0';

        if (!isNumber(input))
        {
            printf("Invalid input! Please enter a valid number.\n");
            continue;
        }

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
            printf("Enter the ID to Update: ");
            if (fgets(input, sizeof(input), stdin))
            {
                input[strcspn(input, "\n")] = '\0';
                if (isNumber(input))
                {
                    userId = (unsigned int)atoi(input);
                    update(userId);
                }
                else
                {
                    printf("Invalid ID!\n");
                }
            }
            break;

        case 4:
            printf("Enter the ID to Delete: ");
            if (fgets(input, sizeof(input), stdin))
            {
                input[strcspn(input, "\n")] = '\0';
                if (isNumber(input))
                {
                    userId = (unsigned int)atoi(input);
                    deleteData(userId);
                }
                else
                {
                    printf("Invalid ID!\n");
                }
            }
            break;

        case 5:
            return 0;

        default:
            printf("Invalid Choice...");
            break;
        }
    }
}

void create()
{
    FILE *fp;
    char buffer[100];
    unsigned int id;
    char name[50];

    printf("Enter Id: \n");
    if (fgets(buffer, sizeof(buffer), stdin))
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (isNumber(buffer))
        {
            id = (unsigned int)atoi(buffer);
        }
        else
        {
            printf("Invalid ID!\n");
            return;
        }
    }

    fp = fopen("data.txt", "r");
    if (fp != NULL)
    {
        int duplicate = 0;
        unsigned int existingID;
        char existingName[50];
        while (fscanf(fp, "ID: %u, Name: %s\n", &existingID, existingName) != EOF)
        {
            if (existingID == id)
            {
                duplicate = 1;
                break;
            }
        }
        fclose(fp);

        if (duplicate)
        {
            printf("ID %u already exists! Please select a different one.\n", id);
            return;
        }
    }

    printf("Enter Your Name: \n");
    if (fgets(buffer, sizeof(buffer), stdin))
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(name, buffer);
    }

    fp = fopen("data.txt", "a");

    if (fp == NULL)
    {
        printf("File not found.\n");
        return;
    }

    fprintf(fp, "ID: %u, Name: %s\n", id, name);
    fclose(fp);

    printf("User Created Successfully!!!\n\n");
}

void read()
{
    FILE *fp;
    fp = fopen("data.txt", "r");

    if (fp == NULL)
    {
        printf("File not found.\n");
        return;
    }

    unsigned int id;
    char name[50];

    printf("-------RECORD-------\n");

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);

    if (size == 0)
    {
        printf("File is empty.\n");
        fclose(fp);
        return;
    }

    rewind(fp);

    while (fscanf(fp, "ID: %u, Name: %s\n", &id, name) != EOF)
    {
        printf("ID: %u, Name: %s\n", id, name);
    }

    fclose(fp);
}

void update(unsigned int searchId)
{
    FILE *fp;
    FILE *temp;

    fp = fopen("data.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fp == NULL)
    {
        printf("File not found.\n");
        return;
    }

    if (temp == NULL)
    {
        printf("Could not create temp file.\n");
        fclose(fp);
        return;
    }

    unsigned int id;
    char name[50];
    int found = 0;

    while (fscanf(fp, "ID: %u, Name: %s\n", &id, name) != EOF)
    {
        if (searchId == id)
        {
            printf("Enter New Name: \n");
            if (fgets(name, sizeof(name), stdin))
            {
                name[strcspn(name, "\n")] = '\0';
            }
            found = 1;
        }

        fprintf(temp, "ID: %u, Name: %s\n", id, name);
    }

    fclose(fp);
    fclose(temp);

    remove("data.txt");
    rename("temp.txt", "data.txt");

    if (found)
    {
        printf("\nData Updated Successfully for ID: %u\n", searchId);
    }
    else
    {
        printf("\nNo record found with ID: %u\n", searchId);
    }
}

void deleteData(unsigned int deleteId)
{
    FILE *fp;
    FILE *temp;

    fp = fopen("data.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fp == NULL)
    {
        printf("File not found.\n");
        return;
    }

    if (temp == NULL)
    {
        printf("Could not create temp file.\n");
        fclose(fp);
        return;
    }

    unsigned int id;
    char name[50];
    int found = 0;

    while (fscanf(fp, "ID: %u, Name: %s\n", &id, name) != EOF)
    {
        if (deleteId == id)
        {
            found = 1;
        }
        else
        {
            fprintf(temp, "ID: %u, Name: %s\n", id, name);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("data.txt");
    rename("temp.txt", "data.txt");

    if (found)
    {
        printf("Data Deleted Successfully for ID: %u\n", deleteId);
    }
    else
    {
        printf("No record found with ID: %u\n", deleteId);
    }
}