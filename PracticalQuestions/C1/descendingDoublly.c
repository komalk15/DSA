/*INSERT ELEMENTS IN DESCENDING */
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;
void insert(node **head, int val);
void display(node *head);
void insert(node **head, int val)
{
    node *temp, *itr;
    temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = 0;
    temp->prev = 0;
    if (*head == 0)
    {
        *head = temp;
        return;
    }
    if (val > (*head)->data)
    {
        temp->next = *head;
        (*head)->prev=temp;
        *head = temp;
        return;
    }
    itr = *head;
    while (itr->next != NULL && val < itr->next->data)
    {
        itr = itr->next;
    }
    temp->next = itr->next;
    if(temp->next!=NULL)
    {
        temp->next->prev=temp;
    }
    itr->next = temp;

}

void display(node *head)
{
    struct node *itr;
    itr = head;
    while (itr != 0)
    {
        printf("%d->", itr->data);
        itr = itr->next;
    }
}
int main()
{
    node *head = 0;
    int val, ch = 1;
    while (ch)
    {
        printf("\nenter element to insert :  ");
        scanf("%d", &val);
        insert(&head, val);
        display(head);
        printf("\nWant to insert more ? ");
        scanf("%d", &ch);
    }

    return 0;
}