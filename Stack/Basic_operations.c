#include <stdio.h>
#define Max_size 100000
void push(int st[], int *top);
void pop(int st[],int *top);
void peek(int st[], int *top);
void display(int st[],int *top);

int main()
{
    int top=-1;
    int n;
    int c;
    
    int stack[Max_size];
    printf("Enter the choice");
    printf("\n\tEnter the choice\n\t1:push\n\t2:pop\n\t3:peek\n\t4:display");

    do
    {
        printf("\nEnter the choice");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                push(stack,&top);
                break;
            }
            case 2:
            {
                pop(stack,&top);
                break;
            }
            case 3:
            {
                peek(stack,&top);
                break;
            }
            case 4:
            {
                display(stack,&top);
                break;
            }
            case 5:
            {
                printf("Invalid choice\n");
            }
        }

    }while(c != 0);
    return 0;

}
void push(int st[],int *top)
{

    int x;
    if(*top==Max_size-1)
    {
        printf("Overflow");
    }
    else
    {
        printf("Enter the value to want to push in the stack: ");
        scanf("%d",&x);
        (*top)++;
        st[*top]=x;

    }
}
void pop(int st[],int *top)
{
    int item;
    if(*top==-1)
    {
        printf("Underflow");
    }
    else
    {
        item = st[*top];
        (*top)--;

    }
    printf("The value poped is:%d",item);
  
}
void peek(int st[],int * top)
{
    if(*top==-1)
    {
        printf("stack is empty");
    }
    else
    {
        printf("%d",st[*top]);
    }
    
}
void display(int st[],int *top)
{
    int i;
    if(*top==-1)
    {
        printf("Stack is empty");
    }
    else
    {   
        for(i=*top;i>=0;i--)
        {
            printf("\n\t%d",st[i]);
        }
        
    }


}