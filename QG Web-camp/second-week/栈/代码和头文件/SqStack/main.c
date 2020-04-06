#include <stdio.h>
#include <stdlib.h>
#include "SqStack.c"
int getint();
char getch();
void tips();
void printStack(SqStack *s);
int main()
{
    int f = 0;//f用来判断是否初始化
    SqStack s;
    char ch;
    while(1) {
        tips();
        ch = getch();
        printf("            ↓\n");
        printf("            %c\n",ch);
        int flag; //flag用来接收返回值
        int sizes, data;
        switch(ch)
        {
            //初始化链表
            case 'a':
                if(f)
                {
                    printf("\n已初始化！\n");
                    break;
                }
                printf("\n请输入栈的长度：");
                while(1)
                {
                    sizes = getint();
                    printf("\n您输入的有效数据为：%d\n", sizes);
                    if(sizes > 0) break;
                    else printf("\n请输入大于0的整数：");
                }

                flag = initStack(&s, sizes);
                f = 1;
                if(flag) printf("\n初始化成功！\n");
                else printf("\n初始化失败！\n");
                break;
            //入栈
            case 'b':
                if(!f)
                {
                    printf("\n请先初始化！\n");
                    break;
                }
                printf("\n请输入入栈的数字：");
                data = getint();
                printf("\n您输入的有效数据为：%d\n", data);
                flag = pushStack(&s, data);
                if(flag) printf("\n入栈成功！\n");
                else
                {
                    if(s.top == s.size) printf("\n栈已满！\n");
                    printf("\n入栈失败！\n");
                }
                break;
            //出栈
            case 'c':
                if(!f)
                {
                    printf("\n请先初始化！\n");
                    break;
                }
                if(isEmptyStack(&s))
                {
                    printf("\n栈为空！请先入栈！\n");
                    break;
                }
                if(flag = popStack(&s, &data))
                {
                    printf("\n出栈成功！\n");
                    printf("\n栈顶元素为：%d\n", data);
                }
                else
                {
                    printf("\n出栈失败！\n");
                }
                break;
            //清空栈
            case 'd':
                if(!f)
                {
                    printf("\n请先初始化！\n");
                    break;
                }
                if(flag = clearStack(&s)) printf("\n清空成功！\n");
                else printf("\n清空失败！\n");
                break;
            //输出栈
            case 'e':
                if(!f)
                {
                    printf("\n请先初始化！\n");
                    break;
                }
                if(isEmptyStack(&s))
                {
                    printf("\n栈为空！请先入栈！\n");
                    break;
                }
                printStack(&s);
                break;
            //检测栈的长度
            case 'f':
                if(!f)
                {
                    printf("\n请先初始化！\n");
                    break;
                }
                printf("\n栈的总长度为：%d\n", s.size);
                if(isEmptyStack(&s))
                {
                    printf("\n当前栈为空！\n");
                }
                else
                {
                    stackLength(&s, &data);
                    printf("\n当前栈的元素个数为：%d\n", data);
                }
                break;
            //获得栈顶元素
            case 'g':
                if(!f)
                {
                    printf("\n请先初始化！\n");
                    break;
                }
                if(isEmptyStack(&s))
                {
                    printf("\n栈为空！请先入栈！\n");
                    break;
                }
                getTopStack(&s, &data);
                printf("\n栈顶元素为：%d\n", data);
                break;
            //销毁栈，结束进程
            case 'h':
                destroyStack(&s);
                return 0;
        }

        putchar('\n');
        system("pause");
        system("cls");
    }
}
void tips()
{
    printf("        *请输入对应编号*        \n");
    printf("|-----a.初始化栈          -----|\n");
    printf("|-----b.入栈              -----|\n");
    printf("|-----c.出栈              -----|\n");
    printf("|-----d.清空栈            -----|\n");
    printf("|-----e.输出栈            -----|\n");
    printf("|-----f.检测栈长度        -----|\n");
    printf("|-----g.获得栈顶元素      -----|\n");
    printf("|-----h.销毁栈，结束程序  -----|\n");
    printf("\n\n你的选择是：");
}
void printStack(SqStack *s)
{
    int i;
    printf("\n当前栈为：\n");
    putchar('\n');
    for(i = 0; i < (*s).top; i ++)
    {
        printf("%d  ", (*s).elem[i]);
    }
    putchar('\n');
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
                    printf("\n重新输入数据：");
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
        if((str[i] >= 'a') && (str[i] <= 'h')) return str[i];
        if((str[i] >= 'A') && (str[i] <= 'H')) return str[i] + 32;
    }
    return 'z';
}
