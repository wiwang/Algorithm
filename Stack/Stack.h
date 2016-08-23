
#define MAX_STACK_SIZE 64
typedef int SElemType;

typedef struct{
    SElemType *base;
    SElemType *top;
    int stackSize;
}SqStack;
