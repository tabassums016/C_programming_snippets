#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node_t;

void traverseLinkedList(Node_t *ptr)
{
    while (ptr != NULL)
    {
        printf("ELement: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
// Case 1
Node_t *deleteAtStart(Node_t *head)
{
    Node_t *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

Node_t *deleteAtIndex(Node_t *head, int index)
{
    Node_t *p = head;
    Node_t *q = p->next;
    int i = 0;
    while (i < index - 1)
    {
        p = p->next;
        q = p->next;
        i++;
    }

    p->next = q->next;
    free(q);
    return head;
}
Node_t *deleteAtEnd(Node_t *head)
{
    Node_t *p = head;
    Node_t *q = p->next;
    int i = 0;
    while (q->next != NULL)
    {
        p = p->next;
        q = p->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

Node_t *deleteGivenValue(Node_t *head, int value)
{
    Node_t *p = head;
    if (p->data == value)
    {
        head= p->next;
        free(p);
    }
    else
    {
        Node_t *q = p->next;
        while (q->data != value && q->next != NULL)
        {
            p = p->next;
            q = p->next;
        }
        if (q->data == value)
        {
            p->next = q->next;
            free(q);
        }
        else
            printf("Value Not Found\n");
    }
    return head;
}

int main()
{
    Node_t *head_1;
    Node_t *head_2;
    Node_t *head_3;
    Node_t *head_4;
    Node_t *head_5;

    // memory allocated in heap memory
    head_1 = (Node_t *)malloc(sizeof(Node_t));
    head_2 = (Node_t *)malloc(sizeof(Node_t));
    head_3 = (Node_t *)malloc(sizeof(Node_t));
    head_4 = (Node_t *)malloc(sizeof(Node_t));
    head_5 = (Node_t *)malloc(sizeof(Node_t));

    head_1->data = 23;
    head_1->next = head_2;
    head_2->data = 6;
    head_2->next = head_3;
    head_3->data = 20;
    head_3->next = head_4;
    head_4->data = 21;
    head_4->next = head_5;
    head_5->data = 11;
    head_5->next = NULL;

    // traverse the list
    printf("Original list\n");
    traverseLinkedList(head_1);

    //Delete element at the start
    printf("Delete at Start:\n");
    head_1 = deleteAtStart(head_1);
    traverseLinkedList(head_1);

    // Delete element at index
    printf("Deleting at index:\n");
    head_1 = deleteAtIndex(head_1, 3);
    traverseLinkedList(head_1);

    // Delete element at the end
    printf("Delete at End:\n");
    head_1 = deleteAtEnd(head_1);
    traverseLinkedList(head_1);

    // Delete a given value
    printf("Delete a given value:\n");
    head_1 = deleteGivenValue(head_1, 20);
    traverseLinkedList(head_1);

    return 0;
}