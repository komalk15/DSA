#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *tail;
void create_circular_linked_list(struct node **head, int value);
void display(struct node *head);
void reverse(struct node **head);
void insert(struct node **head, int value);
void delete(struct node **head);
int main()
{
    struct node *head = NULL;
    int n;
    create_circular_linked_list(&head, 9);
    create_circular_linked_list(&head, 3);
    create_circular_linked_list(&head, 5);
    create_circular_linked_list(&head, 6);
    printf("\nThe data of the linked list is:   ");
    display(head);

    printf("\nThe data of the linked list is:   ");
    reverse(&head);
    display(head);

    printf("\nThe data of the linked list is:   ");
    insert(&head, 8);
    display(head);

    printf("\nThe data of the linked list is:   ");
    delete(&head);
    display(head);

    return 0;
}
void create_circular_linked_list(struct node **head, int value)
{
    int i;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->data = value;
    if (*head == NULL)
    {
        *head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
        tail->next = *head;
    }
}

void insert(struct node **head, int value)
{
    struct node *newnode, *temp;
    int pos, i = 1, l;
    printf("Enter the position");
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->data = value;
    scanf("%d", &pos);
    temp = tail->next;
    while (temp->next != tail)
    {
        temp = temp->next;
        l++;
    }
    if (pos < 0 || pos > l)
    {
        printf("Invalid position");
    }
    else if (pos == l)
    {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
    else if (pos == 1)
    {
        newnode->next = tail->next;
        tail->next = newnode;
    }
    else
    {
        temp = tail->next;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void reverse(struct node **head)
{
    struct node *prev = NULL;
    struct node *current = tail->next;
    struct node *nextnode = current->next;
    if (tail == NULL)
    {
        printf("Invalid");
    }
    else
    {

        while (current != tail)
        {
            prev = current;
            current = nextnode;
            nextnode = current->next;
            current->next = prev;
        }
        nextnode->next = tail;
        tail = nextnode;
    }
}

void display(struct node *head)
{

    struct node *temp;
    temp = tail->next;
    if (tail == NULL)
    {
        printf("Empty list");
    }
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
}

void delete(struct node **head)
{
    struct node *newnode, *temp;
    int pos, i = 1, l;
    printf("Enter the position");
    scanf("%d", &pos);
    temp = tail->next;
    if (tail == 0)
    {
        printf("No node to delete");
    }
    while (temp->next != tail)
    {
        temp = temp->next;
        l++;
    }
    if (pos < 0 || pos > l)
    {
        printf("Invalid position");
    }
    else if (pos == l)
    {
        struct node *prev;
        struct node *current;
        if (current->next == current)
        {
            current->next = NULL;
            free(current);
        }
        else
        {
            while (current->next != tail->next)
            {
                prev = current;
                current = current->next;
                prev->next = tail->next;
                tail = prev;
                free(current);
            }
        }
    }
    else if (pos == 1)
    {
        if (tail->next == temp)
        {
            tail->next = NULL;
            free(temp);
        }
        else
        {
            tail->next = temp->next;
            free(temp);
        }
    }
    else
    {
        struct node *nextnode;
        struct node *current;

        temp = tail->next;
        while (i < pos - 1)
        {
            current = current->next;
            i++;
        }
        nextnode = current->next;
        current->next = nextnode->next;
        free(nextnode);
    }
}