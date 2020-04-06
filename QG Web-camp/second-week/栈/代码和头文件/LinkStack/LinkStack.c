#include "../head/LinkStack.h"
#include <stdlib.h>
#include <stdio.h>

Status initLStack(LinkStack *s)//��ʼ��ջ
{
    (*s).count = 0;
    (*s).top = NULL;
	return SUCCESS;
};

Status isEmptyLStack(LinkStack *s)//�ж�ջ�Ƿ�Ϊ��
{
    if(!(*s).top) return SUCCESS;
    else return ERROR;
};

Status getTopLStack(LinkStack *s,ElemType *e)//�õ�ջ��Ԫ��
{
    if(NULL == (*s).top) return ERROR;
    *e = (*s).top->data;
    return SUCCESS;
};

Status clearLStack(LinkStack *s)//���ջ
{
    StackNode *p;
    p = (*s).top;
    while((*s).top)
    {
        p = p->next;
        free((*s).top);
        (*s).top = p;
    }
    (*s).count = 0;
    return SUCCESS;
};

Status destroyLStack(LinkStack *s)//����ջ
{
    clearLStack(s);
    free(s);
    return SUCCESS;
};

Status LStackLength(LinkStack *s,int *length)//���ջ����
{
    *length = (*s).count;
    return SUCCESS;
};

Status pushLStack(LinkStack *s,ElemType data)//��ջ
{
    StackNode *p;
    p = (StackNode *)malloc(sizeof(StackNode));
    if(NULL == p) return ERROR;
    p->data = data;

    p->next = (*s).top;
    (*s).top = p;

    (*s).count ++;
    return SUCCESS;
};

Status popLStack(LinkStack *s,ElemType *data)//��ջ
{
    if(!(*s).top) return ERROR;
    StackNode *p;
    p = (*s).top;
    (*s).top = (*s).top->next;
    *data = p->data;
    free(p);
    (*s).count --;
    return SUCCESS;
};
