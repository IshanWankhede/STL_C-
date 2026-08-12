#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;

    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int value);

void preorder(struct TreeNode *root);
void inorder(struct TreeNode *root);
void postorder(struct TreeNode *root);

int main()
{
    struct TreeNode *root;

    root = createNode(10);

    (*root).left = createNode(20);
    (*root).right = createNode(30);

    (*(*root).left).left = createNode(40);
    (*(*root).left).right = createNode(50);

    (*(*root).right).right = createNode(60);

    printf("\nPreorder : ");
    preorder(root);

    printf("\nInorder : ");
    inorder(root);

    printf("\nPostorder : ");
    postorder(root);

    return 0;
}

struct TreeNode* createNode(int value)
{
    struct TreeNode *node;

    node = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    if(node == NULL)
    {
        printf("Memory Allocation Failed.\n");
        return NULL;
    }

    (*node).data = value;

    (*node).left = NULL;
    (*node).right = NULL;

    return node;
}

void preorder(struct TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }

    printf("%d ",(*root).data);

    preorder((*root).left);

    preorder((*root).right);
}

void inorder(struct TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }

    inorder((*root).left);

    printf("%d ",(*root).data);

    inorder((*root).right);
}

void postorder(struct TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }

    postorder((*root).left);

    postorder((*root).right);

    printf("%d ",(*root).data);
}