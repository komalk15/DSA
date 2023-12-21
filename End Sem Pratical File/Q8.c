#include <stdio.h>
#include <string.h>

void push(char stack[], int *top, int n, char val){
    if ((*top) >= (n - 1))
        printf("Stack overflow\n");
    else
        stack[++(*top)] = val;
}

void pop(char stack[], int *top){
    if ((*top) == -1)
        printf("Stack underflow\n");

    else{
        char del = stack[(*top)--];
    }
}

int isEmpty(int top){
    if (top == -1)
        return 1;
    
    else
        return 0;
}

void testString(char s[], char stack[], int *top, int n){
    for (int i = 0; s[i] != '\0'; i++){
        if (s[i] == 'a')
            push(stack, top, n, s[i]);
        
        else if (s[i] == 'b'){
            if (stack[(*top)] == 'a'){
                pop(stack, top);
                if (isEmpty(*top) == 1){
                    printf("Invalid String\n");
                    return;
                }
            }

            else{
                printf("Invalid String\n");
                return;
            }
        }

        else if (s[i] == 'c'){
            if (stack[(*top)] == 'b' || stack[(*top)] == 'a')
                pop(stack, top);
            
            else{
                printf("Invalid String\n");
                return;
            }
        }
    }

    if (isEmpty((*top)) == 1)
        printf("Valid String\n");

    else
        printf("Invalid String\n");
}

int main(){
    int n, top = -1;
    printf("Enter the no of elements in the string\n");
    scanf("%d", &n);
    char s[n + 1];
    printf("Enter the string of form a,b and c\n");
    scanf("%s", s);
    char stack[n];
    testString(s, stack, &top, n);
    return 0;
}
