#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void insert(node **head, node **last, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    if (*head == NULL)
    {
        temp->next = NULL;
        (*head) = temp;
        (*last) = temp;
    }
    else
    {
        (*last)->next = temp;
        temp->next = NULL;
        (*last) = temp;
    }
}

void display(node *head, node *last)
{
    if (head == NULL)
    {
        printf("Nothing to display\n");
    }
    else
    {
        printf("Elements are : ");
        while (head != last)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("%d\n", head->data);
    }
}

void deleteAlternatingSec(node **head, node **last)
{
    node *newHead = (*head)->next, *temp = *head;
    (*head) = newHead;
    if (*head == NULL) // Input= NULL
    {
        printf("UnderFlow\n");
    }
    else if (*head == *last) // Input = 10
    {
        free(*head);
        *head = NULL;
        *last = NULL;
    }
    else if ((*head)->next == *last) // Input = 10 20
    {
        free(*head);
        *head = *last;
    }
    else
    {
        while (temp != *last && newHead != *last)
        {
            free(temp);
            temp = newHead->next;
            if (temp == *last)
            {
                newHead->next = NULL;
                break;
            }
            newHead->next = temp->next;
            newHead = temp->next;
        }
        if (temp == *last)
        {
            free(temp);
            *last = newHead;
        }
    }
}

int main()
{
    node *head = NULL, *last = NULL;
    insert(&head, &last, 10);
    insert(&head, &last, 20);
    insert(&head, &last, 30);
    
    display(head, last);

    deleteAlternatingSec(&head, &last);
    display(head, last);

    return 0;
}