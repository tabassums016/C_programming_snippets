/* 
Take element from start as key  starting from
check with the elements in reverse direction starting from the elemnt before the key
if greater, shift right
insert the key when loop ends where blank space is left
*/
#include <stdio.h>

void printArray(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void insertionSort(int *arr, int len)
{
    int key = 0;
    for (int i = 1; i <= len - 1; i++)
    {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[10] = {17, 6, 18, 89, 9};
    insertionSort(arr, 5);
    printArray(arr, 5);
    return 0;
}