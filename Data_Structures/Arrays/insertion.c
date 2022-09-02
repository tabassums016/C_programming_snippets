#include <stdio.h>

int main(){
    char arr[100]={20, 9, 3, 44, 7};
    int size=5;
    int element=50;
    int index=3;
    for (int i=size-1; i>=index; i--){
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    size++;
    for(int i=0; i<size; i++){
        printf("\n%d",arr[i]);
    }
}