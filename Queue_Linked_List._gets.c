#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

struct Queue
{
    unsigned int data;
    struct Queue *next;
};

struct Queue *front = NULL;
struct Queue *rear = NULL;

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
void freeQueue();

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
                freeQueue();
                return 0;

            default:
                printf("Invalid Choice! Please select 1-4.\n");
        }
    }
}

void enqueue()
{
    struct Queue *node;
    char input[100];

    node = (struct Queue *)malloc(sizeof(struct Queue));

    if (node == NULL)
    {
        printf("Memory Allocation Failed.\n");
        return;
    }

    printf("Enter Data : ");

    gets(input);

    if (!isValidUnsignedInt(input))
    {
        printf("Invalid Data! Please enter a valid unsigned integer.\n");
        free(node);
        return;
    }

    (*node).data = (unsigned int)strtoul(input, NULL, 10);
    (*node).next = NULL;

    if (front == NULL)
    {
        front = node;
        rear = node;
    }
    else
    {
        (*rear).next = node;
        rear = node;
    }

    printf("Element Inserted Successfully.\n");
}

void dequeue()
{
    struct Queue *temp;

    if (front == NULL)
    {
        printf("Queue Underflow.\n");
        return;
    }

    temp = front;

    printf("Deleted Element : %u\n", (*front).data);

    front = (*front).next;

    if (front == NULL)
    {
        rear = NULL;
    }

    free(temp);
}

void display()
{
    struct Queue *temp;

    if (front == NULL)
    {
        printf("Queue is Empty.\n");
        return;
    }

    temp = front;

    printf("\nQueue Elements : ");

    while (temp != NULL)
    {
        printf("%u ", (*temp).data);

        temp = (*temp).next;
    }

    printf("\n");
}

void freeQueue()
{
    struct Queue *current;
    struct Queue *next;

    current = front;

    while (current != NULL)
    {
        next = (*current).next;

        free(current);

        current = next;
    }

    front = NULL;
    rear = NULL;

    printf("\nQueue Freed From Memory.\n");
}