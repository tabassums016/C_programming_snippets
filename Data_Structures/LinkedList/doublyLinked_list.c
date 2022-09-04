#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node_t;

void traverseLinkedList(Node_t *ptr)
{
    while (ptr != NULL)
    {
        printf("ELement: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    Node_t *head_1;
    Node_t *head_2;
    Node_t *head_3;

    // memory allocated in heap memory
    head_1 = (Node_t *)malloc(sizeof(Node_t));
    head_2 = (Node_t *)malloc(sizeof(Node_t));
    head_3 = (Node_t *)malloc(sizeof(Node_t));

    head_1->prev = NULL;
    head_1->data = 23;
    head_1->next = head_2;

    head_2->prev = head_1;
    head_2->data = 6;
    head_2->next = head_3;
    
    head_3->prev = head_2;
    head_3->data = 11;
    head_3->next = NULL;

    // traverse the list
    printf("Original list\n");
    traverseLinkedList(head_1);
    return 0;
}