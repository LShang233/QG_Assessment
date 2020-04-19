#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
            if(str[i-1] == '-')
                f = 1;
            for(j = i; j < 50 && (str[j] >= '0' && str[j] <= '9'); j++)
            {

                num = num * 10 + (str[j] - '0');
            }
            break;
        }
    }
    //判断是否为负数
    if(f == 1)
        num *= (-1);
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
    if(num > 2147483647 || num <= 0)
    {
        printf("\n数据溢出,请重新输入范围内的数字！\n");
        printf("\n输入数据：");
        //重新输入
        return getint();
    }
    else
        return num;
}
void write(int n, int min, int max)
{
    //文件指针,打开文件
    FILE *fp;
    fp = fopen("arrey.txt", "w");
    //建数组
    int i = 0, *a, t;
    a = (int *)malloc(sizeof(int) * n);
    srand((unsigned) time (NULL)); //随机种子

    for(i = 0; i < n; i ++)
    {
        a[i] = rand() % (max - min + 1) + min;
    }

    //将量级输入
    fprintf(fp, "%d", n);
    fprintf(fp, "\n");
    //格式化写入文件
    for(i = 0; i < n; i ++)
    {
        fprintf(fp, "%d", a[i]);
        fprintf(fp, "\n");
    }
    //关闭文件
    fclose(fp);
}
void tips()
{
    printf("        *请输入对应编号*        \n");
    printf("         *选择数据量级*         \n");
    printf("|-----a. 10k              -----|\n");
    printf("|-----b. 50k              -----|\n");
    printf("|-----c. 200k             -----|\n");
    printf("|-----d. 100 * 100k       -----|\n");
    printf("|-----e. 自定义           -----|\n");
    printf("\n\n你的选择是：");
}
char getchabc()
{
    //找到符合条件的第一个字符
    char str[100] = {0};
    int i;
    gets(str);
    //兼容大小写
    for(i = 0; i < 100; i++)
    {
        if((str[i] >= 'a') && (str[i] <= 'e'))
            return str[i];
        if((str[i] >= 'A') && (str[i] <= 'E'))
            return str[i] + 32;
    }
    return 'z';
}

int main()
{
    int n = 0, max = 2147483647, min = 0;
    //选择数据量级
    while(n == 0)
    {
        tips();
        char ch;
        ch = getchabc();
        printf("            ↓\n");
        printf("            %c\n",ch);
        switch(ch)
        {
            case 'a':
                n = 10000;
                break;
            case 'b':
                n = 50000;
                break;
            case 'c':
                n = 100000;
                break;
            case 'd':
                n = 10000000;
                break;
            case 'e':
                printf("\n请输入该数据的长度：");
                n = getint();
                break;
            default:
                printf("\n请输入正确编号！\n");
                break;
        }
    }
    printf("\n请输入该数据的最小值：");
    min = getint();

    while(1)
    {
        printf("\n请输入该数据的最大值：");
        max = getint();
        if(min > max)
        {
            printf("\n最大值应大于最小值！\n");
        }
        else
        {
            break;
        }
    }
    write(n, min, max);

    printf("\n生成成功！\n");
    return 0;
}
