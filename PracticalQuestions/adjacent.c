#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void swa(struct node *head);
void create(struct node **head, int value);
void display(struct node *head);

int main()
{
    struct node *head = NULL;
    create(&head, 1);
    create(&head, 2);
    create(&head, 3);
    create(&head, 4);
    create(&head, 5);
    

    printf("The linked list is: ");
    display(head);

    // Swap adjacent nodes
    swa(head);

    printf("\nList after swapping adjacent nodes: ");
    display(head);

    return 0;
}

void swa(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        int data = temp->data;
        temp->data = temp->next->data;
        temp->next->data = data;
        temp = temp->next->next;
    }
}

void create(struct node **head, int value)
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->data = value;

    if (*head == NULL)
    {
        *head = newnode;
        temp = newnode;
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
    printf("NULL\n");
}
