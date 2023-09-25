#include <stdio.h>
#include <stdlib.h>
void Create_list(int n);
void Display_linked_list();
void Insertion_at_beg();
void Insertion_at_end();
void Insertion_at_pos(int n );


struct node{
    int data;
    struct node *next;
    struct node *prev;

};
struct node *temp,*head,*newnode,*tail;
int main()
{

    int n;
    printf("Enter the number of nodes ");
    scanf("%d",&n);
    Create_list(n);
    printf("\nThe the data of the list  is ");
    Display_linked_list();


    //Insertion at beginning
    printf("\nEnter the data to insert at the beginning:  "); 
    Insertion_at_beg();
    Display_linked_list();

    //Insertion at end
    printf("\nEnter the data to insert at the End:  "); 
    Insertion_at_end();
    Display_linked_list();


    //Insertion at the position given tby the user
    printf("\nEnter the data position wherer you want to insert the data  "); 
    Insertion_at_pos(n);
    Display_linked_list();
    return 0;


}
void Create_list(int  n)
{
    struct node *temp,*newnode;
    int i;
    head =0;
    tail=0;
    for(i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->prev =0;
        newnode->next =0;
        
        if(head==0)
        {
            head=temp=newnode;

        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;

        }
        
    }
    
}
void Display_linked_list()
{
    struct node *temp;
    temp=head;
    
    while(temp!=NULL)
    {
        printf("%d  ", temp->data);
        temp=temp->next;
    }
}
void Insertion_at_beg()
{

    newnode=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    if(head==0)
    {
        head=newnode;

    }
    else
    {
        head->prev=newnode;
        newnode->next=head;
        head=newnode;

    }
    
}


void Insertion_at_end()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    
    if(tail==NULL)
    {
        head=newnode=tail;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}


void Insertion_at_pos(int  n)
{
    
    int pos,i;
    newnode=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    printf("Insert the position where you want to insert the node");
    scanf("%d",&pos);
    if(pos<1||pos>n)
    {
        printf("Invalid position");
    }
    if(pos==1)
    {
        Insertion_at_beg();

    }
    while(i<pos-1)
    {
        temp=temp->next;
        i++;

    }
    
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next=newnode;
    temp->next->prev=newnode;


}