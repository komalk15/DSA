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
struct node *flattenBst(struct node *root);
void preorder(struct node *root);

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
        printf("Enter 1 to continue and 0 to exit:  ");
        scanf("%d", &ch);
    }
    preorder(root);
    printf("Binary tree after being flatten is");
    struct node *ans=flattenBst(root);
    preorder(root);
   

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
void inorder(struct node *root, int arr[], int *index)
{
    if (root == NULL)
        return;

    inorder(root->left, arr, index);
    arr[(*index)++] = root->data;
    inorder(root->right, arr, index);
}

struct node *flattenBst(struct node *root)
{
    int size = 20;
    int arr[size];
    int index=0;
    inorder(root,arr,&index);
    
    struct node *newnode=newNode(arr[0]);
    struct node *curr=newnode;
    for(int i=1;i<index;i++)
    {
        struct node *temp=newNode(arr[i]);
        curr->right=temp;
        curr=temp;
    }
    curr->left=NULL;
    curr->right=NULL;
   return newnode;
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
