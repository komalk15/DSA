#include<stdio.h>
#define max 100
void enqueue(int q[],int n,int **Front ,int **rear);
int dequeue(int q[],int **Front,int**rear);
void display(int q[],int *Front,int *rear);
int main()
{
   //intialzing
    int front=-1;
    int rear=-1;
    int q[max];
    int n;
    //insert
    enqueue(q,4,&front ,&rear);
    enqueue(q,4,&front ,&rear);
    enqueue(q,4,&front ,&rear);
    enqueue(q,4,&front ,&rear);
    printf("Queue after deletion is");

    //delete
    dequeue(q,&front,&rear);
    display(q,&front,&rear);


}
void enqueue(int q[],int n,int **Front,int **rear)
{
    if(*Front==-1 && *rear==-1)
    {
        *Front=*rear=0;
        q[*rear]=n;
    }
    if ((*rear + 1) % max == *Front)
    {
        printf("Queue is full");


    }
    else
    {
        *rear=(*rear+1)%max;
        q[*rear]=n;
    }

    
}
int dequeue(int q[],int **Front,int **rear)
{
    if((*Front)==-1 && (*rear)==-1)
    {
        printf("Queue is empty");
        return -1;
    }
    else if(*Front==*rear)
    {
        *Front=*rear=-1;

    }
    else
    {
        int t=q[*Front];
        *Front=((*Front)+1)%max;
        return t;
    }

}
void display(int q[],int *Front,int * rear)
{
    if(*Front == -1 && rear ==-1)
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