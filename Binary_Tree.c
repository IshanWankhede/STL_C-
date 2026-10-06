#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *root = NULL;

struct TreeNode *queue[100];

int front = 0;
int rear = 0;

// Reset queue
void resetQueue()
{
    front = 0;
    rear = 0;
}

// Check if queue is empty
int isQueueEmpty()
{
    return front == rear;
}

// Check if queue is full
int isQueueFull()
{
    return rear == 100;
}

// Add node to queue
void enqueue(struct TreeNode *node)
{
    if (isQueueFull())
    {
        printf("Queue is full!\n");
        return;
    }

    queue[rear] = node;
    rear++;
}

// Remove node from queue
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

// Create a new node
struct TreeNode *createNode(int data)
{
    struct TreeNode *newNode;

    newNode =
        (struct TreeNode *)malloc(
            sizeof(struct TreeNode));

    if (newNode == NULL)
    {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }

    (*newNode).data = data;
    (*newNode).left = NULL;
    (*newNode).right = NULL;

    return newNode;
}

// Add node to binary tree
void addNode(int data)
{
    struct TreeNode *newNode;
    struct TreeNode *current;

    newNode = createNode(data);

    if (root == NULL)
    {
        root = newNode;

        printf(
            "Node %d added successfully!\n",
            data);

        return;
    }

    resetQueue();

    enqueue(root);

    while (!isQueueEmpty())
    {
        current = dequeue();

        if ((*current).left == NULL)
        {
            (*current).left = newNode;

            printf(
                "Node %d added successfully!\n",
                data);

            return;
        }

        enqueue((*current).left);

        if ((*current).right == NULL)
        {
            (*current).right = newNode;

            printf(
                "Node %d added successfully!\n",
                data);

            return;
        }

        enqueue((*current).right);
    }
}

// Search for a node
struct TreeNode *findNode(
    struct TreeNode *node,
    int data)
{
    struct TreeNode *found;

    if (node == NULL)
    {
        return NULL;
    }

    if ((*node).data == data)
    {
        return node;
    }

    found = findNode(
        (*node).left,
        data);

    if (found != NULL)
    {
        return found;
    }

    return findNode(
        (*node).right,
        data);
}

// Update a node
void updateNode(
    int oldData,
    int newData)
{
    struct TreeNode *node;

    node = findNode(root, oldData);

    if (node == NULL)
    {
        printf(
            "Node %d not found!\n",
            oldData);

        return;
    }

    (*node).data = newData;

    printf(
        "Node %d updated to %d successfully!\n",
        oldData,
        newData);
}

// Preorder traversal
void preorder(struct TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    printf(
        "%d ",
        (*node).data);

    preorder((*node).left);

    preorder((*node).right);
}

// Inorder traversal
void inorder(struct TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    inorder((*node).left);

    printf(
        "%d ",
        (*node).data);

    inorder((*node).right);
}

// Postorder traversal
void postorder(struct TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    postorder((*node).left);

    postorder((*node).right);

    printf(
        "%d ",
        (*node).data);
}

// Level order traversal
void levelOrder()
{
    struct TreeNode *current;

    if (root == NULL)
    {
        return;
    }

    resetQueue();

    enqueue(root);

    while (!isQueueEmpty())
    {
        current = dequeue();

        printf(
            "%d ",
            (*current).data);

        if ((*current).left != NULL)
        {
            enqueue((*current).left);
        }

        if ((*current).right != NULL)
        {
            enqueue((*current).right);
        }
    }
}

// Find deepest node
struct TreeNode *findDeepestNode()
{
    struct TreeNode *current = NULL;

    resetQueue();

    enqueue(root);

    while (!isQueueEmpty())
    {
        current = dequeue();

        if ((*current).left != NULL)
        {
            enqueue((*current).left);
        }

        if ((*current).right != NULL)
        {
            enqueue((*current).right);
        }
    }

    return current;
}

// Delete deepest node
void deleteDeepestNode(
    struct TreeNode *deepest)
{
    struct TreeNode *current;

    if (root == NULL || deepest == NULL)
    {
        return;
    }

    resetQueue();

    enqueue(root);

    while (!isQueueEmpty())
    {
        current = dequeue();

        if ((*current).left != NULL)
        {
            if ((*current).left == deepest)
            {
                (*current).left = NULL;

                free(deepest);

                return;
            }

            enqueue((*current).left);
        }

        if ((*current).right != NULL)
        {
            if ((*current).right == deepest)
            {
                (*current).right = NULL;

                free(deepest);

                return;
            }

            enqueue((*current).right);
        }
    }
}

// Delete a node
void deleteNode(int data)
{
    struct TreeNode *target;
    struct TreeNode *deepest;

    if (root == NULL)
    {
        printf("Tree is empty!\n");
        return;
    }

    target = findNode(root, data);

    if (target == NULL)
    {
        printf(
            "Node %d not found!\n",
            data);

        return;
    }

    if ((*root).left == NULL &&
        (*root).right == NULL)
    {
        free(root);

        root = NULL;

        printf(
            "Node %d deleted successfully!\n",
            data);

        return;
    }

    deepest = findDeepestNode();

    (*target).data = (*deepest).data;

    deleteDeepestNode(deepest);

    printf(
        "Node %d deleted successfully!\n",
        data);
}

// Display all traversals
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

// Free the entire tree
void freeTree(struct TreeNode *node)
{
    if (node == NULL)
    {
        return;
    }

    freeTree((*node).left);

    freeTree((*node).right);

    free(node);
}

// Get integer input
int getInteger(char *message)
{
    char input[100];
    int value;

    while (1)
    {
        printf("%s", message);

        if (fgets(
                input,
                sizeof(input),
                stdin) == NULL)
        {
            exit(1);
        }

        if (sscanf(
                input,
                "%d",
                &value) == 1)
        {
            return value;
        }

        printf(
            "Invalid input! Please enter a valid integer.\n");
    }
}

// Main function
int main()
{
    int choice;
    int data;
    int oldData;
    int newData;

    while (1)
    {
        printf("\n");

        printf(
            "=================================\n");

        printf(
            "       BINARY TREE MENU\n");

        printf(
            "=================================\n");

        printf("1. Add Node\n");

        printf("2. Display Traversals\n");

        printf("3. Search Node\n");

        printf("4. Update Node\n");

        printf("5. Delete Node\n");

        printf("6. Exit\n");

        printf(
            "=================================\n");

        choice = getInteger(
            "Enter your choice: ");

        switch (choice)
        {
        case 1:

            data = getInteger(
                "Enter data to add: ");

            addNode(data);

            break;

        case 2:

            displayTree();

            break;

        case 3:

            data = getInteger(
                "Enter data to search: ");

            if (findNode(root, data) != NULL)
            {
                printf(
                    "Node %d found in the tree!\n",
                    data);
            }
            else
            {
                printf(
                    "Node %d not found!\n",
                    data);
            }

            break;

        case 4:

            oldData = getInteger(
                "Enter old value: ");

            newData = getInteger(
                "Enter new value: ");

            updateNode(
                oldData,
                newData);

            break;

        case 5:

            data = getInteger(
                "Enter data to delete: ");

            deleteNode(data);

            break;

        case 6:

            freeTree(root);

            root = NULL;

            printf(
                "\nTree Freed From Memory.\n");

            printf(
                "Program exited successfully!\n");

            return 0;

        default:

            printf(
                "Invalid Choice! Please select 1-6.\n");
        }
    }

    return 0;
}