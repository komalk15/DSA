// Given a singly linked list and a key, count the number of occurrences of the given key in the linked list. For example, if the given linked list is 1->2->1->2->1->3->1 and the given key is 1, then the output should be 4.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insert(struct node **head, int value);
void display(struct node *head);
int find(struct node *head, int key);
int main()
{
    struct node *head = NULL;
    int k;
    insert(&head, 5);
    insert(&head, 5);
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 8);
    insert(&head, 7);
    insert(&head, 2);
    insert(&head, 2);
    insert(&head, 2);
    insert(&head, 2);
    insert(&head, 4);
    insert(&head, 7);
    printf("\nThe list is : ");
    display(head);
    printf("\nEnter the key: ");
    scanf("%d", &k);
    printf("%d", find(head, k));
}
int find(struct node *head, int key)
{
    struct node *temp = head;
    int count = 0;
    if (head == NULL)
    {
        return 0;
    }
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            count++;
        }

        temp = temp->next;
    }

    return count;
}
void insert(struct node **head, int value)
{
    struct node *temp;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
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
void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
}