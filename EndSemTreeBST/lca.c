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
struct node * LCA(struct node *root, int p, int q);
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
    int node1=1;
    int node2=3;
    struct node *ans=LCA(root,node1,node2);
    printf("\nLowest common ansector is: %d",ans->data);
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

struct node * LCA(struct node *root, int p, int q)
{
    if (root == NULL )
    {
        return NULL; 
    }
    if (p < root->data && q < root->data)
    {
        return LCA(root->left, p, q);
    }
    else if (p > root->data && q> root->data)
    {
        return LCA(root->right, p, q);
    }
    else
    {
        return root;
    }
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
