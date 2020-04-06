#include "../head/SqStack.h"
#include <stdlib.h>
#include <stdio.h>

Status initStack(SqStack *s,int sizes) {//��ʼ��ջ
    (*s).elem = (ElemType *)malloc(sizes * sizeof(ElemType));
    if(NULL == (*s).elem) return ERROR;
    (*s).top = 0;
    (*s).size = sizes;
    return SUCCESS;
};

Status isEmptyStack(SqStack *s){//�ж�ջ�Ƿ�Ϊ��
    if((*s).top) return ERROR;
    else return SUCCESS;
};

Status getTopStack(SqStack *s,ElemType *e) {//�õ�ջ��Ԫ��
    if((*s).top)
    {
        *e = (*s).elem[(*s).top-1];
        return SUCCESS;
    }
    else return ERROR;
};

Status clearStack(SqStack *s) {//���ջ
    (*s).top = 0;
    return SUCCESS;
};

Status destroyStack(SqStack *s) {//����ջ
    free(s);
    return SUCCESS;
};

Status stackLength(SqStack *s,int *length) {//���ջ����
    *length = (*s).top;
    return SUCCESS;
};

Status pushStack(SqStack *s,ElemType data) {//��ջ
    if((*s).top >= (*s).size) return ERROR;
    (*s).elem[(*s).top ++] = data;
    return SUCCESS;
};

Status popStack(SqStack *s,ElemType *data) {//��ջ
    *data = (*s).elem[-- (*s).top];
    return SUCCESS;
};
