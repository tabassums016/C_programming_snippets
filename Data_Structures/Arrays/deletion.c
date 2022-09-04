#include <stdio.h>

int main(){
    char arr[100]={20, 9, 3, 44, 7};
    int size=5;
    int index=2;
    for (int i=index; i<size-1; i++){
        arr[i]=arr[i+1];
    }
    size=size-1;
    for(int i=0; i<size; i++){
        printf("%d\n",arr[i]);
    }
}