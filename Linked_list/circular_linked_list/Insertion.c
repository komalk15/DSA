//Here only tail pointer is declared

#include<stdio.h>
#include<stdlib.h>
void create_circular_linked_list(int n);
void display();
void Insert_at_beg();
void Insert_at_pos();
void Insert_at_end(int pos);

struct node{
    int data;
    struct node*next;

}*head;

int main()
{
    int n;
    int pos;
    printf("Enter the number of nodes needed:   ");
    scanf("%d",&n);
    create_circular_linked_list(n);
    printf("\nThe data of the linked list is");
    display();
    printf("\nEnter the position where you wan to insert a node");
    scanf("%d",&pos);
    //Insertion at beg
    if(pos==1)
    {
        Insert_at_beg();
        printf("\nThe data of the linked list is");
        display();
    }
    else if(pos=n)
    {   //Insertion at end
        Insert_at_end();
        display();

    }
    else
    {   //Insertion at postion given by the user
        Insert_at_pos(pos);
        display();


    }
    return 0; 
}
void create_circular_linked_list(int n)
{
    int i;
    struct node *newnode,*temp;
    head=temp=NULL;
    printf("\nEnter the data  to be inserted in the newnode ");
    for(i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        if(head==NULL)
        {
            head=temp=newnode;

        }
        else
        {
            head->next=newnode;
            temp=newnode;
            temp->next=head;
        }
    }
    
}
void display()
{
    
    struct node*temp;
    if(head==NULL)
    {
        printf("Empty list");
    }
    else
    {
        temp=head;
        do
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        while(temp!=head);
       

    }
}

void Insert_at_beg()
{
    struct node *temp,*newnode,*tail;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf('Enter the data of the node');
    scanf("%d",newnode->data);
    newnode->next=0;
    if(tail==0)
    {
        //Means list is empty therefore it will contain its own address
        tail->next=newnode;
    }
    else
    {
        //Firstly we have to store the address of first node at the next of newnode so that contact is not lost;
        newnode->next=tail->next;
        tail->next=newnode;

    }

}
//In circular linked list last node and first node are same
void Insert_at_End()
{
    struct node *temp,*newnode,*tail;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf('Enter the data of the node');
    scanf("%d",newnode->data);
    newnode->next=0;
    if(tail==0)
    {
        //Means list is empty therefore it will contain its own address
        tail->next=newnode;
    }
    else
    {
        
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;

    }

}
void Insert_at_pos(int pos)
{
    int i;
    struct node *temp,*newnode,*tail,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf('Enter the data of the node');
    scanf("%d",newnode->data);
    newnode->next=0;
    while(i<pos-1)
    {
        temp=temp->next;
        temp++;
    }
    for(int i=0;i<pos-1;i++)
    {
        newnode->next=temp->next;
        temp->next=newnode;
    }
}