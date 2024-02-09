#include <stdio.h>
#include <string.h>

void testString(char str[], int elements){
    if (elements % 3 != 0)
        printf("Invalid string\n");

    else{
        int n = (elements / 3);
        int flag = 1, i = 0;
        while (i < n && flag == 1){
            if (str[i] == '1' && str[i + n] == '2' && str[i + 2 * n] == '3')
                flag = 1;
            
            else{
                flag = 0;
                break;
            }
            i++;
        }

        if (flag == 0)
            printf("Invalid String\n");
        
        else
            printf("Valid String\n");
        
    }
}

int main(){
    int elements = 0;
    printf("Enter the no of elements in the string in form of 1,2 and 3\n");
    scanf("%d", &elements);
    char str[elements + 1];
    printf("Enter the string\n");
    scanf("%s", str);
    testString(str, elements);
    return 0;
}
