//Kth largest element without doing any modification in Binary Search Tree.


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
int  Kthsmallest(struct node * root,int i,int k);

int main()
{
    struct node *root=NULL;
    int value;
    int ch=1;
    int k;
    int i=0;
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
    printf("\nEnter the value  :  ");
    scanf("%d",&k);
    printf("%d smallest number is : %d", k, Kthsmallest(root, i, k));

    
}
int  Kthsmallest (struct node * root,int  i,int k)
{
    
    if(root==NULL)
    {
        return -1;
    }
    int left= Kthsmallest(root->left,i,k);
    if(left!=-1)
    {
        return left;
    }
    (i)++;
    if(i==k)
    {
        return root->data;
    }
    return Kthsmallest(root->right,i,k);
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
