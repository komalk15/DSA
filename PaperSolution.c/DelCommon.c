
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void create_list(int n, struct node **head);
void display_linked_list(struct node *head);
void duplicates(struct node **head1, struct node **head2);

int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    create_list(1, &head1);
    create_list(3, &head1);
    create_list(5, &head1);
    create_list(7, &head1);
    create_list(9, &head1);

    printf("\nThe the data of the list 1  is:  ");
    display_linked_list(head1);

    create_list(1, &head2);
    create_list(2, &head2);
    create_list(3, &head2);
    create_list(7, &head2);
    create_list(10, &head2);

    printf("\nThe the data of the list 2  is:  ");
    display_linked_list(head2);

    duplicates(&head1, &head2);
    
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
void duplicates(struct node **head1, struct node **head2)
{
   
    struct node *temp1 = *head1;
    struct node *temp2 = *head2;
    while (temp1 != NULL)   
    {
        temp2=*head2;
        while (temp2 != NULL)
        {
            if ((temp1)->data == (temp2)->data)
            {
                printf("\nThe data same in both the nodes is: %d", temp1->data);
            }
            temp2 = temp2->next;
        }
        temp1=temp1->next;
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
