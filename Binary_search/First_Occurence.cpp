#include<iostream>
using namespace std ;
int first_Occurence(int arr[],int size,int key);
int main()
{
    int even[6] ={2,4,5,8,5,12};
   
    cout<<"First ocuurence of 5 is:   "<<first_Occurence(even,6,5)<<endl;
    return 0;

}

int first_Occurence(int arr[],int size,int key)
{
    int start=0;
    int end=size-1;
    int mid = start+(end-start)/2;
    int asns=-1;
    while(start<=end)
    {
        if (arr[mid]==key)
        {
            return mid;
            end=mid-1;


        }
        if (key>arr[mid])
        {
            start=mid+1;
            
        }
        if(key<arr[mid])
        {
            end=mid-1;

        }
        int mid = start+(end-start)/2;
  

    }
    return -1;



}