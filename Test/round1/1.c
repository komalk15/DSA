#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *reverseInKgroup(struct node **head, int k, int size);
int lenght(struct node **head);
// void swa(struct node *head){
//     struct node *temp=head;
//     while(temp != NULL && temp->next != NULL){
//         int dat = temp->data;
//         temp->data = temp->next->data;
//         temp->next->data = dat;
//         temp = temp->next->next;
//     }
// }
void display(struct node *head); 
void create(struct node **head, int value);

int main()
{
    struct node *head = NULL;
    create(&head, 1);
    create(&head, 2);
    create(&head, 3);
    create(&head, 4);
    create(&head, 5);
    create(&head, 6);
    create(&head, 7);
    printf("The linked list is: ");
    display(head);
    printf("Enter the value of key: ");
    int k;
    scanf("%d", &k);
    printf("List after being rotated is : ");
    head = reverseInKgroup(&head, k, lenght(&head));
    display(head);
    return 0;
}
void create(struct node **head, int value)
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
        temp = newnode;
    }
}
int lenght(struct node **head)
{
    int count = 0;
    struct node *temp = *head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
struct node *reverseInKgroup(struct node **head, int k, int size)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return NULL;
    }
    int count = 0;
    struct node *curr = *head, *nxt = NULL, *prev = NULL;
    while (curr && count < k)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }
    size = size - k;

    if (nxt && size >= k)
    {
        (*head)->next = reverseInKgroup(&nxt, k, size);
    }
    else
    {
        (*head)->next = nxt;
    }
    return prev;
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