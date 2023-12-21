#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
void insert(node **head, int value);
void display(node *head);
node *sort(node **first, node **second);
node *solve(node **first, node **second);

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    int k;
    printf("\nElements of first list:   ");
    insert(&head1, 1);
    insert(&head1, 2);
    insert(&head1, 3);
    insert(&head1, 4);
    insert(&head1, 5);
    display(head1);
    printf("\nElements of secondlist:   ");
    insert(&head2, 1);
    insert(&head2, 3);
    insert(&head2, 4);
    insert(&head2, 6);
    insert(&head2, 9);
    display(head2);
    printf("\nList after being sorted is :   ");
    struct node *sorted = sort(&head1, &head2);
    display(sorted);
}
node *sort(node **first, node **second)
{
    if ((*first) == NULL)
    {
        return *second;
    }
    else if ((*second) == NULL)
    {
        return *first;
    }
    else if ((*first)->data < (*second)->data)
    {
        return solve(first, second);
    }
    else
    {
        return solve(second, first);
    }
}
node *solve(node **first, node **second)

{
    if((*first)->next==NULL)
    {
        (*first)->next=*second;
        return *first;
    }
    node *curr1 = *first;
    node *next1 = curr1->next;
    node *curr2 = *second;
    node *next2;
    while (next1 != NULL && next2 != NULL)
    {
        if (curr2->data >= curr1->data && curr2->data <= next1->data)
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = curr1->next;
            next1 = next1->next;

            if (next1 == NULL)
            {
                curr1->next = curr2;
                return *first;
            }
        }
    }
    return *first;
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