#include <stdio.h>
#include <stdlib.h>

struct node{
    int coeff;
    int power;
    struct node *next;
};
typedef struct node node;

void insert(node **headp1, int c, int p){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->coeff = c;
    newnode->power = p;
    if ((*headp1) == NULL){
        (*headp1) = newnode;
        newnode->next = NULL;
    }
    else{

        node *temp = (*headp1);
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->next = NULL;
    }
}

void addition(node *headp1, node *headp2, node **headp3)
{
    node *temp1 = headp1, *temp2 = headp2;
    while (temp1 != NULL && temp2 != NULL){
        if (temp1->power == temp2->power){
            int sum = temp1->coeff + temp2->coeff;
            insert(&(*headp3), sum, temp1->power);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->power > temp2->power){
            insert(&(*headp3), temp1->coeff, temp1->power);
            temp1 = temp1->next;
        }
        else{
            insert(&(*headp3), temp2->coeff, temp2->power);

            temp2 = temp2->next;
        }
    }

    if (temp1 != NULL && temp2 == NULL){
        insert(&(*headp3), temp1->coeff, temp1->power);
        temp1 = temp1->next;
    }
    else if (temp1 == NULL && temp2 != NULL){
        insert(&(*headp3), temp2->coeff, temp2->power);
        temp2 = temp2->next;
    }
}

void display(node *headp1){
    if (headp1 == NULL){
        printf("The polynomial not present\n");
    }
    else{
        node *temp = headp1;
        while (temp != NULL){
            if (temp->power > 1)
                printf("%dx^%d ", temp->coeff, temp->power);

            else if (temp->power == 0)
                printf("%d ", temp->coeff);
    

            else
                printf("%dx ", temp->coeff);
            temp = temp->next;

            if (temp != NULL)
                printf("+ ");
        }
        printf("\n");
    }
}

int main(){
    int c = 0, p = 0, choice = 1, ans;
    node *headp1 = NULL, *headp2 = NULL, *headp3 = NULL;
    do{
        printf("\nMenu:\n");
        printf("1. Enter the first polynomial\n");
        printf("2. Display the first polynomial\n");
        printf("3. Enter the second polynomial\n");
        printf("4. Add polynomials\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            do{
                printf("Enter the coefficient: ");
                scanf("%d", &c);
                printf("Enter the power of the variable: ");
                scanf("%d", &p);
                insert(&headp1, c, p);
                printf("Enter '1' to enter the next term and '-1' to exit: ");
                scanf("%d", &choice);
            } while (choice != -1);
            break;

        case 2:
            printf("Enter 1 to display first polynomial.\n2 to display second polynomial.\n3 to display the resultant added polynomial : ");
            scanf("%d", &ans);
            switch (ans){
            case 1:
                printf("The first polynomial is:\n");
                display(headp1);
                break;

            case 2:
                printf("The second polynomial is:\n");
                display(headp2);
                break;
            case 3:
                printf("The resultant polynomial is:\n");
                display(headp3);
                break;
            default:
                printf("Invalid choice\n");
            };
            break;

        case 3:
            do{
                printf("Enter the coefficient: ");
                scanf("%d", &c);
                printf("Enter the power of the variable: ");
                scanf("%d", &p);
                insert(&headp2, c, p);
                printf("Enter '1' to enter the next term and '-1' to exit: ");
                scanf("%d", &choice);
            } while (choice != -1);
            break;

        case 4:
            addition(headp1, headp2, &headp3);
            break;

        case 5:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while(choice != 5);
    return 0;
}
