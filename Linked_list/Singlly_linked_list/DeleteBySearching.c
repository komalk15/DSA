#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
void insert(node **head, int n);
void delete(node **head, int value);
void display(node *head);
void deleteFromBeg(node **head);

int main()
{
    int choice, c;
    node *head = NULL;
    insert(&head, 9);
    insert(&head, 3);
    insert(&head, 6);
    insert(&head, 4);
    printf("\nEnter the data of the node which is to be deleted:    ");
    int value;
    scanf("\n%d", &value);
    delete (&head, value);
    display(head);
    return 0;
}

void insert(node **head, int n)
{
    node *temp, *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = n;
    newnode->next = NULL;
    if (*head == NULL)
    {
        *head = temp = newnode;
    }
    else
    {

        node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
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
        pos++;
        curr = curr->next;
    }

    if (curr->next->data == value)
    {
        nextnode = curr->next;
        curr->next = nextnode->next;
        free(nextnode);
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
        temp = (*head)->next;
        free(*head);
        *head = temp;
    }
}