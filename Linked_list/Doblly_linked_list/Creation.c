#include <stdio.h>
#include <stdlib.h>
void Create_list(int n);
void Display_linked_list();
struct node{
    int data;
    struct node *next;
    struct node *prev;

};
struct node *head,*newnode;
int main()
{

    int n;
    printf("Enter the number of nodes ");
    scanf("%d",&n);
    Create_list(n);
    printf("\nThe the data of the list  is ");
    Display_linked_list();
    return 0;


}
void Create_list(int n)
{
    struct node *temp,*newnode;
    int i;
    head =0;
  
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