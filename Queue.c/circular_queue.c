#include <stdio.h>
#define max 100

void enqueue(int q[], int n, int *Front, int *rear);
void dequeue(int q[], int *Front, int *rear);
void display(int q[], int Front, int rear);

int main()
{
    int front = -1;
    int rear = -1;
    int q[max];

    // Insert
    enqueue(q, 4, &front, &rear);
    enqueue(q, 3, &front, &rear);
    enqueue(q, 5, &front, &rear);
    enqueue(q, 7, &front, &rear);
    display(q, front, rear);

    printf("Queue after deletion is:\n");

    // Delete
    dequeue(q, &front, &rear);
    display(q, front, rear);

    return 0;
}

void enqueue(int q[], int n, int *Front, int *rear)
{
    if ((*rear + 1) % max == *Front)
    {
        printf("Queue is full\n");
        return;
    }

    if (*Front == -1 && *rear == -1)
    {
        *Front = *rear = 0;
        q[*rear] = n;
    }
    else
    {
        *rear = (*rear + 1) % max;
        q[*rear] = n;

    }

   
}

void dequeue(int q[], int *Front, int *rear)
{
    if (*Front == -1 && *rear == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    else if (*Front == *rear)
    {
        *Front = *rear = -1;
    }
    else
    {
        *Front = (*Front + 1) % max;
    }
}

void display(int q[], int Front, int rear)
{
    if (Front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    int i = Front;
    while (i != rear)
    {
        printf("%d  ", q[i]);
        i = (i + 1) % max;
    }
    printf("%d\n", q[i]);
}
