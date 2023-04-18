#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int start, int end)
{
    int pivot = array[start];
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

int quick_select(int array[], int start, int end, int k)
{
    if (start == end)
    {
        return array[start];
    }

    int pivot = partition(array, start, end);

    if (k == pivot)
    {
        return array[pivot];
    }
    else if (k < pivot)
    {
        return quick_select(array, start, pivot - 1, k);
    }
    else
    {
        return quick_select(array, pivot + 1, end, k);
    }
}

int main()
{
    int array[] = {4, 2, 1, 5, 3};
    int size = sizeof(array) / sizeof(array[0]);
    int k = 2; // posição do elemento desejado

    printf("Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    int element = quick_select(array, 0, size - 1, k);

    printf("Elemento na posicao %d: %d\n", k, element);

    return 0;
}
