#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
void insert(node **head, int value);
void display(node *head);
void deleteAlternating(node **head);


int main()
{
    node *head;
    head = NULL;
    insert(&head, 5);
    insert(&head, 7);
    insert(&head, 9);
    insert(&head, 4);
    display(head);


    //1 2 3 5
    // output= 2 5
    printf("\nList afer deletion from alternating node is :");
    deleteAlternating(&head);
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
void deleteAlternating(node **head)
{
    node *nextnode;
    node *temp;
    temp = *head;
    nextnode = temp->next;

    while (temp != NULL && nextnode != NULL)
    {
        temp->next = nextnode->next;
        nextnode->next = NULL;
        free(nextnode);
        temp = temp->next;
        if (temp != NULL)
        {
            nextnode = temp->next;
        }
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