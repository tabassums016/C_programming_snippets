#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Stack_t;

void linkedListTraversal(Stack_t *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(Stack_t *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(Stack_t *top)
{
    Stack_t *p = (Stack_t *)malloc(sizeof(Stack_t));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Stack_t *push(Stack_t *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        Stack_t *n = (Stack_t *)malloc(sizeof(Stack_t));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(Stack_t **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        Stack_t *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}
int peek(Stack_t *top, int index)
{ // check the particular postion of stack
    Stack_t *p = top;
    int i = 0;
    while (i < index - 1 )
    {
        p = p->next;
        i++;
        if (p == NULL)
        {
            printf("Not a valid position for the stack\n");
            return -1;
        }
    }
    return p->data;
}

int main()
{
    Stack_t *top = NULL;
    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);
    top = push(top, 19);
    top = push(top, 25);

    linkedListTraversal(top);

    int element = pop(&top);
    printf("Popped element is %d\n", element);
    linkedListTraversal(top);
    int peel_val = peek(top, 4);
    printf("Peek element is %d\n", peel_val);
    return 0;
}