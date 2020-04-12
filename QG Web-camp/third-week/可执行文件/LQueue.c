#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LQueue.c"
void tips();
char getch();

int main()
{
    LQueue *Q;
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
                Q = (LQueue*)malloc(sizeof(LQueue));
                InitLQueue(Q);
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
                EnLQueue(Q, e);
                printf("\n入队成功！\n");
                break;
            //c.出队
            case 'c':
                if(!f)
                {
                    printf("\n请先初始化！\n");
                    break;
                }
                if(Q->length == 0)
                {
                    printf("\n队列为空！请入队！\n");
                    break;
                }
                DeLQueue(Q);
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
                if(Q->length == 0)
                {
                    printf("\n队列为空！请入队！\n");
                    break;
                }
                ClearLQueue(Q);
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
                if(Q->length == 0)
                {
                    printf("\n队列为空！请入队！\n");
                    break;
                }
                printf("\n当前队列为：\n");
                TraverseLQueue(Q, LPrint);
                putchar('\n');
                break;
            //f.确定队列长度
            case 'f':
                if(!f)
                {
                    printf("\n请先初始化！\n");
                    break;
                }
                printf("\n队列长度为：%d\n", LengthLQueue(Q));
                break;
            //g.查看队头元素
            case 'g':
                if(!f)
                {
                    printf("\n请先初始化！\n");
                    break;
                }
                if(Q->length == 0)
                {
                    printf("\n队列为空！请入队！\n");
                    break;
                }
                printf("\n队头元素:");
                GetHeadLQueue(Q, e);
                break;
            //h.检查队列是否为空
            case 'h':
                if(!f)
                {
                    printf("\n请先初始化！\n");
                    break;
                }
                //输出结果
                if(Q->length == 0)
                {
                    printf("\n队列为空！请入队！\n");
                }
                else
                {
                    printf("\n队列不为空！\n");
                    printf("\n当前长度为：%d\n", Q->length);
                }
                break;
            //i.销毁队列,结束进程
            case 'i':
                if(f)
                    DestoryLQueue(Q);
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
    printf("|-----h.检查队列是否为空  -----|\n");
    printf("|-----i.销毁队列,结束进程 -----|\n");
    printf("\n\n你的选择是：");
}
char getch()
{
    //找到符合条件的第一个字符
    char str[100] = {0};
    int i;
    gets(str);
    //兼容大小写
    for(i = 0; i < 100; i++){
        if((str[i] >= 'a') && (str[i] <= 'i')) return str[i];
        if((str[i] >= 'A') && (str[i] <= 'I')) return str[i] + 32;
    }
    return 'z';
}
