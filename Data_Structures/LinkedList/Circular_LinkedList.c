#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node_t;

void traverseLinkedList(Node_t *head)
{
    Node_t *ptr=head;
    do
    {
        printf("ELement: %d\n", ptr->data);
        ptr = ptr->next;
    }while (ptr != head);
}
// Case 1
Node_t *insertAtStart(Node_t *head, int data)
{
    Node_t *ptr = (Node_t *)malloc(sizeof(Node_t));
    ptr->data = data;
    Node_t *p=head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next = head;
    head=ptr; //making the new added elemt as head (i.e. First element)
    return head;
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
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
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
    head_5->next = head_1;


    // traverse the list
    printf("Original list\n");
    traverseLinkedList(head_1);

    // insert element at the start
    printf("Insert at Start:\n");
    head_1 = insertAtStart(head_1, 19);
    traverseLinkedList(head_1);

    // insert element at index
    printf("Inserting at index:\n");
    head_1 = insertAtIndex(head_1, 7, 77);
    traverseLinkedList(head_1);

    // insert element after a node
    printf("Insert after a node:\n");
    head_1 = insertAfterNode(head_1, head_2, 50);
    traverseLinkedList(head_1);

    return 0;
}