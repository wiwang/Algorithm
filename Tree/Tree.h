
typedef int Elem;

typedef struct BinTree
{
    Elem data;
    BinTree* lchild;
    BinTree* rchild;
}BinTree;

typedef enum
{
    Link,
    Thread
}PointerTag;

typedef struct BiThrNode
{
    Elem data;
    struct BiThrNode *lchild;
    struct BiThrNode *rchild;
    PointerTag ltag;
    PointerTag rtag;
}BiThrNode;

typedef struct CSNode
{
    Elem data;
    struct CSNode *firstchild;
    struct CSNode *nextsibling;
}CSNode;


