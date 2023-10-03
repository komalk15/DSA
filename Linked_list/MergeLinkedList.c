#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;
void solve(node **first, node **second);
void display(node *head);
void sort(node **first, node **second) ;
void insert(int value, node **head);
int main()
{

    node *head1=NULL;
    node *head2 = NULL;
    // inserting value in node one
    insert(1, &head1);
    insert(3, &head1);
    insert(5, &head1);
    insert(7, &head1);
    insert(9, &head1);
    // inserting value in node
    insert(1, &head2);
    insert(3, &head2);
    insert(5, &head2);
    insert(7, &head2);
    insert(9, &head2);
    sort(&head1, &head2);
    display(&head1);
}
void insert(int value, node **head)
{
    node *temp,*newnode;
    newnode=(node *)malloc(sizeof(node));
    if(head==0)
    {
        temp=head=newnode;

    }
    else
    {
        temp->next=newnode;
        temp=temp->next;


    }
}
void solve(node **first, **second)
{
    node *curr1 = *first;
    node *next1 = curr1->next;
    node *curr2 = *second;
    node *next2 = curr2->next;
    while (next1 != NULL && next2 != NULL)
    {
        if (curr2->data >= curr1->data && curr2->data <= next->data)
        {

            curr1->next = curr2;
            // to keep the track of the next node in list one following step is done

            next2 = curr2->next
            //curr2 is joined to next1;
            curr2->next = next1;
            curr1 = curr2;
            //curr2 will point to next2 because first node is deleted;

            curr2 = next2;
        }
        else if(curr2->data >= curr1->data && curr2->data <= next->data)
        {
            curr1=curr1->next;
            next1=next1->next;
            if(next1=NULL)
            {
                curr1->next=curr2;
                return *first;
            }
        }
        
    }
    return 1;
}
void sort(node **first, **second)
{
    if (*first == NULL)
    {
        return second;
        
    }
    else
    {
        return first;
       
    }
    if ((*first)->data <= (*second)->data)
    {
        return solve(&first, &second);
    }
    else
    {
        return solve(&second, &first);
    }
}
void display(node *head1)
{
    node *temp=head1;
    while(temp->next!=NULL)
    {
        printf("%d",temp->data);
    }
}