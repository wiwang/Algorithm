
typedef struct ArcNode{
    int ivex;
    int jvex;
    struct ArcNode *ilink;
    struct  ArcNode *jlink;
}ArcNode;

typedef struct VNode {
    int data;
    struct ArcNode *firstarc;
}VNode;
