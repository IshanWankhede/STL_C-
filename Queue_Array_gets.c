#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

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

void enqueue();
void dequeue();
void display();

int main()
{
    char input[100];
    unsigned int choice;

    while (1)
    {
        printf("\n====== QUEUE MENU ======\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter Choice : ");

        gets(input);

        if (!isValidUnsignedInt(input))
        {
            printf("Invalid input! Please enter a valid number.\n");
            continue;
        }

        choice = (unsigned int)strtoul(input, NULL, 10);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nProgram Exited Successfully.\n");
                return 0;

            default:
                printf("Invalid Choice! Please select 1-4.\n");
        }
    }
}

void enqueue()
{
    char input[100];
    unsigned int value;

    if (rear == SIZE - 1)
    {
        printf("\nQueue Overflow.\n");
        return;
    }

    printf("Enter Value : ");

    gets(input);

    if (!isValidUnsignedInt(input))
    {
        printf("Invalid Value! Please enter a valid unsigned integer.\n");
        return;
    }

    value = (unsigned int)strtoul(input, NULL, 10);

    if (front == -1)
    {
        front = 0;
    }

    rear++;

    queue[rear] = value;

    printf("Element Inserted Successfully.\n");
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue Underflow.\n");
        return;
    }

    printf("Deleted Element : %d\n", queue[front]);

    front++;

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("\nQueue is Empty.\n");
        return;
    }

    printf("\nQueue Elements : ");

    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}