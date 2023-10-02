#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
void insert(node **head, int n);
void delete(node **head, int pos);
void display(node *head);
void deleteFromBeg(node **head);

int main()
{
    int choice, c;
    node *head = NULL;

    do
    {
        printf("\nEnter 1: Insert\nEnter 2: Delete\nEnter 3: Display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("\nEnter the element to insert: ");
            int n;
            scanf("%d", &n);
            insert(&head, n);
            break;
        }
        case 2:
        {
            printf("\nEnter the position of node which is to be deleted");
            int pos;
            scanf("\n%d", &pos);
            delete (&head, pos);
            break;
        }
        case 3:
        {
            printf("The list is: ");
            display(head);
            break;
        }
        default:
        {
            break;
        }
        }
        printf("\nEnter 1 to continue and 0 to exit");
        scanf("%d", &c);

    } while (c != 0);
    return 0;
}
void insert(node **head, int n)
{
    node *temp, *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = n;
    newnode->next = NULL;
    if (*head == NULL)
    {
        *head = temp = newnode;
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
    node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("No node found");
    }
    else
    {
        while (temp != NULL)
        {

            printf("\n%d", temp->data);
            temp = temp->next;
        }
    }
}
void delete(node **head, int pos)
{
    node *temp;
    node *nextnode;
    temp = *head;
    int i ;
    if(pos==0)
    {
        deleteFromBeg(head);
        return;

    }
    for (i =0;i< pos - 1;i++)
    {
        temp = temp->next;
    
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
}

void deleteFromBeg(node **head)
{
    node *temp;
    temp = *head;
    if (*head == NULL)
    {
        printf("No node to delete");
    }
    else
    {

        *head = (*head)->next;
        temp->next=NULL;
        free(temp);
    
    }
}