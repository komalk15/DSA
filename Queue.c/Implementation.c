#include<stdio.h>
#define max 100
void enqueue(int * f,int *  r,int value,int q[]);
void dequeue(int * f,int * r,int value,int q[]);
void display(int q[],int f,int r);

int main()
{
    int value;
    int r=-1;
    int f=-1;
    int q[max];
    //Enqueue
    printf("Enter the value to insert");
    scanf("%d",&value);
    enqueue(&f,&r,value,q);
  
    //display
    printf("\nQueue after insertion is");
    display(q,f,r);



    //Dequeue
    
    dequeue(& f,&r,value,q);
    printf("\nQueue after deletion is ");
    display(q,f,r);
    return 0;

}
void enqueue(int *  f,int * r,int value,int q[])
{
    if(*r==max-1)
    {
        printf("\nQueue is full");
    }
    else
    {
        if(*f==-1)
        {
            (*f)++;
            (*r)++;
            q[*f]=value;
        }

    }

}

void dequeue(int * f,int * r,int value,int q[])
{
    int t;
    if(*f ==-1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        int t=q[*f];
        f++;
        if(*f==*r)
        {
            *f=-1;
            *r=-1;

        }

    }
}
void display(int q[],int f,int r)
{
    int i;

    for(i=f;i<=r;i++)
    {
        printf("%d",q[i]);
    }
}