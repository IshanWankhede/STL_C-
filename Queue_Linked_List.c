#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int data;
    struct Queue *next;
};

struct Queue *front = NULL;
struct Queue *rear = NULL;

void enqueue();
void dequeue();
void display();
void freeQueue();

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
                freeQueue();
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}

void enqueue()
{
    struct Queue *node;

    node = (struct Queue *)malloc(sizeof(struct Queue));

    if(node == NULL)
    {
        printf("Memory Allocation Failed.\n");
        return;
    }

    printf("Enter Data : ");
    scanf("%d",&(*node).data);

    (*node).next = NULL;

    if(front == NULL)
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

    if(front == NULL)
    {
        printf("Queue Underflow.\n");
        return;
    }

    temp = front;

    printf("Deleted Element : %d\n",(*front).data);

    front = (*front).next;

    if(front == NULL)
    {
        rear = NULL;
    }

    free(temp);
}

void display()
{
    struct Queue *temp;

    if(front == NULL)
    {
        printf("Queue is Empty.\n");
        return;
    }

    temp = front;

    printf("\nQueue Elements : ");

    while(temp != NULL)
    {
        printf("%d ",(*temp).data);
        temp = (*temp).next;
    }

    printf("\n");
}

void freeQueue()
{
    struct Queue *current;
    struct Queue *next;

    current = front;

    while(current != NULL)
    {
        next = (*current).next;
        free(current);
        current = next;
    }

    front = NULL;
    rear = NULL;

    printf("\nQueue Freed From Memory.\n");
}