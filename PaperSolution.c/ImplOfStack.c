
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void create_list(int n, struct node **head);
void display_linked_list(struct node *head);
void reverse(struct node **head);

int main()
{
    struct node *head = NULL;
    create_list(5, &head);
    create_list(9, &head);
    create_list(8, &head);

    printf("\nThe the data of the list  is ");
    display_linked_list(head);

    printf("\nThe the data of the list after being reversed  is ");
    reverse(&head);
    display_linked_list(head);

    return 0;
}
void create_list(int n, struct node **head)
{

    struct node *temp, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = NULL;

    if (*head == NULL)
    {
        *head=newnode;
        
    }
    else
    {
        temp=*head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        
    }
}

void reverse(struct node **head)
{
    struct node *curr = *head;
    struct node *next = NULL;
    struct node *prev = NULL;
    while (curr != NULL)
    {
        next =curr ->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    (*head) = prev;
}
void display_linked_list(struct node *head)
{
    struct node *temp;
    temp = head;

    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
