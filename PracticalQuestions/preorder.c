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


void preorderIterative(node *root)
{
    if (root == NULL)
    {
        return;
    }
    node *stack[MAX_SIZE];
    int top = -1;
    stack[top++] = root;
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

  
    printf("\nPreorder Iteratively: ");
    preorderIterative(root);
  

    return 0;
}

#include<stdio.h>
int main()
{
    printf("%s",I love you babe);
    return 0;
}

The word steganography is taken from a Greek word it is made up of two words steganos which means "covered”  and graphia meaning "writing”. It is an ancient technique of hiding the information .In this modern era of increasing computer application the security is the major concern .And here Steganography comes into play it is considered as the safest technique to hide the data because it eradicates the  very fact that something is being hidden unlike cryptography where the message is converted into some random text before sending this creates a suspicion that something is valuable .In steganography the data is  covered by the innocent looking files which barely creates suspicion. 
There are various factors of steganography such as robustness and embedding capacity with play a crucial role in hiding data in such the way which would be difficult to detect by human senses.various types of stegraphy techniques are text,video,image,text.Confidential communication and protection of data are its main feature.