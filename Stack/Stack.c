
#include "Stack.h"

void initStack(SqStack *stack)
{
    SElemType *p = NULL;

    if (stack == NULL) return;

    if ((p=(SElemType *)malloc(MAX_STACK_SIZE*size(SElemType))) != NULL)
    {
        stack->base = stack->top = p;
        stack->stackSize = MAX_STACK_SIZE;
    }

    return;
}


void destroyStack(SqStack *stack)
{
    if (stack == NULL) return;

    free(stack->base);
    stack->base=stack->top=NULL;
    stack->stackSize = 0;

    return;
}

int pushStack(SqStack *stack, SElemType elem)
{
    if (stack == NULL) return -1;

    if (stack->stackSize < MAX_STACK_SIZE)
    {
        stack->top = elem;
        stack->stackSize++;
        return 0;
    }
    else
    {
        return -1;
    }
}

SElemType* popStack(SqStack *stack)
{
    if (stack == NULL) return NULL;

    if (stack->top > stack->base)
    {
        stack->top--;
        stack->stackSize--;
        return stack->top;
    }
    else
    {
        return NULL;
    }
}

int isStackEmpty(SqStack *stack)
{
    if (stack == NULL) return 0;
   
    return (stack->base==stack->top) ? 1 : 0;

}
