#include <stdlib.h>
#include <stdio.h>

typedef struct circularQueue
{
    int size;
    int front;
    int back;
    int *arr;
} circularQueue_t;

int isFull(circularQueue_t *head)
{
    if ((head->back + 1)%head->size == head->front )
        return 1;
    else
        return 0;
}

int isEmpty(circularQueue_t *head)
{
    if (head->back == head->front)
        return 1;
    else
        return 0;
}
void queueTraversal(circularQueue_t *head)
{
    printf("Traversing the queue..\n");
    if (isEmpty(head) == 1)
    {
        printf("circularQueue is Empty\n");
    }
    else
    {

        for (int i = head->front+1; i <= head->back; i++)
        {
            printf("%d\n", head->arr[i]);
        }
    }
}

void enqueue(circularQueue_t *head, int data)
{
    if (isFull(head) == 1)
        printf("circularQueue is exhausted\n");
    else
    {
        head->back = (head->back + 1)%head->size;
        head->arr[head->back] = data;
    }
    printf("backInd %d\n",head->back);
    printf("frontInd %d\n",head->front);
}
int dequeue(circularQueue_t *head)
{
    if (isEmpty(head) == 1)
    {
        printf("circularQueue is Empty\n");
        return -1;
    }
    else
    {
        head->front=(head->front+1)%head->size;
        int a=head->arr[head->front];
        return a;
        
    }
}

int main()
{
    circularQueue_t *head = (circularQueue_t *)malloc(sizeof(circularQueue_t));
    head->size = 10;
    head->front = 0;
    head->back = 0;
    head->arr = (int *)malloc(head->size * sizeof(int));
    enqueue(head, 5);
    enqueue(head, 9);
    enqueue(head, 7);
    enqueue(head, 12);
    enqueue(head, 15);
    enqueue(head, 1); 
    enqueue(head, 45);
    enqueue(head, 41);
    enqueue(head, 41);
    enqueue(head, 91);
    enqueue(head, 81);
    queueTraversal(head);
    printf("Dequeuing element %d\n", dequeue(head));
    printf("Dequeuing element %d\n", dequeue(head));
    printf("Dequeuing element %d\n", dequeue(head)); 
    enqueue(head, 15);
    enqueue(head, 1); 
    enqueue(head, 45);
    queueTraversal(head);
    if(isEmpty(head)){
        printf("Queue is empty\n");
    }
    if(isFull(head)){
        printf("Queue is full\n");
    }
    return 0;
}
