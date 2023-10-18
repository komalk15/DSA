#include <stdio.h>
#include <string.h>
#define max 100
void Infix_to_postfix(char st[], char *s, int *top);
void push(char st[], int *top, char value);
char pop(char st[], int *top);
int prec(char a);
int main()
{
    char s[max] = "((a/b)+c)-(d+(e*f))";
    int top = -1;
    char st[max];
    Infix_to_postfix(st, s, &top);
    return 0;
}
void Infix_to_postfix(char st[], char *s, int *top)
{
    int a = 0;
    char ans[max] = " ";
    
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
            if (*top == -1 || s[i] == '(')
            {
                push(st, top, s[i]);
            }
            else
            {
                if (prec(s[i]) >= prec(st[*top]))
                {
                    push(st, top, s[i]);
                }
                else
                {
                    if (s[i] == ')')
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
                        while (*top != -1 && prec(s[i]) <= prec(st[*top]))
                        {
                            ans[a] = pop(st, top);
                            a++;
                        }
                        push(st, top, s[i]);
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
    puts(ans);
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
    if (*top == max - 1)
    {
        printf("Overflow");
    }
    else
    {

        (*top)++;
        st[*top] = value;
    }
}
char pop(char st[], int *top)
{
    int t;
    if (*top == -1)
    {
        printf("Underflow");
        return 0;
    }
    else
    {
        t = st[*top];
        (*top)--;
    }
    return t;
}