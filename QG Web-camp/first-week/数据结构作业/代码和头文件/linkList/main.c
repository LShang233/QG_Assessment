#include "../head/linkedList.h"
#include "linkedList.c"
#include <stdio.h>
#include <stdlib.h>
void tips();
char getch();
int getint();
LNode* SetLNode(ElemType e);
void printList(LinkedList L);
LNode* FindList(LinkedList L, ElemType e);
int main()
{
    LinkedList L;
    L = NULL;
    while(1)
    {
        char ch;
        int flag, p, e;
        //flag:接收枚举返回值
        LNode *q;

        //ch输入
        tips();
        ch = getch();
        printf("            ↓\n");
        printf("            %c\n",ch);

        switch(ch)
        {
            //a.初始化链表
            case 'a':
                if(InitList(&L))
                {
                    printf("\n初始化成功！\n");
                }
                else printf("\n初始化失败！\n");
                break;
            //b.插入节点
            case 'b':
                if(NULL == L)
                {
                    printf("\n请先初始化\n");
                    break;
                }
                printf("\nb：将q节点插入到p节点后\n");
                //输入p节点
                printf("\n输入新增q节点的数据（int）：");
                q = SetLNode(getint());
                printf("\n您输入的有效数据为：%d\n", q->data);
                //判断并插入q节点
                if(NULL == L->next)
                {
                    printf("\n当前链表为空，默认将p插入到头结点。\n");
                    flag = InsertList(L, q);
                }
                else
                {
                    printList(L);
                    printf("\n请选择q节点的数据：");
                    p = getint();
                    printf("\n您输入的有效数据为：%d\n", p);
                    flag = InsertList(FindList(L, p), q);
                }
                //输出插入结果
                if(flag)
                {
                    printf("\n插入成功！\n");
                }
                else
                {
                    if(NULL == FindList(L, p))
                    {
                        printf("\n未找到p节点\n");
                    }
                    else
                        printf("\n插入失败！\n");
                    //是否插入至头结点
                    int i = 1;
                    char ch[20];
                    while(i)
                    {
                        printf("\n是否插入至头节点？\n1.是\n2.否\n\n你的回答：");
                        gets(ch);
                        switch(ch[0])
                        {
                            case '1':
                                flag = InsertList(L, q);
                                if(flag)
                                {
                                    printf("\n成功插入头节点！\n");
                                }
                                else
                                {
                                    printf("\n插入失败！\n");
                                }
                                i = 0;
                                break;
                            case '2':
                                i = 0;
                                printf("\n插入失败！\n");
                                break;
                            default:
                                printf("\n编号错误！请输入正确编号！\n");
                        }
                    }
                }
                break;
            //c.输出链表
            case 'c':
                if(NULL == L)
                {
                    printf("\n请先初始化\n");
                    break;
                }
                if(NULL == L->next)
                {
                    printf("\n链表为空！请输入节点数据！\n");
                    break;
                }
                printList(L);
                break;
            //d.反向链接列表
            case 'd':
                if(NULL == L)
                {
                    printf("\n请先初始化\n");
                    break;
                }
                if(NULL == L->next)
                {
                    printf("\n链表为空！请输入节点数据！\n");
                    break;
                }
                printList(L);
                flag = ReverseList(&L);
                //输出结果
                if(flag)
                {
                    printf("\n反向连接后为：\n");
                    TraverseList(L, print);
                    putchar('\n');
                }
                else
                {
                    printf("\n反向失败！\n");
                }
                break;
            //e.调换奇偶顺序
            case 'e':
                if(NULL == L)
                {
                    printf("\n请先初始化\n");
                    break;
                }
                if(NULL == L->next)
                {
                    printf("\n链表为空！请输入节点数据！\n");
                    break;
                }
                printf("\ne：调换奇偶顺序\ne.g:input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3\n");
                //修改前
                printList(L);
                L = ReverseEvenList(&L);
                //修改后
                printf("\n修改后链表为：\n");
                TraverseList(L, print);
                putchar('\n');
                break;
            //f.找到中间节点
            case 'f':
                if(NULL == L)
                {
                    printf("\n请先初始化\n");
                    break;
                }
                if(NULL == L->next)
                {
                    printf("\n链表为空！请输入节点数据！\n");
                    break;
                }
                printList(L);
                q = FindMidNode(&L);
                //q为找到的中间节点
                if(NULL != q)
                    printf("\n当前链表的中间节点的数据为：%d\n", q->data);
                else
                    printf("\n链表为空！请输入节点数据！\n");
                break;
            //g.删除节点并取值
            case 'g':
                if(NULL == L)
                {
                    printf("\n请先初始化\n");
                    break;
                }
                if(NULL == L->next)
                {
                    printf("\n链表为空！请输入节点数据！\n");
                    break;
                }
                printf("\ng：删除p后的第一个节点，并获取其值。\n");
                printList(L);
                printf("\n请选择p节点数据：\n");
                p = getint();
                //找到p节点,先判断p节点的位置
                q = FindList(L, p);
                if(NULL == q)
                {
                    printf("\n未找到p节点\n");
                }
                else if(NULL == q->next)
                {
                    printf("\np为最后一个节点\n");
                }
                else
                {
                    //条件符合输出节点
                    DeleteList(q, &e);
                    printf("\np下一个节点的值为：%d\n", e);
                }
                break;
            //h.查询节点是否存在
            case 'h':
                if(NULL == L)
                {
                    printf("\n请先初始化\n");
                    break;
                }
                if(NULL == L->next)
                {
                    printf("\n链表为空！请输入节点数据！\n");
                    break;
                }
                printf("\n需要查询的节点数据为：");
                p = getint();
                flag = SearchList(L, p);
                //输出结果
                if(flag)
                    printf("\n节点存在！\n");
                else
                    printf("\n未找到该节点！\n");
                break;
            //i.判断链表是否成环
            case 'i':
                if(NULL == L)
                {
                    printf("\n请先初始化\n");
                    break;
                }
                if(NULL == L->next)
                {
                    printf("\n链表为空！请输入节点数据！\n");
                    break;
                }
                //输出结果
                if(IsLoopList(L))
                {
                    printf("\n链表成环！\n");
                }
                else
                {
                    printf("\n链表未成环！\n");
                }
                break;
            //j.销毁链表,结束进程
            case 'j':
                DestroyList(&L);
                return 0;

            default:
                printf("\n请输入有效编号！\n");
                break;
        }
        putchar('\n');
        system("pause");
        system("cls");
    }
}
void tips()
{
    printf("        *请输入对应编号*        \n");
    printf("|-----a.初始化链表        -----|\n");
    printf("|-----b.插入节点          -----|\n");
    printf("|-----c.输出链表          -----|\n");
    printf("|-----d.反向链接列表      -----|\n");
    printf("|-----e.调换奇偶顺序      -----|\n");
    printf("|-----f.找到中间节点      -----|\n");
    printf("|-----g.删除节点并取值    -----|\n");
    printf("|-----h.查询节点是否存在  -----|\n");
    printf("|-----i.判断链表是否成环  -----|\n");
    printf("|-----j.销毁链表,结束进程 -----|\n");
    printf("\n\n你的选择是：");
}
LNode* SetLNode(ElemType e)
{
    //创建新节点，数据为e
    LNode *New;
    New = (LNode *)malloc(sizeof(LNode));
    New->data = e;
    return New;
}
void printList(LinkedList L)
{
    //输出链表
    printf("\n当前链表为：\n");
    TraverseList(L, print);
    putchar('\n');
}
LNode* FindList(LinkedList L, ElemType e)
{
    //在L中找到数据为e的节点，返回该节点地址
    if(NULL == (L = L->next) || NULL == L) return NULL;
    while(L)
    {
        if(L->data == e)
        {
            return L;
        }
        L = L->next;
    }
    return NULL;
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
            if(str[i-1] == '-') f = 1;
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
                    printf("\n输入q节点数据：");
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
        printf("\n输入q节点数据：");
        //重新输入
        return getint();
    }
    else
        return num;
}
char getch()
{
    //找到符合条件的第一个字符
    char str[100] = {0};
    int i;
    gets(str);
    //兼容大小写
    for(i = 0; i < 100; i++){
        if((str[i] >= 'a') && (str[i] <= 'j')) return str[i];
        if((str[i] >= 'A') && (str[i] <= 'J')) return str[i] + 32;
    }
    return 'z';
}
