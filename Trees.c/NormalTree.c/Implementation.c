
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
void preorder(struct node *root);
void postorder(struct node *root);
void inorder(struct node *root);
struct node *create(struct node *root);

struct node *create(struct node *root)
{
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data ,or enter -1 to exit:    ");
    scanf("%d", &x);
    if (x == -1)
    {
        return 0;
    }
    newnode->data = x;
    printf("Enter left child of %d", x);
    newnode->left = create(root->left);
    printf("Enter right child of %d", x);
    newnode->right = create(root->right);
    return newnode;
}
void preorder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    printf("%d->", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if (root == 0)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d->", root->data);
}
void inorder(struct node *root)
{
    if (root == 0)
    {
        return;
    }

    printf("%d->", root->data);
    inorder(root->left);
    inorder(root->right);
}
int main()
{
    struct node *root = create(root);
    printf("Preorder is :   ");
    preorder(root);
    printf("inorder is :   ");
    inorder(root);
    printf("Postorder is :   ");
    postorder(root);

    return 0;
}