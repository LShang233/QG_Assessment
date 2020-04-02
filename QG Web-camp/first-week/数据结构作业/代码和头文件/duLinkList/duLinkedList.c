#include "../head/duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
    if(NULL == (*L = (DuLNode *)malloc(sizeof(DuLNode))))
    {
        return OVERFLOW;
    }
    (*L)->next = NULL;
    (*L)->prior = NULL;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
    DuLNode *p;
    while(*L)
    {
        p = (*L)->next;
        free(*L);
        *L = p;
    }
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    if(NULL == p || NULL == q || p->prior == NULL) return ERROR;
    q->prior = p->prior;
    q->next = p;
    q->prior->next = q;
    p->prior = q;
    return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    if(NULL == p || NULL == q) return ERROR;
    q->next = p->next;
    p->next = q;

    q->prior = p;
    if(q->next)
        q->next->prior = q;

    return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    if(NULL == p || NULL == p->next) return ERROR;

    DuLNode *i;
    i = p->next;
    *e = i->data;
    p->next = i->next;

    if(p->next)
        p->next->prior = p;
    free(i);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void print(ElemType e) {printf("%d  ", e);}
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    L = L->next;
    while(L)
    {
        (*visit)(L->data);
        L = L->next;
    }
}
