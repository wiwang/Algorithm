
#define MAX_STACK_SIZE 64
typedef int SElemType;

typedef struct{
    SElemType *base;
    SElemType *top;
    int stackSize;
}SqStack;


void initStack(SqStack *stack);
void destroyStack(SqStack *stack);
int pushStack(SqStack *stack, SElemType elem);
SElemType* popStack(SqStack *stack);
int isStackEmpty(SqStack *stack);
