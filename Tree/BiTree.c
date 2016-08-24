#include "Base.h"
#include "Stack.h"
#include "BiTree.h"

void RecurPreOrderTraverse(BinTree *root)
{
    if(root != NULL)
    {
        printf("%d.\n", root->data);
	PreOrderTraverse(root->lchild);
        PreOrderTraverse(root->rchild);
    }
}


void NonRecurPreOrderTraverse(BinTree *root)
{
    stack<BinTree *> s;
    BinTree *p = root;
    while(p!=NULL || !s.empty())
    {
	while(p!=NULL)
        {
            printf("%d.\n", p->data);
	    s.push(p);
	    p = p->lchild;		
	}
		
	if(!s.empty())
	{
	    p = s.top();
	    s.pop();
	    p = p->rchild;
	}	
    }
}



void RecurInOrderTraverse(BinTree *root)
{
    if(root != NULL)
    {
	RecurInOrderTraverse(root->lchild);
	printf("%d.\n", root->data);		
        RecurInOrderTraverse(root->rchild);
    }
}

void NonRecurInOrderTraverse(BinTree *root)
{
    stack<BinTree *> s;
    BinTree *p = root;
    while(p!=NULL || !s.empty())
    {
	while(p!=NULL)
	{
	    s.push(p);
	    p = p->lchild;		
	}
		
	if(!s.empty())
	{
	    p = s.top();
	    printf("%d.\n", p->data);			
	    s.pop();
	    p = p->rchild;
	}	
    }
}


void RecurPostOrderTraverse(BinTree *root)
{
    if(root != NULL)
    {
	RecurPostOrderTraverse(root->lchild);		
        RecurPostOrderTraverse(root->rchild);
	printf("%d.\n", root->data);		
    }
}


/*
要保证根结点在左孩子和右孩子访问之后才能访问，因此对于任一结点P，先将其入栈。如果P不存在左孩子和右孩子，则可以直接访问它；或者P存在左孩子或者右孩子，但是其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。若非上述两种情况，则将P的右孩子和左孩子依次入栈，这样就保证了每次取栈顶元素的时候，左孩子在右孩子前面被访问，左孩子和右孩子都在根结点前面被访问
*/


void NonRecurPostOrderTraverse(BinTree *root)
{
    stack<BinTree*> s;
    BinTree *cur; //当前结点  
    BinTree *pre=NULL; //前一次访问的结点  
    s.push(root); 

    while(!s.empty())
    {
        cur=s.top(); 
        if((cur->lchild==NULL&&cur->rchild==NULL)||
           (pre!=NULL&&(pre==cur->lchild||pre==cur->rchild)))
        {
            cout<<cur->data<<""; //如果当前结点没有孩子结点或者孩子节点都已被访问过  
            s.pop();
            pre=cur; 
        } 
        else 
        { 
            if(cur->rchild!=NULL)
                s.push(cur->rchild); 
            if(cur->lchild!=NULL)    
                s.push(cur->lchild);
        }
    }

}


BinTree* GetParentOfNode(BinTree *root, Elem data, BinTree *parent)
{
    BinTree *node = NULL;

    if(root != NULL)
    {
        if(root->data == data)
            return parent;
        
        if(node=GetParentOfNode(root->lchild, data, root) != NULL)
            return node;
        
        if(node=GetParentOfNode(root->rchild, data, root) != NULL)
            return node;
    }
    
    return NULL;
}

int GetLevelOfNode(BinTree *root, Elem data)
{
    int level;    

    if (root==NULL) return -1;

    if (root->data==data)
    {     
        return 0;
    }
    else
    {
        level = GetLevelOfNode(root->lchild, data);
        if (level>=0) return level+1;
        level = GetLevelOfNode(root->rchild, data);
        if (level>=0) return level+1;
    }
}


