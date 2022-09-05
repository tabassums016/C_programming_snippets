#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int precedence(char ch){
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}
int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
        return 1;
    else
        return 0;
}
char *InfixToPostfix(char* infix)
{
    Stack_t *sp = (Stack_t *) malloc(sizeof(Stack_t));
    sp->size=100;
    sp->top=-1;
    sp->arr=(char*)malloc(sizeof(char));
    char *postfix= (char *)malloc((strlen(infix)+1) *sizeof(char));
    int i=0; //for infix
    int j=0; //for postfix
    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i])> precedence(stack_top(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))    
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{

    char *exp1 = "x+y/z-k*j+t";
    char *postfix=InfixToPostfix(exp1);
   printf("Postfix= %s\n",postfix);

    return 0;
}