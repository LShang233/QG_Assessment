#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AQueue.c"
char getch();
void tips();
int getint();
void datatips();
double getdouble();
char getchtype();

int main()
{
    AQueue *Q;
    char ch;
    char str[100];
    int flag, f = 0, i;
    void *e;
    e = (void*)malloc(sizeof(void));
    //f判断是否初始化
    //flag:接收枚举返回值
    while(1)
    {
        //ch输入
        tips();
        ch = getch();
        printf("            ↓\n");
        printf("            %c\n",ch);

        switch(ch)
        {
            //a.初始化队列
            case 'a':
                if(f)
                {
                    printf("\n已初始化！\n");
                    break;
                }
                Q = (AQueue*)malloc(sizeof(AQueue));
                InitAQueue(Q);
                printf("\n初始化成功！\n");
                f = 1;
                break;
            //b.入队
            case 'b':
                if(!f)
                {
                    printf("\n请先初始化！\n");
                    break;
                }
                char chtype;
                //入队
                flag = 1;
                int intdata;
                double doubledata;
                char chardata[100];
                while(flag)
                {
                    //输入正确的datatype
                    datatips();
                    datatype[Q->rear] = getchtype();
                    printf("            ↓\n");
                    printf("            %c\n", datatype[Q->rear]);
                    switch(datatype[Q->rear])
                    {
                        case 'i':
                            printf("\n输入入队的数据：");
                            intdata = getint();
                            printf("\n你输入的有效数据是：%d\n", intdata);
                            *(int *)e = intdata;
                            EnAQueue(Q, e);
                            flag = 0;
                            break;
                        case 'd':
                            printf("\n输入入队的数据：");
                            doubledata = getdouble();
                            printf("\n你输入的有效数据是：%lf\n", doubledata);
                            *(double *)e = doubledata;
                            EnAQueue(Q, e);
                            flag = 0;
                            break;
                        case 'c':
                        case 's':
                            printf("\n输入入队的数据：");
                            for(i = 0; i < 50; i++) chardata[i] = '\0';
                            gets(chardata);
                            if(datatype[Q->rear] == 'c')
                            {
                                printf("\n你输入的有效数据是：%c\n", chardata[0]);
                                *(char *)e = chardata[0];
                            }
                            else
                            {
                                strcpy((char *)e, chardata);
                                printf("\n你输入的有效数据是：%s\n", (char *)e);
                            }
                            EnAQueue(Q, e);
                            flag = 0;
                            break;
                        default:
                            printf("\n编号错误!\n请重新输入！\n\n");
                    }
                }
                printf("\n入队成功！\n");
                break;
            //c.出队
            case 'c':
                if(!f)
                {
                    printf("\n请先初始化！\n");
                    break;
                }
                if(IsEmptyAQueue(Q))
                {
                    printf("\n队列为空！请入队！\n");
                    break;
                }
                DeAQueue(Q);
                //输出结果
                printf("\n已出队！\n");
                break;
            //d.清空队列
            case 'd':
                if(!f)
                {
                    printf("\n请先初始化！\n");
                    break;
                }
                if(IsEmptyAQueue(Q))
                {
                    printf("\n队列为空！请入队！\n");
                    break;
                }
                ClearAQueue(Q);
                //输出结果
                printf("\n已清空！\n");
                break;
            //e.输出队列
            case 'e':
                if(!f)
                {
                    printf("\n请先初始化！\n");
                    break;
                }
                if(IsEmptyAQueue(Q))
                {
                    printf("\n队列为空！请入队！\n");
                    break;
                }
                printf("\n当前队列为：\n");
                TraverseAQueue(Q, APrint);
                putchar('\n');
                break;
            //f.确定队列长度
            case 'f':
                if(!f)
                {
                    printf("\n请先初始化！\n");
                    break;
                }
                printf("\n队列长度为：%d\n", LengthAQueue(Q));
                break;
            //g.查看队头元素
            case 'g':
                if(!f)
                {
                    printf("\n请先初始化！\n");
                    break;
                }
                if(IsEmptyAQueue(Q))
                {
                    printf("\n队列为空！请入队！\n");
                    break;
                }
                printf("\n队头元素:");
                GetHeadAQueue(Q, e);
                break;
            //h.检查队列是否已满
            case 'h':
                if(!f)
                {
                    printf("\n请先初始化！\n");
                    break;
                }
                //输出结果
                if(IsFullAQueue(Q))
                {
                    printf("\n队列已满！\n");
                }
                else
                {
                    printf("\n队列未满！\n");
                    printf("\n当前长度为：%d\n", Q->length);
                }
                break;
            //i.检查队列是否为空
            case 'i':
                if(!f)
                {
                    printf("\n请先初始化！\n");
                    break;
                }
                //输出结果
                if(IsEmptyAQueue(Q))
                {
                    printf("\n队列为空！\n");
                }
                else
                {
                    printf("\n队列不为空！\n");
                    printf("\n当前长度为：%d\n", Q->length);
                }
                break;
            //j.销毁队列,结束进程
            case 'j':
                if(f)
                    DestoryAQueue(Q);
                return 0;
            default:
                printf("\n请输入有效编号！\n");
                break;
        }
        putchar('\n');
        system("pause");
        system("cls");
    }

    return 0;
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
        printf("\n输入q节点数据：");
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
            if(str[i-1] == '-') f = 1;
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
                    return getdouble();
                default:
                    printf("\n编号错误！请输入正确编号！\n");
            }
        }
    }
    return num;
}
void tips()
{
    printf("        *请输入对应编号*        \n");
    printf("|-----a.初始化队列        -----|\n");
    printf("|-----b.入队              -----|\n");
    printf("|-----c.出队              -----|\n");
    printf("|-----d.清空队列          -----|\n");
    printf("|-----e.输出队列          -----|\n");
    printf("|-----f.确定队列长度      -----|\n");
    printf("|-----g.查看队头元素      -----|\n");
    printf("|-----h.检查队列是否已满  -----|\n");
    printf("|-----i.检查队列是否为空  -----|\n");
    printf("|-----j.销毁队列,结束进程 -----|\n");
    printf("\n\n你的选择是：");
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
