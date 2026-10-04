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

    value = strtoul(
        start,
        &endPtr,
        10
    );

    if (errno == ERANGE ||
        value > UINT_MAX)
    {
        return 0;
    }

    if (*endPtr != '\0')
    {
        return 0;
    }

    return 1;
}


unsigned int getUnsignedInt(const char **message)
{
    char input[100];
    const char *inputPtr;

    while (1)
    {
        printf("%s", *message);

        if (fgets(
                input,
                sizeof(input),
                stdin
            ) == NULL)
        {
            exit(1);
        }

        input[strcspn(
            input,
            "\n"
        )] = '\0';

        inputPtr = input;

        if (isValidUnsignedInt(&inputPtr))
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
   QUEUE
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


/* =========================
   CREATE NODE
   ========================= */

struct TreeNode *createNode(
    unsigned int *data)
{
    struct TreeNode *newNode;

    newNode =
        (struct TreeNode *)malloc(
            sizeof(struct TreeNode)
        );

    if (newNode == NULL)
    {
        printf(
            "Memory Allocation Failed.\n"
        );

        exit(1);
    }

    (*newNode).data = *data;

    (*newNode).left = NULL;

    (*newNode).right = NULL;

    return newNode;
}


/* =========================
   INSERT NODE
   ========================= */

void addNode(unsigned int *data)
{
    struct TreeNode *current;

    if (root == NULL)
    {
        root =
            createNode(data);

        printf(
            "Node %u added successfully!\n",
            *data
        );

        return;
    }

    current = root;

    while (1)
    {
        if (*data == (*current).data)
        {
            printf(
                "Node %u already exists in the BST!\n",
                *data
            );

            return;
        }

        if (*data < (*current).data)
        {
            if ((*current).left == NULL)
            {
                (*current).left =
                    createNode(data);

                printf(
                    "Node %u added successfully!\n",
                    *data
                );

                return;
            }

            current =
                (*current).left;
        }
        else
        {
            if ((*current).right == NULL)
            {
                (*current).right =
                    createNode(data);

                printf(
                    "Node %u added successfully!\n",
                    *data
                );

                return;
            }

            current =
                (*current).right;
        }
    }
}


/* =========================
   SEARCH NODE
   ========================= */

struct TreeNode *findNode(
    struct TreeNode **node,
    unsigned int *data)
{
    if (*node == NULL)
    {
        return NULL;
    }

    if (*data == (**node).data)
    {
        return *node;
    }

    if (*data < (**node).data)
    {
        return findNode(
            &((**node).left),
            data
        );
    }

    return findNode(
        &((**node).right),
        data
    );
}


/* =========================
   PREORDER
   ========================= */

void preorder(struct TreeNode **node)
{
    if (*node == NULL)
    {
        return;
    }

    printf(
        "%u ",
        (**node).data
    );

    preorder(
        &((**node).left)
    );

    preorder(
        &((**node).right)
    );
}


/* =========================
   INORDER
   ========================= */

void inorder(struct TreeNode **node)
{
    if (*node == NULL)
    {
        return;
    }

    inorder(
        &((**node).left)
    );

    printf(
        "%u ",
        (**node).data
    );

    inorder(
        &((**node).right)
    );
}


/* =========================
   POSTORDER
   ========================= */

void postorder(struct TreeNode **node)
{
    if (*node == NULL)
    {
        return;
    }

    postorder(
        &((**node).left)
    );

    postorder(
        &((**node).right)
    );

    printf(
        "%u ",
        (**node).data
    );
}


/* =========================
   LEVEL ORDER
   ========================= */

void levelOrder()
{
    struct TreeNode *current;

    if (root == NULL)
    {
        return;
    }

    resetQueue();

    enqueue(&root);

    while (!isQueueEmpty())
    {
        current = dequeue();

        printf(
            "%u ",
            (*current).data
        );

        if ((*current).left != NULL)
        {
            enqueue(
                &((*current).left)
            );
        }

        if ((*current).right != NULL)
        {
            enqueue(
                &((*current).right)
            );
        }
    }
}


/* =========================
   FIND MINIMUM
   ========================= */

struct TreeNode *findMinNode(
    struct TreeNode **node)
{
    struct TreeNode *current;

    current = *node;

    while ((*current).left != NULL)
    {
        current =
            (*current).left;
    }

    return current;
}


/* =========================
   DELETE NODE
   ========================= */

struct TreeNode *deleteNodeRecursive(
    struct TreeNode **node,
    unsigned int *data)
{
    struct TreeNode *successor;
    struct TreeNode *temp;

    if (*node == NULL)
    {
        return NULL;
    }


    /* Search left */

    if (*data < (**node).data)
    {
        (**node).left =
            deleteNodeRecursive(
                &((**node).left),
                data
            );
    }


    /* Search right */

    else if (*data > (**node).data)
    {
        (**node).right =
            deleteNodeRecursive(
                &((**node).right),
                data
            );
    }


    /* Node found */

    else
    {
        /*
           CASE 1:
           No child
        */

        if ((**node).left == NULL &&
            (**node).right == NULL)
        {
            free(*node);

            return NULL;
        }


        /*
           CASE 2:
           Only right child
        */

        if ((**node).left == NULL)
        {
            temp =
                (**node).right;

            free(*node);

            return temp;
        }


        /*
           CASE 2:
           Only left child
        */

        if ((**node).right == NULL)
        {
            temp =
                (**node).left;

            free(*node);

            return temp;
        }


        /*
           CASE 3:
           Two children
        */

        successor =
            findMinNode(
                &((**node).right)
            );

        (**node).data =
            (*successor).data;

        (**node).right =
            deleteNodeRecursive(
                &((**node).right),
                &((*successor).data)
            );
    }

    return *node;
}


void deleteNode(unsigned int *data)
{
    struct TreeNode *found;

    if (root == NULL)
    {
        printf(
            "Tree is empty!\n"
        );

        return;
    }

    found =
        findNode(
            &root,
            data
        );

    if (found == NULL)
    {
        printf(
            "Node %u not found!\n",
            *data
        );

        return;
    }

    root =
        deleteNodeRecursive(
            &root,
            data
        );

    printf(
        "Node %u deleted successfully!\n",
        *data
    );
}


/* =========================
   UPDATE NODE
   ========================= */

void updateNode(
    unsigned int *oldData,
    unsigned int *newData)
{
    struct TreeNode *found;

    found =
        findNode(
            &root,
            oldData
        );

    if (found == NULL)
    {
        printf(
            "Node %u not found!\n",
            *oldData
        );

        return;
    }

    if (*oldData == *newData)
    {
        printf(
            "Old value and new value are same.\n"
        );

        return;
    }

    found =
        findNode(
            &root,
            newData
        );

    if (found != NULL)
    {
        printf(
            "Node %u already exists!\n",
            *newData
        );

        return;
    }

    /*
       Delete old value and insert
       new value to preserve BST.
    */

    deleteNode(oldData);

    addNode(newData);

    printf(
        "Node %u updated to %u successfully!\n",
        *oldData,
        *newData
    );
}


/* =========================
   DISPLAY TREE
   ========================= */

void displayTree()
{
    if (root == NULL)
    {
        printf(
            "\nTree is empty!\n"
        );

        return;
    }

    printf(
        "\nPreorder    : "
    );

    preorder(&root);

    printf(
        "\nInorder     : "
    );

    inorder(&root);

    printf(
        "\nPostorder   : "
    );

    postorder(&root);

    printf(
        "\nLevel Order : "
    );

    levelOrder();

    printf("\n");
}


/* =========================
   FREE TREE
   ========================= */

void freeTree(
    struct TreeNode **node)
{
    if (*node == NULL)
    {
        return;
    }

    freeTree(
        &((**node).left)
    );

    freeTree(
        &((**node).right)
    );

    free(*node);

    *node = NULL;
}


/* =========================
   MAIN
   ========================= */

int main()
{
    char input[100];

    const char *inputPtr;

    unsigned int choice;
    unsigned int data;
    unsigned int oldData;
    unsigned int newData;

    while (1)
    {
        printf("\n");

        printf(
            "=================================\n"
        );

        printf(
            "     BINARY SEARCH TREE MENU\n"
        );

        printf(
            "=================================\n"
        );

        printf(
            "1. Add Node\n"
        );

        printf(
            "2. Display Traversals\n"
        );

        printf(
            "3. Search Node\n"
        );

        printf(
            "4. Update Node\n"
        );

        printf(
            "5. Delete Node\n"
        );

        printf(
            "6. Exit\n"
        );

        printf(
            "=================================\n"
        );

        printf(
            "Enter your choice: "
        );

        if (fgets(
                input,
                sizeof(input),
                stdin
            ) == NULL)
        {
            break;
        }

        input[strcspn(
            input,
            "\n"
        )] = '\0';

        inputPtr = input;

        if (!isValidUnsignedInt(
                &inputPtr
            ))
        {
            printf(
                "Invalid input! Please enter a valid number.\n"
            );

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
                        "Enter data to add: "
                    );

                addNode(&data);

                break;


            case 2:

                displayTree();

                break;


            case 3:

                data =
                    getUnsignedInt(
                        "Enter data to search: "
                    );

                if (findNode(
                        &root,
                        &data
                    ) != NULL)
                {
                    printf(
                        "Node %u found in the BST!\n",
                        data
                    );
                }
                else
                {
                    printf(
                        "Node %u not found!\n",
                        data
                    );
                }

                break;


            case 4:

                oldData =
                    getUnsignedInt(
                        "Enter old value: "
                    );

                newData =
                    getUnsignedInt(
                        "Enter new value: "
                    );

                updateNode(
                    &oldData,
                    &newData
                );

                break;


            case 5:

                data =
                    getUnsignedInt(
                        "Enter data to delete: "
                    );

                deleteNode(&data);

                break;


            case 6:

                freeTree(&root);

                printf(
                    "\nTree Freed From Memory.\n"
                );

                printf(
                    "Program exited successfully!\n"
                );

                return 0;


            default:

                printf(
                    "Invalid Choice! Please select 1-6.\n"
                );
        }
    }

    return 0;
}