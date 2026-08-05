#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void display();

int main()
{
    int choice;

    while(1)
    {
        printf("\n====== CIRCULAR QUEUE MENU ======\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter Choice : ");
        scanf("%d",&choice);

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
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}

void enqueue()
{
    int value;

    // Queue Full
    if((rear + 1) % SIZE == front)
    {
        printf("\nQueue Overflow.\n");
        return;
    }

    printf("Enter Value : ");
    scanf("%d",&value);

    // First Element
    if(front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;

    printf("Element Inserted Successfully.\n");
}

void dequeue()
{
    if(front == -1)
    {
        printf("\nQueue Underflow.\n");
        return;
    }

    printf("Deleted Element : %d\n",queue[front]);

    // Only one element present
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
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

    i = front;

    while(1)
    {
        printf("%d ",queue[i]);

        if(i == rear)
        {
            break;
        }

        i = (i + 1) % SIZE;
    }

    printf("\n");
}