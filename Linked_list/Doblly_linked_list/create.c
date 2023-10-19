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
int main()
{

    struct node *head=NULL;
    Create_list(&head, 7);
    Create_list(&head, 5);
    Create_list(&head, 4);
    Create_list(&head, 8);
    printf("\nThe the data of the list  is ");
    Display_linked_list(head);
    return 0;
}
void Create_list(struct node **head, int n)
{
    struct node *temp, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=n;

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