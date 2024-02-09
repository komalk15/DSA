#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
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

    printf("Enter the data of the node which is to be deleted: ");
    int value;
    scanf("%d", &value);
    delete(&head, value);
    display(head);

    return 0;
}

void insert(node **head, int n)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = n;
    newnode->next = *head;

    if (*head == NULL)
    {
        *head = newnode;
        newnode->next = *head;
    }
    else
    {
        node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display(node *head)
{
    node *temp;
    temp = head;

    if (head == NULL)
    {
        printf("No node found\n");
    }
    else
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

void delete(node **head, int value)
{
    if (*head == NULL)
    {
        printf("No node found\n");
        return;
    }

    node *curr = *head;
    node *prev = NULL;

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
    if (*head == NULL)
    {
        printf("No node to delete\n");
        return;
    }

    node *temp = *head;
    node *last = *head;

    while (last->next != *head)
    {
        last = last->next;
    }

    *head = temp->next;
    last->next = *head;
    free(temp);
}
