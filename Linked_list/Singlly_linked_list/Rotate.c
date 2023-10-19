#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
void insert(node **head, int value);
void display(node *head);
void rotate(node **head, int k);

// Input: linked list = 10->20->30->40->50->60, k = 4
// Output: 50->60->10->20->30->40.

int main()
{
    node *head;
    head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
   
    printf("\nList is :  ");
    display(head);
    printf("\nList after rotation is:  ");
    rotate(&head, 2);
    display(head);
}
void insert(node **head, int value)
{
    node *temp, *newnode;

    newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
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

void display(node *head)
{
    node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}
void rotate(node **head, int k)
{
    // Input: 10->20->30->40->50->60
    //k = 4
    // Output: 50->60->10->20->30->40.

    struct node *current = *head;
    int i = 1;
    while (i<k && current != NULL )
    {
        current = current->next;
        i++;
    }
    
    struct node *nextnode = current;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = *head;
    *head=nextnode->next;
    nextnode->next=NULL;

}