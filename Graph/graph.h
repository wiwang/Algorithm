#define MAX_VERTEX_NUM 100

typdef enum
{
    unvisited,
    visited
}VisitIf;


typedef struct edge
{
    VisitIf mark;
    int ivex;
    int jvex;
    struct edge *ilink;
    struct edge *jlink;
    int weight;
}Edge;

typedef struct vertex
{
    int value;
    Edge *firstEdge;
}Vertex;

typedef struct
{
    Vertex adjMulList[MAX_VERTEX_NUM];
    int verNum;
    int edgeNum;
}VertexBox;
 
