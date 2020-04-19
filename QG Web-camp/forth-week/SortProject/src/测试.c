#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"textdata.c"

int main()
{
    FILE *fp;
    //文件打开错误
    if((fp = fopen("arrey.txt", "r")) == NULL)
    {
        printf("error open!");
        system("PAUSE");
        exit(0);
    }

    //拿出量级
    int n;
    fscanf(fp, "%d", &n);
    fscanf(fp, "\n");
    int i, *arr;
    arr = (int *)malloc(sizeof(int) * n);
    //读取到数组
    for(i = 0; i < n; i ++)
    {
        fscanf(fp, "%d", &arr[i]);
        fscanf(fp, "\n");
    }
    //关闭文件
    fclose(fp);


    char ch;
    while(1)
    {
        //选择数据量级
        tips();
        ch = getchabc();
        printf("            ↓\n");
        printf("            %c\n",ch);
        switch(ch)
        {
        case 'a':
            bigData(n, arr);
            break;
        case 'b':
            smallData(n, arr);
            break;
        case 'c':
            return 0;
        default:
            printf("\n请输入正确编号！\n");
            break;
        }

        putchar('\n');
        system("pause");
        system("cls");
    }
    return 0;
}

