#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    struct Stack *next;
};

struct Stack *top = NULL;

void push();
void pop();
void peek();
void display();
void freeStack();

int main()
{
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
        scanf("%d",&choice);

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
                freeStack();
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}

void push()
{
    struct Stack *node;

    node = (struct Stack *)malloc(sizeof(struct Stack));

    if(node == NULL)
    {
        printf("Memory Allocation Failed.\n");
        return;
    }

    printf("Enter Data : ");
    scanf("%d",&(*node).data);

    (*node).next = top;

    top = node;

    printf("Element Pushed Successfully.\n");
}

void pop()
{
    struct Stack *temp;

    if(top == NULL)
    {
        printf("Stack Underflow.\n");
        return;
    }

    temp = top;

    printf("Deleted Element : %d\n",(*top).data);

    top = (*top).next;

    free(temp);
}

void peek()
{
    if(top == NULL)
    {
        printf("Stack is Empty.\n");
        return;
    }

    printf("Top Element : %d\n",(*top).data);
}

void display()
{
    struct Stack *temp;

    if(top == NULL)
    {
        printf("Stack is Empty.\n");
        return;
    }

    temp = top;

    printf("\nStack Elements :\n");

    while(temp != NULL)
    {
        printf("%d\n",(*temp).data);
        temp = (*temp).next;
    }
}

void freeStack()
{
    struct Stack *current;
    struct Stack *next;

    current = top;

    while(current != NULL)
    {
        next = (*current).next;
        free(current);
        current = next;
    }

    top = NULL;

    printf("\nStack Freed From Memory.\n");
}