
#include "queue.h"

void InitQueue(Queue *q)
{
    q->head = 0;
    q->tail = 0;
    q->size = 0;

    memset(q->array, 0, sizeof(q->array));
 
    return;
}

BOOLEAN QueueEmpty(Queue *q)
{
    return (q->size==0?TRUE:FALSE);
}


BOOLEAN EnQueue(Queue *q, int value)
{
    if(q->size < MAX_QUEUE_SIZE)
    {
        q->array[q->tail] = value;
        q->tail = (q->tail++)%MAX_QUEUE_SIZE;
        q->size++;
       
        return TRUE;
    }
    else
    {
        printf("Queue size is %d.\n", q->size);

        return FALSE;
    }
}

int DeQueue(Queue *q)
{
    int value;
    if(q->size > 0)
    {
        value = q->array[q->head];
        q->head = (q->head++)%MAX_QUEUE_SIZE;
        q->size--;
   
        return value;     
    }
    else
    {
        return -1;
    }
}
