#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;

};
typedef struct node node;
void create_list(int n,node **head);
void display_linked_list(node *head);
void insert_node_at_beginning(int n,node **head);
void insert_node_at_end(int n,node **head);
void insert_node_at_a_given_position(int pos,int n,node **head);
int main()
{
    node *head;
    int n;
    int choice;
    int pos;
    create_list(5,&head);

    do
    {
        
        
        printf("\nEnter 1: For isertion in the beginning\nEnter 2: For isertion in the End\nEnter 3: For isertion at any position\nEnter 4: Display");
        scanf("\n%d",&choice);
        switch(choice)
        {
            case 1:
            {
                
                printf("\nEnter the data of the node you want to insert in the beginning of the linked list");
                scanf("%d",&n);
                insert_node_at_beginning(n,&head);
                break;
                
            }
            case 2:
            {
                printf("\nEnter the data of the node you want to insert in the end  of the linked list");
                scanf("%d",&n);
                insert_node_at_end(n,&head);
                break;

            }
            case 3:
            {
                printf("\nEnter the position where want to insert in the end  of the linked list");
                scanf("%d",&pos);
                printf("\nEnter the data");
                scanf("%d",&n);
                insert_node_at_a_given_position(pos,n,&head);
                break;
            }
            case 4:
            {
                display_linked_list(head);
                break;

            }
            default:
            {
                  break;
            }
        
        }
    }while(choice!=0);
    return 0;

}
void create_list (int n,node **head)
{
    node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=NULL;
    if(*head==NULL)
        *head=newnode;
    else
    {
        (*head)->next=newnode;
        *head=newnode;
    }
}
void display_linked_list(node *head)
{
    node *temp=head;
    while(temp!=NULL)
    {
        printf("%d  ", temp->data);
        temp=temp->next;
    }
}

void insert_node_at_beginning(int n,node **head)
{

    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    newnode->data=n;
    if(*head==NULL)
    {
        (*head)=newnode;
        newnode->next=NULL;

    }
    else
    {
        newnode->next=*head;
        *head=newnode;

    }
    
}
void insert_node_at_end(int n,node **head)
{
    node *temp,*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=NULL;
    temp=*head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next = newnode;
}
void insert_node_at_a_given_position(int pos ,int n,node **head)
{
    node *temp,*newnode;
    int i=1,count=0;
    newnode=(struct node *)malloc(sizeof(struct node));
    temp = *head;
    while(temp!=NULL)
    {
        count+=1;
        temp=temp->next;
    }
    if(pos < 0|| pos >= count-1)
    {
        printf("Invalid position");
    }
    else
    {
        temp = *head;
        while(i < pos-1)
        {
            i++;
            temp=temp->next;
        }
        newnode->data=n;
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
