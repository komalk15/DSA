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
void push(node **stack, int *top, node *data)
{
    if (*top == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++*top] = data;
    }
}
node *pop(node **stack, int *top)
{
    node *temp = NULL;
    if (*top == -1)
    {
        printf("Stack Underflow \n");
    }
    else
    {
        temp = stack[*top];
        (*top)--;
    }
    return temp;
}
int isEmpty(int top)
{
    return (top == -1) ? 1 : 0;
}
//create an empty stack
//initialize current node as root
//while(cuurent!=NULL)
    //current=curretn->left
//pop the top element and printf 
///current =current
void inorderIterative(node *root)
{
    node *stack[MAX_SIZE];
    int top = -1;
    node *current = root;
    while (current || !isEmpty(top))
    {
        while (current != NULL)
        {
            push(stack, &top, current);
            current = current->left;
        }
        current = pop(stack, &top);
        printf("%d ", current->data);
        current = current->right;
    }
    printf("\n");
}
void preorderIterative(node *root)
{
    if (root == NULL)
        return;
    node *stack[MAX_SIZE];
    int top = -1;
    push(stack, &top, root);
    while (!isEmpty(top))
    {
        node *currNode = pop(stack, &top);
        printf("%d ", currNode->data);
        if (currNode->right)
        {
            push(stack, &top, currNode->right);
        }
        if (currNode->left)
        {
            push(stack, &top, currNode->left);
        }
    }
    printf("\n");
}

//push root to first stack
//loop while first stack is not empty
    //pop a node from first stack and push it to second 
    //push left and right children of the popped node to first stack
//printf content of second stack
void postorderIterative(node *root)
{
    if (root == NULL)
        return;
    node *stack[MAX_SIZE];
    int top = -1;
    node *stack2[MAX_SIZE];
    int top2 = -1;
    push(stack, &top, root);
    while (!isEmpty(top))
    {
        node *currNode = pop(stack, &top);
        push(stack2, &top2, currNode);
        if (currNode->right)
        {
            push(stack, &top, currNode->right);
        }
        if (currNode->left)
        {
            push(stack, &top, currNode->left);
        }
    }
    while (!isEmpty(top2))
    {
        node *curr = pop(stack2, &top2);
        printf("%d ", curr->data);
    }
    printf("\n");
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
    printf("Enter data and -1 to stop : ");
    do
    {
        scanf("%d", &val);
        if (val == -1)
            break;
        root = insert(root, val);
    } while (val != -1);
    printf("Inorder Iteratively : ");
    inorderIterative(root);
    printf("preorder Iteratively : ");
    preorderIterative(root);
    printf("postoder Iteratively : ");
    postorderIterative(root);

    int cnt = 0;
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);
    int result = 0;
    kthsmallest(root, k, &result, &cnt);
    printf("The %d smallest element is: %d\n", k, result);
    // reset count
    cnt = 0;
    kthlargest(root, k, &result, &cnt);
    printf("The %d largest element is: %d\n", k, result);
}
// 10 8 9 6 5 7 13 11 12 -1