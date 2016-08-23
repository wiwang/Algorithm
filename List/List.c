/*
the fundamental operations on linked list like create, add, delete, insert, merge, reverse and so on
*/


#include <stdio.h>
#include <stdlib.h>

#include "List.h"


T_Node* createList(char *data[], int size)
{
    T_Node *node, *head;

    if (data == NULL)
        return NULL;
    
    head = NULL;
    while(--size >= 0)
    {
        if((node=(T_Node *)malloc(sizeof(T_Node))) != NULL)
        {
            node->data = data[size];
            node->next = head;
            head = node;
        }
    }

    return head;
}

T_Node* getNext(T_Node *current)
{
    return (current!=NULL ? current->next : NULL);
}

T_Node* reverseList(T_Node *head)
{
    T_Node *current, *pre, *next;
    
    pre = NULL;
    current = head;

    while(NULL != current)
    {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }

    return pre;
}


int main(int argc, char *argv[])
{
    char *data[] = {"a", "b", "c", "d", "e", "f", "g"};    
    
    T_Node *node;
    T_Node *head = createList(data, sizeof(data)/sizeof(char *));
    
    printf("the List is:\n"); 
    for(node=head; node!=NULL; node=getNext(node))
    {
        printf("%s", node->data); 
    }
    printf("\n");

    head = reverseList(head);

    printf("the reversed List is:\n");
    for(node=head; node!=NULL; node=getNext(node))
    {
        printf("%s", node->data); 
    }
    printf("\n");
    
    return 0;
}

