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
		
		while(!s.empty())
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
		
		while(!s.empty())
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
	    RecurInOrderTraverse(root->lchild);		
		RecurInOrderTraverse(root->rchild);
	    printf("%d.\n", root->data);		
	}
}

void NonRecurPostOrderTraverse(BinTree *root)
{


}




