#include <stdio.h>
#include <string.h>

void push(char st[], int *top, char value, int max);
void pop(char st[], int *top);
int getParams(char s);
int is_empty(int top);

int main()
{
    int max = 200;
    int top = -1;
    char st[max];
    char str[] = "()()";
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        int b = getParams(str[i]);
        if (b > 0)
        {
            push(st, &top, b, max);
        }
        else
        {
            if (is_empty(top))
            {
                printf("\nUnbalanced");
                break;
            }
            if ((st[top] + b) == 0)
            {
                pop(st, &top);
            }
            else
            {
                printf("\nUnbalanced");
                break;
            }
        }
    }

    if (is_empty(top))
    {
        printf("\nBalanced");
    }
    else
    {
        printf("\nUnbalanced");
    }

    return 0;
}

int getParams(char s)
{
    switch (s)
    {
    case '{':
        return 1;
    case '[':
        return 2;
    case '(':
        return 3;
    case '}':
        return -1;
    case ']':
        return -2;
    case ')':
        return -3;
    default:
        return 0;
    }
}

int is_empty(int top)
{
    return (top == -1) ? 1 : 0;
}

void push(char st[], int *top, char value, int max)
{
    if (*top > max - 1)
    {
        printf("Overflow");
    }
    else
    {
        (*top)++;
        st[*top] = value;
    }
}

void pop(char st[], int *top)
{
    if (*top == -1)
    {
        printf("Underflow");
    }
    else
    {
        (*top)--;
    }
}
