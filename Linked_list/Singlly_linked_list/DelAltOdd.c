#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
void insert(node **head, int value);
void display(node *head);
void Delete(node **head);


int main()
{
    node *head;
    head = NULL;
    insert(&head, 5);
    insert(&head, 7);
    insert(&head, 9);
    insert(&head, 4);
    display(head);
    printf("Linked list after deletion is:  ");
    Delete(&head);
    display(head);

}
void insert(node **head, int value)
{
    node *temp, *newnode;

    newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;

    if (*head == NULL)
    {
        *head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}



void display(node *head)
{
    node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}
// Input: linked list = 10->20->30->40->50->60
// Output: 20->40->60

void Delete(node **head)
{
    struct node *temp=*head;
    if(*head==NULL)
    {
        return ;
    }
    if((*head)->next==NULL)
    {
        (*head)->next=NULL;
        free(*head);
    }
    else
    {
        if(temp==*head)
        {
            *head=temp->next;
            free(temp);
            temp=*head;

        }
        struct node *nextnode=temp->next;
        while(temp!=NULL && temp->next!=NULL )
        {
            temp->next=nextnode->next;
            free(nextnode);
            
            {
                nextnode=temp->next;
                temp=temp->next;
                 
            }
            
            

        }

    }
}