#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data1;
    int data2;
    struct node *next;

} *head1, *head2;
void create_list_2(int n);
void create_list_1(int n);
void display_1();
void display_2();
int main()
{
    int n1, n2;

    create_list_1(n1);

    create_list_2(n2);

    printf("First linked list is: ");
    display_1();
    printf("First linked list is: ");
    display_2();
}
void create_list_1(int n)
{
    int i;
    struct node *newnode, *temp;
    head1 = temp = NULL;
    // head1 = temp = NULL;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (head1 == NULL)
    {
        head1 = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}
void create_list_2(int n)
{
    int i;
    struct node *newnode, *temp;
    head2 = temp = NULL;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (head2 == NULL)
    {
        head2 = temp = newnode;
    }
    else
    {
        head2->next = newnode;
        temp = newnode;
    }
}

void display_1()
{

    struct node *temp;
    if (head1 == NULL)
    {
        printf("Empty list");
    }
    else
    {
        while (temp->next != NULL)
        {
            printf("%d  %d", temp->data1, temp->data2);
            temp = temp->next;
        }
    }
}
void display_2()
{

    struct node *temp;
    temp = head2;
    if (head2 == NULL)
    {
        printf("Empty list");
    }
    else
    {
        while (temp->next != NULL)
        {
            printf("%d  %d", temp->data1, temp->data2);
            temp = temp->next;
        }
    }
}
