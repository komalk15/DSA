// 3.count the no.  of nodes which are multiple of k in a BST

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
#include <stdio.h>
#include <stdlib.h>
struct node *
create(struct node *root, int value);
void inorder(struct node *root);
struct node *newNode(int value);
int multiple(struct node *root, int k);
int main()
{
    int value;
    int k;
    int ch = 1;
    struct node *root = NULL;
    while (ch == 1)
    {
        printf("\nEnter the value:  ");
        scanf("%d", &value);
        root = create(root, value);
        printf("\nPress 1 to continue and 0 to exit:    ");
        scanf("%d", &ch);
    }
    printf("\nThe inorder traversal of the tree is:   ");
    inorder(root);
    printf("\nThe the value of k whoes multiple you want to calculate:  ");
    scanf("%d", &k);
    int ans = multiple(root, k);
    printf("\nThe number of nodes having k as multiple are: %d ", ans);
    return 0;
}
int multiple(struct node *root, int k)
{
    int count = 0;
    if (root == NULL)
    {
        return 0;
    }
    count = count + multiple(root->left, k);
    count = count + multiple(root->right, k);
    if ((root->data) % k == 0)

    {
        count++;
    }
    return count;
}
struct node *newNode(int value)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = value;
    return newnode;
}
struct node *create(struct node *root, int value)
{
    if (root == NULL)
    {
        return newNode(value);
    }
    if (root->data > value)
    {
        root->left = create(root->left, value);
    }
    if (root->data < value)
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
