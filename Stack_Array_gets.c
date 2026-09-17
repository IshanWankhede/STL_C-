#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

#define SIZE 5

unsigned int stack[SIZE];
int top = -1;

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
                printf("\nProgram Exited Successfully.\n");
                return 0;

            default:
                printf("Invalid Choice! Please select 1-5.\n");
        }
    }
}

void push()
{
    char input[100];
    unsigned int value;

    if (top == SIZE - 1)
    {
        printf("Stack Overflow.\n");
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

    top++;

    stack[top] = value;

    printf("Element Pushed Successfully.\n");
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow.\n");
        return;
    }

    printf("Deleted : %u\n", stack[top]);

    top--;
}

void peek()
{
    if (top == -1)
    {
        printf("Stack Empty.\n");
        return;
    }

    printf("Top Element : %u\n", stack[top]);
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack Empty.\n");
        return;
    }

    printf("Stack : ");

    for (i = top; i >= 0; i--)
    {
        printf("%u ", stack[i]);
    }

    printf("\n");
}