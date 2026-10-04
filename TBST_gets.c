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
    int rightThread;
};

struct TreeNode *root = NULL;


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

        /*
           Reset pointer every time because
           validation advances the pointer.
        */
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
   CREATE NODE
   ========================= */

struct TreeNode *createNode(unsigned int *data)
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

    (*newNode).data = *data;

    (*newNode).left = NULL;

    (*newNode).right = NULL;

    /*
       1 = right pointer is a thread
       0 = right pointer is a real child
    */
    (*newNode).rightThread = 1;

    return newNode;
}


/* =========================
   FIND INORDER SUCCESSOR
   ========================= */

struct TreeNode *inorderSuccessor(
    struct TreeNode *node)
{
    struct TreeNode *current;

    if (node == NULL)
        return NULL;

    if ((*node).rightThread == 1)
        return (*node).right;

    current = (*node).right;

    while (current != NULL &&
           (*current).left != NULL)
    {
        current = (*current).left;
    }

    return current;
}


/* =========================
   FIND MINIMUM NODE
   ========================= */

struct TreeNode *findMinNode()
{
    struct TreeNode *current;

    if (root == NULL)
        return NULL;

    current = root;

    while ((*current).left != NULL)
    {
        current = (*current).left;
    }

    return current;
}


/* =========================
   INSERT NODE
   ========================= */

void addNode(unsigned int *data)
{
    struct TreeNode *newNode;
    struct TreeNode *current;
    struct TreeNode *parent = NULL;

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

    while (current != NULL)
    {
        parent = current;

        if (*data == (*current).data)
        {
            printf(
                "Duplicate value! Node not added.\n"
            );

            free(newNode);

            return;
        }

        if (*data < (*current).data)
        {
            if ((*current).left == NULL)
                break;

            current = (*current).left;
        }
        else
        {
            if ((*current).rightThread == 1)
                break;

            current = (*current).right;
        }
    }

    /*
       Insert as left child.
    */
    if (*data < (*parent).data)
    {
        (*newNode).left = NULL;

        /*
           Parent becomes inorder successor.
        */
        (*newNode).right = parent;

        (*newNode).rightThread = 1;

        (*parent).left = newNode;
    }

    /*
       Insert as right child.
    */
    else
    {
        /*
           Parent's old thread becomes
           new node's thread.
        */
        (*newNode).right = (*parent).right;

        (*newNode).rightThread = 1;

        (*parent).right = newNode;

        /*
           Parent's right is now a real child.
        */
        (*parent).rightThread = 0;
    }

    printf("Node added successfully.\n");
}


/* =========================
   SEARCH NODE
   ========================= */

struct TreeNode *findNode(unsigned int *data)
{
    struct TreeNode *current = root;

    while (current != NULL)
    {
        if (*data == (*current).data)
            return current;

        if (*data < (*current).data)
        {
            current = (*current).left;
        }
        else
        {
            if ((*current).rightThread == 1)
                return NULL;

            current = (*current).right;
        }
    }

    return NULL;
}


/* =========================
   INORDER TRAVERSAL
   ========================= */

void inorder()
{
    struct TreeNode *current;

    current = findMinNode();

    while (current != NULL)
    {
        printf("%u ", (*current).data);

        current = inorderSuccessor(current);
    }
}


/* =========================
   PREORDER TRAVERSAL
   ========================= */

void preorder(struct TreeNode *node)
{
    if (node == NULL)
        return;

    printf("%u ", (*node).data);

    if ((*node).left != NULL)
        preorder((*node).left);

    if ((*node).rightThread == 0 &&
        (*node).right != NULL)
    {
        preorder((*node).right);
    }
}


/* =========================
   POSTORDER TRAVERSAL
   ========================= */

void postorder(struct TreeNode *node)
{
    if (node == NULL)
        return;

    if ((*node).left != NULL)
        postorder((*node).left);

    if ((*node).rightThread == 0 &&
        (*node).right != NULL)
    {
        postorder((*node).right);
    }

    printf("%u ", (*node).data);
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

        printf("%u ", (*current).data);

        if ((*current).left != NULL)
        {
            queue[rear++] = (*current).left;
        }

        /*
           IMPORTANT:
           A thread is NOT a child.
        */
        if ((*current).rightThread == 0 &&
            (*current).right != NULL)
        {
            queue[rear++] = (*current).right;
        }
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
    inorder();

    printf("\nPostorder   : ");
    postorder(root);

    printf("\nLevel Order : ");
    levelOrder();

    printf("\n");
}


/* =========================
   UPDATE NODE
   ========================= */

void updateNode(
    unsigned int *oldData,
    unsigned int *newData)
{
    if (findNode(oldData) == NULL)
    {
        printf("Old node not found!\n");
        return;
    }

    if (*oldData == *newData)
    {
        printf("Old and new values are same.\n");
        return;
    }

    if (findNode(newData) != NULL)
    {
        printf("New value already exists!\n");
        return;
    }

    printf(
        "For Threaded BST, use Delete followed by Add "
        "to safely change a value.\n"
    );
}


/* =========================
   DELETE NODE
   ========================= */

void deleteNode(unsigned int *data)
{
    struct TreeNode *current;
    struct TreeNode *parent = NULL;

    current = root;

    /*
       Find node.
    */
    while (current != NULL)
    {
        if (*data == (*current).data)
            break;

        parent = current;

        if (*data < (*current).data)
        {
            current = (*current).left;
        }
        else
        {
            if ((*current).rightThread == 1)
                current = NULL;
            else
                current = (*current).right;
        }
    }

    if (current == NULL)
    {
        printf("Node not found!\n");
        return;
    }


    /*
       TWO CHILDREN
    */
    if ((*current).left != NULL &&
        (*current).rightThread == 0 &&
        (*current).right != NULL)
    {
        struct TreeNode *successorParent = current;
        struct TreeNode *successor =
            (*current).right;

        while ((*successor).left != NULL)
        {
            successorParent = successor;
            successor = (*successor).left;
        }

        (*current).data = (*successor).data;

        current = successor;
        parent = successorParent;
    }


    /*
       ONLY LEFT CHILD
    */
    if ((*current).left != NULL &&
        (*current).rightThread == 1)
    {
        struct TreeNode *child =
            (*current).left;

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
            (*parent).rightThread = 0;
        }

        /*
           Find rightmost node in left subtree.
        */
        {
            struct TreeNode *rightmost = child;

            while ((*rightmost).rightThread == 0 &&
                   (*rightmost).right != NULL)
            {
                rightmost = (*rightmost).right;
            }

            /*
               Connect thread to current's successor.
            */
            (*rightmost).right =
                (*current).right;

            (*rightmost).rightThread = 1;
        }

        free(current);

        printf("Node deleted successfully.\n");

        return;
    }


    /*
       ONLY RIGHT CHILD
    */
    if ((*current).left == NULL &&
        (*current).rightThread == 0 &&
        (*current).right != NULL)
    {
        struct TreeNode *child =
            (*current).right;

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
            (*parent).rightThread = 0;
        }

        free(current);

        printf("Node deleted successfully.\n");

        return;
    }


    /*
       LEAF NODE
    */
    if ((*current).left == NULL &&
        (*current).rightThread == 1)
    {
        if (parent == NULL)
        {
            root = NULL;
        }
        else if ((*parent).left == current)
        {
            (*parent).left = NULL;
        }
        else
        {
            /*
               Restore parent's thread.
            */
            (*parent).right =
                (*current).right;

            (*parent).rightThread = 1;
        }

        free(current);

        printf("Node deleted successfully.\n");

        return;
    }
}


/* =========================
   FREE TREE
   ========================= */

void freeTree(struct TreeNode *node)
{
    if (node == NULL)
        return;

    if ((*node).left != NULL)
        freeTree((*node).left);

    if ((*node).rightThread == 0 &&
        (*node).right != NULL)
    {
        freeTree((*node).right);
    }

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
        printf(" THREADED BINARY SEARCH TREE\n");
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

        choice =
            (unsigned int)strtoul(
                input,
                NULL,
                10
            );

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
                    &(const char *){
                        "Enter data to search: "
                    }
                );

                if (findNode(&data) != NULL)
                    printf("Node found!\n");
                else
                    printf("Node not found!\n");

                break;


            case 4:

                oldData = getUnsignedInt(
                    &(const char *){
                        "Enter old data: "
                    }
                );

                newData = getUnsignedInt(
                    &(const char *){
                        "Enter new data: "
                    }
                );

                updateNode(
                    &oldData,
                    &newData
                );

                break;


            case 5:

                data = getUnsignedInt(
                    &(const char *){
                        "Enter data to delete: "
                    }
                );

                deleteNode(&data);

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