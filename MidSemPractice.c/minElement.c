#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create_list(int n, struct node **head);
void display_linked_list(struct node *head);
void find_min(struct node **head);
void delete_node(struct node **head, int min);
void delete_node_after(struct node **head, int min);
void delete_node_before(struct node **head, int min);

int main()
{
    struct node *head = NULL;
    create_list(6, &head);
    create_list(1, &head);
    create_list(2, &head);
    create_list(8, &head);

    printf("\nThe data of the list is ");
    display_linked_list(head);
    find_min(&head);
    display_linked_list(head);

    return 0;
}

void create_list(int n, struct node **head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = NULL;

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

void find_min(struct node **head)
{
    struct node *temp = *head;
    struct node *prev = NULL;
    int min = INT_MAX;

    while (temp != NULL)
    {
        if (min > (temp->data))
        {
            min = temp->data;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("\nMinimum element is %d", min);
    // printf("\nList after deleting the minimum element is: ");
    // delete_node(head, min);
    // printf("\nList after deleting the node after minimum element is: ");
    // delete_node_after(head,min);
    printf("\nList after deleting the node before minimum element is: ");
    delete_node_before(head,min);
}
// 6 1 2 8
// void delete_node_after(struct node **head, int min)
// {
//     struct node *temp = *head;
//     struct node *nextnode;

//     // Check if the head node should be deleted

//     while (temp != NULL && temp->data == min)
//     {
//         *head = temp->next;
//         free(temp);
//         temp = *head;
//     }
//     // Traverse the list and delete nodes after the node with the value min
//     while (temp != NULL && temp->next != NULL)
//     {
//         if (temp->data == min)
//         {
//             nextnode = temp->next;
//             temp->next = nextnode->next;
//             temp=nextnode;
//             free(nextnode);
//         }
//         else
//         {
//             temp = temp->next;
//         }
//     }
// }



// 6 1 2 8
void delete_node_before(struct node **head, int min)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    if ((*head)->next->data == min)
    {
        struct node *temp = *head;
        *head = temp->next;
        free(temp);
        return;
    }

    struct node *prev = *head;
    struct node *current = (*head)->next;

    while (current->next != NULL)
    {
        if (current->next->data == min)
        {
            struct node *temp = current;
            prev->next = current->next;
            free(temp);
            return;
        }
        prev = current;
        current = current->next;
    }
}



// void delete_node(struct node **head, int min)
// {
//     struct node *temp = *head;
//     struct node *prev = NULL;
//     while (temp != NULL)
//     {
//         if (temp->data == min)
//         {
//             if (temp == *head)
//             {
//                 *head = temp->next;
//                 free(temp);
//                 temp = *head;
//             }
//             else
//             {
//                 prev->next = temp->next;
//                 free(temp);
//                 temp = prev->next;
//             }
//         }
//         else
//         {
//             prev = temp;
//             temp = temp->next;
//         }
//     }
// }

void display_linked_list(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
