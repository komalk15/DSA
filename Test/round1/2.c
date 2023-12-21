#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void levelOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    // create a queue and enqueue the root node
    struct Node **queue =
        (struct Node **)malloc(sizeof(struct Node *) * 100);
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        // dequeue a node from the queue
        struct Node *current = queue[front++];

        // process current node
        printf("%d ", current->data);

        // enqueue the left child
        if (current->left != NULL)
        {
            queue[rear++] = current->left;
        }

        // enqueue the right child
        if (current->right != NULL)
        {
            queue[rear++] = current->right;
        }
    }
}

int main()
{
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Level order traversal of binary tree: ");
    levelOrderTraversal(root);

    return 0;
}