
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insert(struct node **head, int value);
void display(struct node *head);
void Create(struct node **head,struct node **positive,struct node **negative);

int main()
{
    struct node *head = NULL;
    struct node *positive=NULL;
    struct node *negative=NULL;
    insert(&head, 1);
    insert(&head, 3);
    insert(&head, -4);
    insert(&head, 2);
    insert(&head, -4);
    insert(&head, -3);
    insert(&head, 7);

    printf("\nThe original linked is : ");
    display(head);

    Create(&head,&positive,&negative);

    printf("\nThe linked cantaining postive numbers  is : ");
    display(positive);

    printf("\nThe linked cantaining negative numbers  is : ");
   display(negative);


    return 0;
}
void Create(struct node **head,struct node **positive,struct node **negative)
{
   
    struct node *curr=*head;
    while(curr!=NULL)
    {
        if(curr->data >=0)
        {
            insert(positive,curr->data);
        }
        else
        {
            insert(negative,curr->data);

        }
        curr = curr->next;
    }
}
void insert(struct node **head, int value)
{
    struct node *newnode;
    struct node *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->data = value;
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
void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
}
