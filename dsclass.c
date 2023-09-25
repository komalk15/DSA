#include<stdio.h>
float  area(int **r);
float perimeter( int *r);
int main()
{
    int * r;
    float a=area(&r);
    float p=perimeter(r);
    printf("Area=%f,Perimeter=%f",a,p);
    return 0;
}
float area(int **r)
{
    *r=(int*)malloc(sizeof(int));
    printf("Enter the value of radius 'r'");
    scanf("%d",**r);
    float a= 3.14 *(**r) * (**r);
    return a;

}
float perimeter (int*r)
{
    float p;
    p=2*3.14*(*r);
    return p;

}
