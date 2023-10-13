#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * next;

}node;
void enqueue(node **front,node **rear,int value);
int  dequeue(node **front,node **rear);
void display_linked_list(node *f,node *r);
    
int main()
{
    node *front=NULL,*rear=NULL;
    int n;
   

    //create
    enqueue(&front,&rear,4);
    enqueue(&front,&rear,0);
    enqueue(&front,&rear,8);
    enqueue(&front,&rear,8);
    enqueue(&front,&rear,8);
    printf("The the data of the list  is ");
    display_linked_list(front,rear);

    //delete
  
    printf("\nDeleting the node from the end of list:   ");
    dequeue(&front,&rear);
    display_linked_list(front,rear);
    return 0;

}
void enqueue(node **front,node **rear,int value)
{

    node *newnode=NULL;
    newnode=(node *)malloc(sizeof(node));
        
    if(newnode==NULL)
    {
        printf("Queue is full");
    }
    else 
    {
        newnode->data=value;
        newnode->next=NULL;
        if((*rear)==NULL)
        {
            
            (*rear)=newnode;
            (*front)=newnode;
        }
        else
        {
            
            (*rear)->next=newnode;
            (*rear)=newnode;
        }
    }
        
}
            

void display_linked_list(node *front,node *rear)
{
    

    if(front==NULL )
    {
        printf("empty");
    }
    else
    {
        
        while(front!=rear)
        {
            printf("%d\t",front->data);
            front=front->next;
        }
        printf("%d\t",front->data);
       
        
    }
}

int dequeue(node **front,node **rear)
{

    struct node *temp;
    int t;
    if(*front==NULL )
    {
        printf("\nempty");
        return -1;
    }
    else 
    {
        if((*front)->next==NULL)
        {
            t=(*front)->data;
            free(*front);
            *front=NULL;
            *rear=NULL;
           

        }
        else
        {   
            t=(*front)->data;
            temp=(*front)->next;
            (*front)->next=NULL;
            free(*front);
            *front=temp;
            
        }
    }
    return t;
   
}

   





    


