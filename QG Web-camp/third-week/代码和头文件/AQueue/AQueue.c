#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head/AQueue.h"

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
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
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
    return Q->length;
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
    Q->rear = Q->front = Q->length = 0;
}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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
 *    @description : ��������
 *    @param         q ָ��q
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
