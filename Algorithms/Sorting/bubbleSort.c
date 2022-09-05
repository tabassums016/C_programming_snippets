#include <stdio.h>

void printArray(int* arr, int len)
{
    for(int i=0; i<len; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void bubbleSort(int* arr, int len)
{
    int temp=0;
    int count=0;
    int sorted=0;
    for (int i=0; i<len-1; i++)
    {
        sorted=1;
        for (int j=0; j<len-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                sorted=0;
            }
            count++;
        }
        if(sorted==1)
        break;
    }
    printf("Time complexity=%d\n",count); // 1+2+3+....+(n-1)
}

int main()
{
    int arr[10]={1,6,8,89,9};
    bubbleSort(arr,5);
    printArray(arr,5);

}