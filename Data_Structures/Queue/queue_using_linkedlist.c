#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int data;
    struct Queue *next;
} Queue_t;

Queue_t *f = NULL; // front
Queue_t *r = NULL; // rear

void traverseLinkedList(Queue_t *ptr)
{
    printf("Traversing the elements of linked list\n");
    while (ptr != NULL)
    {
        printf("ELement: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
void enqueue(int val)
{
    Queue_t *n = (Queue_t *)malloc(sizeof(Queue_t));
    if (n == NULL)
    {
        printf("Queue is Full");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n; // changing rear to the last(newly added) element
        }
    }
}
int dequeue()
{
    Queue_t *ptr=f;
    int val=-1;
    if (f == NULL)
    {
        printf("Queue is Empty");
    }
    else{
        val=ptr->data;
        f=f->next;
        free(ptr);
    }
}

int main()
{
    enqueue(6);
    enqueue(60);
    enqueue(622);
    enqueue(63);
    enqueue(11);
    traverseLinkedList(f);
    dequeue();
    dequeue();
    traverseLinkedList(f);
}