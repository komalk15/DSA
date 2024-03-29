#include <stdio.h>
void bubbleSort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    bubbleSort(arr, n);
    printf("\nArray after sorting: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
