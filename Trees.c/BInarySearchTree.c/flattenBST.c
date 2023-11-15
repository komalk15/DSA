#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *newNode(int val);
struct node *insert(struct node *root, int val);
void Display(struct node *head);
struct node *flaten(struct node *root);
void inorderCalc(struct node *root, int arr[], int *index);


int main()
{
    int ch = 1;
    int val;
    struct node *root = NULL;

    while (ch)
    {
        printf("Enter the value: ");
        scanf("%d", &val);
        root = insert(root, val);

        printf("Enter 1 to continue or 0 to exit: ");
        scanf("%d", &ch);
    }

    flaten(root);
    Display(root);
    

    return 0;
}
void Display(struct node *head)
{
    while (head)
    {
        printf("%d-> ", head->data);
        head = head->right;
    }
    printf("\n");
}


void inorderCalc(struct node *root, int arr[], int *index)
{
    if (root == NULL)
    {
        return;
    }
    inorderCalc(root->left, arr, index);
    arr[(*index)++] = root->data;
    inorderCalc(root->right, arr, index);
}

struct node *flaten(struct node *root)
{
    int i;
    int max = 100;
    int arr[max];
    int index = 0;
    inorderCalc(root, arr, &index);

    struct node *newnode = newNode(arr[0]);
    struct node *curr = newnode;
    for (i = 1; i < max; i++)
    {
        struct node *temp = newNode(arr[i]);
        curr->right = temp;
        curr = temp;
    }
    curr->right = NULL;
    return newnode;
}


struct node *insert(struct node *root, int val)
{
    if (root == NULL)
    {
        return newNode(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    if (val >= root->data)
    {
        root->right = insert(root->right, val);
    }
    return root;
}

struct node *newNode(int val)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
