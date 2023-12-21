#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

void insert(node **head, int n);
void delete(node **head, int value);
void display(node *head);
void deleteFromBeg(node **head);

int main()
{
    
    node *head = NULL;
    insert(&head, 9);
    insert(&head, 3);
    insert(&head, 6);
    insert(&head, 4);
    display(head);
    

    printf("\nEnter the data of the node which is to be deleted: ");
    int value;
    scanf("%d", &value);
    delete (&head, value);
    display(head);
    return 0;
}

void insert(node **head, int n)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = n;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (*head == NULL)
    {
        *head = newnode;
        (*head)->next = *head;
        (*head)->prev = *head;
    }
    else
    {
        node *tail = (*head)->prev;
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = *head;
        (*head)->prev = newnode;
        *head = newnode;
    }
}

void display(node *head)
{
    node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("No node found");
    }
    else
    {
        do
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

void delete(node **head, int value)
{
    node *curr = *head;
    node *prev = NULL;
    if (curr == NULL)
    {
        printf("No node found\n");
        return;
    }

    do
    {
        if (curr->data == value)
        {
            if (prev == NULL)
            {
                deleteFromBeg(head);
                return;
            }
            prev->next = curr->next;
            curr->next->prev = prev;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != *head);

    printf("Node with value %d not found\n", value);
}

void deleteFromBeg(node **head)
{
    node *temp = *head;
    if (*head == NULL)
    {
        printf("No node to delete\n");
        return;
    }
    else if ((*head)->next == *head)
    {
        free(temp);
        *head = NULL;
    }
    else
    {
        node *tail = (*head)->prev;
        *head = temp->next;
        (*head)->prev = tail;
        tail->next = *head;
        free(temp);
    }
}
