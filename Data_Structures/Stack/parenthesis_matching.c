#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    char *arr;
} Stack_t;

int isEmpty(Stack_t *ptr)
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

int isFull(Stack_t *ptr)
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

void push(Stack_t *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %c to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(Stack_t *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
char stack_top(Stack_t *sp)
{
    return sp->arr[sp->top];
}

int parenthesisMatch(char *exp)
{
    // Create and initialize the stack
    Stack_t *sp = (Stack_t *)malloc(sizeof(Stack_t));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }

    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int match(char open, char close)
{
    if (open == '(' && close == ')')
        return 1;
    else if (open == '[' && close == ']')
        return 1;
    else if (open == '{' && close == '}')
        return 1;
    else
        return 0;
}
int multiple_parenthesisMatch(char *exp)
{
    // Create and initialize the stack
    Stack_t *sp = (Stack_t *)malloc(sizeof(Stack_t));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            if (match(stack_top(sp), exp[i])==1)
            {
                pop(sp);
                printf("Pop Successful\n");
            }
            else
            {
                printf("Unbalanced equation\n");
                return 0;
            }
        }
    }

    if (isEmpty(sp))
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

    char *exp1 = "6+(8)(*--$$9)";
    char *exp2 = "[{6+(8){(*--$$9)}]";
    // Check if stack is empty
    if (parenthesisMatch(exp1))
    {
        printf("The single parenthesis is matching\n");
    }
    else
    {
        printf("The single parenthesis is not matching\n");
    }
    if (multiple_parenthesisMatch(exp2))
    {
        printf("The multiple parenthesis is matching\n");
    }
    else
    {
        printf("The multiple parenthesis is not matching\n");
    }

    return 0;
}