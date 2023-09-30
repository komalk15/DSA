//for reverse we have to maintain 2 pointer one is "current" and  another is "nextnode"
#include <stdio.h>
#include <stdlib.h>
void Create_list(int n);
void Display_linked_list();
void reverse_dobly_linked();


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
    reverse_dobly_linked();
    printf("\nThe the data of the list after being reversed is ");
    Display_linked_list();
    return 0;


}
void Create_list(int n)
{
    struct node *tail,*newnode;
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
            head=tail=newnode;

        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;

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
 
void reverse_dobly_linked()
{
    struct node *current ,*nextnode,*tail;
    current=head;
    
    while(current!=0)
    {
        nextnode=current->next;
        current->next=current->prev;
        current->prev=nextnode;
        current=nextnode;

    }
    current =head;
    head=tail;
    tail=current;

}
