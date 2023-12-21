#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void create_list(int n, struct node **head);
void display_linked_list(struct node *head);
void detect(struct node **head);
void display_linked_list(struct node *head);

int main()
{
    struct node *head = NULL;
    create_list(5, &head);
    create_list(5, &head);
    create_list(8, &head);
    create_list(9, &head);
    create_list(9, &head);
    create_list(10, &head);
    create_list(10, &head);

    printf("\nThe the data of the list  is:  ");
    display_linked_list(head);
    // Remove duplicate
    detect(&head);
    printf("\nThe the data of the list  after removal of duplicate elements is: ");
    display_linked_list(head);
    return 0;
}
void create_list(int n, struct node **head)
{

    struct node *temp, *newnode;
    int data, i = 0;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;
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

void detect(struct node **head)
{
    struct node *curr, *nextnode;
    curr = *head;
    if (*head == NULL)
    {
        printf("No node");
    }
    while (curr != NULL)
    {
        if (curr->next != NULL && curr->data == curr->next->data)
        {
            nextnode = curr->next->next;
            struct node *nodetobedeleted = curr->next;
            free(nodetobedeleted);
            curr->next = nextnode;
        }
        else
        {
            curr = curr->next;
        }
    }
}