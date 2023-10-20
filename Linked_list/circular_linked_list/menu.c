#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *tail;
void insert(NODE **head, int val)
{
    NODE *itr, *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = val;
    temp->next = NULL;
    if (*head == 0)
    {
        *head = tail = temp;
        tail->next = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
        tail->next = *head;
        return;
    }
}

void insertatbeg(NODE **head, int val)
{
    NODE *temp, *itr;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = val;
    temp->next = *head;
    *head = temp;
    tail->next = *head;
}

void insertatend(NODE **head, int val)
{
    NODE *temp, *itr;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = val;
    tail->next = temp;
    tail = temp;
    temp->next = *head;
}

void insertafter(NODE **head, int val, int pos)
{
    NODE *temp, *itr;
    int i = 1;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = val;
    itr = *head;
    while (i < pos)
    {
        itr = itr->next;
        i++;
    }
    temp->next = itr->next;
    itr->next = temp;
}

void insertbefore(NODE **head, int val, int pos)
{
    NODE *temp, *itr;
    int i = 1;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = val;
    itr = *head;
    while (i < pos - 1)
    {
        itr = itr->next;
        i++;
    }
    temp->next = itr->next;
    itr->next = temp;
}
void delbeg(NODE **head)
{
    NODE *temp, *itr;
    if (head == 0)
    {
        printf("EMPTY LINKED LIST");
    }
    else if (*head == tail)
    {
        tail = 0;
        free(tail);
        printf("NOW THE LIST IS EMPTY");
        return;
    }
    else
    {
        temp = *head;
        *head = temp->next;
        tail->next = *head;
        free(temp);
        return;
    }
}
void delend(NODE **head)
{
    NODE *temp, *itr;
    itr = tail->next;
    if (head == 0)
    {
        printf("EMPTY LINKED LIST");
    }
    else if (tail->next == tail)
    {
        tail = 0;
        free(itr);
        printf("NOW THE LIST IS EMPTY");
    }
    else
    {

        while (itr->next != tail->next)
        {
            temp = itr;
            itr = itr->next;
        }
        temp->next = tail->next;
        tail = temp;
        free(itr);
        return;
    }
}

void delnode(NODE **head)
{
    int pos, i = 1;
    printf("enter position :  ");
    scanf("%d", &pos);
    NODE *temp, *itr;
    itr = *head;
    if (head == 0)
    {
        printf("EMPTY LINKED LIST ");
    }
    else if (pos == 1)
    {
        delbeg(&head);
    }
    else
    {

        while (i < pos - 1)
        {
            itr = itr->next;
            i++;
        }
        temp = itr->next;
        itr->next = temp->next;
        free(temp);

        return;
    }
}

void display(NODE **head)
{
    NODE *itr, *temp;
    temp = tail->next;

    // first method to print all elements
    /* while(temp->next!=tail->next)
      {
          printf("%d",temp->data);
          temp=temp->next;
      }
      printf("%d",tail->data);*/

    // second method to print all elements
    do
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
}
void main()
{
    NODE *head = NULL;
    int ch, val, value, op, pos;

    head = 0;
    do
    {

        printf("ENTER DATA  : ");
        scanf("%d", &val);
        insert(&head, val);

        printf("DO YOU WANT TO CONTINUE : 0 OR 1   ");
        scanf("%d", &ch);
    } while (ch == 1);
    while (1)
    {
        printf("*******OPERATIONS*******\n");
        printf("\n1.INSERT AT BEG\n2.INSERT AT END\n3.INSERT BEFORE \n4.INSERT AFTER\n5.DELETE BEG\n6.DELETE END\n7.DELETE A NODE\n 8.DISPLAY\n9.EXIT\n");
        printf("ENTER YOUR CHOICE :  ");
        scanf("%d", &op);
        switch (op)
        {

        case 1:
            printf("enter value :  ");
            scanf("%d", &value);
            insertatbeg(&head, value);
            break;
        case 2:
            printf("enter value :  ");
            scanf("%d", &value);
            insertatend(&head, value);
            break;
        case 3:
            printf("enter value :  ");
            scanf("%d", &value);
            printf("enter value :  ");
            scanf("%d", &pos);
            insertafter(&head, value, pos);
            break;
        case 4:
            printf("enter value :  ");
            scanf("%d", &value);
            printf("enter value :  ");
            scanf("%d", &pos);
            insertbefore(&head, value, pos);
            break;
        case 5:
            delbeg(&head);
            break;
        case 6:
            delend(&head);
            break;
        case 7:

            delnode(&head);
            break;
        case 8:
            display(&head);
            break;
        case 9:
            printf("     EXIT       \n");
            exit(0);
        default:
            printf("   WRONG CHOICE \n");
            break;
        }
    }
}


