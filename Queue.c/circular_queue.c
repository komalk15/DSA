#include<stdio.h>
#define max 100
int main()
void enqueue(int q[],int n,int *front ,int *rear);
void dequeue(int *front,int *rear);
void display();
{
   
    int front=-1;
    int rear=-1;
    int q[max];
    int n;
    printf("Enter the vaule to insert");
    scanf("%d",&n);
    enqueue(q,n,&front ,&rear);
    printf("Queue after deletion is");
    dequeue(&front,&rear);
    display();


}
void enqueue(int q[],int n,int *front,int *rear)
{
    if(*front ==-1 && *rear==-1)
    {
    
        (*front)=(*rear)=0;
        q[*front]=n;

    }
}