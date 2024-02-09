// Write a program in ‘C’ to convert an infix expression to a postfix expression using the concept of stack.
#include <stdio.h>
#include <string.h>
#define size 20
void push(char st[], int *top, char value);
char pop(char st[], int *top);
int prec(char a);
int main()
{

    int top = -1, a = 0;
    char ans[size] = " ";
    char s[size] = "((a/b)+c)^(d+(e*f))";
    char st[size];
    int i;

    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {

            ans[a] = s[i];
            a++;
        }
        else
        {
            if (top == -1 || s[i] == '(')
                push(st, &top, s[i]);
            else
            {
                if (prec(s[i]) >= prec(st[top]))
                {
                    push(st, &top, s[i]);
                }
                else
                {
                    if (s[i] == ')')
                    {
                        while (st[top] != '(')
                        {
                            ans[a] = pop(st, &top);
                            a++;
                        }
                        char t = pop(st, &top);
                    }
                    else
                    {
                        while (top != -1 && prec(s[i]) <= prec(st[top]))
                        {
                            ans[a] = pop(st, &top);
                            a++;
                        }
                        push(st, &top, s[i]);
                    }
                }
            }
        }
    }
    while (top != -1)
    {
        ans[a] = pop(st, &top);
        a++;
    }
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
    case '^':
        return 4;
    case '(':
        return 0;
    }
    return -1;
}

char pop(char st[], int *top)
{
    char t;
    if (*top == -1)
    {
        printf("\nStack is Empty");
    }
    else
    {

        t = st[*top];
        (*top)--;
    }
    return t;
}
void push(char st[], int *top, char value)
{
    if (*top == size - 1)
    {
        printf("\nStack is full");
    }
    else
    {
        (*top)++;
        st[*top] = value;
    }
}