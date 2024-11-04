#include <stdio.h>

void swap(int *x, int *y);
void quicksort(int array[], int length);
void quicksort_recursion(int array[], int low, int high);
int partition(int array[], int low, int high);

int main()
{
    int a[] = {10, 85, 49, 16, 0, 150, 70};
    int length = 7;

    quicksort(a, length);

    for (int i = 0; i < length; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// quicksort function

void quicksort(int array[], int length)
{
    quicksort_recursion(array, 0, length - 1);
}

void quicksort_recursion(int array[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(array, low, high);
        quicksort_recursion(array, low, pivot_index -1); // low end
        quicksort_recursion(array, pivot_index +1, high); // high end

    }
}

// this is where the decision of where the swap will happen, i and j is the end points of low and high.
// it will check for the pivot value and it will swap the places.
int partition(int array[], int low, int high)
{
    int pivot_value = array[high];

    int i = low;

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot_value)
        {
            swap(&array[i], &array[j]);
            i++;
        }
    }
    swap(&array[i], &array[high]);

    return i; // this is where the pivot will be
}
