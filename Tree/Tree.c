#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

/*
create a tree as first-child-next-sibling structure when input tree node in layer order
*/




/*
supposing we get a pre-ordering and in-ordering result of a binary tree,
we can build a unique tree based on these two result.

for example:
pre-ordering: a b c d e f g
in-ordering:  c b e d a f g

*/

int createBiTree(char preOrder[], int preLen, char inOrder[], int inLen, BinTree *tree)
{
    BinTree *node = NULL;
    int root;
    int leftSize;
    int rightSize;

    if((node=(BinTree *)malloc(sizeof(BinTree))) == NULL)
        return -1;

    node->data = preOrder[0];

    for(root=0; root<inLen; root++)
    {
        if(preOrder[0] == inOrder[root]) break;
    }
    
    if(root==inLen) return -1;

    

}
