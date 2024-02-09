#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
void insert(node **head, int value);
void display(node *head);
struct node *add(node *head1,node **head2);
struct node *solve(node**head1,node**head2)

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    int k;
    printf("\nElements of first list:   ");
    insert(&head1, 1);
    insert(&head1, 2);
    insert(&head1, 3);
    insert(&head1, 4);
    insert(&head1, 5);
    display(head1);
    printf("\nElements of secondlist:   ");
    insert(&head2, 1);
    insert(&head2, 3);
    insert(&head2, 4);
    insert(&head2, 6);
    insert(&head2, 9);
    display(head2);
    node * result=add(&head1,&head2);
    return 0;
}

void insert(node **head,node **tail int value)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=NULL;
    if(*head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp ;
        tail=temp;
    }
    
    
}
struct node *solve(node **head1,node **head2)
{
    head1=reverse(head1);
    head2=reverse(head2);
    node *ans=add(head1,head2);
    ans=reverse(ans);
    return ans;

}
struct node *add(node **head1,node **head2)
{
    int carry=0;
    
    while(*head!=NULL && *head!=NULL)
    {
        int sum =(*head1)->data+(*head2)->data +carry;
        digit=sum/10;

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

