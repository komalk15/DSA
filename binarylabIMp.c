#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node * left;
    struct node * right;
};
struct node *create(struct node * root)
{
    int x;
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    
    scanf("%d",&x);
    if(x==-1)
    {
        return 0;
    }
    newnode->val=x;
    printf("Enter the data for the left child:  ");
    newnode->left=create(root);
    printf("Enter the data for the right child: ");
    newnode->right=create(root);
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
int main()
{
    struct node *  root =NULL;
    root = create(root);
    printf("\nInorder Traveral is: ");
    inorder(root);
    printf("\nPreorder Traveral is: ");
    preorder(root);
    printf("\nPostorder Traveral is: ");
    postorder(root);
    return 0;


}