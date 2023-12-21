#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory cannot be allocated");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct node *impleList(struct node *head, int data)
{
    struct node *newnode, *temp;
    newnode = createNode(data);
    temp = head;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}

struct node *rev(struct node *head)
{
    struct node *temp, *prev, *nextnode;
    temp = nextnode = head;
    prev = NULL;
    while (nextnode != NULL)
    {
        nextnode = nextnode->next;
        temp->next = prev;
        prev = temp;
        temp = nextnode;
    }
    head = prev;
    return head;
}

void display(struct node *head)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (temp->next != NULL)
        {
            printf("%d", temp->data);
            temp = temp->next;
            printf(" -> ");
        }
        printf("%d", temp->data);
    }
}

struct node *subtractList(struct node *head, struct node *top)
{
    struct node *temp, *prev, *newList = NULL;
    temp = head;
    prev = top;
    int a, b, c;
    while (temp != NULL && prev != NULL)
    {
        if (temp->data < prev->data)
        {
            b = temp->data + 10;
            c = b - prev->data;
            temp->next->data = temp->next->data - 1;
        }
        else
            c = temp->data - prev->data;
        newList = impleList(newList, c);
        temp = temp->next;
        prev = prev->next;
    }
    return newList;
}

int main()
{
    struct node *head = NULL, *top = NULL, *listL;
    int n, a, b, m, i = 1, j = 1, choice;

    do
    {
        printf("\nMenu:\n");
        printf("1. Enter the first number\n");
        printf("2. Enter the second number\n");
        printf("3. Subtract and Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter first number -> ");
            scanf("%d", &n);
            while (n > 0)
            {
                a = n % 10;
                head = impleList(head, a);
                n = n / 10;
                i++;
            }
            break;
        case 2:
            printf("Enter second number -> ");
            scanf("%d", &m);
            while (m > 0)
            {
                b = m % 10;
                top = impleList(top, b);
                m = m / 10;
                j++;
            }
            break;
        case 3:
            listL = subtractList(head, top);
            printf("\nList 1 : ");
            head = rev(head);
            display(head);

            printf("\n\nList 2 : ");
            top = rev(top);
            display(top);

            printf("\n\nSubtraction of numbers is : ");
            listL = rev(listL);
            display(listL);
            break;
        case 4:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
