#include<iostream>
using namespace std ;
int binarysearch(int arr[],int size,int key);
int main()
{
    int even[6] ={2,4,5,8,9,12};
    cout<<"Index of 8 is:   "<<binarysearch(even,6,8)<<endl;
    return 0;

}

int binarysearch(int arr[],int size,int key)
{
    int start=0;
    int end=size-1;

    while(start<=end)
    {
        int mid = start+(end-start)/2;
        if (arr[mid]==key)
        {
            return mid;

        }
        if (key>arr[mid])
        {
            start=mid+1;
        }
        if(key<arr[mid])
        {
            end=mid-1;

        }
        
  

    }
    return -1;



}