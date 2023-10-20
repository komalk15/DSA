//create a dobly linked list and delete the 4 element from the last and display the linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
void create(struct node **head,int value);
void delete(struct node **head,int n);
void display(struct node *head);

void create(struct node **head,int value)
{
    struct node *newnode,*temp,*nextnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(*head==NULL)
    {
        *head=temp=newnode;
    }
    else
    {
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
    }


}


void delete(struct node **head,int n)
{
    struct node *temp;
    struct node *nextnode;
    struct node * Node_To_Be_del;
    int len=0;
    int count;
    int i=0;
   
    if((*head)==NULL)
    {
        printf("List is empty");
    }
    if((*head)->next==NULL)
    {
        printf("List is  too short");
    }
    temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        len ++;
        
    }
    len=len-n;
    temp=*head;
    while(i<len)
    {
        temp=temp->next;
        i++;
    }
    Node_To_Be_del=temp->next;
    nextnode=temp->next->next;
    free( Node_To_Be_del);
    temp->next=nextnode;


}
void display(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
        
    }
}
int main()
{
   
    struct node *head=NULL;
    create(&head,4);
    create(&head,2);
    create(&head,6);
    create(&head,3);
    create(&head,8);
    create(&head,5);
    printf("The list is:    ");
    display(head);

    printf("The list is:    ");
    delete(&head,4);
    display(head);
    


}