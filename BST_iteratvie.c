#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

struct TreeNode
{
    unsigned int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct QueueNode
{
    struct TreeNode *treeNode;
    struct QueueNode *next;
};

struct TreeNode *root = NULL;

struct QueueNode *front = NULL;
struct QueueNode *rear = NULL;

struct TreeNode *stack[100];
int top = -1;


//   INPUT VALIDATION

int isNumber(const char *str)
{
    if (*str == '\0')
        return 0;

    while (*str != '\0')
    {
        if (!isdigit((unsigned char)*str))
            return 0;

        str++;
    }

    return 1;
}


int isValidUnsignedInt(const char *str)
{
    const char *temp = str;
    char *endptr;
    unsigned long value;

    while (isspace((unsigned char)*temp))
        temp++;

    if (!isNumber(temp))
        return 0;

    errno = 0;

    value = strtoul(str, &endptr, 10);

    while (isspace((unsigned char)*endptr))
        endptr++;

    if (*endptr != '\0')
        return 0;

    if (errno == ERANGE || value > UINT_MAX)
        return 0;

    return 1;
}


unsigned int getUnsignedInt(const char *message)
{
    char input[100];
    const char *inputPtr = input;

    while (1)
    {
        printf("%s", message);

        gets(input);

        inputPtr = input;

        if (isValidUnsignedInt(inputPtr))
        {
            return (unsigned int)strtoul(input, NULL, 10);
        }

        printf("Invalid input! Please enter a valid unsigned integer.\n");
    }
}


//   QUEUE FUNCTIONS USING LINKED LIST

void resetQueue()
{
    front = NULL;
    rear = NULL;
}


int isQueueEmpty()
{
    return front == NULL;
}


void enqueue(struct TreeNode *node)
{
    struct QueueNode *newNode;

    newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    (*newNode).treeNode = node;
    (*newNode).next = NULL;

    if (rear == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        (*rear).next = newNode;
        rear = newNode;
    }
}


struct TreeNode *dequeue()
{
    struct QueueNode *temp;
    struct TreeNode *treeNode;

    if (isQueueEmpty())
        return NULL;

    temp = front;

    treeNode = (*temp).treeNode;

    front = (*front).next;

    if (front == NULL)
        rear = NULL;

    free(temp);

    return treeNode;
}


//   STACK FUNCTIONS

void resetStack()
{
    top = -1;
}


int isStackEmpty()
{
    return top == -1;
}


int isStackFull()
{
    return top == 99;
}


void push(struct TreeNode *node)
{
    if (isStackFull())
    {
        printf("Stack is full!\n");
        return;
    }

    stack[++top] = node;
}


struct TreeNode *pop()
{
    if (isStackEmpty())
        return NULL;

    return stack[top--];
}


//   CREATE NODE

struct TreeNode *createNode(unsigned int *data)
{
    struct TreeNode *newNode;

    newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    (*newNode).data = *data;
    (*newNode).left = NULL;
    (*newNode).right = NULL;

    return newNode;
}


//   BST INSERTION

void addNode(unsigned int *data)
{
    struct TreeNode *newNode;
    struct TreeNode *current;

    newNode = createNode(data);

    if (newNode == NULL)
        return;

    if (root == NULL)
    {
        root = newNode;

        printf("Node added successfully.\n");

        return;
    }

    current = root;

    while (1)
    {
        if (*data == (*current).data)
        {
            printf("Duplicate value! Node not added.\n");

            free(newNode);

            return;
        }

        if (*data < (*current).data)
        {
            if ((*current).left == NULL)
            {
                (*current).left = newNode;

                printf("Node added successfully.\n");

                return;
            }

            current = (*current).left;
        }
        else
        {
            if ((*current).right == NULL)
            {
                (*current).right = newNode;

                printf("Node added successfully.\n");

                return;
            }

            current = (*current).right;
        }
    }
}


//   BST SEARCH

struct TreeNode *findNode(
    struct TreeNode *node,
    unsigned int *data)
{
    if (node == NULL)
        return NULL;

    if (*data == (*node).data)
        return node;

    if (*data < (*node).data)
        return findNode((*node).left, data);

    return findNode((*node).right, data);
}


//   PREORDER TRAVERSAL USING STACK

void preorder(struct TreeNode *node)
{
    struct TreeNode *current;

    if (node == NULL)
        return;

    resetStack();

    push(node);

    while (!isStackEmpty())
    {
        current = pop();

        printf("%u ", (*current).data);

        if ((*current).right != NULL)
            push((*current).right);

        if ((*current).left != NULL)
            push((*current).left);
    }
}


//   INORDER TRAVERSAL USING STACK

void inorder(struct TreeNode *node)
{
    struct TreeNode *current;

    current = node;

    resetStack();

    while (current != NULL || !isStackEmpty())
    {
        while (current != NULL)
        {
            push(current);

            current = (*current).left;
        }

        current = pop();

        printf("%u ", (*current).data);

        current = (*current).right;
    }
}


//   POSTORDER TRAVERSAL USING STACK

void postorder(struct TreeNode *node)
{
    struct TreeNode *current;
    struct TreeNode *previous;

    current = node;
    previous = NULL;

    resetStack();

    while (current != NULL || !isStackEmpty())
    {
        while (current != NULL)
        {
            push(current);

            current = (*current).left;
        }

        current = stack[top];

        if ((*current).right != NULL &&
            previous != (*current).right)
        {
            current = (*current).right;
        }
        else
        {
            printf("%u ", (*current).data);

            previous = current;

            pop();

            current = NULL;
        }
    }
}


//   LEVEL ORDER TRAVERSAL

void levelOrder()
{
    struct TreeNode *current;

    if (root == NULL)
        return;

    resetQueue();

    enqueue(root);

    while (!isQueueEmpty())
    {
        current = dequeue();

        printf("%u ", (*current).data);

        if ((*current).left != NULL)
            enqueue((*current).left);

        if ((*current).right != NULL)
            enqueue((*current).right);
    }
}


//   DISPLAY TREE

void displayTree()
{
    if (root == NULL)
    {
        printf("\nTree is empty!\n");
        return;
    }

    printf("\nPreorder    : ");
    preorder(root);

    printf("\nInorder     : ");
    inorder(root);

    printf("\nPostorder   : ");
    postorder(root);

    printf("\nLevel Order : ");
    levelOrder();

    printf("\n");
}


//   FIND MINIMUM NODE

struct TreeNode *findMinNode(struct TreeNode *node)
{
    struct TreeNode *current = node;

    while ((*current).left != NULL)
    {
        current = (*current).left;
    }

    return current;
}


//   ITERATIVE BST DELETE

int deleteNodeIterative(unsigned int *data)
{
    struct TreeNode *current;
    struct TreeNode *parent;
    struct TreeNode *successor;
    struct TreeNode *successorParent;
    struct TreeNode *child;

    current = root;
    parent = NULL;

    while (current != NULL &&
           (*current).data != *data)
    {
        parent = current;

        if (*data < (*current).data)
            current = (*current).left;
        else
            current = (*current).right;
    }

    if (current == NULL)
        return 0;

    if ((*current).left != NULL &&
        (*current).right != NULL)
    {
        successorParent = current;
        successor = (*current).right;

        while ((*successor).left != NULL)
        {
            successorParent = successor;
            successor = (*successor).left;
        }

        (*current).data = (*successor).data;

        current = successor;
        parent = successorParent;
    }

    if ((*current).left != NULL)
        child = (*current).left;
    else
        child = (*current).right;

    if (parent == NULL)
    {
        root = child;
    }
    else if ((*parent).left == current)
    {
        (*parent).left = child;
    }
    else
    {
        (*parent).right = child;
    }

    free(current);

    return 1;
}


void deleteNode(unsigned int *data)
{
    if (!deleteNodeIterative(data))
    {
        printf("Node not found!\n");
        return;
    }

    printf("Node deleted successfully.\n");
}


//   UPDATE NODE

void updateNode(
    unsigned int *oldData,
    unsigned int *newData)
{
    if (findNode(root, oldData) == NULL)
    {
        printf("Old node not found!\n");
        return;
    }

    if (*oldData == *newData)
    {
        printf("Old and new values are same.\n");
        return;
    }

    if (findNode(root, newData) != NULL)
    {
        printf("New value already exists!\n");
        return;
    }

    deleteNodeIterative(oldData);

    addNode(newData);

    printf("Node updated successfully.\n");
}


//   FREE TREE

void freeTree(struct TreeNode *node)
{
    if (node == NULL)
        return;

    freeTree((*node).left);
    freeTree((*node).right);

    free(node);
}


//   MAIN

int main()
{
    char input[100];
    const char *inputPtr = input;

    unsigned int choice;
    unsigned int data;
    unsigned int oldData;
    unsigned int newData;

    while (1)
    {
        printf("\n==============================\n");
        printf("     BINARY SEARCH TREE MENU\n");
        printf("==============================\n");

        printf("1. Add Node\n");
        printf("2. Display Traversals\n");
        printf("3. Search Node\n");
        printf("4. Update Node\n");
        printf("5. Delete Node\n");
        printf("6. Exit\n");

        printf("==============================\n");

        printf("Enter your choice: ");

        gets(input);

        inputPtr = input;

        if (!isValidUnsignedInt(inputPtr))
        {
            printf("Invalid choice!\n");
            continue;
        }

        choice = (unsigned int)strtoul(input, NULL, 10);

        switch (choice)
        {
            case 1:

                data = getUnsignedInt(
                    "Enter data: "
                );

                addNode(&data);

                break;


            case 2:

                displayTree();

                break;


            case 3:

                data = getUnsignedInt(
                    "Enter data to search: "
                );

                if (findNode(root, &data) != NULL)
                    printf("Node found!\n");
                else
                    printf("Node not found!\n");

                break;


            case 4:

                oldData = getUnsignedInt(
                    "Enter old data: "
                );

                newData = getUnsignedInt(
                    "Enter new data: "
                );

                updateNode(&oldData, &newData);

                break;


            case 5:

                data = getUnsignedInt(
                    "Enter data to delete: "
                );

                deleteNode(&data);

                break;


            case 6:

                freeTree(root);
                root = NULL;

                printf("Program exited successfully.\n");

                return 0;


            default:

                printf("Invalid choice! Please select 1-6.\n");
        }
    }

    return 0;
}
