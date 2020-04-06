#include "../head/LinkStack.h"
#include <stdlib.h>
#include <stdio.h>

Status initLStack(LinkStack *s)//初始化栈
{
    (*s).count = 0;
    (*s).top = NULL;
	return SUCCESS;
};

Status isEmptyLStack(LinkStack *s)//判断栈是否为空
{
    if(!(*s).top) return SUCCESS;
    else return ERROR;
};

Status getTopLStack(LinkStack *s,ElemType *e)//得到栈顶元素
{
    if(NULL == (*s).top) return ERROR;
    *e = (*s).top->data;
    return SUCCESS;
};

Status clearLStack(LinkStack *s)//清空栈
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

Status destroyLStack(LinkStack *s)//销毁栈
{
    clearLStack(s);
    free(s);
    return SUCCESS;
};

Status LStackLength(LinkStack *s,int *length)//检测栈长度
{
    *length = (*s).count;
    return SUCCESS;
};

Status pushLStack(LinkStack *s,ElemType data)//入栈
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

Status popLStack(LinkStack *s,ElemType *data)//出栈
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
