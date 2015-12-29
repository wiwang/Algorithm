#include "List.h"


T_Node* ReverseLink(T_Node *head)
{
    T_Node *current, pre;
    
    pre = NULL;
    current = head;

    while(NULL != current)
    {
        current->next = pre;
        pre = current;
        current = current->next;
    }

    head = current;

    return head;
}
