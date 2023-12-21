#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char Product_Id;
    char Product_Name[50];
    int Total_sale;
    char Product_Grade;
    struct node *next;
};

struct node *create(char id, const char *name, int sale, char grade);
void enqueue(struct node **front, struct node **rear, char id, const char *name, int sale, char grade);
void dequeue(struct node **front, struct node **rear);
void display(struct node *front);

int main()
{
    struct node *front = NULL;
    struct node *rear = NULL;

    int choice;
    char id;
    char name[50];
    int sale;
    char grade;

    do
    {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the details (ID Name Sales Grade): \n");
            printf("\nEnter id: ");
            scanf(" %c", &id);
            printf("\nEnter name: ");
            scanf("%s", name);
            printf("\nEnter sale: ");
            scanf(" %d", &sale);
            printf("\nEnter grade: ");
            scanf(" %c", &grade);
            enqueue(&front, &rear, id, name, sale, grade);
            break;
        case 2:
            dequeue(&front, &rear);
            break;
        case 3:
            display(front);
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

struct node *create(char id, const char *name, int sale, char grade)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->Product_Id = id;
    strcpy(newnode->Product_Name, name);
    newnode->Total_sale = sale;
    newnode->Product_Grade = grade;
    newnode->next = NULL;
    return newnode;
}

void enqueue(struct node **front, struct node **rear, char id, const char *name, int sale, char grade)
{
    struct node *newnode = create(id, name, sale, grade);

    if (*rear == NULL)
    {
        *front = *rear = newnode;
    }
    else
    {
        (*rear)->next = newnode;
        *rear = newnode;
    }

    printf("Product enqueued\n");
}

void dequeue(struct node **front, struct node **rear)
{
    if (*front == NULL)
    {
        printf("Queue is empty. Cannot dequeue.\n");
    }
    else
    {
        struct node *temp = *front;
        *front = (*front)->next;

        // If dequeuing the last element, update the rear pointer
        if (*front == NULL)
        {
            *rear = NULL;
        }

        printf("Product dequeued: %c\n", temp->Product_Id);
        free(temp);
    }
}

void display(struct node *front)
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Product Queue:\n");
        while (front != NULL)
        {
            printf("ID: %c, Name: %s, Sales: %d, Grade: %c\n", front->Product_Id, front->Product_Name, front->Total_sale, front->Product_Grade);
            front = front->next;
        }
    }
}
