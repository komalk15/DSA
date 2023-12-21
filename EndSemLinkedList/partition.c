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
    printf("Enter the number of elements:\n");
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
    printf("\nElements in the list are: ");
    display(head);

    printf("\n\nEnter the value for partitioning: ");
    scanf("%d", &V);
    printf("\nPartitioned Linked List: ");
    head = partition(head, V);
    display(head);

    // Free the allocated memory
    while (head != NULL)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

struct node *create(struct node *head, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
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
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (temp->next != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}
// struct node *partition(struct node *head, int V)
// {
//     struct node *temp = head, *right = NULL, *left = NULL, *prev;

//     while (temp != NULL)
//     {
//         if (temp->data <= V)
//         {
//             right = create(right, temp->data);
//         }
//         else
//         {
//             left = create(left, temp->data);
//         }
//         temp = temp->next;
//     }

//     if (right == NULL)
//     {
//         // All elements are greater than V, return the original list
//         return head;
//     }

//     temp = right; // The head of the new list is the head of the 'right' list
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }

//     temp->next = left;

//     return right;
// }

struct node *partition(struct node *head, int V)
{
    struct node *temp = head, *right = NULL, *left = NULL, *prev;

    while (temp != NULL)
    {
        if (temp->data <= V)
        {
            right = create(right, temp->data);
        }
        else
        {
            left = create(left, temp->data);
        }
        temp = temp->next;
    }
    temp = right;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = left;

    return right;
}

