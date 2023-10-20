#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *tail;
void create_circular_linked_list(struct node **head,int value);
void display(struct node *head);
int main()
{
    struct node *head = NULL;
    int n;
    create_circular_linked_list(&head,9);
    create_circular_linked_list(&head,3);
    create_circular_linked_list(&head,5);
    create_circular_linked_list(&head,6);
    printf("\nThe data of the linked list is:   ");
    display(head);
}
void create_circular_linked_list(struct node **head,int value)
{
    int i;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=value;
    if (*head == NULL)
    {
        *head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
        tail->next = *head;
    }
}
void display(struct node *head)
{

    struct node *temp;
    temp=tail->next;
    if (head == NULL)
    {
        printf("Empty list");
    }
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
}
