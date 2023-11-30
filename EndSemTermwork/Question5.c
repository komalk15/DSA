// Write a C program to craeate a single linked list , like L0 -> L1 -> … -> Ln-1 -> Ln. Write another C
// fucntion to rearrange the nodes in the list so that the new formed list is : L0 -> Ln -> L1 -> Ln-1 -> L2-> Ln-2 .You are required to do this in place without altering the nodes’ values.

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insert(struct node **head, int value);
void display(struct node *head);
struct node *middle(struct node **head);
struct node *reverse(struct node **head);
void rearrange(struct node **head);

int main()
{
    struct node *head = NULL;
    insert(&head, 1);
    insert(&head, 3);
    insert(&head, 5);
    insert(&head, 2);
    insert(&head, 4);
    insert(&head, 6);
    insert(&head, 7);

    printf("\nThe linked is : ");
    display(head);

    printf("\nThe linked is after rearrangement is  : ");
    rearrange(&head);
    display(head);

    return 0;
}
struct node *middle(struct node **head)
{
    struct node *fast = *head;
    struct node *slow = *head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
struct node *reverse(struct node **head)
{
    struct node *curr = *head;
    struct node *nextnode = NULL;
    struct node *prev = NULL;
    while (curr != NULL)
    {
        nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }
    return prev;
}

void rearrange(struct node **head)
{
    struct node *mid = middle(head);
    struct node *temp = mid->next;
    mid->next = reverse(&temp);
    struct node* head1 = *head;
    struct node *head2 = mid->next;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = 0;
    *head = newnode;
    struct node *curr = *head;
    while (head1 && head2)
    {
        // First add the element from list
        if (head1)
        {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
        // Then add the element from the second list
        if (head2)
        {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }
    // Assign the head of the new list to head pointer
    *head = (*head)->next;
}

void insert(struct node **head, int value)
{
    struct node *newnode;
    struct node *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->data = value;
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
void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
}