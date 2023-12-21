#include <stdio.h>

void insertionSort(int ar[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = ar[i];
        int j = i - 1;
        for (j = i - 1; j >= 0; j--)
        {
            if (ar[i] < ar[j])
                ar[i] = ar[j];
            else
                break;
        }
        ar[j + 1] = temp;
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
    selectionSort(arr, n);
    printf("\nArray after sorting: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
