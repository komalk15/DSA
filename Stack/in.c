#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100
void push(char st[], int *top, char value);
char pop(char st[], int *top);
int Infix_to_postfix(char st[], char *str, int *top);
int prec(char a);
void reverse(char *str);
void brackets(char *str);

int main()
{
    int top = -1;
    char st[max];
    char str[max] = "((a/b)+c)-(d+(e*f))";
    Infix_to_postfix(st, str, &top);
    return 0;
}
void reverse(char *str)
{
    int i=0;
    int length=strlen(str);
    int j=length-1;
    char temp;
    while(i<j)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;


    }
}

void brackets(char *str)
{
    int i=0;
    while (str[i] != '\0')
    {
        if (str[i] == '(')
        {
            str[i]=')';
        }
        else if( str[i]==')')
        {
            str[i]='(';
        }
        i++;
    }
}

int Infix_to_postfix(char st[], char *str, int *top)
{

    char ans[max] = " ";
    int a = 0;
    int i;
    reverse(str);
    brackets(str);
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            ans[a] = str[i];
            a++;
        }
        else
        {
            if (*top == -1 || str[i] == '(')
            {
                push(st, top, str[i]);
            }
            else
            {
                if (prec(str[i]) >= prec(st[*top]))
                {
                    push(st, top, str[i]);
                }
                else
                {
                    if (str[i] == ')')
                    {
                        while (st[*top] != '(')
                        {
                            ans[a] = pop(st, top);
                            a++;
                        }
                        pop(st, top);
                    }
                    else
                    {
                        while (*top != -1 && prec(str[i]) <= prec(st[*top]))
                        {
                            ans[a] = pop(st, top);
                            a++;
                        }
                        push(st, top, str[i]);
                    }
                }
            }
        }
    }
    while (*top != -1)
    {
        ans[a] = pop(st, top);
        a++;
    }
    reverse(ans);
    puts(ans);

    return 0;
}

int prec(char a)
{
    switch (a)
    {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    case '%':
        return 3;
    case '(':
        return 0;
    }
    return -1;
}
void push(char st[], int *top, char value)
{
    if (*top > max - 1)
    {
        printf("\nOverflow");
    }
    else
    {
        (*top)++;
        st[*top] = value;
    }
}
char pop(char st[], int *top)
{
    char t;
    if (*top == -1)
    {
        printf("\nUnderflow");
    }
    else
    {
        t = st[*top];
        (*top)--;
    }
    return t;
}
