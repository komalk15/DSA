#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
void Create_list(struct node **head,int value);
void Display_linked_list(struct node *head);
void reverse(struct node **head);
int main()
{

    int n;
    struct node *head=NULL;
    Create_list(&head,8);
    Create_list(&head,4);
    Create_list(&head,5);
    Create_list(&head,3);
    Create_list(&head,1);
    Display_linked_list(head);
    //reverse
    printf("\nList after being reversed is: ");
    reverse(&head);
    Display_linked_list(head);
    return 0;
}
void Create_list(struct node **head,int value)
{
    struct node *temp, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (*head == NULL)
    {
        *head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }

}
//reverse
void reverse(struct node **head)
{
    struct node *prevnode,*current,*nextnode;
    prevnode=0;
    current=nextnode=*head;
    while(nextnode!=0)
    {
        nextnode=nextnode->next;
        current ->prev=current->next;
        current->next=prevnode;
        prevnode=current;
        current=nextnode;
    }
    *head=prevnode;
}

void Display_linked_list(struct node *head)
{
    struct node *temp;
    temp = head;

    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}