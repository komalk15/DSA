#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
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
int height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    // return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    if (left > right)
    {
        return left + 1;
    }
    else
    {
        return right + 1;
    }
}

int main()
{

    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Preorder is :   ");
    preorder(root);
    printf("\n");

    printf("Inorder is :   ");
    inorder(root);
    printf("\n");

    printf("Postorder is :   ");
    postorder(root);
    printf("\n");
    int h=height(root);
    printf("%d",h);

    return 0;
}
