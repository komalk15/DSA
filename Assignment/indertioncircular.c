#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;

void insert(node **head, int val) {
    node *temp, *itr;
    temp = (node *)malloc(sizeof(node));
    temp->data = val;

    if (*head == NULL) {
        temp->prev = temp;
        temp->next = temp;
        *head = temp;
        return;
    }

    itr = *head;
    while (itr->next != *head && itr->next->data < val) {
        itr = itr->next;
    }

    temp->next = itr->next;
    temp->prev = itr;
    itr->next->prev = temp;
    itr->next = temp;

    if (val < (*head)->data) {
        *head = temp;
    }
}

void display(node *head) {
    if (head == NULL) {
        return;
    }

    node *itr = head;
    do {
        printf("%d ", itr->data);
        itr = itr->next;
    } while (itr != head);
}

int main() {
    node *head = NULL;
    int val, ch = 1;

    while (ch) {
        printf("Enter element to insert: ");
        scanf("%d", &val);
        insert(&head, val);
        display(head);
        printf("Want to insert more? (1 for yes, 0 for no): ");
        scanf("%d", &ch);
    }

    return 0;
}
