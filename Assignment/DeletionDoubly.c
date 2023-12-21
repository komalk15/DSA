#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;

} node;
void insert(node **head, int n);
void delete(node **head, int value);
void display(node *head);
void deleteFromBeg(node **head);

int main()
{
    
    node *head = NULL;
    insert(&head, 9);
    insert(&head, 3);
    insert(&head, 6);
    insert(&head, 4);
    display(head);

    printf("\nEnter the data of the node which is to be deleted:    ");
    int value;
    scanf("\n%d", &value);
    delete (&head, value);
    display(head);
    return 0;
}

void insert(node **head, int n)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    node *temp = *head;
    newnode->data = n;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (*head == NULL)
    {
        *head = temp = newnode;
    }
    else
    {

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
}
void display(node *head)
{
    node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("No node found");
    }
    else
    {
        while (temp != NULL)
        {

            printf("\n%d", temp->data);
            temp = temp->next;
        }
    }
}
void delete(node **head, int value)
{
    node *curr;
    node *prev;
    int pos = 0;
    node *nextnode;
    curr = (*head);
    int i;
    if (curr == (*head) && curr->data == value)
    {
        deleteFromBeg(head);
        return;
    }
    while (curr->next->data != value)
    {
        curr = curr->next;
    }

    if (curr->next->data == value)
    {
        nextnode = curr->next;
        curr->next = nextnode->next;
        free(nextnode);
        curr->next->prev = curr->next;
    }
}

void deleteFromBeg(node **head)
{
    node *temp;

    if (*head == NULL)
    {
        printf("No node to delete");
    }
    else
    {
        temp = *head;
        (*head) = temp->next;
        free(temp);
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
    }
}