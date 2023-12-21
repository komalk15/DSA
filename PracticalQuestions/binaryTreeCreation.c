#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *right;
    struct node *left;
};
void inorder(struct node *root);
struct node *create(struct node *root);
int main()
{
    struct node *root = create(root);
    printf("Inorder traversal is:   ");
    inorder(root);
    return 0;
}
struct node *create(struct node *root)
{
    int x;

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter 1 to continue and -1 to exit");
    scanf("%d", &x);
    if (x == -1)
    {
        return 0;
    }
    newnode->data = x;
    printf("Enter the left child of %d", x);
    newnode->left = create(root->left);
    printf("Enter the right child of %d", x);
    newnode->right = create(root->right);
    return newnode;
}
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}