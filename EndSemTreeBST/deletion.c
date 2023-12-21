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

struct node *deletion(struct node *root, int key);

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
        printf("Enter 1 to continue and 0 to exit");
        scanf("%d", &ch);
    }
    preorder(root);
    

    int key;
    printf("\nEnter the key you want to delete");
    scanf("%d", &key);
    root = deletion(root, key);
    printf("\nInorder traversal:    ");
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
struct node * minval(struct node *node)
{
    while(node->left!=NULL)
    {
        node=node->left;
    }
    return node;
}

struct node *deletion(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key > root->data)
    {
        root->right = deletion(root->right, key);
    }
    else if (key <root->data)
    {
        root->left = deletion(root->left, key);
    }
    else 
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        else if (root->left == NULL && root->right != NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else
        {
            int mini=minval(root->right)->data;
            root->data=mini;
            root->right=deletion(root->right,mini);

        }
    }
    return root;
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

