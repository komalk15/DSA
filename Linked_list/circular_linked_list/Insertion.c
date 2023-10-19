//Here only tail pointer is declared
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void create_circular_linked_list(struct node **head,int value);
void display(struct node *head);
void Insert_at_beg(struct node **head,int value);
void Insert_at_pos(struct node **head,int pos,int value);
void Insert_at_end(struct node **head,int value);
int main()
{
    struct node *head = NULL;
    int n,pos;
    create_circular_linked_list(&head,9);
    create_circular_linked_list(&head,3);
    create_circular_linked_list(&head,5);
    create_circular_linked_list(&head,6);
    printf("\nList is: ");
    display(head);
    printf("\nInsertion in beginning: ");
    Insert_at_beg(&head,7);
    display(head);

    printf("\nInsertion at a position: ");
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    Insert_at_pos(&head,pos,6);
    display(head);

    printf("\nInsertion in end: ");
    Insert_at_end(&head,6);
    printf("\nThe data of the linked list is:   ");
    display(head);
}
void create_circular_linked_list(struct node **head,int value)
{
    int i;
    struct node *newnode, *tail;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=value;
    if (*head == NULL)
    {
        *head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
        tail->next = *head;
    }
}

void Insert_at_beg(struct node **head,int value)
{
    struct node *newnode,*tail;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=newnode;
        (*head)->next=newnode;
    }
    else
    {
        //Firstly we have to store the address of first node at the next of newnode so that contact is not lost;
        tail=*head;
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }
        newnode->next=tail->next;
        tail->next=newnode;

    }

}
//In circular linked list last node and first node are same only in end we have to change tail
void Insert_at_end(struct node **head,int value)
{
    struct node *newnode,*tail;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if(*head==0)
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
void Insert_at_pos(struct node **head,int pos,int value)
{
    int i;
    struct node *temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    int l=0;
    temp=*head;
    while(temp->next!=NULL)
    {
        l=l+1;

    }
    
    if(pos<0 ||pos >l)
    {
        printf("Invalid Position");
    }
    else if(pos==1)
    {
        Insert_at_beg(head,value);
        
    }

    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;

}
void display(struct node *head)
{

    struct node *temp;
    if (head == NULL)
    {
        printf("Empty list");
    }
    else
    {
        temp = head;
        do
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        } while (temp->next != head);
    }
}
