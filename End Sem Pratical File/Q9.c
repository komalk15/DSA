#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node node;

node *createNode(int val){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    return newnode;
}

void insert(node **root, int val){
    if ((*root) == NULL){
        (*root) = createNode(val);
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else{
        if (val > (*root)->data)
            insert(&(*root)->right, val);
        
        else
            insert(&(*root)->left, val);
    }
}

void preorder(node *root){
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root){
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(node *root){
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main(){
    node *root = NULL;
    int choice, ans = 0, val = 0;
    do{
        printf("\nMenu:\n");
        printf("1. Insert a value in BST\n");

        printf("2. Display the tree\n");
        printf("0. Exit\n");
        printf("Enter the choice : ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            printf("Enter the elements in the BST\n");
            do{
                scanf("%d", &val);
                insert(&root, val);
                printf("Enter 1 to enter the next element and 0 to exit. ");
                scanf("%d", &ans);
            } while (ans != 0);
            break;

        case 2:
            do{
                printf("\nEnter 1 to display BST with preorder traversal\nEnter 2 to display BST with inorder traversal\nEnter 3 to display BST with postorder traversal\nEnter 0 to exit : ");
                scanf("%d",&ans);
                
                switch(ans){
                    case 1:
                        preorder(root);
                        break;

                    case 2:
                        inorder(root);
                        break;

                    case 3:
                        postorder(root);
                        break;

                    case 0:
                        printf("Exiting the program\n");
                        break;

                    default:
                        printf("Invalid choice.Try again !\n");
                }
            } while (ans != 0);

        case 0:
            printf("Exiting the program\n");
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 0);
}