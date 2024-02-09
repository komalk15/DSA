//Q6. Write a C program to create two link lists positive and negative from Original linked list, so that
//positive linked list contains all positive elements and negative linked list contains negative elements.
//Positive and negative linked lists should use the node of existing original linked list.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insert(struct node **head, int value);
void display(struct node *head);
void create(struct node *head, struct node **positive, struct node **negative);

int main()
{
    struct node *head = NULL;
    struct node *positive = NULL;
    struct node *negative = NULL;
    int choice, value;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Display Original Linked List\n");
        printf("3. Display Linked List with Positive Numbers\n");
        printf("4. Display Linked List with Negative Numbers\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insert(&head, value);
            break;
        case 2:
            printf("\nThe original linked list is: ");
            display(head);
            break;
        case 3:
            create(head, &positive, &negative);
            printf("\nThe linked list containing positive numbers is: ");
            display(positive);
            break;
        case 4:
            create(head, &positive, &negative);
            printf("\nThe linked list containing negative numbers is: ");
            display(negative);
            break;
        case 5:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}

void create(struct node *head, struct node **positive, struct node **negative)
{
    struct node *curr = head;
    while (curr != NULL)
    {
        if (curr->data >= 0)
        {
            insert(positive, curr->data);
        }
        else
        {
            insert(negative, curr->data);
        }
        curr = curr->next;
    }
}

void insert(struct node **head, int value)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->data = value;

    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


