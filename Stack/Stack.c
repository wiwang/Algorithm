#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void initStack(SqStack *stack)
{
    SElemType *p = NULL;

    if (stack == NULL) return;

    if ((p=(SElemType *)malloc(MAX_STACK_SIZE*sizeof(SElemType))) != NULL)
    {
        stack->base = stack->top = p;
        stack->stackSize = 0;
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
        *(stack->top) = elem;
        stack->top++;
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


int main(int argc, void *argv[])
{
    int i;
    SElemType *elem;
    SElemType array[] = {0,1,2,3,4,5,6,7,8,9};

    SqStack s;

    initStack(&s);
    
    for(i=0; i<(sizeof(array)/sizeof(SElemType)); i++) 
    {    
        pushStack(&s, array[i]);
    }
   
    while(!isStackEmpty(&s))
    {
        elem = popStack(&s);
        printf("%d\n", *elem);
    }

    destroyStack(&s);

    return 0;
}
