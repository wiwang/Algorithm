
#define MAX_QUEUE_SIZE 100

typedef struct
{
    int array[MAX_QUEUE_SIZE];
    int head; /*the dequeue one*/
    int tail; /*the enqueue one*/
    int size;
}Queue;

