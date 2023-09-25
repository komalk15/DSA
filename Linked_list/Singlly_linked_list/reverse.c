#include<stdio.h>
#include<stdlib.h>
void create_list(int n);
void display_linked_list();
void reverse_linked_list();
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
    printf("\nThe the data of the list  is ");
    display_linked_list();
    printf("\nList after being reversed is ");
    reverse_linked_list();
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
void reverse_linked_list()
{
    struct node *current_node,*pre_node,*next_node;
    pre_node=0;
    current_node=next_node=head;
    while(next_node!=0)
    {
        next_node=next_node->next;
        current_node->next=pre_node;
        pre_node=current_node;
        current_node=next_node;
    }
    head=pre_node;
}

    


