#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    unsigned int data;

    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *root = NULL;


/* Queue */
struct TreeNode *queue[100];

int front = -1;
int rear = -1;


/* Queue Functions */
void enqueue(struct TreeNode *node);
struct TreeNode *dequeue();


/* Tree Functions */
void addNode(unsigned int data);
void preorder(struct TreeNode *node);
void inorder(struct TreeNode *node);
void postorder(struct TreeNode *node);


int main()
{
    int choice;
    unsigned int data;

    while(1)
    {
        printf("\n========== BINARY TREE ==========\n");

        printf("1. Add Node\n");
        printf("2. Preorder\n");
        printf("3. Inorder\n");
        printf("4. Postorder\n");
        printf("5. Exit\n");

        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                printf("Enter Data : ");
                scanf("%u", &data);

                addNode(data);

                break;


            case 2:

                printf("\nPreorder : ");

                preorder(root);

                printf("\n");

                break;


            case 3:

                printf("\nInorder : ");

                inorder(root);

                printf("\n");

                break;


            case 4:

                printf("\nPostorder : ");

                postorder(root);

                printf("\n");

                break;


            case 5:

                return 0;


            default:

                printf("\nInvalid Choice.\n");
        }
    }
}


/* ================= QUEUE ================= */

void enqueue(struct TreeNode *node)
{
    if(rear == 99)
    {
        printf("\nQueue Overflow.\n");
        return;
    }

    if(front == -1)
    {
        front = 0;
    }

    rear++;

    queue[rear] = node;
}


struct TreeNode *dequeue()
{
    struct TreeNode *temp;

    if(front == -1 || front > rear)
    {
        return NULL;
    }

    temp = queue[front];

    front++;

    return temp;
}


/* ================= ADD NODE ================= */

void addNode(unsigned int data)
{
    struct TreeNode *node;
    struct TreeNode *temp;

    int found = 0;


    /* Create new node */

    node = (struct TreeNode *)malloc(sizeof(struct TreeNode));


    if(node == NULL)
    {
        printf("\nMemory Allocation Failed.\n");
        return;
    }


    (*node).data = data;

    (*node).left = NULL;

    (*node).right = NULL;


    /* If tree is empty */

    if(root == NULL)
    {
        root = node;

        printf("\nNode Added Successfully.\n");

        return;
    }


    /* Start Queue */

    front = -1;
    rear = -1;

    enqueue(root);


    /* Find first empty position */

    while(found == 0)
    {
        temp = dequeue();


        /* Check LEFT */

        if((*temp).left == NULL)
        {
            (*temp).left = node;

            found = 1;
        }

        else
        {
            enqueue((*temp).left);


            /* Check RIGHT */

            if((*temp).right == NULL)
            {
                (*temp).right = node;

                found = 1;
            }

            else
            {
                enqueue((*temp).right);
            }
        }
    }


    printf("\nNode Added Successfully.\n");
}


/* ================= PREORDER ================= */

void preorder(struct TreeNode *node)
{
    if(node == NULL)
    {
        return;
    }

    printf("%u ", (*node).data);

    preorder((*node).left);

    preorder((*node).right);
}


/* ================= INORDER ================= */

void inorder(struct TreeNode *node)
{
    if(node == NULL)
    {
        return;
    }

    inorder((*node).left);

    printf("%u ", (*node).data);

    inorder((*node).right);
}


/* ================= POSTORDER ================= */

void postorder(struct TreeNode *node)
{
    if(node == NULL)
    {
        return;
    }

    postorder((*node).left);

    postorder((*node).right);

    printf("%u ", (*node).data);
}