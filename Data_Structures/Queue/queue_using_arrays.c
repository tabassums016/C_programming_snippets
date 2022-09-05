#include <stdlib.h>
#include <stdio.h>

typedef struct queue
{
    int size;
    int front;
    int back;
    int *arr;
} queue_t;

int isFull(queue_t *head)
{
    if (head->back == head->size - 1)
        return 1;
    else
        return 0;
}

int isEmpty(queue_t *head)
{
    if (head->back == head->front)
    {
        head->back, head->front=-1;
        return 1;
    }
    else
        return 0;
}
void queueTraversal(queue_t *head)
{
    if (isEmpty(head) == 1)
    {
        printf("QUeue is Empty\n");
    }
    else
    {

        for (int i = head->front+1; i <= head->back; i++)
        {
            printf("%d\n", head->arr[i]);
        }
    }
}

void enqueue(queue_t *head, int data)
{
    if (isFull(head) == 1)
        printf("Queue is exhausted");
    else
    {
        head->back = head->back + 1;
        head->arr[head->back] = data;
    }
}
int dequeue(queue_t *head)
{
    if (isEmpty(head) == 1)
    {
        printf("QUeue is Empty\n");
        return -1;
    }
    else
    {
        head->front=head->front+1;
        int a=head->arr[head->front];
        return a;
        // for (int i = 0; i <= head->back; i++)
        // {
        //     printf("%d\n", head->arr[i]);
        // }
    }
}

int main()
{
    queue_t *head = (queue_t *)malloc(sizeof(queue_t));
    head->size = 10;
    head->front = -1;
    head->back = -1;
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
    enqueue(head, 45);
    enqueue(head, 45);
    enqueue(head, 45);
    queueTraversal(head);
}
