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
Node_t *insertAtStart(Node_t *head, int data)
{
    Node_t *ptr = (Node_t *)malloc(sizeof(Node_t));
    ptr->data = data;

    ptr->next = head;
    return ptr;
}

Node_t *insertAtIndex(Node_t *head, int index, int data)
{
    Node_t *ptr = (Node_t *)malloc(sizeof(Node_t));
    Node_t *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
        if (p==NULL)
        {
            printf("Index greater the list size\n");
            return head;
        }
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
Node_t *insertAtEnd(Node_t *head, int data)
{
    Node_t *ptr = (Node_t *)malloc(sizeof(Node_t));
    Node_t *p = head;
    int i = 0;
    while (p->next!= NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next=ptr;
    ptr->next = NULL;
    return head;
}

Node_t *insertAfterNode(Node_t *head, Node_t *prev_node, int data)
{
    Node_t *ptr = (Node_t *)malloc(sizeof(Node_t));
    ptr->data = data;
    ptr->next = prev_node->next;
    prev_node->next=ptr;
    return head;
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

    head_1->data = 23;
    head_1->next = head_2;
    head_2->data = 6;
    head_2->next = head_3;
    head_3->data = 11;
    head_3->next = NULL;

    // traverse the list
    printf("Original list\n");
    traverseLinkedList(head_1);

    // insert element at the start
    printf("Insert at Start:\n");
    head_1 = insertAtStart(head_1, 196);
    traverseLinkedList(head_1);

    // insert element at index
    printf("Inserting at index:\n");
    head_1 = insertAtIndex(head_1, 5, 77);
    traverseLinkedList(head_1);

    // insert element at the end
    printf("Insert at End:\n");
    head_1 = insertAtEnd(head_1, 100);
    traverseLinkedList(head_1);

    // insert element after a node
    printf("Insert after a node:\n");
    head_1 = insertAfterNode(head_1, head_2, 50);
    traverseLinkedList(head_1);

    return 0;
}