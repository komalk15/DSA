#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};
struct node * newNode(int val)
{
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;



}
struct  node *insert(struct node *root,int val)
{
    if(root==NULL)
    {
        return newNode(val);;
    }
    struct node ** queue=(struct node **)malloc(sizeof(struct node*)*100);
    int front=0;
    int rear=0;
    queue[rear++]=root;
    while(front<rear)
    {
        struct node *current=queue[front++];
        printf("%d",current->data);
        if(current->left!=NULL)
        {
            queue[rear++]=current->left;
        }
        if(current->right!=NULL)
        {
            queue[rear++]=current->right;
        }
       
    }
    return root;
    free(queue);

}
int main()
{
    struct node *root=NULL;
    int ch=1;
    int val;
    while(ch==1)
    {
        printf("\nEnter the value:  ");
        scanf("%d",&val);
        root = insert(root, val);
        printf("\nPress 1 to continue and 0 to exit");
        scanf("%d",&ch);
    }
    return 0;

}