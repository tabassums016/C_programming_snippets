#include <stdio.h>

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
            return i;
    }
    return -1;
}
int BinarySearch(int arr[], int size, int element)
{
    // Only for Sorted Array
    int low = 0, high = size - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
            return mid;
        if (arr[mid] > element)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 5, 6, 7, 8, 12, 15, 77, 87, 99};
    int size = sizeof(arr) / sizeof(int);
    int element = 80;
    int result_index = BinarySearch(arr, size, element);
    printf("\nElement %d fount at index %d\n", element, result_index);
}