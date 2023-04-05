#include <stdio.h>
#include <stdlib.h>

void quicksort(int array[], int start, int end)
{
    if (start < end)
    {
        int pivot = choose_pivot(array, start, end);
        pivot = partition(array, start, end, pivot);
        quicksort(array, start, pivot - 1);
        quicksort(array, pivot + 1, end);
    }
}

int choose_pivot(int array[], int start, int end)
{
    return array[start];
}

int partition(int array[], int start, int end, int pivot)
{
    int left = start + 1;
    int right = end;

    while (left <= right)
    {
        while (left <= end && array[left] < pivot)
        {
            left++;
        }

        while (right >= start && array[right] > pivot)
        {
            right--;
        }

        if (left < right)
        {
            swap(&array[left], &array[right]);
        }
    }

    swap(&array[start], &array[right]);
    return right;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int array[] = {4, 2, 1, 5, 3};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Array antes da ordenacao:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    int new_size = size - 1;

    quicksort(array, 0, new_size);

    printf("Array depois da ordenacao:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
