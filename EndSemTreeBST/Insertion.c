#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(struct node *root, int value);
struct node *newNode(int data);
struct node *insertion(struct node *root, int n);

void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);

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
    int n;
    printf("Enter the data you want to insert");
    scanf("%d", &n);
    root = insertion(root, n);
    

    printf("\nInorder traversal:    ");
    inorder(root);
    printf("\npreorder traversal:   ");
    preorder(root);
    printf("\npostorder traversal:  ");
    postorder(root);
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
struct node *insertion(struct node *root, int n)
{

    if (root == NULL)
    {
        return newNode(n);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, n);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, n);
    }

    return root;
}
void delete(struct node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    id(key>root->val)
    {
        root->right=deleteNode(root->right,key)
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
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d->", root->data);
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
    printf("%d->", root->data);
}