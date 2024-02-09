#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(struct node *root, int value);
struct node *newNode(int data);
bool validateBST(struct node *root, int min, int max);
void inorder(struct node *root);

    int main()
{

    int ch = 1;
    int value;
    struct node *root = NULL;
    while (ch == 1)
    {
        printf("Enter the data");
        scanf("%d", &value);
        root = create(root, value);
        printf("Enter 1 to continue and 0 to exit");
        scanf("%d", &ch);
    }
    printf("\nInorder traversal:    ");
    inorder(root);
    if (validateBST(root,INT_MIN,INT_MAX))
    {
        printf("\nIts a bst");
    }
    else
    {
        printf("\nIts not a bst");
    }

    return 0;
}
struct node *newNode(int value)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
bool validateBST(struct node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data >= max || root->data <= min)
    {
        return false;
    }
    return validateBST(root->left, INT_MIN, root->data) && validateBST(root->right, root->data, INT_MAX);
}

struct node *create(struct node *root, int value)
{
    if (root == NULL)
    {
        return newNode(value);
    }
    else if (value < root->data)
    {
        root->left = create(root->left, value);
    }
    else
    {
        root->right = create(root->right, value);
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
    printf("%d->", root->data);
    inorder(root->right);
}
