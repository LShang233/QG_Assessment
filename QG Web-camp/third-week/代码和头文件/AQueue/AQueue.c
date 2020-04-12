#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head/AQueue.h"

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
    int i;
    for(i = 0; i < MAXQUEUE; i ++)
    {
        Q->data[i] = (void *)malloc(sizeof(void));
    }
    Q->length = Q->front = Q->rear = 0;

}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
    int i;
    for(i = 0; i < MAXQUEUE; i ++)
    {
        free(Q->data[i]);
    }
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
    if(Q->length == MAXQUEUE)
        return TRUE;
    else
        return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
    if(!Q->length)
        return TRUE;
    else
        return FALSE;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e)
{
    if(IsEmptyAQueue(Q)) return FALSE;
    switch(datatype[Q->front])
    {
        case 'i':
            *(int *)e = *(int *)Q->data[Q->front];
            printf("%d\n", *(int *)e);
            break;
        case 'd':
            *(double *)e = *(double *)Q->data[Q->front];
            printf("%lf\n", *(double *)e);
            break;
        case 'c':
            *(char *)e = *(char *)Q->data[Q->front];
            printf("%c\n", *(char *)e);
            break;
        case 's':
            strcpy((char*)Q->data[Q->front], (char*)e);
            printf("%s\n", (char *)e);
            break;
        default:
            return FALSE;
    }


    return TRUE;
}



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
    return Q->length;
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data)
{
    if(IsFullAQueue(Q)) return FALSE;
    switch(datatype[Q->rear])
    {
        case 'i':
            *(int *)Q->data[Q->rear] = *(int *)data;
            break;
        case 'd':
            *(double *)Q->data[Q->rear] = *(double *)data;
            break;
        case 'c':
            *(char *)Q->data[Q->rear] = *(char *)data;
            break;
        case 's':
            strcpy((char*)Q->data[Q->rear], (char*)data);
            break;
        default:
            return FALSE;
    }
    Q->length ++;
    Q->rear = (Q->rear + 1) % MAXQUEUE;

    return TRUE;
}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
    if(IsEmptyAQueue(Q)) return FALSE;

    Q->length --;
    Q->front = (Q->front + 1) % MAXQUEUE;

    return TRUE;
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
    Q->rear = Q->front = Q->length = 0;
}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
    if(IsEmptyAQueue(Q)) return FALSE;
    int i;
    for(i = Q->front; i != Q->rear; i = (i + 1) % MAXQUEUE)
    {
        type = datatype[i];
        foo(Q->data[i]);
    }
    return TRUE;
}



/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q)
{
    switch(type)
    {
        case 'i':
            printf("%d  ", *(int *)q);
            break;
        case 'd':
            printf("%lf  ", *(double *)q);
            break;
        case 'c':
            printf("%c  ", *(char *)q);
            break;
        case 's':
            printf("%s  ", (char *)q);
            break;
    }
}
