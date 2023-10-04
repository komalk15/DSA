#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
void insert(node **head, int value);
void display(node *head);
void deleteAlternating(node **head);



int main()
{
    node *head;
    head = NULL;
    insert(&head, 5);
    insert(&head, 7);
    // insert(&head, 9);
    insert(&head, 4);
    display(head);


    //1 2 3 5
    // output= 2 5
    printf("\nList afer deletion from alternating node is :");
    deleteAlternating(&head);
    display(head);
}
void insert(node **head, int value)
{
    node *temp, *newnode;

    newnode = (node *)malloc(sizeof(node));
    newnode->data = value;
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





// 1 2 3 5
// output= 2 5
void deleteAlternating(node **head)
{
    node *temp;
    node *nextnode;
    node *current=*head;
    nextnode = temp->next;
   

    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    else
    {
        temp=head;
        *head=(*head)->next;
        free(temp);

    }
    while (current!= NULL && current!= NULL)
    {
        
        current->next = current->next;
        current->next = NULL;
        free(nextnode);
        current= current->next;
        if (current!= NULL)
        {
            nextnode = current->next;
        }
    }
}




void display(node *head)
{
    node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}