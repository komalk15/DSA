#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *solve(int arr[], int pre[], int *postorderIndex, int inorderStart, int inorderEnd, int n);
int findPosition(int arr[], int element, int n);
void preorder(struct node *root);
void postorder(struct node *root);
void inorder(struct node *root);
int main()
{

    int post[11] = {9, 1, 2, 12, 7, 5, 3, 11, 4, 8};
    int arr[11]  = {9, 5, 1, 7,2, 12, 8, 4, 3, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int postorderIndex = n - 1;
    struct node *root = solve(arr, post, &postorderIndex, 0, n - 1, n);
    printf("\nPreorder is :   ");
    preorder(root);
    printf("\ninorder is :   ");
    inorder(root);
    printf("\nPostorder is :   ");
    postorder(root);
    return 0;
}
struct node *solve(int arr[], int post[], int *index, int inorderStart, int inorderEnd, int n)
{
    if (*index < 0 || inorderStart > inorderEnd)
    {
        return NULL;
    }
    int element = post[(*index)--];
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = element;
    int pos = findPosition(arr, element, n);
    root->right = solve(arr, post, index, pos + 1, inorderEnd, n);
    root->left = solve(arr, post, index, inorderStart, pos - 1, n);
    return root;
}
int findPosition(int arr[], int element, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
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

    inorder(root->left);
    printf("%d->", root->data);
    inorder(root->right);
}
