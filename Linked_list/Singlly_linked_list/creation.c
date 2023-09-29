#include<stdio.h>
#include<stdlib.h>
void create_list(int n,node **head);
void display_linked_list();

typedef struct node
{
    int data;
    struct node * next;

}node;
int main()
{
    int n;
    node  *head;
    create_list(5,&head);
    create_list(5,&head);
    create_list(5,&head);
    
    printf("\nThe the data of the list  is ");
    display_linked_list();
    return 0;

}
void create_list (int n,node **head)
{

    struct node *temp,*newnode;
    int data,i=0;
    for(i=0;i<n;i++)
    {   
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data of node %d :",i+1);
        scanf("%d", &newnode->data);
        newnode->next=NULL;

        if(head==NULL)
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


    


