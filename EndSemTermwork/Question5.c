#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insert(struct node **head, int value);
void display(struct node *head);
struct node *middle(struct node *head);
struct node *reverse(struct node *head);
void rearrange(struct node **head);

int main()
{
    struct node *head = NULL;
    int choice, value;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Display Linked List\n");
        printf("3. Rearrange Linked List\n");
        printf("4. Exit\n");
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
            printf("\nThe linked list is: ");
            display(head);
            break;
        case 3:
            printf("\nRearranging the linked list...\n");
            rearrange(&head);
            printf("Linked List after rearrangement: ");
            display(head);
            break;
        case 4:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}

struct node *middle(struct node *head)
{
    struct node *fast = head;
    struct node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

struct node *reverse(struct node *head)
{
    struct node *curr = head;
    struct node *nextnode = NULL;
    struct node *prev = NULL;
    while (curr != NULL)
    {
        nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }
    return prev;
}

void rearrange(struct node **head)
{
    struct node *mid = middle(*head);
    struct node *temp = mid->next;
    mid->next = NULL;
    struct node *head2 = reverse(temp);
    struct node *head1 = *head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = 0;
    *head = newnode;
    struct node *curr = *head;

    while (head1 || head2)
    {
        if (head1)
        {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }

        if (head2)
        {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }

    *head = (*head)->next;
}

void insert(struct node **head, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
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

    printf("Node inserted with value: %d\n", value);
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
