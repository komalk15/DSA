 //Given the head of a linked list, remove the nth node from the end of the list and return its head.

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insert(struct node **head, int value);
void display(struct node *head);
int  delete(struct node **head,int k);

int main()
{
    struct node *head = NULL;
    int k;
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 4);
    insert(&head, 7);
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 4);
    insert(&head, 7);
    printf("\nThe list is : ");
    display(head);
    printf("\nEnter the value of k: ");
    scanf("%d",&k);
    printf("\nThe list after deletion  is  : ");
    delete(&head,k);
    display(head);

  
}
int delete(struct node **head,int k)
{
    int length=0,i;
    struct node *temp,*nextnode;
    temp=*head;
    if(*head==NULL || (*head)->next==NULL)
    {
        return 0;
    }
    while(temp!=NULL)
    {
        length++;
        temp=temp->next;

    }
    
    length=length-k;
    temp=*head;
    while(i<length)
    { 
        temp=temp->next;
        i++;
    }
    nextnode=temp->next->next;
    free(temp->next);
    temp->next=nextnode;
}

void insert(struct node **head, int value)
{
    struct node *temp;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
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
void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
}