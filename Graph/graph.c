BOOLEAN visited[MAX_VERTEX_NUM];


/*like PreOrder traverse in tree*/`

void DFSTraverse(AMLGragh *g)
{
    int i;

    for(i=0; i<g->verNum; i++)
    {
        if(!visited[i]) DFS(g, i);
    }

    retrun;
}

void DFS(AMLGragh *g, int v)
{
    Edge *e = g->adjMulList[v]->firstEdge;

    visited[v] = TRUE;
    printf("%d\n", v);

    for(; e!=NULL; e=e->ilink)
    {
        if(!visited[e->jvex]) DFS(g, e->jvex);
    }

    return;
}


/*like hierarchy traverse in tree*/

void BFSTraverse(AMLGragh *g)
{
    int i;
    int w;
    Edge *e;

    Queue *q = (Queue *)malloc(sizeof(Queue));
    if(q == NULL) return;

    InitQueue(q);

    for(i=0; i<g->verNum; i++) 
    {
        if(!visited[i])
        {
            Enqueue(q, i);
            visited[i] = TRUE;
            printf("%d", i);
         
            while(!QueueEmpty(q))
            {
                w = Dequeue(q);
                e = g->adjMulList[w]->firstEdge;
                for(; e!=NULL; e=e->ilink)
                {
                    if(!visited[e->jvex])
                    {
                        Enqueue(q, e->jvex);
                        visited[e->jvex] = TRUE;
                        printf("%d\n", e->jvex);
                    }
                }    
            }

        }

    }

    return;
}



