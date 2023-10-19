#include <stdio.h>
#include <string.h>
#define max 100
void push(char st[], int *top, char value);
void pop(char st[], int *top);

int main()
{
    int top = -1;
    char st[max];
    char str[max] = "((())))";
    int i;
    int flag;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '(')
        {
            push(st, &top, str[i]);
        }

        else 
        {

            if (top == -1 )
            {
                
                printf("\nUnbalanced");
                return 0;
                
            }
            else
            {
                pop(st, &top);
                
                
            }
        }
    }
    if (top == -1 )
    {
    
        printf("\nbalanced");
    }
    else
    {
        printf("\nUnbalanced");
    }
    return 0;
}
void push(char st[], int *top, char value)
{
    if (*top > max - 1)
    {
        printf("\nOverflow");
    }
    else
    {
        st[*top] = value;
        (*top)++;
    }
}
void pop(char st[], int *top)
{
    if (*top == -1)
    {
        printf("\nUnderflow");
    }
    else
    {
        (*top)--;
    }
}
