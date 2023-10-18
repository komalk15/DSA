
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void create_circular_linked_list(struct node **head,int value);
void display(struct node *head);
void reverse(struct node **head);
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
    reverse(&head);
    display(head);
    return 0;

}
void create_circular_linked_list(struct node **head,int value)
{
    int i;
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=value;
    if (*head == NULL)
    {
        *head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
        temp->next = *head;
    }
}

void reverse(struct node **head)
{
    
}
void display(struct node *head)
{

    struct node *temp;
    if (head == NULL)
    {
        printf("Empty list");
    }
    else
    {
        temp = head;
        do
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        } while (temp->next != head);
    }
}
