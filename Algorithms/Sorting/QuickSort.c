/*
Take element from start as pivot 
take two var i, j; i is next of pivot, j is last element
move i till it valuw less than or equal pivot
decrement j till arr[j] is greater than pivot
then swap arr[i] and arr[j]
when i,j cross each other, swap pivot and arr[j]
this creates a partition at pivot with lower values in left and higher in right
now sort the partitions separately leaving the pivot at partition index at its place
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

int partition(int *arr, int low, int high)
{
    int i = low + 1;
    int j = high;
    int pivot = arr[low];
    int temp = 0;

    while (i < j)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
       
    } 
    
        arr[low] = arr[j];
        arr[j] = pivot;
    return j;
}
void quickSort(int *arr, int low, int high)
{
    int partition_ix=0;

     if(low<high)
     {
        partition_ix=partition(arr,low,high);
        printf("Partition Index= %d\n",partition_ix);
        quickSort(arr,low,partition_ix-1);
        quickSort(arr,partition_ix+1, high);
     }

    
}

int main()
{
    int arr[] = {17, 6, 18, 89, 9,87,21};
    int len=sizeof(arr)/sizeof(int);
    printArray(arr, len);
    quickSort(arr, 0, len-1);
    printArray(arr, len);
}