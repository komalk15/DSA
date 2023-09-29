#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
} node;
void enqueue(int value, node **top, node **rear);
int dequeue(node **top);
void displayQueue(node *top);

int main()
{
    node *top = NULL;
    node *rear = NULL;
    printf("Enqued Some Elements: ");
    for (int i = 18; i < 23; i++)
    {
        enqueue(i, &top, &rear);
    }
        
    displayQueue(top);
    int dequeued = dequeue(&top);
    printf("Dequeued: %d\n", dequeued);
    printf("Queue After Dequeue\n");
    displayQueue(top);
    return 0;
}
void enqueue(int value, node **top, node **rear)
{
    node *temp = NULL;
    temp = (node *)malloc(sizeof(node));
    temp->info = value;
    temp->next = NULL;
    if (*top == NULL)
    {
        *top = temp;
        *rear = temp;
    }
    else
    {
        (*rear)->next = temp;
        *rear = temp;
    }
}

int dequeue(node **top)
{
    if (*top == NULL)
    {
        printf("Nothing to delete\n");
        return -1;
    }
    int deleted = (*top)->info;
    node *temp = NULL;
    temp = (node *)malloc(sizeof(node));
    temp = *top;
    *top = (*top)->next;
    temp->next = NULL;
    free(temp);
    return deleted;
}

void displayQueue(node *top)
{
    node *iter = NULL;
    iter = top;
    while (iter != NULL)
    {
        printf("%d ", iter->info);
        iter = iter->next;
    }
    printf("\n");
};

