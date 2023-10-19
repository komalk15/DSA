//Palindrome using stack
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#define Max_size 100000
void push(int st[], int *top,int x);
void pop(int st[],int *top);
void display(int st[],int *top);
void check_pallindrome(int st[],int *top,char *str);
int main()
{
    int top=-1;
    int n;
    int c;
    int stack[Max_size];
    char str[Max_size]="komok";
    check_pallindrome(stack,&top,str);
    

}

void check_pallindrome(int st[],int *top,char *str)
{
    int length=strlen(str);
    int mid=strlen(str)/2;
    int i;
    for(i=0;i<mid;i++)
    {
        push(st,top,str[i]);

    }
    if(length%2==0)
    {
        i++;
    }
    if(st[*top]==str[i])
    {
        pop(st,top);

    }
    if(*top==-1)
    {
        printf("Its a pallindrome");
    }
}
void push(int st[],int *top,int x)
{
    if(*top==Max_size-1)
    {
        printf("Overflow");
    }
    else
    {
        
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

