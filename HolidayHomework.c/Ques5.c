//Given the head of a linked list, rotate the list to the right by k places.

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insert(struct node **head, int value);
void display(struct node *head);
struct node *rotate (struct node **head,int k);

int main()
{
    struct node *head = NULL;
    int k;
    insert(&head, 5);
    insert(&head, 5);
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 8);
    insert(&head, 7);
    insert(&head, 2);
    insert(&head, 2);
    insert(&head, 2);
    insert(&head, 2);
    insert(&head, 4);
    insert(&head, 7);
    printf("\nThe list is : ");
    display(head);
    printf("\nEnter the value of k: ");
    scanf("%d",&k);
    printf("\nThe list after rotation is  : ");
    rotate(&head,k);
    display(head);

  
}
struct node * rotate (struct node **head,int k)
{
    int i,count=0;
    struct node *temp;
    temp=*head;
    if(*head==NULL || (*head)->next==NULL||k==0)
    {
        return head;
    }
    while(temp->next!=NULL)
    {
        count++;
        temp=temp->next;
    }
    temp->next=*head;
    k=k%12;
    k=count-k;
    temp=*head;
    for(int i=0;i<k;i++ )
    {
        temp=temp->next;
    }
    *head=temp->next;
    temp->next=NULL;
    return *head;

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