#include<stdio.h>
#define max 100
void enqueue(int q[],int n,int **front ,int **rear);
int dequeue(int q[],int **front,int**rear);
void display(int q[],int *front,int *rear);
int main()
{
   
    int front;
    int rear=-1;
    int q[max];
    int n;
    
    enqueue(q,4,&front ,&rear);
    enqueue(q,4,&front ,&rear);
    enqueue(q,4,&front ,&rear);
    enqueue(q,4,&front ,&rear);
    printf("Queue after deletion is");
    dequeue(q,&front,&rear);
    display(q,&front,&rear);


}
void enqueue(int q[],int n,int **front,int **rear)
{
    if(*front==-1 && *rear==-1)
    {
        *front=*rear=0;
        q[*rear]=n;
    }
    if ((*rear + 1) % max == *front)
    {
        printf("Queue is full");


    }
    else
    {
        *rear=(*rear+1)%max;
        q[*rear]=n;
    }

    
}
int dequeue(int q[],int **front,int **rear)
{
    if((*front)==-1 && (*rear)==-1)
    {
        printf("Queue is empty");
        return -1;
    }
    else if(*front==*rear)
    {
        *front=*rear=-1;

    }
    else
    {
        int t=q[*front];
        *front=((*front)+1)%max;
        return t;
    }

}
void display(int q[],int *front,int * rear)
{
    if(*front == -1 && rear ==-1)
        printf("Queue is empty");
    
    else
    {
        int i;
        while(i!=rear)
        {
            printf("%d",q[i]);
            i=(i+1)%max;

            
        }
         printf("%d\n", q[i]);

    }
}