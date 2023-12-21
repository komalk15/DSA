

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int value);
struct node *create(struct node *root, int data);
void inorder(struct node *root);
int search(struct node *root, int);
struct node *minVal(struct node *root);
struct node *delete(struct node *root, int val);
int CountLeaf(struct node *root);
int max(int right, int left);
int height(struct node *root);
int countNodesRight(struct node *root);
int Kthsmallest(struct node *root, int i, int k);

int main()
{
    struct node *root = NULL;
    int value;
    int ch = 1;
    int n, c, x, i = 0, k;
    while (ch == 1)
    {
        printf("\nEnter the value:    ");
        scanf("%d", &value);
        root = create(root, value);
        printf("\nEnter  1 to continue or 0 to exit:  ");
        scanf("%d", &ch);
    }
    printf("\nInorder traversal of the root is :  ");
    inorder(root);
    while (1)
    {

        printf("\nEnter 1 to Search a particular key");
        printf("\nEnter 2 to Delete a node from the tree ");
        printf("\nEnter 3 to find total number of leaf nodes ");
        printf("\nEnter 4 to find height of a binary search tree ");
        printf("\nEnter 5 to count total number of nodes form right hand side of root node");
        printf("\nEnter 6 Kth largest element without doing any modification in Binary Search Tree");

        scanf("%d", &c);

        switch (c)
        {

        case 1:
            printf("\nEnter the value to search  :  ");
            scanf("%d", &n);
            search(root, n);
            if (search(root, n))
            {
                printf("\nValue is found");
            }
            else
            {
                printf("\nvalue is not found");
            }

            break;

        case 2:

            printf("\nEnter the key you want to delete: ");
            scanf("%d", &x);
            if (!search(root, x))
                printf("\nKey is not found\n");
            else
            {
                root = delete (root, x);
                printf("\nTree after deletion of node");
                inorder(root);
            }
            break;

        case 3:
            printf("\nThe total number of leaf nodes present in tree are %d", CountLeaf(root));
            break;

        case 4:
            printf("\nThe height of the tree is %d\n", height(root));
            break;

        case 5:
            printf("\nThe number of nodes in the right sub tree of root %d", countNodesRight(root->right));
            break;
        case 6:
            printf("\nEnter the value  :  ");
            scanf("%d", &k);
            printf("\n%d smallest number is : %d", k, Kthsmallest(root, i, k));
            break;
        default:
            printf("\nINVALID INPUT\n");
            break;
        }
    }
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
int search(struct node *root, int n)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == n)
    {

        return 1;
    }
    else if (n > root->data)
    {
        return search(root->right, n);
    }
    else
    {
        return search(root->left, n);
    }
}
struct node *create(struct node *root, int value)
{
    if (root == NULL)
    {
        return newNode(value);
    }
    if (value < root->data)
    {
        root->left = create(root->left, value);
    }
    if (value > root->data)
    {
        root->right = create(root->right, value);
    }
    return root;
}
struct node *minVal(struct node *root)
{
    struct node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
struct node *delete(struct node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == val)
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
            if (root->left != NULL && root->right != NULL)
            {
                int mini = minVal(root->right)->data;
                root->data = mini;
                root->right = delete (root->right, mini);
                return root;
            }
        }
    }
    else if (root->data > val)
    {
        root->left = delete (root->left, val);
        return root;
    }
    else
    {
        root->right = delete (root->right, val);
        return root;
    }
}
int CountLeaf(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    int left = CountLeaf(root->left);
    int right = CountLeaf(root->right);

    return left + right;
}
int max(int right, int left)
{
    if (right > left)
    {
        return right;
    }
    else
    {
        return left;
    }
}

int height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return 1 + max(right, left);
}
int countNodesRight(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + countNodesRight(root->right) + countNodesRight(root->left);
}
int Kthsmallest(struct node *root, int i, int k)
{

    if (root == NULL)
    {
        return -1;
    }
    int left = Kthsmallest(root->left, i, k);
    if (left != -1)
    {
        return left;
    }
    (i)++;
    if (i == k)
    {
        return root->data;
    }
    return Kthsmallest(root->right, i, k);
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