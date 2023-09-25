#include<iostream>
using namespace std ;
int last_Occurence(int arr[],int size,int key);
int main()
{
    int even[6] ={2,4,5,8,5,12};
   
    cout<<"last ocuurence of 5 is:   "<<last_Occurence(even,6,5)<<endl;
    return 0;

}

int last_Occurence(int arr[],int size,int key)
{
    int start=0;
    int end=size-1;
    int mid = start+(end-start)/2;
    int ans=-1;
    while(start<=end)
    {
        if (arr[mid]==key)
        {
            ans=mid;
            start=mid+1;


        }
        if (key>arr[mid])
        {
            start=mid+1;
            
        }
        if(key<arr[mid])
        {
            end=mid-1;

        }
        mid=start+(end-start)/2;
    }
    return ans;



}