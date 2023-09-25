#include<stdio.h>
#include<stdlib.h>
void create_list(int n);
void display_linked_list();
void length();
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
    printf("The the data of the list  is ");
    display_linked_list();
    length();
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
void length()

{
    struct node *temp;
    int count=0;
    temp=head;
    while(temp!=0)
    {
        if(head==0)
        {
            printf("List is empty");
        }
        else
        {
            count++;
            temp=temp->next;
        }
      
    }
    printf("\nThe lenght of the list is : %d",count);
      
    
}
    


