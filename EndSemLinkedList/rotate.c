#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
void insert(node **head, int value);
void display(node *head);
void rotate(struct node **head,int k);



int main()
{
    node *head;
    head = NULL;
     int k;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    display(head);
    printf("\nEnter the place by which you want to rotate the linked list:  ");
    scanf("%d",&k);
    rotate(&head,k);
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
void rotate(struct node **head,int k)
{
    struct node *temp=*head;
    int count=1;
    if(*head==NULL||(*head)->next==NULL||k==0)
    {
        printf("Linked list is too short");
    }
    while(temp->next!=NULL)
    {
        count++;
        temp=temp->next;
    }
    temp->next=*head;
    k=k%count;
    k=count-k;
   
    for(int i=0;i<k;i++)
    {
        temp=temp->next;

    }
    *head=temp->next;
    temp->next=NULL;
 
   
    
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