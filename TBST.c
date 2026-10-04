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
            return (unsigned int)strtoul(input, NULL, 10);
        }

        printf("Invalid input! Please enter a valid unsigned integer.\n");
    }
}


/* =========================
   CREATE NODE
   ========================= */

struct TreeNode *createNode(unsigned int data)
{
    struct TreeNode *newNode;

    newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    /*
       1 means right pointer is a thread.
       0 means right pointer is a real child.
    */
    newNode->rightThread = 1;

    return newNode;
}


/* =========================
   FIND INORDER SUCCESSOR
   ========================= */

struct TreeNode *inorderSuccessor(struct TreeNode *node)
{
    struct TreeNode *current;

    if (node == NULL)
        return NULL;

    /*
       If right is a thread,
       it directly points to successor.
    */
    if (node->rightThread == 1)
        return node->right;

    /*
       Otherwise find the leftmost
       node in the right subtree.
    */
    current = node->right;

    while (current != NULL &&
           current->left != NULL)
    {
        current = current->left;
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

    while (current->left != NULL)
    {
        current = current->left;
    }

    return current;
}


/* =========================
   INSERT NODE
   ========================= */

void addNode(unsigned int data)
{
    struct TreeNode *newNode;
    struct TreeNode *current;
    struct TreeNode *parent = NULL;

    newNode = createNode(data);

    if (newNode == NULL)
        return;

    /*
       Empty tree.
    */
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

        if (data == current->data)
        {
            printf("Duplicate value! Node not added.\n");

            free(newNode);

            return;
        }

        if (data < current->data)
        {
            if (current->left == NULL)
                break;

            current = current->left;
        }
        else
        {
            /*
               If rightThread is 1,
               right is not a child.
            */
            if (current->rightThread == 1)
                break;

            current = current->right;
        }
    }

    /*
       Insert on left.
    */
    if (data < parent->data)
    {
        newNode->left = NULL;

        /*
           New node's successor is parent.
        */
        newNode->right = parent;
        newNode->rightThread = 1;

        parent->left = newNode;
    }

    /*
       Insert on right.
    */
    else
    {
        /*
           New node takes parent's old
           inorder successor.
        */
        newNode->right = parent->right;
        newNode->rightThread = 1;

        parent->right = newNode;

        /*
           Parent's right is now a real child.
        */
        parent->rightThread = 0;
    }

    printf("Node added successfully.\n");
}


/* =========================
   SEARCH NODE
   ========================= */

struct TreeNode *findNode(unsigned int data)
{
    struct TreeNode *current = root;

    while (current != NULL)
    {
        if (data == current->data)
            return current;

        if (data < current->data)
        {
            current = current->left;
        }
        else
        {
            if (current->rightThread == 1)
                return NULL;

            current = current->right;
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
        printf("%u ", current->data);

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

    printf("%u ", node->data);

    /*
       Left is always a child.
    */
    if (node->left != NULL)
        preorder(node->left);

    /*
       Only traverse right if it is
       an actual child.
    */
    if (node->rightThread == 0 &&
        node->right != NULL)
    {
        preorder(node->right);
    }
}


/* =========================
   POSTORDER TRAVERSAL
   ========================= */

void postorder(struct TreeNode *node)
{
    if (node == NULL)
        return;

    if (node->left != NULL)
        postorder(node->left);

    if (node->rightThread == 0 &&
        node->right != NULL)
    {
        postorder(node->right);
    }

    printf("%u ", node->data);
}


/* =========================
   LEVEL ORDER TRAVERSAL
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
        {
            queue[rear++] = current->left;
        }

        /*
           Add right only if it is
           a real child.
        */
        if (current->rightThread == 0 &&
            current->right != NULL)
        {
            queue[rear++] = current->right;
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

void updateNode(unsigned int oldData,
                unsigned int newData)
{
    if (findNode(oldData) == NULL)
    {
        printf("Old node not found!\n");
        return;
    }

    if (oldData == newData)
    {
        printf("Old and new values are same.\n");
        return;
    }

    if (findNode(newData) != NULL)
    {
        printf("New value already exists!\n");
        return;
    }

    /*
       For a BST, we cannot simply change
       the data because it may break the
       BST ordering and threads.

       Therefore we rebuild the tree.
    */

    /*
       Save all values except oldData
       and rebuild would be one approach.

       For this simple implementation,
       delete + insert is used.
    */

    printf("Update in a threaded BST requires "
           "deletion and reinsertion.\n");

    printf("Use Delete and Add operations "
           "to change a value safely.\n");
}


/* =========================
   DELETE NODE
   ========================= */

void deleteNode(unsigned int data)
{
    struct TreeNode *current;
    struct TreeNode *parent = NULL;
    struct TreeNode *successor;
    struct TreeNode *successorParent;

    current = root;

    /*
       Find node and its parent.
    */
    while (current != NULL)
    {
        if (data == current->data)
            break;

        parent = current;

        if (data < current->data)
        {
            current = current->left;
        }
        else
        {
            if (current->rightThread == 1)
            {
                current = NULL;
            }
            else
            {
                current = current->right;
            }
        }
    }

    if (current == NULL)
    {
        printf("Node not found!\n");
        return;
    }


    /*
       CASE 1:
       Node has two real children.

       Replace data with inorder successor,
       then delete successor.
    */
    if (current->left != NULL &&
        current->rightThread == 0 &&
        current->right != NULL)
    {
        successorParent = current;
        successor = current->right;

        while (successor->left != NULL)
        {
            successorParent = successor;
            successor = successor->left;
        }

        current->data = successor->data;

        /*
           Delete successor.
           Successor cannot have a left child.
        */
        current = successor;
        parent = successorParent;
    }


    /*
       CASE 2:
       Node has only left child.
    */
    if (current->left != NULL &&
        current->rightThread == 1)
    {
        struct TreeNode *child = current->left;

        /*
           If deleting root.
        */
        if (parent == NULL)
        {
            root = child;
        }
        else if (parent->left == current)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
            parent->rightThread = 0;
        }

        /*
           Find rightmost node of left subtree
           and update its thread to current's
           successor.
        */
        {
            struct TreeNode *rightmost = child;

            while (rightmost->rightThread == 0 &&
                   rightmost->right != NULL)
            {
                rightmost = rightmost->right;
            }

            rightmost->right = current->right;
            rightmost->rightThread = 1;
        }

        free(current);

        printf("Node deleted successfully.\n");

        return;
    }


    /*
       CASE 3:
       Node has only right child.
    */
    if (current->left == NULL &&
        current->rightThread == 0 &&
        current->right != NULL)
    {
        struct TreeNode *child = current->right;

        if (parent == NULL)
        {
            root = child;
        }
        else if (parent->left == current)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
            parent->rightThread = 0;
        }

        free(current);

        printf("Node deleted successfully.\n");

        return;
    }


    /*
       CASE 4:
       Leaf node.
    */
    if (current->left == NULL &&
        current->rightThread == 1)
    {
        if (parent == NULL)
        {
            root = NULL;
        }
        else if (parent->left == current)
        {
            parent->left = NULL;
        }
        else
        {
            /*
               Parent's right pointer was pointing
               to current as a real child.

               Replace it with current's successor.
            */
            parent->right = current->right;
            parent->rightThread = 1;
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

    if (node->left != NULL)
        freeTree(node->left);

    if (node->rightThread == 0 &&
        node->right != NULL)
    {
        freeTree(node->right);
    }

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

        if (fgets(input, sizeof(input), stdin) == NULL)
            continue;

        input[strcspn(input, "\n")] = '\0';

        if (!isValidUnsignedInt(input))
        {
            printf("Invalid choice!\n");
            continue;
        }

        choice = (unsigned int)strtoul(input, NULL, 10);

        switch (choice)
        {
            case 1:

                data = getUnsignedInt("Enter data: ");

                addNode(data);

                break;


            case 2:

                displayTree();

                break;


            case 3:

                data = getUnsignedInt(
                    "Enter data to search: ");

                if (findNode(data) != NULL)
                    printf("Node found!\n");
                else
                    printf("Node not found!\n");

                break;


            case 4:

                oldData = getUnsignedInt(
                    "Enter old data: ");

                newData = getUnsignedInt(
                    "Enter new data: ");

                updateNode(oldData, newData);

                break;


            case 5:

                data = getUnsignedInt(
                    "Enter data to delete: ");

                deleteNode(data);

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