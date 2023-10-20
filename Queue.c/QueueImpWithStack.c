#include <stdio.h>
#include <stdlib.h>
#define max 100

void enqueue(int st1[], int x, int *top1, int *count);
void dequeue(int st1[], int st2[], int *top1, int *top2, int *count);
void push1(int st1[], int *top1, int value);
void push2(int st2[], int *top2, int value);
int pop1(int st1[], int *top1);
int pop2(int st2[], int *top2);
void display(int st1[], int *top1);

int main()
{
    int top1 = -1;
    int top2 = -1;
    int stack1[max];
    int stack2[max];
    int count = 0;

    enqueue(stack1, 7, &top1, &count);
    enqueue(stack1, 4, &top1, &count);
    enqueue(stack1, 6, &top1, &count);
    enqueue(stack1, 3, &top1, &count);
    enqueue(stack1, 2, &top1, &count);
    display(stack1, &top1);
    dequeue(stack1, stack2, &top1, &top2, &count);
    display(stack1, &top1);

    return 0;
}

void enqueue(int st1[], int x, int *top1, int *count)
{
    push1(st1, top1, x);
    (*count) = (*count) + 1;
}

void dequeue(int st1[], int st2[], int *top1, int *top2, int *count)
{
    int i = 0;
    int a;

    if ((*top1) == -1 && (*top2) == -1)
    {
        printf("QUEUE is empty");
    }
    else
    {
        for (i = 0; i < (*count); i++)
        {
            a = pop1(st1, top1);
            push2(st2, top2, a);
        }
        int b = pop2(st2, top2);
        printf("\nDeleted element is: ");
        printf("%d\n", b);
        (*count)--;
        for (i = 0; i < (*count); i++)
        {
            a = pop2(st2, top2);
            push1(st1, top1, a);
        }
    }
}

void push1(int st1[], int *top1, int value)
{
    if (*top1 == max - 1)
    {
        printf("full");
    }
    else
    {
        (*top1)++;
        st1[*top1] = value;
    }
}

void push2(int st2[], int *top2, int value)
{
    if (*top2 == max - 1)
    {
        printf("full");
    }
    else
    {
        (*top2)++;
        st2[*top2] = value;
    }
}

int pop1(int st1[], int *top1)
{
    return st1[(*top1)--];
}

int pop2(int st2[], int *top2)
{
    return st2[(*top2)--];
}

void display(int st1[], int *top1)
{
    int i;
    if (*top1 == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        for (i = *top1; i >= 0; i--)
        {
            printf("%d\t", st1[i]);
        }
    }
}
