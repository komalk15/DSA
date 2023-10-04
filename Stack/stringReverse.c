//Write a program in ‘C’ to print the reverse of a string using stack.
#include<stdio.h>
#include<string.h>
#define max 100
void push(char st[],int* top,int value);
char pop(char st[],int* top);


int main()
{
    int top=-1;
    int i;
    char st[max];
    char str[20];
    printf("Enter the string: ");
    fgets(str,20, stdin);
    for(i=0;i<strlen(str);i++)
    {
        push(st,&top,str[i]);

    }
    for(i=0;i<strlen(str);i++)
    {
        str[i]=pop(st,&top);

    }
    printf("Reversed string is ");
    printf("%s",str);
   


}
void push(char st[],int *top,int value) 
{
    if(*top==max-1)
    {
        printf("Overflow");

    }
    else
    {

        (*top)++;
        st[*top]=value;
        
    }
}
char pop(char st[],int *top)
{
    if(*top==-1)
    {
        printf("Underflow");

    }
    else
    {

        return st[(*top)--];
    }
    return -1;
    

}
