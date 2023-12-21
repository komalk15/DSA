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
int kthSmallestElement(struct node *root, int i, int k);

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

    int i = 0;
    int k;
    printf("Enter the value of k");
    scanf("%d", &k);
    int ans = kthSmallestElement(root, i, k);
    printf("Kth Smallest Element is %d: ", ans);

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
int kthSmallestElement(struct node *root, int i, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    int left = kthSmallestElement(root->left, i, k);
    if (left != -1)
    {
        return left;
    }
    i++;
    if (i == k)
    {
        return root->data;
    }
    int right = kthSmallestElement(root->right, i, k);
    return right;
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