#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node * left;
    struct node * right;
};
struct node *create(struct node * root,int data);
struct node * newNode(int data);
void preorder(struct node * root);
void postorder(struct node * root);
void inorder(struct node * root);

int main()
{
    struct node *  root =NULL;

    int x;
    int ch=1;
    int num;
    while(ch==1)
    {
        printf("Enter the data: ");
        scanf("%d",&x);
        root = create(root,x);
        printf("Enter 1 to continue and 0 to discontinue:   ");
        scanf("%d",&ch);

    }
    printf("\nInorder Traveral is: ");
    inorder(root);
    printf("\nPreorder Traveral is: ");
    preorder(root);
    printf("\nPostorder Traveral is: ");
    postorder(root);
    printf("\nEnter the data to search ");
    scanf("%d",&num);

    search()
    return 0;


}
struct node *create(struct node * root,int data)
{
    
    if(root==NULL)
    {
        return newNode(data);

    }
    if(data < root->val)
    {
        root->left=create(root->left,data);

    }
    if(data >root->val)
    {
        root->right=create(root->right,data);
    }
    return root;

}
struct node * newNode(int data)
{
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->val=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;

}

void preorder(struct node * root)
{
    if(root==NULL)
    {
        return ;
    }
    printf("%d->",root->val);
    preorder(root->left);
    preorder(root->right);

}

void postorder(struct node * root)
{
    if(root==NULL)
    {
        return ;
    }
   
    postorder(root->left);
    postorder(root->right);
    printf("%d->",root->val);

}
void inorder(struct node * root)
{
    if(root==NULL)
    {
        return ;
    }
   
    inorder(root->left);
    printf("%d->",root->val);
    inorder(root->right);

}
