#include <stdio.h>
#include <stdlib.h>
//creation of the node of a tree
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
//creation of the node of a queue
struct QueueNode
{
    struct node *data;
    struct QueueNode *next;
};
//structure of queue
struct Queue
{
    struct QueueNode *front, *rear;
};
//this function creates and returns an empty queue
struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

//enqueue
void enqueue(struct Queue *queue, struct node *node)
{
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newNode->data = node;
    newNode->next = NULL;

    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}
//dequeue

struct node *dequeue(struct Queue *queue)
{
    if (queue->front == NULL)
        return NULL;

    struct node *temp = queue->front->data;
    struct QueueNode *tempNode = queue->front;

    queue->front = queue->front->next;

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(tempNode);
    return temp;
}

void levelOrderTraversal(struct node *root)
{
    if (root == NULL)
        return;

    // Create an empty queue for level order traversal
    struct Queue * queue = createQueue();

    // Enqueue root and initialize height
    enqueue(queue, root);

    printf("Level Order Traversal: ");
    while (queue->front != NULL)
    {
        // Dequeue a node from the queue
        struct node *tempNode = dequeue(queue);

        // Print the dequeued node
        printf("%d ", tempNode->data);

        // Enqueue the left child
        if (tempNode->left != NULL)
            enqueue(queue, tempNode->left);

        // Enqueue the right child
        if (tempNode->right != NULL)
            enqueue(queue, tempNode->right);
    }

    // Free the queue
    free(queue);
}

struct node *create(struct node *root)
{
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the value or -1 to return ");
    scanf("%d", &x);
    if (x == -1)
    {
        return NULL;
    }
    newnode->data = x;
    printf("Enter the left child");
    newnode->left = create(root);
    printf("Enter the right child");
    newnode->right = create(root);
    return newnode;
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    struct node *root = NULL;
    root = create(root);
    printf("\nPrint the inorder traversal: ");
    inorder(root);
    printf("\nPrint the preorder traversal: ");
    preorder(root);
    printf("\nPrint the postorder traversal: ");
    postorder(root);

    // Perform level order traversal
    levelOrderTraversal(root);

    return 0;
}
