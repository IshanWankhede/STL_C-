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


/* =========================
   INPUT VALIDATION
   ========================= */

int isNumber(const char **str)
{
    if (**str == '\0')
        return 0;

    while (**str != '\0')
    {
        if (!isdigit((unsigned char)**str))
            return 0;

        (*str)++;
    }

    return 1;
}


int isValidUnsignedInt(const char **str)
{
    const char *temp = *str;
    char *endptr;
    unsigned long value;

    while (isspace((unsigned char)*temp))
        temp++;

    if (!isNumber(&temp))
        return 0;

    errno = 0;

    value = strtoul(*str, &endptr, 10);

    while (isspace((unsigned char)*endptr))
        endptr++;

    if (*endptr != '\0')
        return 0;

    if (errno == ERANGE || value > UINT_MAX)
        return 0;

    return 1;
}


unsigned int getUnsignedInt(const char **message)
{
    char input[100];
    const char *inputPtr = input;

    while (1)
    {
        printf("%s", *message);

        gets(input);

        inputPtr = input;

        if (isValidUnsignedInt(&inputPtr))
        {
            return (unsigned int)strtoul(input, NULL, 10);
        }

        printf("Invalid input! Please enter a valid unsigned integer.\n");
    }
}


/* =========================
   QUEUE FUNCTIONS
   ========================= */

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

    queue[rear++] = *node;
}


struct TreeNode *dequeue()
{
    if (isQueueEmpty())
        return NULL;

    return queue[front++];
}


/* =========================
   CREATE NODE
   ========================= */

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


/* =========================
   BST INSERTION
   ========================= */

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


/* =========================
   BST SEARCH
   ========================= */

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


/* =========================
   TRAVERSALS
   ========================= */

void preorder(struct TreeNode *node)
{
    if (node == NULL)
        return;

    printf("%u ", (*node).data);

    preorder((*node).left);
    preorder((*node).right);
}


void inorder(struct TreeNode *node)
{
    if (node == NULL)
        return;

    inorder((*node).left);

    printf("%u ", (*node).data);

    inorder((*node).right);
}


void postorder(struct TreeNode *node)
{
    if (node == NULL)
        return;

    postorder((*node).left);
    postorder((*node).right);

    printf("%u ", (*node).data);
}


/* =========================
   LEVEL ORDER TRAVERSAL
   ========================= */

void levelOrder()
{
    struct TreeNode *current;

    if (root == NULL)
        return;

    resetQueue();

    enqueue(&root);

    while (!isQueueEmpty())
    {
        current = dequeue();

        printf("%u ", (*current).data);

        if ((*current).left != NULL)
            enqueue(&((*current).left));

        if ((*current).right != NULL)
            enqueue(&((*current).right));
    }
}


/* =========================
   DISPLAY TREE
   ========================= */

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


/* =========================
   FIND MINIMUM NODE
   ========================= */

struct TreeNode *findMinNode(struct TreeNode *node)
{
    struct TreeNode *current = node;

    while ((*current).left != NULL)
    {
        current = (*current).left;
    }

    return current;
}


/* =========================
   BST DELETE
   ========================= */

struct TreeNode *deleteNodeRecursive(
    struct TreeNode *node,
    unsigned int *data)
{
    struct TreeNode *successor;

    if (node == NULL)
        return NULL;

    if (*data < (*node).data)
    {
        (*node).left =
            deleteNodeRecursive((*node).left, data);
    }
    else if (*data > (*node).data)
    {
        (*node).right =
            deleteNodeRecursive((*node).right, data);
    }
    else
    {
        /* Case 1: No child */

        if ((*node).left == NULL &&
            (*node).right == NULL)
        {
            free(node);

            return NULL;
        }


        /* Case 2: Only right child */

        if ((*node).left == NULL)
        {
            struct TreeNode *temp = (*node).right;

            free(node);

            return temp;
        }


        /* Case 3: Only left child */

        if ((*node).right == NULL)
        {
            struct TreeNode *temp = (*node).left;

            free(node);

            return temp;
        }


        /* Case 4: Two children */

        successor = findMinNode((*node).right);

        (*node).data = (*successor).data;

        (*node).right =
            deleteNodeRecursive(
                (*node).right,
                &(*successor).data);
    }

    return node;
}


void deleteNode(unsigned int *data)
{
    if (findNode(root, data) == NULL)
    {
        printf("Node not found!\n");
        return;
    }

    root = deleteNodeRecursive(root, data);

    printf("Node deleted successfully.\n");
}


/* =========================
   UPDATE NODE
   ========================= */

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

    /*
       We cannot directly change the value
       because it may violate the BST property.

       Therefore:
       1. Delete old value
       2. Insert new value
    */

    root = deleteNodeRecursive(root, oldData);

    addNode(newData);

    printf("Node updated successfully.\n");
}


/* =========================
   FREE TREE
   ========================= */

void freeTree(struct TreeNode *node)
{
    if (node == NULL)
        return;

    freeTree((*node).left);
    freeTree((*node).right);

    free(node);
}


/* =========================
   MAIN
   ========================= */

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

        if (!isValidUnsignedInt(&inputPtr))
        {
            printf("Invalid choice!\n");
            continue;
        }

        choice = (unsigned int)strtoul(input, NULL, 10);

        switch (choice)
        {
            case 1:

                data = getUnsignedInt(
                    &(const char *){"Enter data: "}
                );

                addNode(&data);

                break;


            case 2:

                displayTree();

                break;


            case 3:

                data = getUnsignedInt(
                    &(const char *){"Enter data to search: "}
                );

                if (findNode(root, &data) != NULL)
                    printf("Node found!\n");
                else
                    printf("Node not found!\n");

                break;


            case 4:

                oldData = getUnsignedInt(
                    &(const char *){"Enter old data: "}
                );

                newData = getUnsignedInt(
                    &(const char *){"Enter new data: "}
                );

                updateNode(&oldData, &newData);

                break;


            case 5:

                data = getUnsignedInt(
                    &(const char *){"Enter data to delete: "}
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