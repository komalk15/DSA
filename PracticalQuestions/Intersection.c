#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void insert(node **head, int value);
void display(node *head);
node *intersection(node **head1, node **head2);

int main()
{
    // 1st 3->6->9->15->30
    // 2nd 10->15->30
    node *head1 = NULL;
    insert(&head1, 3);
    insert(&head1, 6);
    insert(&head1, 9);

    node *intersectionNode = (node *)malloc(sizeof(node));
    intersectionNode->data = 15;
    intersectionNode->next = NULL;
    insert(&head1, intersectionNode->data);

    insert(&head1, 30);
    printf("List A is: ");
    display(head1);

    node *head2 = NULL;
    insert(&head2, 10);
    (head2)->next = intersectionNode; // Point to the intersection node
    printf("\nList B is: ");
    display(head2);

    // Connect the second list to the intersection node
    node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = intersectionNode;

    node *ans = intersection(&head1, &head2);

    if (ans != NULL)
    {
        printf("\nThe point at which both the lists intersect is %d", ans->data);
    }
    else
    {
        printf("\nThe lists do not intersect.");
    }

    return 0;
}

node *intersection(node **head1, node **head2)
{
    node *temp1 = *head1;
    node *temp2 = *head2;

    while (temp1 != temp2)
    {
        if (temp1 == NULL)
        {
            temp1 = *head2; // Start over with the second list
        }
        else
        {
            temp1 = temp1->next;
        }

        if (temp2 == NULL)
        {
            temp2 = *head1; // Start over with the first list
        }
        else
        {
            temp2 = temp2->next;
        }
    }

    return temp1;
}

void insert(node **head, int value)
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

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
