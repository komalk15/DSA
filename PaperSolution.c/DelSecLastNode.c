#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void createList(struct node **head, int value);
void display(struct node *head);
void delete(struct node **head, int n);
int main()
{
    struct node *head = NULL;
    createList(&head, 16);
    createList(&head, 6);
    createList(&head, 36);
    createList(&head, 26);
    createList(&head, 65);
    createList(&head, 61);
    createList(&head, 33);
    createList(&head, 74);
   
    display(head);
    printf("\nList after the deletion of last second node is :    \n");
    delete (&head,3);
    display(head);
}

void createList(struct node **head, int value)
{
    struct node *newnode, *temp;

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
        temp = temp->next;
    }
}

void delete(struct node **head, int n)
{
    if (*head == NULL || (*head)->next == NULL) {
        // The list is empty or has only one element, so we can't delete the second last node.
        printf("List is too short to delete the second last node.\n");
        return;
    }

    if((*head)->next->next==NULL){
        (*head)=(*head)->next;
        return;
    }

    struct node* current = *head;
    struct node* prev = NULL;

    while (current->next->next != NULL) {
        prev = current;
        current = current->next;    // 1 3 6 7 9         prev<-6  cur<-7
    }

    // Update the 'next' pointer of the second last node to skip the last node
    prev->next = current->next;     //6 9

    // Free the memory of the last node
    free(current);          // free 7






    // struct node *curr,*temp, *del;
    // int count=0,i=0;
    // temp = *head;
    // if(*head==NULL ||(*head)->next==NULL){
    //     printf("Too short to delete the second last node");
    //     return;
    // }
    // if((*head)->next->next==NULL){
    //     (*head)=(*head)->next;
    //     return;
    // }

    // while(temp->next!=NULL)
    // {
    //     temp=temp->next;
    //     count++;
    // }
    // count-=n;
    // temp = *head;
    // while(i<count){
    //     i++;
    //     temp=temp->next;
    // }
    // // 6 7 9         temp<-6  del<-7

    // del=temp->next;
    // temp->next=temp->next->next;
    // free(del);
}
void display(struct node *head)
{

    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}