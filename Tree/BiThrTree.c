#include "Base.h"
#include "BiTree.h"

/*
this function will return a head node whose lchild pointer to root node, and rchild point to the last node when traverse the tree in inorder
*/

BiThrNode* InOrderThreading(BiThrNode *root)
{
    static BiThrNode* pre = NULL;
    BiThrNode* head = NULL;

    if((head=(BiThrNode *)malloc(sizeof(BiThrNode))) != NULL)
    {
        head->LTag = Link;
        head->lchild = root;
        head->RTag = Thread;        

        pre = head;

        Threading(root);
        
        //Threading the last Node
        head->rchild = pre;
        pre->RTag = Thread;
        pre->rchild = head;
    }

    return head;
}


void Threading(BiThrNode *p)
{
    if(p != NULL)
    {
        Threading(p->lchild);

        if(p->lchild == NULL)
        {
            p->LTag = Thread;
            p->lchild = pre;
        }

        if(pre->rchild == NULL)
        {
            pre->RTag = Thread;
            pre->rchild = p;
        }

        pre = p;

        Threading(p->rchild);
    }

    return;
}


//based on the threaded tree above, traverse this tree from the start to end
int InOrderTraverseThrTree(BiThrNode *head)
{
    BiThrNode *p = NULL;

    if(head == NULL)
        return -1;
    
    p = head->lchild;
    while(p != head)
    {
        while(p->LTag == Link) 
        {
            p = p->lchild;
        }
        printf("%d, ", p->data);
        while(p->RTag == Thread && p->rchild != head)
        {
            p = p->rchild;
            printf("%d, ", p->data);
        }
        p = p->rchild;
    }

    return 1;
}
