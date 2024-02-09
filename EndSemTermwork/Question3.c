#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create(struct node *head, int data);
void display(struct node *head);
struct node *partition(struct node *head, int V);


int main()
{
    struct node *head = NULL;
    int n, data, V, i = 1, count = 0;
    printf("Enter the no of elements :\n");
    scanf("%d", &n);
    while (i <= n)
    {
        printf("Enter %d element -> ", i);
        scanf("%d", &data);
        head = create(head, data);
        i++;
        count++;
    }
    printf("\nTotal elements: %d\n", count);
    printf("\nElements in the list are : ");
    display(head);

    printf("\n\nEnter the value for partitioning: ");
    scanf("%d", &V);
    printf("\nPartitioned Linked List : ");
    head =partition(head, V);
    display(head);
    return 0;
}


struct node *create(struct node *head, int data)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = 0;
    
    temp = head;
    if (head == 0)
    {
        head = newnode;
    }
    else
    {
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp = head;
    if (head == 0)
    {
        printf("List is empty\n");
    }
    else
    {
        while (temp->next != 0)
        {
            printf("%d", temp->data);
            temp = temp->next;
            printf(" -> ");
        }
        printf("%d", temp->data);
    }
}
struct node *partition(struct node *head, int V)
{
    struct node *temp = head, *right = 0, *left = 0, *prev;
    while (temp != 0)
    {
        if (temp->data <= V)
        {
            right = create(right, temp->data);
        }
        else
            left = create(left, temp->data);
        temp = temp->next;
    }
    prev = right;
    while (prev->next != 0)
    {
        prev = prev->next;
    }
    prev->next = left;
    return right;
}

