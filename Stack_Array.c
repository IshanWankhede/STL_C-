#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

int stack[SIZE];
int top = -1;

int isNumber(const char *str)
{
    if(*str == '\0')
        return 0;

    while(*str)
    {
        if(!isdigit(*str))
            return 0;

        str++;
    }

    return 1;
}

void push();
void pop();
void peek();
void display();

int main()
{
    char input[100];
    int choice;

    while(1)
    {
        printf("\n====== STACK MENU ======\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter Choice : ");

        if(!fgets(input, sizeof(input), stdin))
        {
            printf("Invalid Error.\n");
            continue;
        }

        input[strcspn(input, "\n")] = '\0';

        if(!isNumber(input))
        {
            printf("Invalid input! Please enter a valid number.\n");
            continue;
        }

        choice = atoi(input);

        switch(choice)
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
    int value;

    if(top == SIZE - 1)
    {
        printf("Stack Overflow.\n");
        return;
    }

    printf("Enter Value : ");

    if(!fgets(input, sizeof(input), stdin))
    {
        printf("Invalid Error.\n");
        return;
    }

    input[strcspn(input, "\n")] = '\0';

    if(!isNumber(input))
    {
        printf("Invalid Value! Please enter a valid number.\n");
        return;
    }

    value = atoi(input);

    top++;
    stack[top] = value;

    printf("Element Pushed Successfully.\n");
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow.\n");
        return;
    }

    printf("Deleted : %d\n", stack[top]);

    top--;
}

void peek()
{
    if(top == -1)
    {
        printf("Stack Empty.\n");
        return;
    }

    printf("Top Element : %d\n", stack[top]);
}

void display()
{
    int i;

    if(top == -1)
    {
        printf("Stack Empty.\n");
        return;
    }

    printf("Stack : ");

    for(i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    printf("\n");
}