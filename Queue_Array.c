#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

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

void enqueue();
void dequeue();
void display();

int main()
{
    char input[100];
    unsigned int choice;

    while(1)
    {
        printf("\n====== QUEUE MENU ======\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

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

        choice = (unsigned int)atoi(input);

        switch(choice)
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
    int value;

    if(rear == SIZE - 1)
    {
        printf("\nQueue Overflow.\n");
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
        printf("Invalid Value! Please enter a number.\n");
        return;
    }

    value = atoi(input);

    if(front == -1)
    {
        front = 0;
    }

    rear++;
    queue[rear] = value;

    printf("Element Inserted Successfully.\n");
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("\nQueue Underflow.\n");
        return;
    }

    printf("Deleted Element : %d\n", queue[front]);

    front++;

    if(front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("\nQueue is Empty.\n");
        return;
    }

    printf("\nQueue Elements : ");

    for(i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}