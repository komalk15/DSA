#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void insert(node **head, int value);
void display(node **head);
struct node *rotateByKgroup(node **head, int k, int size);
int length(node **head);

int main()
{
    node *head;
    head = NULL;
    int k;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    printf("Original linked list: ");
    display(&head);

    printf("\nEnter the places by which you want to rotate the linked list: ");
    scanf("%d", &k);

    head=rotateByKgroup(&head, k, length(&head));

    printf("After reversing linked list in k group is : ");
    display(&head);

    return 0;
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

int length(node **head)
{
    int count = 0;
    struct node *temp;
    temp = *head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

struct node *rotateByKgroup(node **head, int k, int size)
{
    int count = 0;
    struct node *curr = *head, *prev = NULL, *nxt = NULL;
    while (count < k && curr )
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }

    size = size - k;

    if (nxt && size >= k)
    {
        (*head)->next = rotateByKgroup(&nxt, k, size);
    }
    else
    {
        (*head)->next = nxt;
    }
    return prev;
}

void display(node **head)
{
    node *temp;
    temp = *head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
