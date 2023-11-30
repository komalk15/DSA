// Q7. W.A.P. to create a binary search tree and perform following operations:
// 1) Search a particular key.
// 2) Delete a node from the tree.
// 3) Find total number of leaf nodes
// 4) Find height of a binary search tree
// 5) Count total numbers of nodes from right hand side of root node
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int value);
struct node *create(struct node *root,int val);
struct node *minVal(struct node *root);
void inorder(struct node *root);
struct node * delete(struct node * root,int val);



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
    printf("\nEnter the value to delete:  ");
    scanf("%d",&n);
    delete(root,n);
    inorder(root);
    
   
  
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
struct node *create(struct node *root,int val)
{
    if(root==NULL)
    {
        return newNode(val);
    }
    if(val < root->data)
    {
        root->left=create(root->left,val);

    }
    if(val > root->data)
    {
        root->right=create(root->right, val);
    }
    return root;


}
struct node *minVal(struct node *root)
{
    struct node *temp=root;
    while(temp->right!=NULL)
    {
        temp=temp->right;
        
    }
    return temp;
}
struct node * delete(struct node * root,int val)
{
    if(root==NULL)
    {
        return root;
    }
    if(root->data==val)
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left!=NULL && root->right==NULL)
        {
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL && root->right!=NULL)
        {
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else
        {
            if(root->left!=NULL && root->right !=NULL)
            {
                int mini =minVal(root->right)->data;
                root->data=mini;
                root->right=delete(root->right,mini);
                return root;
            }
        }
    }
    else if(root->data > val)
    {
        root->left=delete(root->left,val);
        return root;
    }
    else
    {
        root->right=delete(root->right,val);
        return root;

    }
    
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