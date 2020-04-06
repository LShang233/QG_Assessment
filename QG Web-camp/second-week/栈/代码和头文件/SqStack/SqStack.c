#include "../head/SqStack.h"
#include <stdlib.h>
#include <stdio.h>

Status initStack(SqStack *s,int sizes) {//初始化栈
    (*s).elem = (ElemType *)malloc(sizes * sizeof(ElemType));
    if(NULL == (*s).elem) return ERROR;
    (*s).top = 0;
    (*s).size = sizes;
    return SUCCESS;
};

Status isEmptyStack(SqStack *s){//判断栈是否为空
    if((*s).top) return ERROR;
    else return SUCCESS;
};

Status getTopStack(SqStack *s,ElemType *e) {//得到栈顶元素
    if((*s).top)
    {
        *e = (*s).elem[(*s).top-1];
        return SUCCESS;
    }
    else return ERROR;
};

Status clearStack(SqStack *s) {//清空栈
    (*s).top = 0;
    return SUCCESS;
};

Status destroyStack(SqStack *s) {//销毁栈
    free(s);
    return SUCCESS;
};

Status stackLength(SqStack *s,int *length) {//检测栈长度
    *length = (*s).top;
    return SUCCESS;
};

Status pushStack(SqStack *s,ElemType data) {//入栈
    if((*s).top >= (*s).size) return ERROR;
    (*s).elem[(*s).top ++] = data;
    return SUCCESS;
};

Status popStack(SqStack *s,ElemType *data) {//出栈
    *data = (*s).elem[-- (*s).top];
    return SUCCESS;
};
