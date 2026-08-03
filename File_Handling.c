#include <stdio.h>

void create();
void read();
void update(unsigned int searchId);
void deleteData(unsigned int deleteId);

int main()
{

    unsigned int choice, userId;

    while (1)
    {
        printf("\n1. Create");
        printf("\n2. Read");
        printf("\n3. Update");
        printf("\n4. Delete");
        printf("\n5. Exit");

        printf("\n\nEnter Your Choice: ");
        scanf("%u", &choice);

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
            scanf("%u", &userId);
            update(userId);
            break;

        case 4:
            printf("Enter the ID to Delete: ");
            scanf("%u", &userId);
            deleteData(userId);
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
    fp = fopen("data.txt", "a");

    if (fp == NULL)
    {
        printf("File not found.\n");
        return;
    }

    unsigned int id;
    char name[50];

    printf("Enter Id: \n");
    scanf("%u", &id);

    printf("Enter Your Name: \n");
    scanf("%s", name);

    fprintf(fp, "ID: %u, Name: %s\n", id, name);
    fclose(fp);
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

    fseek(fp, 0, SEEK_END); // move to end of file
    long size = ftell(fp);  // get position (file size)

    if (size == 0)
    {
        printf("File is empty.\n");
        fclose(fp);
        return;
    }

    rewind(fp); // reset pointer to start

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
            getchar(); 
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
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