#include <stdio.h>

#define SIZE 5

int stack[SIZE];
int top = -1;

void push();
void pop();
void peek();
void display();

int main()
{
    int choice;

    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid Choice\n");
        }
    }
}

void push()
{
    int value;

    if(top == SIZE-1)
    {
        printf("Stack Overflow\n");
        return;
    }

    printf("Enter Value : ");
    scanf("%d",&value);

    top++;
    stack[top] = value;
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("Deleted : %d\n",stack[top]);

    top--;
}

void peek()
{
    if(top == -1)
    {
        printf("Stack Empty\n");
        return;
    }

    printf("Top Element : %d\n",stack[top]);
}

void display()
{
    int i;

    if(top == -1)
    {
        printf("Stack Empty\n");
        return;
    }

    printf("Stack : ");

    for(i = top; i >= 0; i--)
    {
        printf("%d ",stack[i]);
    }

    printf("\n");
}