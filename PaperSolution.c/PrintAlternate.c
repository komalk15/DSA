
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void create_list(int n, struct node **head);
void display_linked_list(struct node *head);
void print_alternate(struct node **head);

int main()
{
    struct node *head=NULL;
    create_list(5, &head);
    create_list(9, &head);
    create_list(8, &head);

    printf("\nThe the data of the list  is ");
    display_linked_list(head);
    printf("\nThe the data of alternative list is:  ");
    print_alternate(&head);
    
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

void print_alternate(struct node **head)
{
    int i=0;
    struct node *temp=*head;
    while(temp!=NULL)
    {
        if(i%2==0)
        {
            printf("%d",temp->data);

        }
        i=i+1;
        temp=temp->next;

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
