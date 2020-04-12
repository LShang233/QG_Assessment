#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head/LQueue.h"
int getint();
void datatips();
char getchtype();
double getdouble();
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
    Q->front = Q->rear = NULL;
    Q->length = head = tail = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
    Node *p;
    p = Q->front;
    while(p != Q->rear)
    {
        p = Q->front;
        Q->front = Q->front->next;
        free(p->data);
        free(p);
    }
    free(Q->front);
    Q->front = Q->rear = NULL;
    Q->length = 0;
    head = tail = 0;
}


/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
    if(Q->length)
    {
        printf("\n��ǰ����Ϊ��%d\n", Q->length);
        return FALSE;
    }
    else
    {
        printf("\n����Ϊ�գ�\n");
        return TRUE;
    }
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
    if(!Q->length) return FALSE;
    switch(datatype[head])
    {
        case 'i':
            *(int *)e = *(int *)Q->front->data;
            printf("%d\n", *(int *)e);
            break;
        case 'd':
            *(double *)e = *(double *)Q->front->data;
            printf("%lf\n", *(double *)e);
            break;
        case 'c':
            *(char *)e = *(char *)Q->front->data;
            printf("%c\n", *(char *)e);
            break;
        case 's':
            strcpy((char*)Q->front->data, (char*)e);
            printf("%s\n", (char *)e);
            break;
        default:
            return FALSE;
    }
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
    if(Q->length == 0)
    {
        printf("\n����Ϊ�գ�\n");
        return 0;
    }
    return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data)
{
    if(Q->length > 30)
    {
        printf("\n�������͵�������\n����������\n");
        return FALSE;
    }

    int intdata = 0;
    double doubledata = 0;
    char chardata[100];
    int flag = 1;

    //�����ڵ���Ԥ����
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    newnode->data = (void *)malloc(sizeof(void));
    newnode->next = NULL;

    //���úýڵ������
    while(flag)
    {
        datatips();
        int j;
        datatype[tail] = getchtype();
        printf("            ��\n");
        printf("            %c\n", datatype[tail]);
        //��������
        switch(datatype[tail])
        {
            case 'i':
                printf("\n������ӵ����ݣ�");
                intdata = getint();
                printf("\n���������Ч�����ǣ�%d\n", intdata);
                *(int *)newnode->data = intdata;
                flag = 0;
                break;
            case 'd':
                printf("\n������ӵ����ݣ�");
                doubledata = getdouble();
                printf("\n���������Ч�����ǣ�%lf\n", doubledata);
                *(double *)newnode->data = doubledata;
                flag = 0;
                break;
            case 'c':
            case 's':
                printf("\n������ӵ����ݣ�");
                for(j = 0; j < 50; j++)
                    chardata[j] = '\0';
                gets(chardata);
                if(datatype[tail] == 'c')
                {
                    printf("\n���������Ч�����ǣ�%c\n", chardata[0]);
                    *(char *)newnode->data = chardata[0];
                }
                else
                {
                    strcpy((char *)newnode->data, chardata);
                    printf("\n���������Ч�����ǣ�%s\n", (char *)newnode->data);
                }
                flag = 0;
                break;
            default:
                printf("\n��Ŵ���!\n���������룡\n\n");
                break;
        }
    }
    //���ڵ��������
    if(Q->front)
        Q->rear->next = newnode;
    else
        Q->front = newnode;
    Q->rear = newnode;
    tail = (tail + 1) % 30;
    Q->length ++;
    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
    Node *p;
    p = Q->front;
    Q->front = Q->front->next;
    free(p);
    Q->length --;
    head = (head + 1) % 30;
    return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
    DestoryLQueue(Q);
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
    Node *p;
    p = Q->front;
    int count = 0;
    while(p && count <= Q->length)
    {
        int i;
        i = (head + count) % 30;
        type = datatype[i];
        foo(p->data);

        count ++;
        p = p->next;
    }
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q

 *  @notice      : None
 */
void LPrint(void *q)
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

char getchtype()
{
    //�ҵ����������ĵ�һ���ַ�
    char str[100] = {0};
    int i;
    gets(str);
    //���ݴ�Сд
    for(i = 0; i < 100; i++){
        if(str[i] == 'i' || str[i] == 'd' || str[i] == 'c' || str[i] == 's') return str[i];
        if(str[i] == 'I' || str[i] == 'D' || str[i] == 'C' || str[i] == 'S') return str[i] + 32;
    }
    return 'z';
}
void datatips()
{
    printf("        *�������Ӧ���*        \n");
    printf("|-----i.����              -----|\n");
    printf("|-----d.������            -----|\n");
    printf("|-----c.�ַ���            -----|\n");
    printf("|-----s.�ַ���            -----|\n");
    printf("\n\n���ѡ���ǣ�");
}
int getint()
{
    //int�ĳ�����
    long long num = 0;
    int i, j, f = 0;
    char str[50], ch[10];
    for(i = 0; i < 50; i++)
    {
        str[i] = 'a';
    }
    gets(str);
    //ȡ���ַ����ڳ��ֵĵ�һ������
    for(i = 0; i < 50; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            if(i > 0 && str[i-1] == '-') f = 1;
            for(j = i; j < 50 && (str[j] >= '0' && str[j] <= '9'); j++)
            {

                num = num * 10 + (str[j] - '0');
            }
            break;
        }
    }
    //�ж��Ƿ�Ϊ����
    if(f == 1) num *= (-1);
    //�������ֻ�����Ϊ0
    if(!num)
    {
        i = 1;
        while(i)
        {
            printf("\n�Ƿ�ȷ����������Ϊ0��\n1.��\n2.��\n\n��Ļش�");
            gets(ch);
            switch(ch[0])
            {
                case '1':
                    return 0;
                case '2':
                    i = 0;
                    printf("\n���ݴ������������룡\n");
                    printf("\n�������ݣ�");
                    //��������
                    return getint();
                default:
                    printf("\n��Ŵ�����������ȷ��ţ�\n");
            }
        }
    }
    //�ж��Ƿ������int��
    if(num > 2147483647 || num < -2147483648)
    {
        printf("\n�������,����������intֵ��Χ�ڵ����֣�\n");
        printf("\n�������ݣ�");
        //��������
        return getint();
    }
    else
        return num;
}
double getdouble()
{
    //�������������
    double num = 0;
    int i, j, f = 0;
    char str[50], ch[10];
    for(i = 0; i < 50; i++)
    {
        str[i] = '\0';
    }
    gets(str);
    //ȡ���ַ����ڳ��ֵĵ�һ������
    for(i = 0; i < 50; i++)
    {
        //�ҵ���һ������
        if(str[i] >= '0' && str[i] <= '9')
        {
            if(i > 0 && str[i-1] == '-') f = 1;
            //˳���ҵ�һ������
            for(j = i; j < 50 && (str[j] >= '0' && str[j] <= '9'); j++)
            {

                num = num * 10 + (str[j] - '0');
            }
            break;
        }
    }
    //��ʱjָ���ַ������ֺ���ַ�
    if(str[j] == '.')
    {
        int ten = 10;
        float point;
        for(j = j + 1; j < 50 && (str[j] >= '0' && str[j] <= '9'); j++)
        {
            point = str[j] - '0';
            num = num + point / ten;
            ten *= 10;
        }
    }
    //�ж��Ƿ�Ϊ����
    if(f == 1) num *= (-1);
    //�������ֻ�����Ϊ0
    if(!num || i == 50)
    {
        i = 1;
        while(i)
        {
            printf("\n�Ƿ�ȷ����������Ϊ0��\n1.��\n2.��\n\n��Ļش�");
            gets(ch);
            switch(ch[0])
            {
                case '1':
                    return 0;
                case '2':
                    i = 0;
                    printf("\n���ݴ������������룡\n");
                    printf("\n�������ݣ�");
                    //��������
                    return getdouble();
                default:
                    printf("\n��Ŵ�����������ȷ��ţ�\n");
            }
        }
    }
    return num;
}
