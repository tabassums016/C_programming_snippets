/*
Select an element from start
Compare with all the elements, 
if smaller element found then compare that element with remaining to find minimum and swap with th element at the particular index
Repeat with the next index

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

void selectionSort(int *arr, int len)
{
    int temp;
    int min_index = 0;
    for (int i = 0; i < len - 1; i++)
    {
        min_index = i;
        for (int j=i+1; j<len; j++)
        {
            if (arr[j]<arr[min_index])
                min_index=j;
        }
        temp=arr[min_index];
        arr[min_index]=arr[i];
        arr[i] = temp;
    }
}

void main()
{
    int arr[10] = {2, 6, 18, 89, 9};

    printf("\nArray Before Sort:\n");
    printArray(arr, 5);

    selectionSort(arr, 5);

    printf("\nArray After Sort:\n");
    printArray(arr, 5);
    
}