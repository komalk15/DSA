// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int data;
//     struct node *left;
//     struct node *right;
// };

// struct QueueNode
// {
//     struct node *data;
//     struct QueueNode *next;
// };

// struct Queue
// {
//     struct QueueNode *front, *rear;
// };

// struct Queue *createQueue()
// {
//     struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
//     queue->front = queue->rear = NULL;
//     return queue;
// }

// void enqueue(struct Queue *queue, struct node *node)
// {
//     struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
//     newNode->data = node;
//     newNode->next = NULL;

//     if (queue->rear == NULL)
//     {
//         queue->front = queue->rear = newNode;
//         return;
//     }

//     queue->rear->next = newNode;
//     queue->rear = newNode;
// }

// struct node *dequeue(struct Queue *queue)
// {
//     if (queue->front == NULL)
//         return NULL;

//     struct node *temp = queue->front->data;
//     struct QueueNode *tempNode = queue->front;

//     queue->front = queue->front->next;

//     if (queue->front == NULL)
//     {
//         queue->rear = NULL;
//     }
//     free(tempNode);
//     return temp;
// }

// void levelOrderTraversal(struct node *root)
// {
//     if (root == NULL)
//         return;

//     // Create an empty queue for level order traversal
//     struct Queue * queue = createQueue();

//     // Enqueue root and initialize height
//     enqueue(queue, root);

//     printf("Level Order Traversal: ");
//     while (queue->front != NULL)
//     {
//         // Dequeue a node from the queue
//         struct node *tempNode = dequeue(queue);

//         // Print the dequeued node
//         printf("%d ", tempNode->data);

//         // Enqueue the left child
//         if (tempNode->left != NULL)
//             enqueue(queue, tempNode->left);

//         // Enqueue the right child
//         if (tempNode->right != NULL)
//             enqueue(queue, tempNode->right);
//     }

//     // Free the queue
//     free(queue);
// }

// struct node *create(struct node *root)
// {
//     int x;
//     struct node *newnode;
//     newnode = (struct node *)malloc(sizeof(struct node));
//     scanf("%d", &x);
//     if (x == -1)
//     {
//         return NULL;
//     }
//     newnode->data = x;
//     printf("Enter the left child of %d:   ",x);
//     newnode->left = create(root);
//     printf("Enter the right child of %d :  ",x);
//     newnode->right = create(root);
//     return newnode;
// }

// void preorder(struct node *root)
// {
//     if (root == NULL)
//         return;
//     printf("%d ", root->data);
//     preorder(root->left);
//     preorder(root->right);
// }

// void postorder(struct node *root)
// {
//     if (root == NULL)
//         return;
//     postorder(root->left);
//     postorder(root->right);
//     printf("%d ", root->data);
// }

// int main()
// {
//     struct node *root = NULL;
//     printf("Enter  value or -1 to exit ");
//     root = create(root);
//     printf("\nPrint the inorder traversal: ");
//     inorder(root);
//     printf("\nPrint the preorder traversal: ");
//     preorder(root);
//     printf("\nPrint the postorder traversal: ");
//     postorder(root);

//     levelOrderTraversal(root);

//     return 0;
// }

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

    struct Node **queue =(struct Node **)malloc(sizeof(struct Node *) * 100);
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {

        struct Node *current = queue[front++];

        printf("%d ", current->data);

        if (current->left != NULL)
        {
            queue[rear++] = current->left;
        }

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