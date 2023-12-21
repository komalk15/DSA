// Write a C program to sort a sequence of characters given by user in an array,
// using Quick sort technique.

#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

int partition(char array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(char array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void printArray(char array[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%c  ", array[i]);
    printf("\n");
}

int main()
{
    int n = 100;
    char data[n];

    printf("Enter The elements: ");
    scanf("%s", data);

    printf("Unsorted Array:  ");
    printArray(data, strlen(data));

    quickSort(data, 0, strlen(data) - 1);
    printf("Sorted array in ascending order: ");
    printArray(data, strlen(data));
}