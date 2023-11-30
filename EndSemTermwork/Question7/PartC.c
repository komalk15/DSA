// Q7. W.A.P. Find total number of leaf nodes
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *newNode(int val);
struct node *insert(struct node *root, int val);
void inorder(struct node *root);
void preorder(struct node *root);
int  CountLeaf(struct node *root);
void postorder(struct node *root);

int main()
{
    int ch = 1;
    int val;
    struct node *root = NULL; // Initialize root to NULL

    while (ch == 1)
    {
        printf("Enter the value: ");
        scanf("%d", &val);
        root = insert(root, val);

        printf("Enter 1 to continue or 0 to exit: ");
        scanf("%d", &ch);
    }

    printf("\nInorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("The Number of leaf nodes are : %d",CountLeaf(root));

    return 0;
}
int  CountLeaf(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    int left = CountLeaf(root->left);
    int right = CountLeaf(root->right);

    return left + right;
}

struct node *newNode(int val)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node *insert(struct node *root, int val)
{
    if (root == NULL)
    {
        return newNode(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }

    return root;
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
