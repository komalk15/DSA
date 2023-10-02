#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
void insert(node **head, int n);
void display(node *head);

int main()
{
    node *head = NULL;
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 9);
    display(head);
}
void insert(node **head, int n)
{
    node *temp, *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = n;
    newnode->next = NULL;
    if (*head == NULL)
    {
        *head= temp = newnode; 
    }
    else
    {
        temp->next = newnode;
        temp = temp->next;
        
    }
}
void display(node *head)
{
    node *temp;
    temp = head;
    while (temp != NULL)
    {

        printf("\n%d", temp->data);
        temp = temp->next;
    }
}
