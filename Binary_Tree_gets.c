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

struct TreeNode *root = NULL;

struct TreeNode *queue[100];

int front = 0;
int rear = 0;


int isNumber(const char **str)
{
    if (**str == '\0')
    {
        return 0;
    }

    while (**str)
    {
        if (!isdigit((unsigned char)**str))
        {
            return 0;
        }

        (*str)++;
    }

    return 1;
}


int isValidUnsignedInt(const char **str)
{
    char *endPtr;
    unsigned long value;
    const char *start = *str;
    const char *scan = *str;

    if (*start == '\0')
    {
        return 0;
    }

    if (!isNumber(&scan))
    {
        return 0;
    }

    errno = 0;

    value = strtoul(start, &endPtr, 10);

    if (errno == ERANGE || value > UINT_MAX)
    {
        return 0;
    }

    if (*endPtr != '\0')
    {
        return 0;
    }

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

        if (isValidUnsignedInt(&inputPtr))
        {
            return (unsigned int)strtoul(input, NULL, 10);
        }

        printf("Invalid input! Please enter a valid unsigned integer.\n");
    }
}


void resetQueue()
{
    front = 0;
    rear = 0;
}


int isQueueEmpty()
{
    return front == rear;
}


int isQueueFull()
{
    return rear == 100;
}


void enqueue(struct TreeNode **node)
{
    if (isQueueFull())
    {
        printf("Queue is full!\n");
        return;
    }

    queue[rear] = *node;
    rear++;
}


struct TreeNode *dequeue()
{
    struct TreeNode *node;

    if (isQueueEmpty())
    {
        return NULL;
    }

    node = queue[front];

    front++;

    return node;
}


struct TreeNode *createNode(unsigned int *data)
{
    struct TreeNode *newNode;

    newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    if (newNode == NULL)
    {
        printf("Memory Allocation Failed.\n");
        exit(1);
    }

    (*newNode).data = *data;
    (*newNode).left = NULL;
    (*newNode).right = NULL;

    return newNode;
}


struct TreeNode *findNode(struct TreeNode **node, unsigned int *data)
{
    struct TreeNode *found;

    if (*node == NULL)
    {
        return NULL;
    }

    if ((*(*node)).data == *data)
    {
        return *node;
    }

    found = findNode(&((*(*node)).left), data);

    if (found != NULL)
    {
        return found;
    }

    return findNode(&((*(*node)).right), data);
}


void addNode(unsigned int *data)
{
    struct TreeNode *newNode;
    struct TreeNode *current;

    newNode = createNode(data);

    if (root == NULL)
    {
        root = newNode;

        printf("Node %u added successfully!\n", *data);

        return;
    }

    resetQueue();

    enqueue(&root);

    while (!isQueueEmpty())
    {
        current = dequeue();

        if ((*current).left == NULL)
        {
            (*current).left = newNode;

            printf("Node %u added successfully!\n", *data);

            return;
        }

        enqueue(&((*current).left));

        if ((*current).right == NULL)
        {
            (*current).right = newNode;

            printf("Node %u added successfully!\n", *data);

            return;
        }

        enqueue(&((*current).right));
    }
}


void preorder(struct TreeNode **node)
{
    if (*node == NULL)
    {
        return;
    }

    printf("%u ", (*(*node)).data);

    preorder(&((*(*node)).left));

    preorder(&((*(*node)).right));
}



void inorder(struct TreeNode **node)
{
    if (*node == NULL)
    {
        return;
    }

    inorder(&((*(*node)).left));

    printf("%u ", (*(*node)).data);

    inorder(&((*(*node)).right));
}


void postorder(struct TreeNode **node)
{
    if (*node == NULL)
    {
        return;
    }

    postorder(&((*(*node)).left));

    postorder(&((*(*node)).right));

    printf("%u ", (*(*node)).data);
}


void updateNode(unsigned int *oldData, unsigned int *newData)
{
    struct TreeNode *node;

    node = findNode(&root, oldData);

    if (node == NULL)
    {
        printf("Node %u not found!\n", *oldData);

        return;
    }

    (*node).data = *newData;

    printf(
        "Node %u updated to %u successfully!\n",
        *oldData,
        *newData
    );
}


struct TreeNode *findDeepestNode()
{
    struct TreeNode *current = NULL;

    resetQueue();

    enqueue(&root);

    while (!isQueueEmpty())
    {
        current = dequeue();

        if ((*current).left != NULL)
        {
            enqueue(&((*current).left));
        }

        if ((*current).right != NULL)
        {
            enqueue(&((*current).right));
        }
    }

    return current;
}


void deleteDeepestNode(struct TreeNode **deepest)
{
    struct TreeNode *current;

    if (root == NULL || *deepest == NULL)
    {
        return;
    }

    resetQueue();

    enqueue(&root);

    while (!isQueueEmpty())
    {
        current = dequeue();

        if ((*current).left != NULL)
        {
            if ((*current).left == *deepest)
            {
                (*current).left = NULL;

                free(*deepest);

                return;
            }

            enqueue(&((*current).left));
        }

        if ((*current).right != NULL)
        {
            if ((*current).right == *deepest)
            {
                (*current).right = NULL;

                free(*deepest);

                return;
            }

            enqueue(&((*current).right));
        }
    }
}


void deleteNode(unsigned int *data)
{
    struct TreeNode *target;
    struct TreeNode *deepest;

    if (root == NULL)
    {
        printf("Tree is empty!\n");

        return;
    }

    target = findNode(&root, data);

    if (target == NULL)
    {
        printf("Node %u not found!\n", *data);

        return;
    }

    if ((*root).left == NULL && (*root).right == NULL)
    {
        free(root);

        root = NULL;

        printf("Node %u deleted successfully!\n", *data);

        return;
    }

    deepest = findDeepestNode();

    (*target).data = (*deepest).data;

    deleteDeepestNode(&deepest);

    printf("Node %u deleted successfully!\n", *data);
}


void displayTree()
{
    if (root == NULL)
    {
        printf("\nTree is empty!\n");

        return;
    }

    printf("\nPreorder : ");

    preorder(&root);

    printf("\nInorder  : ");

    inorder(&root);

    printf("\nPostorder: ");

    postorder(&root);

    printf("\n");
}


void freeTree(struct TreeNode **node)
{
    if (*node == NULL)
    {
        return;
    }

    freeTree(&((*(*node)).left));

    freeTree(&((*(*node)).right));

    free(*node);

    *node = NULL;
}


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
        printf("\n");
        printf("=================================\n");
        printf("       BINARY TREE MENU\n");
        printf("=================================\n");
        printf("1. Add Node\n");
        printf("2. Display Traversals\n");
        printf("3. Search Node\n");
        printf("4. Update Node\n");
        printf("5. Delete Node\n");
        printf("6. Exit\n");
        printf("=================================\n");

        printf("Enter your choice: ");

        gets(input);

        if (!isValidUnsignedInt(&inputPtr))
        {
            printf("Invalid input! Please enter a valid number.\n");

            continue;
        }

        choice = (unsigned int)strtoul(input, NULL, 10);

        switch (choice)
        {
            case 1:

                data = getUnsignedInt("Enter data to add: ");

                addNode(&data);

                break;


            case 2:

                displayTree();

                break;


            case 3:

                data = getUnsignedInt("Enter data to search: ");

                if (findNode(&root, &data) != NULL)
                {
                    printf("Node %u found in the tree!\n", data);
                }
                else
                {
                    printf("Node %u not found!\n", data);
                }

                break;


            case 4:

                oldData = getUnsignedInt("Enter old value: ");

                newData = getUnsignedInt("Enter new value: ");

                updateNode(&oldData, &newData);

                break;


            case 5:

                data = getUnsignedInt("Enter data to delete: ");

                deleteNode(&data);

                break;


            case 6:

                freeTree(&root);

                printf("\nTree Freed From Memory.\n");

                printf("Program exited successfully!\n");

                return 0;


            default:

                printf("Invalid Choice! Please select 1-6.\n");
        }
    }

    return 0;
}