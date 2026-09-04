#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct TreeNode {
    unsigned int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *root = NULL;

struct TreeNode *queue[100];
int front = 0;
int rear = 0;

void resetQueue() {
    front = 0;
    rear = 0;
}

int isQueueEmpty() {
    return front == rear;
}

int isQueueFull() {
    return rear == 100;
}

void enqueue(struct TreeNode *node) {
    if (isQueueFull()) {
        printf("Queue is full!\n");
        return;
    }

    queue[rear] = node;
    rear++;
}

struct TreeNode *dequeue() {
    if (isQueueEmpty()) {
        return NULL;
    }

    struct TreeNode *node = queue[front];
    front++;

    return node;
}

int isNumber(char str[]) {
    int i = 0;

    if (str[0] == '\0') {
        return 0;
    }

    while (str[i] != '\0') {
        if (!isdigit((unsigned char)str[i])) {
            return 0;
        }

        i++;
    }

    return 1;
}

unsigned int getUnsignedInt(char message[]) {
    char input[100];

    while (1) {
        printf("%s", message);

        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = '\0';

        if (isNumber(input)) {
            return (unsigned int)strtoul(input, NULL, 10);
        }

        printf("Invalid input! Please enter a positive number.\n");
    }
}

struct TreeNode *createNode(unsigned int data) {
    struct TreeNode *newNode;

    newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct TreeNode *findNode(struct TreeNode *node, unsigned int data) {
    if (node == NULL) {
        return NULL;
    }

    if (node->data == data) {
        return node;
    }

    struct TreeNode *found;

    found = findNode(node->left, data);

    if (found != NULL) {
        return found;
    }

    return findNode(node->right, data);
}

void addNode(unsigned int data) {
    struct TreeNode *newNode = createNode(data);

    if (root == NULL) {
        root = newNode;

        printf("Node %u added successfully!\n", data);

        return;
    }

    resetQueue();

    enqueue(root);

    while (!isQueueEmpty()) {
        struct TreeNode *current = dequeue();

        if (current->left == NULL) {
            current->left = newNode;

            printf("Node %u added successfully!\n", data);

            return;
        }

        enqueue(current->left);

        if (current->right == NULL) {
            current->right = newNode;

            printf("Node %u added successfully!\n", data);

            return;
        }

        enqueue(current->right);
    }
}

void preorder(struct TreeNode *node) {
    if (node == NULL) {
        return;
    }

    printf("%u ", node->data);

    preorder(node->left);
    preorder(node->right);
}

void inorder(struct TreeNode *node) {
    if (node == NULL) {
        return;
    }

    inorder(node->left);

    printf("%u ", node->data);

    inorder(node->right);
}

void postorder(struct TreeNode *node) {
    if (node == NULL) {
        return;
    }

    postorder(node->left);
    postorder(node->right);

    printf("%u ", node->data);
}

void updateNode(unsigned int oldData, unsigned int newData) {
    struct TreeNode *node;

    node = findNode(root, oldData);

    if (node == NULL) {
        printf("Node %u not found!\n", oldData);
        return;
    }

    node->data = newData;

    printf(
        "Node %u updated to %u successfully!\n",
        oldData,
        newData
    );
}

struct TreeNode *findDeepestNode() {
    struct TreeNode *current = NULL;

    resetQueue();

    enqueue(root);

    while (!isQueueEmpty()) {
        current = dequeue();

        if (current->left != NULL) {
            enqueue(current->left);
        }

        if (current->right != NULL) {
            enqueue(current->right);
        }
    }

    return current;
}

void deleteDeepestNode(struct TreeNode *deepest) {
    struct TreeNode *current;

    if (root == NULL || deepest == NULL) {
        return;
    }

    resetQueue();

    enqueue(root);

    while (!isQueueEmpty()) {
        current = dequeue();

        if (current->left != NULL) {
            if (current->left == deepest) {
                current->left = NULL;

                free(deepest);

                return;
            }

            enqueue(current->left);
        }

        if (current->right != NULL) {
            if (current->right == deepest) {
                current->right = NULL;

                free(deepest);

                return;
            }

            enqueue(current->right);
        }
    }
}

void deleteNode(unsigned int data) {
    struct TreeNode *target;
    struct TreeNode *deepest;

    if (root == NULL) {
        printf("Tree is empty!\n");
        return;
    }

    target = findNode(root, data);

    if (target == NULL) {
        printf("Node %u not found!\n", data);
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        free(root);

        root = NULL;

        printf("Node %u deleted successfully!\n", data);

        return;
    }

    deepest = findDeepestNode();

    target->data = deepest->data;

    deleteDeepestNode(deepest);

    printf("Node %u deleted successfully!\n", data);
}

void displayTree() {
    if (root == NULL) {
        printf("\nTree is empty!\n");
        return;
    }

    printf("\nPreorder : ");
    preorder(root);

    printf("\nInorder  : ");
    inorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\n");
}

void freeTree(struct TreeNode *node) {
    if (node == NULL) {
        return;
    }

    freeTree(node->left);
    freeTree(node->right);

    free(node);
}

int main() {
    unsigned int choice;
    unsigned int data;
    unsigned int oldData;
    unsigned int newData;

    while (1) {
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

        choice = getUnsignedInt("Enter your choice: ");

        if (choice == 1) {
            data = getUnsignedInt("Enter data to add: ");
            addNode(data);
        }
        else if (choice == 2) {
            displayTree();
        }
        else if (choice == 3) {
            data = getUnsignedInt("Enter data to search: ");

            if (findNode(root, data) != NULL) {
                printf("Node %u found in the tree!\n", data);
            }
            else {
                printf("Node %u not found!\n", data);
            }
        }
        else if (choice == 4) {
            oldData = getUnsignedInt("Enter old value: ");
            newData = getUnsignedInt("Enter new value: ");

            updateNode(oldData, newData);
        }
        else if (choice == 5) {
            data = getUnsignedInt("Enter data to delete: ");

            deleteNode(data);
        }
        else if (choice == 6) {
            freeTree(root);

            root = NULL;

            printf("\nProgram exited successfully!\n");

            break;
        }
        else {
            printf("Invalid choice! Please select 1-6.\n");
        }
    }

    return 0;
}
