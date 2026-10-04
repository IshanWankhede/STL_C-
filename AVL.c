#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <errno.h>

struct TreeNode
{
    unsigned int data;
    int height;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *root = NULL;


/* =========================
   INPUT VALIDATION
   ========================= */

int isValidUnsignedInt(const char *str)
{
    char *endptr;
    unsigned long value;

    while (isspace((unsigned char)*str))
        str++;

    if (*str == '\0')
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

    while (1)
    {
        printf("%s", message);

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("Input error!\n");
            continue;
        }

        input[strcspn(input, "\n")] = '\0';

        if (isValidUnsignedInt(input))
        {
            return (unsigned int)strtoul(
                input,
                NULL,
                10
            );
        }

        printf(
            "Invalid input! Please enter a valid unsigned integer.\n"
        );
    }
}


/* =========================
   CREATE NODE
   ========================= */

struct TreeNode *createNode(unsigned int data)
{
    struct TreeNode *newNode;

    newNode = (struct TreeNode *)malloc(
        sizeof(struct TreeNode)
    );

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->data = data;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


/* =========================
   HEIGHT
   ========================= */

int getHeight(struct TreeNode *node)
{
    if (node == NULL)
        return 0;

    return node->height;
}


/* =========================
   MAXIMUM
   ========================= */

int max(int a, int b)
{
    return (a > b) ? a : b;
}


/* =========================
   UPDATE HEIGHT
   ========================= */

void updateHeight(struct TreeNode *node)
{
    if (node == NULL)
        return;

    node->height =
        1 + max(
            getHeight(node->left),
            getHeight(node->right)
        );
}


/* =========================
   BALANCE FACTOR
   ========================= */

int getBalance(struct TreeNode *node)
{
    if (node == NULL)
        return 0;

    return getHeight(node->left)
         - getHeight(node->right);
}


/* =========================
   RIGHT ROTATION
   LL CASE
   ========================= */

struct TreeNode *rightRotate(struct TreeNode *y)
{
    struct TreeNode *x;
    struct TreeNode *temp;

    x = y->left;
    temp = x->right;

    x->right = y;
    y->left = temp;

    updateHeight(y);
    updateHeight(x);

    return x;
}


/* =========================
   LEFT ROTATION
   RR CASE
   ========================= */

struct TreeNode *leftRotate(struct TreeNode *x)
{
    struct TreeNode *y;
    struct TreeNode *temp;

    y = x->right;
    temp = y->left;

    y->left = x;
    x->right = temp;

    updateHeight(x);
    updateHeight(y);

    return y;
}


/* =========================
   AVL INSERTION
   ========================= */

struct TreeNode *insertNode(
    struct TreeNode *node,
    unsigned int data)
{
    int balance;

    /*
       Normal BST insertion
    */

    if (node == NULL)
        return createNode(data);

    if (data < node->data)
    {
        node->left =
            insertNode(
                node->left,
                data
            );
    }
    else if (data > node->data)
    {
        node->right =
            insertNode(
                node->right,
                data
            );
    }
    else
    {
        printf(
            "Duplicate value! Node not added.\n"
        );

        return node;
    }


    /*
       Update height
    */

    updateHeight(node);


    /*
       Get balance factor
    */

    balance = getBalance(node);


    /*
       LL CASE
       Left Left
    */

    if (balance > 1 &&
        data < node->left->data)
    {
        return rightRotate(node);
    }


    /*
       RR CASE
       Right Right
    */

    if (balance < -1 &&
        data > node->right->data)
    {
        return leftRotate(node);
    }


    /*
       LR CASE
       Left Right
    */

    if (balance > 1 &&
        data > node->left->data)
    {
        node->left =
            leftRotate(node->left);

        return rightRotate(node);
    }


    /*
       RL CASE
       Right Left
    */

    if (balance < -1 &&
        data < node->right->data)
    {
        node->right =
            rightRotate(node->right);

        return leftRotate(node);
    }

    return node;
}


void addNode(unsigned int data)
{
    root = insertNode(root, data);

    printf("Node added successfully.\n");
}


/* =========================
   SEARCH
   ========================= */

struct TreeNode *findNode(
    struct TreeNode *node,
    unsigned int data)
{
    if (node == NULL)
        return NULL;

    if (data == node->data)
        return node;

    if (data < node->data)
        return findNode(
            node->left,
            data
        );

    return findNode(
        node->right,
        data
    );
}


/* =========================
   FIND MINIMUM
   ========================= */

struct TreeNode *findMinNode(
    struct TreeNode *node)
{
    struct TreeNode *current = node;

    while (current != NULL &&
           current->left != NULL)
    {
        current = current->left;
    }

    return current;
}


/* =========================
   AVL DELETION
   ========================= */

struct TreeNode *deleteNodeRecursive(
    struct TreeNode *node,
    unsigned int data)
{
    int balance;

    if (node == NULL)
        return NULL;


    /*
       Normal BST deletion
    */

    if (data < node->data)
    {
        node->left =
            deleteNodeRecursive(
                node->left,
                data
            );
    }
    else if (data > node->data)
    {
        node->right =
            deleteNodeRecursive(
                node->right,
                data
            );
    }
    else
    {
        /*
           Node with zero or one child
        */

        if (node->left == NULL ||
            node->right == NULL)
        {
            struct TreeNode *child;

            if (node->left != NULL)
                child = node->left;
            else
                child = node->right;

            /*
               No child
            */

            if (child == NULL)
            {
                free(node);

                return NULL;
            }

            /*
               One child
            */

            {
                struct TreeNode *temp = node;

                node = child;

                free(temp);
            }
        }
        else
        {
            /*
               Two children

               Find inorder successor
            */

            struct TreeNode *successor;

            successor =
                findMinNode(node->right);

            node->data = successor->data;

            node->right =
                deleteNodeRecursive(
                    node->right,
                    successor->data
                );
        }
    }


    /*
       Update height
    */

    updateHeight(node);


    /*
       Check balance
    */

    balance = getBalance(node);


    /*
       LL CASE
    */

    if (balance > 1 &&
        getBalance(node->left) >= 0)
    {
        return rightRotate(node);
    }


    /*
       LR CASE
    */

    if (balance > 1 &&
        getBalance(node->left) < 0)
    {
        node->left =
            leftRotate(node->left);

        return rightRotate(node);
    }


    /*
       RR CASE
    */

    if (balance < -1 &&
        getBalance(node->right) <= 0)
    {
        return leftRotate(node);
    }


    /*
       RL CASE
    */

    if (balance < -1 &&
        getBalance(node->right) > 0)
    {
        node->right =
            rightRotate(node->right);

        return leftRotate(node);
    }

    return node;
}


void deleteNode(unsigned int data)
{
    if (findNode(root, data) == NULL)
    {
        printf("Node not found!\n");
        return;
    }

    root =
        deleteNodeRecursive(
            root,
            data
        );

    printf("Node deleted successfully.\n");
}


/* =========================
   UPDATE
   ========================= */

void updateNode(
    unsigned int oldData,
    unsigned int newData)
{
    if (findNode(root, oldData) == NULL)
    {
        printf("Old node not found!\n");
        return;
    }

    if (oldData == newData)
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
       Cannot directly change data in AVL.

       Delete old value and insert new value.
    */

    root =
        deleteNodeRecursive(
            root,
            oldData
        );

    root =
        insertNode(
            root,
            newData
        );

    printf("Node updated successfully.\n");
}


/* =========================
   PREORDER
   ========================= */

void preorder(struct TreeNode *node)
{
    if (node == NULL)
        return;

    printf("%u ", node->data);

    preorder(node->left);
    preorder(node->right);
}


/* =========================
   INORDER
   ========================= */

void inorder(struct TreeNode *node)
{
    if (node == NULL)
        return;

    inorder(node->left);

    printf("%u ", node->data);

    inorder(node->right);
}


/* =========================
   POSTORDER
   ========================= */

void postorder(struct TreeNode *node)
{
    if (node == NULL)
        return;

    postorder(node->left);
    postorder(node->right);

    printf("%u ", node->data);
}


/* =========================
   LEVEL ORDER
   ========================= */

void levelOrder()
{
    struct TreeNode *queue[100];

    int front = 0;
    int rear = 0;

    struct TreeNode *current;

    if (root == NULL)
        return;

    queue[rear++] = root;

    while (front < rear)
    {
        current = queue[front++];

        printf("%u ", current->data);

        if (current->left != NULL)
            queue[rear++] = current->left;

        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}


/* =========================
   DISPLAY
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
   FREE TREE
   ========================= */

void freeTree(struct TreeNode *node)
{
    if (node == NULL)
        return;

    freeTree(node->left);
    freeTree(node->right);

    free(node);
}


/* =========================
   MAIN
   ========================= */

int main()
{
    char input[100];

    unsigned int choice;
    unsigned int data;
    unsigned int oldData;
    unsigned int newData;

    while (1)
    {
        printf("\n==============================\n");
        printf("          AVL TREE MENU\n");
        printf("==============================\n");

        printf("1. Add Node\n");
        printf("2. Display Traversals\n");
        printf("3. Search Node\n");
        printf("4. Update Node\n");
        printf("5. Delete Node\n");
        printf("6. Exit\n");

        printf("==============================\n");

        printf("Enter your choice: ");

        if (fgets(input, sizeof(input), stdin) == NULL)
            continue;

        input[strcspn(input, "\n")] = '\0';

        if (!isValidUnsignedInt(input))
        {
            printf("Invalid choice!\n");
            continue;
        }

        choice =
            (unsigned int)strtoul(
                input,
                NULL,
                10
            );

        switch (choice)
        {
            case 1:

                data =
                    getUnsignedInt(
                        "Enter data: "
                    );

                addNode(data);

                break;


            case 2:

                displayTree();

                break;


            case 3:

                data =
                    getUnsignedInt(
                        "Enter data to search: "
                    );

                if (findNode(root, data) != NULL)
                    printf("Node found!\n");
                else
                    printf("Node not found!\n");

                break;


            case 4:

                oldData =
                    getUnsignedInt(
                        "Enter old data: "
                    );

                newData =
                    getUnsignedInt(
                        "Enter new data: "
                    );

                updateNode(
                    oldData,
                    newData
                );

                break;


            case 5:

                data =
                    getUnsignedInt(
                        "Enter data to delete: "
                    );

                deleteNode(data);

                break;


            case 6:

                freeTree(root);

                root = NULL;

                printf(
                    "Program exited successfully.\n"
                );

                return 0;


            default:

                printf(
                    "Invalid choice! Please select 1-6.\n"
                );
        }
    }

    return 0;
}