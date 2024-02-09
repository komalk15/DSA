#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void display(node *);
node *solve(node *, node **);
node *sort(node **, node **); // Corrected declaration
void insert(int, node **);

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;

    // inserting values into the first linked list
    insert(1, &head1);
    insert(3, &head1);
    insert(5, &head1);
    insert(7, &head1);
    insert(9, &head1);

    // inserting values into the second linked list
    insert(1, &head2);
    insert(4, &head2);
    insert(6, &head2);
    insert(8, &head2);
    insert(10, &head2);

    node *sorted = sort(&head1, &head2); // Corrected function call
    display(sorted);
}

void insert(int value, node **head)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;

    if (*head == NULL)
    {
        *head = newnode;
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
node *sort(node **first, node **second)
{
    if (*first == NULL)
    {
        return *second;
    }
    if (*second == NULL)
    {
        return *first;
    }

    if ((*first)->data <= (*second)->data)
    {
        return solve(*first, second);
    }
    else
    {
        return solve(*second, first);
    }
}
node *solve(node *first, node **second)
{
    if (first->next == NULL)
    {
        (first)->next = *second;
        return first;
    }
    node *curr1 = first;
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
                return first;
            }
        }
    }
    return first;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
