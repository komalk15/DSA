#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;

}*head;
void create_circular_linked_list(int n);
void display();
int main()
{
    int n;
    printf("Enter the number of nodes needed:   ");
    scanf("%d",&n);
    create_circular_linked_list(n);
    printf("\nThe data of the linked list is");
    display();

  
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
