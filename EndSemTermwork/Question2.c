#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *insert(struct node *head, int value);
struct node *create(struct node *A, struct node *B);

void display(struct node *head);
int main()
{
    struct node *A, *B, *S;
    A = B = S = NULL;

    int ch=1;
    int chr=1;
    int value;

    printf("\nEnter elements of List A ");
    while (ch == 1)
    {
        printf("\nEnter the value: ");
        scanf("%d", &value);
        A = insert(A, value);
        printf("Enter 1 to continue or 0 to exit: ");
        scanf("%d", &ch);
    }
    printf("\nEnter elements of List B ");
    while (chr == 1)
    {
        printf("\nEnter the value: ");
        scanf("%d", &value);
        B = insert(B, value);
        printf("Enter 1 to continue or 0 to exit: ");
        scanf("%d", &chr);
    }

    do
    {
        printf("\nEnter 1: Create\n");
        printf("\nEnter 2: Display\n");
        printf("\nEnter 3: Exit\n");

        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            S = create(A, B);
            printf("Linked List S created.\n");
            break;
        case 2:
            if (S != NULL)
            {
                display(S);
            }
            else
            {
                printf("List S is empty\n");
            }
            break;
        case 3:
            printf("Exit\n");
            break;
        default:
            printf("Invalid ");
        }

    } while (ch != 3);

    return 0;
}
struct node *insert(struct node *head, int value)

{
    struct
 
node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        return newnode; // Insert at the beginning of an empty list
    }

    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newnode; 
    return head;
}


struct node *create(struct node *A, struct node *B)
{
    struct node *S = NULL;
    struct node *tail = NULL;

    while (A != NULL || B != NULL)
    {
        if (A != NULL)
        {
            S = insert(S, A->data);
            A = A->next;
        }

        if (B != NULL)
        {
            S = insert(S, B->data);
            B = B->next;
        }
    }

    return S;
}

void display(struct node *head)
{
    printf("Linked List: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
