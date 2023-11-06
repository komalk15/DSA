#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data; 
    struct node *left, *right;
};
struct node *solve(int arr[], int pre[], int *preorderIndex, int inorderStart, int inorderEnd, int n);
int findPosition(int arr[], int element, int n);
void preorder(struct node *root);
void postorder(struct node *root);
void inorder(struct node *root);
int main()
{
    int preorderIndex = 0;
    int arr[11] = {8, 4, 10, 9, 11, 2, 5, 1, 6, 3, 7};
    int pre[11] = {1, 2, 4, 8, 9, 10, 11, 5, 3, 6, 7};

    int n = sizeof(arr) / sizeof(arr[0]);
    struct node *root = solve(arr, pre, &preorderIndex, 0, n - 1, n);
    printf("\nPreorder is :   ");
    preorder(root);
    printf("\ninorder is :   ");
    inorder(root);
    printf("\nPostorder is :   ");
    postorder(root);
    return 0;
}
struct node *solve(int arr[], int pre[], int *index, int inorderStart, int inorderEnd, int n)
{
    if (*index >= n || inorderStart > inorderEnd)
    {
        return NULL;
    }
    int element = pre[(*index)++];
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = element;
    int pos = findPosition(arr, element, n);
    root->left = solve(arr, pre, index, inorderStart, pos - 1, n);
    root->right = solve(arr, pre, index, pos + 1, inorderEnd, n);
    return root;
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


int findPosition(int arr[], int element, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1; 
}
