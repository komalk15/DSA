#include <stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void selectionSort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
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
