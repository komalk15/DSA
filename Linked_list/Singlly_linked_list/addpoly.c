#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    int power;
    struct node *next;
};

struct node *createNode(int data, int power)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Invalid");
        exit(1);
    }
    newnode->data = data;
    newnode->power = power;
    newnode->next = 0;
    return newnode;
}

struct node *impleList(struct node *head, int data, int power)
{
    struct node *temp, *newnode;
    newnode = createNode(data, power);
    temp = head;
    if (head == 0)
    {
        head = newnode;
    }
    else
    {
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}
struct node *impleList1(struct node *top, int data, int power)
{
    struct node *temp, *newnode;
    newnode = createNode(data, power);
    temp = top;
    if (top == 0)
    {
        top = newnode;
    }
    else
    {
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return top;
}
void display(struct node *head)
{
    struct node *temp = head;
    if (head == 0)
    {
        printf("List is empty");
    }
    else
    {
        while (temp->next != 0)
        {
            printf("%dx^%d", temp->data, temp->power);
            temp = temp->next;
            printf(" + ");
        }
        printf("%dx^%d", temp->data, temp->power);
    }
}

struct node *addP(struct node *head, struct node *top, int m, int n)
{
    struct node *temp, *prev;
    if (n >= m)
    {
        temp = head;
        prev = top;
        while (temp != 0)
        {
            while (prev != 0)
            {
                if (temp->power == prev->power)
                {
                    temp->data = (temp->data) + (prev->data);
                }
                prev = prev->next;
            }
            temp = temp->next;
            prev = top;
        }
        return head;
    }
    else
    {
        prev = head;
        temp = top;
        while (temp != 0)
        {
            while (prev != 0)
            {
                if (temp->power == prev->power)
                {
                    temp->data = (temp->data) + (prev->data);
                }
                prev = prev->next;
            }
            temp = temp->next;
            prev = head;
        }
        return top;
    }
}
int main()
{
    struct node *head, *top = 0;
    head = 0;
    int i = 1, j = 1, data, power, p, c = 0, n, m, data2, data3, data1, choice, pos, count = 0;
    printf("Enter the total no of terms u want in 1 exp:\n");
    scanf("%d", &n);
    while (i <= n)
    {
        printf("Enter the coefficient for %d term ->:", i);
        scanf("%d", &data);
        printf("Enter the power for %d term ->:", i);
        scanf("%d", &power);
        head = impleList(head, data, power);
        i++;
        
    }
    printf("Expression 1 is :\n");
    display(head);
    printf("\nEnter the total no of terms u want in 2 exp:\n");
    scanf("%d", &m);
    while (j <= m)
    {
        printf("Enter the coefficient for %d term ->:", j);
        scanf("%d", &data1);
        printf("Enter the power for %d term ->:", j);
        scanf("%d", &p);
        top = impleList1(top, data1, p);
        j++;
        
    }
    printf("Expression 2 is :\n");
    display(top);

    head = addP(head, top, m, n);
    printf("\nSum :\n");
    display(head);
    return 0;
}