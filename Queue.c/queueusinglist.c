#include<stdio.h>
#include<stdlib.h>
void enqueue(int n,node **front,node **rear);
int  dequeue(node **front,node **rear);
void display_linked_list(node *f,node *r);



typedef struct node
    {
        int data;
        struct node * next;

    }node;
    
int main()
{
    node *front=NULL,*rear=NULL;
    int n;
    printf("Enter the number of nodes ");
    scanf("%d",&n);

    //create
    enqueue(n,&front,&rear);
    printf("The the data of the list  is ");
    display_linked_list(front,rear);

    //delete
  
    printf("\nDeleting the node from the end of list:   ");
    dequeue(&front,&rear);
    display_linked_list(front,rear);
    
   
    
    return 0;

}
void enqueue(int n,node **front,node *s*rear)
{

    struct node *newnode;
    int data,i=0;
    for(i=0;i<n;i++)
    {   
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data of node %d :",i+1);
        scanf("%d", &newnode->data);
        newnode->next=0;
        
        if(newnode==NULL)
        {
            printf('Queue is full');
        }
        else if(*rear==NULL)
        {
            *front==newnode;
            *rear=newnode;
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
    struct node *temp;

    if(*front==0 && *rear==0)
    {
        printf("empty");
    }
    else
    {
        *temp=*front;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        
    }
}

int dequeue(node **front,node **rear)
{

    struct node *temp;
    int t;
    if(*front==NULL && *rear==NULL)
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
            temp=*front->next;
            *front->next=NULL;
            free(temp);
            return t;
        }
   
}

   





    


