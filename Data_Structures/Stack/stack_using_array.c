#include <stdio.h>
#include <stdlib.h>
 
typedef struct stack
{
    int size;
    int top;
    int *arr;
}stack_t;
 
int isEmpty(stack_t *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(stack_t *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int main()
{
    stack_t *s;
    s=(stack_t *)malloc(sizeof(stack_t));
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    s->arr[0]=10;
    s->top++;

    if(isEmpty(s)==1){
        printf("The stack is empty\n");
    }
    else{
        printf("The stack is not empty\n");
    }
    if(isFull(s)==1){
        printf("The stack is full\n");
    }
    else{
        printf("The stack is not full\n");
    }
 
    return 0;
}