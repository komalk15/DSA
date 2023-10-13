
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void create_list(int n, struct node **head);
void display_linked_list(struct node *head);
void search(int value, struct node **head, int n);

int main()
{
    struct node *head = NULL;
    create_list(5, &head);
    create_list(9, &head);
    create_list(8, &head);

    printf("\nThe the data of the list  is ");
    display_linked_list(head);

    printf("\nThe list after the insertion of node is ");
    search(9, &head, 4);
    display_linked_list(head);

    return 0;
}
void create_list(int n, struct node **head)
{

    struct node *temp, *newnode;
    int data, i = 0;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;
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

void search(int value, struct node **head, int n)
{
    struct node *temp = *head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = NULL;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            
            newnode->next = temp->next;
            temp->next = newnode;
            break;
        }
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found");
    }
}

void display_linked_list(struct node *head)
{
    struct node *temp;
    temp = head;

    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
