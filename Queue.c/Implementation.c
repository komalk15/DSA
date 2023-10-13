#include <stdio.h>
#define Max_size 10

void enqueue(int q[], int value, int *r, int *f);
int dequeue(int q[], int *r, int *f);
void display(int q[], int r, int f);

int main()
{
    int q[Max_size];
    int r = -1;
    int f = -1;
    enqueue(q, 12, &r, &f);
    enqueue(q, 4, &r, &f);
    enqueue(q, 3, &r, &f);
    display(q, r, f);
    int item = dequeue(q, &r, &f);
    printf("The value deleted from the stack is: %d\n", item);
    display(q, r, f);
    return 0;
}

void enqueue(int q[], int value, int *r, int *f)
{
    if (*r == Max_size - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        if(*f==-1)
        {
            (*f)++;
        }
        (*r)++;
        q[(*r)]=value;

       
    }
}

void display(int q[], int r, int f)
{
    for (int i = f; i <= r; i++)
    {
        printf("%d ", q[i]); 
    }
    printf("\n");
}

int dequeue(int q[], int *r, int *f)
{
    int t;
    if (*f == -1)
    {
        printf("Stack is empty\n");
        return -1; 
    }
    else
    {
        t = q[*f];
        
        if (*f == *r)
        {
            *f = -1;
            *r = -1;
        }
        else
        {
            (*f)++;
        }
    }
    return t;
}
