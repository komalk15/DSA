#include <stdio.h>
#include <string.h>
#define max 100
void check_pallindrome(char st[], char *str, int *top);
void push(char st[], char value, int *top);
void pop(char st[], int *top);
int main()
{
    char stack[max];
    char str[max] = "komok";
    int top = -1;
    check_pallindrome(stack, str,&top);
}
void check_pallindrome(char st[], char *str, int *top)
{
    int i;
    int length = strlen(str);
    int mid = length / 2;
    for (i = 0; i < mid; i++)
    {
        push(st, str[i], top);
    }
    if (length % 2 == 0)
    {
        i = mid;
    }
    if (length % 2 != 0)
    {
        i = mid + 1;
    }
    while (str[i] != '\0')
    {
        if (str[*top] == str[i])
        {
            pop(st,top);
           
        }
        i++;
    }
    if ((*top) == -1)
    {
        printf("Its is a pallindrome");
    }
    else
    {
        printf("Its is not a pllindrome");
    }
}
void push(char st[], char value, int *top)
{
    if (*top == max - 1)
    {
        printf("Stack is full");
    }
    else
    {

        st[(*top)++] = value;
    }
}
void pop(char st[], int *top)
{
    if (*top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        (*top)--;
    }
}