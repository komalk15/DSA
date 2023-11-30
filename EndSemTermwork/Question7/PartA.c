// Q7. Find height of a binary search tree

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int value);
struct node *create(struct node *root,int data);
void inorder(struct node *root);
int search(struct node *root,int );

int main()
{
    struct node *root=NULL;
    int value;
    int ch=1;
    int n;
    while(ch==1)
    {
        printf("\nEnter the value:    ");
        scanf("%d",&value);
        root=create(root,value);
        printf("\nEnter  1 to continue or 0 to exit ");
        scanf("%d",&ch);
    }
    printf("\nInorder traversal of the root is :  ");
    inorder(root);
    printf("\nEnter the value to search  :  ");
    scanf("%d",&n);
    search(root,n);
    if(search(root,n))
    {
        printf("\nValue is found");
    }
    else
    {
        printf("\nvalue is not found");
    }
    return 0;
}
struct node *newNode(int value)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
int search(struct node * root,int n)
{
    if(root==NULL)
    {
        return 0 ;
    }
    if(root->data ==n)
    {
        
        return 1;
    }
    else if(n > root->data)
    {
        return search(root->right,n);
    }
    else
    {
        return search(root->left,n);
    }


}
struct node *create(struct node *root,int value)
{
    if(root==NULL)
    {
        return newNode(value);
    }
    if(value < root->data)
    {
        root->left=create(root->left,value);

    }
    if(value > root->data)
    {
        root->right=create(root->right, value);
    }
    return root;


}
void inorder(struct node *root)
{
    if(root==NULL)
    {
        return ;
    }
    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);


}