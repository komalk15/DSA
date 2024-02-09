// Q4. Write a program to add of two polynomials of degree n, using linked list For example 
// p1 = an xn + an-1 xn-1 + an-2 xn-2 + …….. a0x0
// p2 = bn xn +bn-1 xn-1 + bn-2 xn-2 + …….. b0 x0
// p1 = first polynomial p2 = second polynomial Find out p3= p1+p2*/

//PROGRAM CODE:- 

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int coeffi;
    int power;
    struct node * next;
}node;

void create(node**head, int pow, int coeffi)
{
    node*temp=(node*)malloc(sizeof(node));
    if(temp ==  NULL)
    {
        printf("Not enough memory\n");
        return ;
    }
    temp ->power = pow;
    temp ->coeffi  = coeffi;
    temp -> next  = NULL;
    node*iterator = *head;
    if( iterator == NULL)
    {
        *head = temp;
    }
    else
    {
        node*tail = NULL;
        while( iterator && pow >iterator -> power )
        {
            tail = iterator;
            iterator =  iterator-> next;
        }
        if( iterator && iterator -> power == pow )
        {
            iterator -> coeffi += coeffi;
            return ;
        }
        if( tail == NULL )
        {
            temp -> next = *head;
            *head = temp;
        }
        else 
        {
            tail -> next = temp;
            temp -> next = iterator;
        }
    }
}

void sum_list(node**first, node**second, node**res)
{
    node*first_it = *first;
    node*second_it = *second;
    node*iterator = *res;
    while(first_it || second_it)
    {
        if( first_it && second_it && first_it- > power < second_it->power ) 
        {
            if(*res == NULL)
                *res = iterator = first_it;
            else
            {
                iterator -> next = first_it;
                iterator = first_it;
            }
            first_it = first_it -> next;
        }
        else if( first_it && second_it && first_it- >power > second_it -> power)
        {
            if(*res ==NULL)
                *res = iterator = second_it;
            else 
            {
                iterator -> next = second_it;
                iterator = second_it;
            }
            second_it = second_it -> next;
        }
        else if(first_it && second_it && first_it -> power == second_it -> power )
        {
            first_it -> coeffi += second_it -> coeffi;
            if(*res == NULL)
            {
                *res = iterator = first_it;
            }
            else
            {
                iterator -> next = first_it;
                iterator = first_it;
            }
            first_it = first_it -> next;
            second_it = second_it -> next;
        }
        else if(first_it)
        {
            if(*res != NULL)
            {
                iterator -> next=first_it;
                return ;
            }
        }
        else if(second_it)
        {
            if(*res != NULL)
            {
                iterator->next = second_it;
                return ;
            }
        }
    }
}

void display_poly(node*iterator)
{
    while(iterator&&iterator->next)
    {
        printf("%d X^%d + ", iterator->coeffi, iterator->power);
        iterator = iterator -> next;
    }
    if(iterator)
        printf("%d X^%d",iterator->coeffi,iterator->power);
    printf("\n");
}

int main()
{
    int n,pow,coeffi;
    node *poly_first,*poly_second, *final_poly;
    poly_first = poly_second = final_poly = NULL;
    printf("Enter the number of terms in first polynomial : ");
    scanf("%d", &n);
    for( int i = 0 ; i < n ; i++ )
    {
        printf("Enter the coefficient and power respectively : ");
        scanf("%d %d",&coeffi,&pow);
        create(&poly_first,pow,coeffi);
    }
    printf("Enter the number of terms in second polynomial : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the coefficient and power respectively : ");
        scanf("%d %d",&coeffi,&pow);
        create(&poly_second,pow,coeffi);
    }
    printf("First Polynomial\n");
    display_poly(poly_first);
    printf("Second Polynomial\n");
    display_poly(poly_second);
    sum_list(&poly_first,&poly_second,&final_poly);
    printf("The sum polynomial\n");
    display_poly(final_poly);
    return 0;
}






















// OUTPUT:-

// Enter the number of terms in first polynomial : 4
// Enter the coefficient and power respectively : 45 5
// Enter the coefficient and power respectively : 34 4
// Enter the coefficient and power respectively : 20 2
// Enter the coefficient and power respectively : 32 7
// Enter the number of terms in second polynomial : 3
// Enter the coefficient and power respectively : 1 2
// Enter the coefficient and power respectively : 2 4
// Enter the coefficient and power respectively : 35 3
// First Polynomial
// 20 X^2 + 34 X^4 + 45 X^5 + 32 X^7
// Second Polynomial
// 1 X^2 + 35 X^3 + 2 X^4
// The sum polynomial
// 21 X^2 + 35 X^3 + 36 X^4 + 45 X^5 + 32 X^7















