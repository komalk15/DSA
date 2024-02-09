#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insert(struct node **head, int value);
void display(struct node *head);
void reverse(struct node **head);

int main()
{
    struct node *head = NULL;
    insert(&head, 6);
    insert(&head, 3);
    insert(&head, 5);
    insert(&head, 8);
    insert(&head, 4);
    printf("The linked list is:");
    display(head);
    printf("The linked after being reversed is:");
    display(head);
}

void insert(struct node **head, int value)
{

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->data = value;
    struct node *temp = *head;
    if (*head == NULL)
    {
        *head = temp = newnode;
        newnode->next = *head;
    }
    else
    {
        
        while (temp->next !=*head)
        {
            temp=temp->next;
        }
        temp->next = newnode;
        temp = newnode;
        newnode->next = *head;
    }
}

void display(struct node *head)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}
void reverse(struct node **head)
{
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *nextnode = NULL;

    do
    {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    } while (current != *head);

    (*head)->next = prev;
    *head = prev;
}