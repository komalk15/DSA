#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
void Create_list(struct node **head, int n);
void Display_linked_list(struct node *head);
void delete(struct node **head);
int main()
{

    struct node *head = NULL;
    Create_list(&head, 7);
    Create_list(&head, 5);
    Create_list(&head, 4);
    Create_list(&head, 8);
    printf("\nThe the data of the list  is ");
    Display_linked_list(head);
    printf("\nThe the data of the list after deletion in alternative position is ");
    delete (&head);
    Display_linked_list(head);
    return 0;
}
void Create_list(struct node **head, int n)
{
    struct node *temp, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;

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
//The the data of the list  is 7  5  4  8
//The the data of the list after deletion in alternative position is 7  4
void delete(struct node **head)
{
    struct node *temp;
    struct node *nextnode;
    temp = *head;
    nextnode = temp->next;

    if (*head == NULL)
    {
        return;
    }
    while (temp != NULL && nextnode != NULL)
    {
        temp->next = nextnode->next;
        nextnode->next = NULL;
        nextnode->prev = NULL;
        free(nextnode);
        temp = temp->next;
        if (temp != NULL)
        {
            nextnode = temp->next;
        }
    }
}
