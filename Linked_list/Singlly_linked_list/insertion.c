#include<stdio.h>
#include<stdlib.h>
void create_list(int n);
void display_linked_list();
void insert_node_at_beginning();
void insert_node_at_end();
void insert_node_at_a_given_position();
struct node
    {
        int data;
        struct node * next;

    }*head;
int main()
{
    int n;
    printf("Enter the number of nodes ");
    scanf("%d",&n);
    create_list(n);
    printf("The the data of the list  is\n");
    display_linked_list();
    printf("\nEnter the data of the node you want to insert in the beginning of the linked list");
    insert_node_at_beginning();
    display_linked_list();
    printf("\nEnter the data of the node you want to insert in the end  of the linked list");
    insert_node_at_end();
    display_linked_list();
    printf("\nEnter the data of the node you want to insert in any position of the linked list");
    insert_node_at_a_given_position();
    display_linked_list();
    return 0;

}
void create_list (int n)
{

    struct node *temp,*newnode;
    int data,i=0;
    for(i=0;i<n;i++)
    {   
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data of node %d :",i+1);
        scanf("%d", &newnode->data);
        newnode->next=0;

        if(head==0)
        {
            head=temp=newnode;
            
        }
        else
        {
            temp->next=newnode;
            temp=newnode;

        }
    }
            
}
void display_linked_list()
{
    struct node *temp;
    temp=head;
    
    while(temp!=NULL)
    {
        printf("%d  ", temp->data);
        temp=temp->next;
    }
}

void insert_node_at_beginning()
{

    struct node *emp,*newnode;
    emp=head;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data of the node: ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}
void insert_node_at_end()
{
    struct node *temp,*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data of the node: ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next = newnode;
}
void insert_node_at_a_given_position()
{
    int i=1,pos,count=0;
    struct node *temp,*newnode;
    printf("\nEnter the position from where you want to delete a node: ");
    scanf("%d",&pos);
    while(temp=NULL)
    {
        count+=1;
        temp=temp->next;
   
    }
    temp=temp->next;
    if(pos < 1|| pos >count)
    {
        printf("Invalid position");

    }
    else
    {
        temp = head;
        while(i<pos)
        {
            i++;
            temp=temp->next;
        }
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data of the node");
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;



    }
}


