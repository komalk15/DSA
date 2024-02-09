// Count no of nodes having at least 1 child

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
int countn(struct node *root);

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
    printf("\nThe number of root nodes having at least one child is %d:   ", countn(root));

    return 0;
}
int countn(struct node *root)
{
    int count = 0;
    if (root == NULL)
    {
        return 0;
    }
    if (root->left != NULL || root->right != NULL)
    {
        count++;
    }
    
    count = count + countn(root->left);
    count = count + countn(root->right);
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
