#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

typedef struct node
{
    int data;
    struct node *left, *right;
} node;

node *insert(node *root, int data)
{
    if (root == NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else if (root->data > data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

int isEmpty(int top)
{
    return (top == -1) ? 1 : 0;
}

void inorderIterative(node *root)
{
    node *stack[MAX_SIZE];
    int top = -1;
    node *current = root;
    while (current || !isEmpty(top))
    {
        while (current != NULL)
        {
            stack[top++] = current;
            current = current->left;
        }
        current = stack[--top];
        printf("%d ", current->data);
        current = current->right;
    }
}

void preorderIterative(node *root)
{
    if (root == NULL)
    {
        return;
    }
    node *stack[MAX_SIZE];
    int top = -1;
    stack[++top] = root;
    while (top != -1)
    {
        node *currNode = stack[top--];
        printf("%d ", currNode->data);
        if (currNode->right)
        {
            stack[++top] = currNode->right;
        }
        if (currNode->left)
        {
            stack[++top] = currNode->left;
        }
    }
}

void postorderIterative(node *root)
{
    if (root == NULL)
    {
        return;
    }
    node *stack1[MAX_SIZE];
    int top1 = -1;
    node *stack2[MAX_SIZE];
    int top2 = -1;
    stack1[++top1] = root;
    while (!isEmpty(top1))
    {
        node *currNode = stack1[top1--];
        stack2[++top2] = currNode;
        if (currNode->right)
        {
            stack1[++top1] = currNode->right;
        }
        if (currNode->left)
        {
            stack1[++top1] = currNode->left;
        }
    }
    while (!isEmpty(top2))
    {
        node *curr = stack2[top2--];
        printf("%d ", curr->data);
    }
}

void kthsmallest(node *root, int k, int *result, int *cnt)
{
    if (root == NULL || *cnt > k)
    {
        return;
    }
    kthsmallest(root->left, k, result, cnt);
    (*cnt)++;
    if (*cnt == k)
    {
        *result = root->data;
    }
    kthsmallest(root->right, k, result, cnt);
}

void getNumberOfNodes(node *root, int *cnt)
{
    if (root == NULL)
    {
        return;
    }

    getNumberOfNodes(root->left, cnt);
    (*cnt)++;
    getNumberOfNodes(root->right, cnt);
}

void kthlargest(node *root, int k, int *result, int *cnt)
{
    int n = 0;

    getNumberOfNodes(root, &n);
    // kth largest = (n-k+1)th smallest where n = total nodes
    kthsmallest(root, n - k + 1, result, cnt);
}

int main()
{
    int val;
    node *root = NULL;
    printf("Enter data and -1 to stop: ");
    do
    {
        scanf("%d", &val);
        if (val == -1)
            break;
        root = insert(root, val);
    } while (val != -1);

    printf("Inorder Iteratively: ");
    inorderIterative(root);
    printf("\nPreorder Iteratively: ");
    preorderIterative(root);
    printf("\nPostorder Iteratively: ");
    postorderIterative(root);

    int cnt = 0;
    int k;
    printf("\nEnter the value of k: ");
    scanf("%d", &k);
    int result = 0;
    kthsmallest(root, k, &result, &cnt);
    printf("The %d smallest element is: %d\n", k, result);

    // reset count
    cnt = 0;
    kthlargest(root, k, &result, &cnt);
    printf("The %d largest element is: %d\n", k, result);

    return 0;
}
