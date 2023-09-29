#include<stdio.h>
#define max 100
void enqueue(int q[],int n,int **front ,int **rear);
int dequeue(int q[],int **front,int**rear);
void display(int *front,int *rear);
int main()
{
   
    int front=-1;
    int rear=-1;
    int q[max];
    int n;
    
    enqueue(q,4,&front ,&rear);
    enqueue(q,4,&front ,&rear);
    enqueue(q,4,&front ,&rear);
    enqueue(q,4,&front ,&rear);
    printf("Queue after deletion is");
    dequeue(q,&front,&rear);
    display(&front,&rear);


}
void enqueue(int q[],int n,int **front,int **rear)
{
    if((*front)==-1 &&(*rear)==-1)
    {
        *front=*rear=0;
        q[*rear]=n;
    
    }
    else if((*rear)%max==front)
    {
        printf("Queue is full");
    }
    else
    {
        (*rear)=(*rear)%max;
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
        *front=(*front+1)%max;
    }

}