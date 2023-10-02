#include<stdio.h>
#include<stdlib.h>
void create_list(int n,struct node **head);
void display_linked_list();
// void delete_node_beg();
// void delete_node_end();

struct node
{
    int data;
    struct node * next;

};
int main()
{
    int n;
    struct node *head=NULL;
    printf("Enter the number of nodes ");
    scanf("%d",&n);
    create_list(5,&head);
    printf("The the data of the list  is ");
    display_linked_list();
    // delete_node_beg();
    // printf("\nDeleting the node from the beginning of the list:   ");
    // display_linked_list();
    // printf("\nDeleting the node from the end of list:   ");
    // delete_node_end();
    display_linked_list();
    printf("\nDeleting the node from the position specific by the user:  ");
   
    
    return 0;

}
void create_list (int n,struct node **head)
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
void delete_node_beg()
{

    struct node *temp,*next;
    if (head == NULL)
    {
        printf("List is already empty. Cannot delete from an empty list.\n");
        return;
    }
    else
    {
        temp=head;
        head=head->next;
        free(temp);

    }    
    

}
void delete_node_end()
{

    struct node *prenode,*temp;
    temp=head;
    while(temp->next!=0)
    {
        prenode=temp;
        temp=temp->next;

    }
    if(temp==head)
    {
        head=0;

    }
    else
    {
        prenode->next=0;
    }
    free(temp);


}


    


