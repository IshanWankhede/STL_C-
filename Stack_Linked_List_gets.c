#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

struct Stack
{
    unsigned int data;
    struct Stack *next;
};

struct Stack *top = NULL;

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

void push();
void pop();
void peek();
void display();
void freeStack();

int main()
{
    char input[100];
    unsigned int choice;

    while (1)
    {
        printf("\n====== STACK MENU ======\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
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
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                freeStack();
                return 0;

            default:
                printf("Invalid Choice! Please select 1-5.\n");
        }
    }
}

void push()
{
    struct Stack *node;
    char input[100];

    node = (struct Stack *)malloc(sizeof(struct Stack));

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

    (*node).next = top;

    top = node;

    printf("Element Pushed Successfully.\n");
}

void pop()
{
    struct Stack *temp;

    if (top == NULL)
    {
        printf("Stack Underflow.\n");
        return;
    }

    temp = top;

    printf("Deleted Element : %u\n", (*top).data);

    top = (*top).next;

    free(temp);
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack is Empty.\n");
        return;
    }

    printf("Top Element : %u\n", (*top).data);
}

void display()
{
    struct Stack *temp;

    if (top == NULL)
    {
        printf("Stack is Empty.\n");
        return;
    }

    temp = top;

    printf("\nStack Elements :\n");

    while (temp != NULL)
    {
        printf("%u\n", (*temp).data);

        temp = (*temp).next;
    }
}

void freeStack()
{
    struct Stack *current;
    struct Stack *next;

    current = top;

    while (current != NULL)
    {
        next = (*current).next;

        free(current);

        current = next;
    }

    top = NULL;

    printf("\nStack Freed From Memory.\n");
}