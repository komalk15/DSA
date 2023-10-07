
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};
void create_list(int n, struct node **head);
void display_linked_list(struct node *head);
void pallindrome(struct node **head);
struct node *reverse(struct node **head);
struct node *FindMiddle(struct node **head);

// 5123215
int main()
{
    struct node *head = NULL;
    create_list(5, &head);
    create_list(1, &head);
    create_list(2, &head);
    create_list(3, &head);
    create_list(2, &head);
    create_list(1, &head);
    create_list(5, &head);

    printf("\nThe the data of the list  is ");
    display_linked_list(head);

    // Check for palllindrome
    pallindrome(&head);
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

struct node *FindMiddle(struct node **head)
{
    struct node *fast;
    struct node *slow;
    slow = *head;
    fast = (*head)->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct node *reverse(struct node **head)
{

    struct node *curr;
    struct node *prev = NULL;
    struct node *nextnode = NULL;
    curr = *head;
    while (curr != NULL)
    {
        nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }

    return prev;
}
void pallindrome(struct node **head)
{
    if ((*head)->next == NULL)
    {
        printf("\nEmpty but is a pallindrome");
    }
    struct node *middle;
    middle = FindMiddle(head);
    struct node *temp = middle->next;
    middle->next = reverse(&temp);
    struct node *head1 = *head;
    struct node *head2 = middle->next;
    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            printf("\nNot a pallindrome");
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    printf("\npallindrome");
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
