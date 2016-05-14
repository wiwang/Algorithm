#include <stdio.h>
#include <stdlib.h>
#include "Base.h"
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
        q->tail++;
        q->tail = q->tail%MAX_QUEUE_SIZE;
        
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
        printf("Queue is empty.\n");
        return -1;
    }
}


int main(int argc, char* argv[])
{
    int i;
    int elem;
    Queue q;

    InitQueue(&q);    

    for(i=1; i<argc; i++)
    {
        elem = atoi(argv[i]);
        EnQueue(&q, elem);
    }
 
    printf("Queue length is %d, head is %d, tail is %d.\n", q.size, q.head, q.tail);
    
    for(i=0; i<q.size; i++)
    {
        printf("%d\n", q.array[q.head+i]);
    } 

    return 0;
}
