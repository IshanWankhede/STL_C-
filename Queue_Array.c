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
        printf("\n====== QUEUE MENU ======\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter Choice : ");
        scanf("%d", &choice);

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

    if(rear == SIZE - 1)
    {
        printf("\nQueue Overflow.\n");
        return;
    }

    if(front == -1)
    {
        front = 0;
    }

    printf("Enter Value : ");
    scanf("%d", &value);

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