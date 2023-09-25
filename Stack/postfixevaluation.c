#include<stdio.h>
#include<string.h> 
int evaluate(int b1,int b2,char op);
void push(int st[],int value,int *top,int max);
int pop(int st[],int  *top);


int main()
{
    char s[100]="23+2-5";
    int max=100;
    int st[max];
    int top=-1;
    int n=strlen(s);
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            push(st,s[i]-'0',& top,max);
        
        }
        else
        {
            int b2=pop(st,&top);
            
            int b1=pop(st,&top);
        
            int result=evaluate(b1,b2,s[i]);
            push(st,result,&top,max);
        }

    }
    int temp = pop(st, &top);
    printf("%d\n", temp);
    return 0;
}
int evaluate(int b1,int b2,char op)
{
    switch(op)
    {
        case '+':return b1+b2;
        case '-':return b1-b2;
        case '*':return b1*b2;
        default: return 0;
    }
}

void push(int st[],int value,int *top,int max)
{
    if(*top>max-1)
    {
        printf("\nStack is full");

    }
    else
    {
        st[++(*top)]=value;
        
        
    }

}
int pop(int st[],int *top)
{
    if(*top==-1)
    {
        printf("\nStack is Empty");
        return 0;

    }
    else
    {
      
        return st[(*top)--];
    }
    
}
