#include <stdio.h>

void merge(int arr[], int s, int mid, int e)
{

    int len1 = mid - s + 1;
    int len2 = e - mid;
    int A[len1], B[len2];
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        A[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid + 1;
    for (int j = 0; j < len2; j++)
    {
        B[j] = arr[mainArrayIndex++];
    }
    // merging two arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;
    while (index1 < len1 && index2 < len2)
    {
        if (A[index1] < B[index2])
        {
            arr[mainArrayIndex++] = A[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = B[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = A[index1++];
    }

   
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = B[index2++];
    }
}
void mergesort(int arr[], int s, int e)
{
    if (s < e)
    {
        int mid = (s + e) / 2;
        mergesort(arr, s, mid);
        mergesort(arr, mid + 1, e);
        merge(arr, s, mid, e);
    }
}

int main()
{
    int n;
    printf("\nEnter the size of array:  ");
    scanf("%d", &n);
    int arr[n];

    printf("\nEnter the elements of array:  ");
    int i;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array before sorting: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    mergesort(arr, 0, n - 1);
    printf("\nArray after sorting: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
