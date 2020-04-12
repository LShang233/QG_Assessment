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
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
    Q->front = Q->rear = NULL;
    Q->length = head = tail = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
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
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
    if(Q->length)
    {
        printf("\n当前长度为：%d\n", Q->length);
        return FALSE;
    }
    else
    {
        printf("\n队列为空！\n");
        return TRUE;
    }
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
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
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
    if(Q->length == 0)
    {
        printf("\n队列为空！\n");
        return 0;
    }
    return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data)
{
    if(Q->length > 30)
    {
        printf("\n超出泛型的容量！\n队列已满！\n");
        return FALSE;
    }

    int intdata = 0;
    double doubledata = 0;
    char chardata[100];
    int flag = 1;

    //创建节点与预处理
    Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    newnode->data = (void *)malloc(sizeof(void));
    newnode->next = NULL;

    //设置好节点的数据
    while(flag)
    {
        datatips();
        int j;
        datatype[tail] = getchtype();
        printf("            ↓\n");
        printf("            %c\n", datatype[tail]);
        //输入数据
        switch(datatype[tail])
        {
            case 'i':
                printf("\n输入入队的数据：");
                intdata = getint();
                printf("\n你输入的有效数据是：%d\n", intdata);
                *(int *)newnode->data = intdata;
                flag = 0;
                break;
            case 'd':
                printf("\n输入入队的数据：");
                doubledata = getdouble();
                printf("\n你输入的有效数据是：%lf\n", doubledata);
                *(double *)newnode->data = doubledata;
                flag = 0;
                break;
            case 'c':
            case 's':
                printf("\n输入入队的数据：");
                for(j = 0; j < 50; j++)
                    chardata[j] = '\0';
                gets(chardata);
                if(datatype[tail] == 'c')
                {
                    printf("\n你输入的有效数据是：%c\n", chardata[0]);
                    *(char *)newnode->data = chardata[0];
                }
                else
                {
                    strcpy((char *)newnode->data, chardata);
                    printf("\n你输入的有效数据是：%s\n", (char *)newnode->data);
                }
                flag = 0;
                break;
            default:
                printf("\n编号错误!\n请重新输入！\n\n");
                break;
        }
    }
    //将节点插入链表
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
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
    DestoryLQueue(Q);
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
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
 *    @description : 操作函数
 *    @param         q 指针q

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
    //找到符合条件的第一个字符
    char str[100] = {0};
    int i;
    gets(str);
    //兼容大小写
    for(i = 0; i < 100; i++){
        if(str[i] == 'i' || str[i] == 'd' || str[i] == 'c' || str[i] == 's') return str[i];
        if(str[i] == 'I' || str[i] == 'D' || str[i] == 'C' || str[i] == 'S') return str[i] + 32;
    }
    return 'z';
}
void datatips()
{
    printf("        *请输入对应编号*        \n");
    printf("|-----i.整型              -----|\n");
    printf("|-----d.浮点型            -----|\n");
    printf("|-----c.字符型            -----|\n");
    printf("|-----s.字符串            -----|\n");
    printf("\n\n你的选择是：");
}
int getint()
{
    //int的出错处理
    long long num = 0;
    int i, j, f = 0;
    char str[50], ch[10];
    for(i = 0; i < 50; i++)
    {
        str[i] = 'a';
    }
    gets(str);
    //取出字符串内出现的第一段数字
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
    //判断是否为负数
    if(f == 1) num *= (-1);
    //若无数字或数字为0
    if(!num)
    {
        i = 1;
        while(i)
        {
            printf("\n是否确定输入数据为0？\n1.是\n2.否\n\n你的回答：");
            gets(ch);
            switch(ch[0])
            {
                case '1':
                    return 0;
                case '2':
                    i = 0;
                    printf("\n数据错误！请重新输入！\n");
                    printf("\n输入数据：");
                    //重新输入
                    return getint();
                default:
                    printf("\n编号错误！请输入正确编号！\n");
            }
        }
    }
    //判断是否溢出（int）
    if(num > 2147483647 || num < -2147483648)
    {
        printf("\n数据溢出,请重新输入int值范围内的数字！\n");
        printf("\n输入数据：");
        //重新输入
        return getint();
    }
    else
        return num;
}
double getdouble()
{
    //无数据溢出处理
    double num = 0;
    int i, j, f = 0;
    char str[50], ch[10];
    for(i = 0; i < 50; i++)
    {
        str[i] = '\0';
    }
    gets(str);
    //取出字符串内出现的第一段数字
    for(i = 0; i < 50; i++)
    {
        //找到第一个数字
        if(str[i] >= '0' && str[i] <= '9')
        {
            if(i > 0 && str[i-1] == '-') f = 1;
            //顺势找到一串数字
            for(j = i; j < 50 && (str[j] >= '0' && str[j] <= '9'); j++)
            {

                num = num * 10 + (str[j] - '0');
            }
            break;
        }
    }
    //此时j指向字符串数字后的字符
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
    //判断是否为负数
    if(f == 1) num *= (-1);
    //若无数字或数字为0
    if(!num || i == 50)
    {
        i = 1;
        while(i)
        {
            printf("\n是否确定输入数据为0？\n1.是\n2.否\n\n你的回答：");
            gets(ch);
            switch(ch[0])
            {
                case '1':
                    return 0;
                case '2':
                    i = 0;
                    printf("\n数据错误！请重新输入！\n");
                    printf("\n输入数据：");
                    //重新输入
                    return getdouble();
                default:
                    printf("\n编号错误！请输入正确编号！\n");
            }
        }
    }
    return num;
}
