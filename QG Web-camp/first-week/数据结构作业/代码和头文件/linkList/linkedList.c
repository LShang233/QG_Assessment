#include "../head/linkedList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    if(NULL == (*L = (LNode *)malloc(sizeof(LNode))))
    {
        return OVERFLOW;
    }
    (*L)->next = NULL;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
    LNode *p;
    while(*L)
    {
        p = (*L)->next;
        free(*L);
        *L = p;
    }
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
    if(NULL == p || NULL == q) return ERROR;
    q->next = p->next;
    p->next = q;
    return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    if(NULL == p || NULL == p->next) return ERROR;
    LNode *i;
    i = p->next;
    *e = i->data;
    p->next = p->next->next;
    free(i);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void print(ElemType e) {printf("%d  ", e);}
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    L = L->next;
    while(L)
    {
        (*visit)(L->data);
        L = L->next;
    }
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    if(NULL == (L = L->next) || NULL == L) return ERROR;
    while(L)
    {
        if(L->data == e)
        {
            return SUCCESS;
        }
        L = L->next;
    }
    return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    LNode *p, *q;
    if(NULL == (*L)->next) return ERROR;
    if(NULL == (*L)->next->next) return SUCCESS;
    p = (*L)->next;
    (*L)->next = NULL;
    while(p)
    {
        q = p->next;
        p->next = (*L)->next;
        (*L)->next = p;
        p = q;
    }
    return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    LNode *quick, *slow;
    quick = slow = L->next;
    while(quick->next && quick->next->next)
    {
        slow = slow->next;
        quick = quick->next->next;
        if(quick == slow) return SUCCESS;
    }
    return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
    LinkedList oddd, evee, pre;
    pre = *L;
    while(NULL != pre->next && NULL != pre->next->next)
    {
        oddd = pre->next;
        evee = oddd->next;

        oddd->next = evee->next;
        pre->next = evee;
        evee->next = oddd;

        pre = oddd;
    }
    return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
    LNode *quick, *slow;
    quick = slow = (*L)->next;
    while(NULL != quick && NULL != quick->next)
    {
        slow = slow->next;
        quick = quick->next->next;
    }
    return slow;
}
