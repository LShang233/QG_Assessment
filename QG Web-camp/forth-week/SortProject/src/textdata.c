#include <time.h>
#include"sort.c"
void tipsA();
void tipsB();
void tips();
char getchc();
char getchd();
char getchabc();
void smallRadon();
void smallData(int n, int *arr);
void bigData(int n, int *arr);
void big1(int large);
void big2(int large);
void bign1(int n, int *arr);
void bign2(int n, int *arr);
void smallSelf(int n, int *arr);




void tips()
{
    printf("        *请输入对应编号*        \n");
    printf("|-----a.大数据量测试      -----|\n");
    printf("|-----b.大量小数组测试    -----|\n");
    printf("|-----c.退出              -----|\n");
    printf("ps:自定义数据还有亿点点问题，实在debug不出来了orz\n");
    printf("pss：明明代码一毛一样orz\n");
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
        if((str[i] >= 'a') && (str[i] <= 'c'))
            return str[i];
        if((str[i] >= 'A') && (str[i] <= 'C'))
            return str[i] + 32;
    }
    return 'z';
}
void smallData(int n, int *arr)
{
    char ch;
    while(1)
    {
        //选择测试的层次
        tipsB();
        ch = getchc();
        printf("            ↓\n");
        printf("            %c\n",ch);
        switch(ch)
        {
            case 'a':
                smallRadon();
                break;

            case 'b':
                smallSelf(n, arr);
                break;

            case 'c':
                return;

            default:
                printf("输入错误\n");
                break;
        }
        system("pause");
        system("cls");
    }

}
void tipsB()
{
    printf("          *请输入对应编号*        \n");
    printf("|-----a.100 * 100k测试      -----|\n");
    printf("|-----b.自定义数据测试      -----|\n");
    printf("|-----c.返回                -----|\n");
    printf("注：a为1~100的随机数            \n");
    printf("\n\n你的选择是：");
}
char getchc()
{
    //找到符合条件的第一个字符
    char str[100] = {0};
    int i;
    gets(str);
    //兼容大小写
    for(i = 0; i < 100; i++)
    {
        if((str[i] >= 'a') && (str[i] <= 'c'))
            return str[i];
        if((str[i] >= 'A') && (str[i] <= 'C'))
            return str[i] + 32;
    }
    return 'z';
}
void smallRadon()
{
    int i, max = 0, a[100], imax;
    long s, e, l, total;
    char ch;
    printf("\n100个数据 * 100k次排序花费时间：\n");
    //插入排序
    total = 0;
    for(i = 0; i < 100000; i ++)
    {
        for(l = 0; l < 100; l ++)
        {
            a[l] = rand() % 101;
        }
        s = clock();
        insertSort(a, 100);
        e = clock();
        total += (e - s);
    }
    printf("插入排序：%ld ms\n", total);

    //归并排序
    total = 0;
    for(i = 0; i < 100000; i ++)
    {
        for(l = 0; l < 100; l ++)
        {
            a[l] = rand() % 101;
        }
        s = clock();
        int *temp;
        temp = (int *)malloc(100 * sizeof(int));
        MergeSort(a, 0, 100, temp);
        e = clock();
        total += (e - s);
    }
    printf("归并排序：%ld ms\n", total);

    //快排（递归版）
    total = 0;
    for(i = 0; i < 100000; i ++)
    {
        for(l = 0; l < 100; l ++)
        {
            a[l] = rand() % 101;
        }
        s = clock();
        QuickSort_Recursion(a, 0, 100);
        e = clock();
        total += (e - s);
    }
    printf("快排（递归版）：%ld ms\n", total);

    //快速排序（非递归版）
    total = 0;
    for(i = 0; i < 100000; i ++)
    {
        for(l = 0; l < 100; l ++)
        {
            a[l] = rand() % 101;
        }
        s = clock();
        QuickSort(a, 100);
        e = clock();
        total += (e - s);
    }
    printf("快速排序（非递归版）：%ld ms\n", total);

    //快速排序（枢轴存放）
    total = 0;
    for(i = 0; i < 100000; i ++)
    {
        for(l = 0; l < 100; l ++)
        {
            a[l] = rand() % 101;
        }
        s = clock();
        QuickSort(a, 100);
        e = clock();
        total += (e - s);
    }
    printf("快速排序（枢轴存放）：%ld ms\n", total);

    //计数排序
    total = 0;
    for(i = 0; i < 100000; i ++)
    {
        for(l = 0; l < 100; l ++)
        {
            a[l] = rand() % 101;
        }
        s = clock();
        CountSort(a, 100, 101);
        e = clock();
        total += (e - s);
    }
    printf("计数排序：%ld ms\n", total);

    //基数计数排序
    total = 0;
    for(i = 0; i < 100000; i ++)
    {
        for(l = 0; l < 100; l ++)
        {
            a[l] = rand() % 101;
        }
        s = clock();
        RadixCountSort(a, 100);
        e = clock();
        total += (e - s);
    }
    printf("基数计数排序：%ld ms\n", total);

    return;
}
void smallSelf(int n, int *arr)
{
    if(n < 100)
    {
        printf("少于100个不排序！");
        return;
    }
    printf("每100个数据为一组，剩余的100个数据不测试！");
    int nnn = n / 100;

    int i, max = 0, a[100], imax;
    long s, e, l, total;
    char ch;
    printf("\n100个数据 * %d次排序花费时间：\n", nnn);

    //插入排序
    total = 0;
    for(i = 0; i < nnn; i ++)
    {
        for(l = 0; l < 100; l ++)
        {
            a[l] = arr[nnn * 100 + l];
        }
        s = clock();
        insertSort(a, 100);
        e = clock();
        total += (e - s);
    }
    printf("插入排序：%ld ms\n", total);

    //归并排序
    total = 0;
    for(i = 0; i < nnn; i ++)
    {
        for(l = 0; l < 100; l ++)
        {
            a[l] = arr[nnn * 100 + l];
        }
        s = clock();
        int *temp;
        temp = (int *)malloc(100 * sizeof(int));
        MergeSort(a, 0, 100, temp);
        e = clock();
        total += (e - s);
    }
    printf("归并排序：%ld ms\n", total);

    //快排（递归版）
    total = 0;
    for(i = 0; i < nnn; i ++)
    {
        for(l = 0; l < 100; l ++)
        {
            a[l] = arr[nnn * 100 + l];
        }
        s = clock();
        QuickSort_Recursion(a, 0, 100);
        e = clock();
        total += (e - s);
    }
    printf("快排（递归版）：%ld ms\n", total);

    //快速排序（非递归版）
    total = 0;
    for(i = 0; i < nnn; i ++)
    {
        for(l = 0; l < 100; l ++)
        {
            a[l] = arr[nnn * 100 + l];
        }
        s = clock();
        QuickSort(a, 100);
        e = clock();
        total += (e - s);
    }
    printf("快速排序（非递归版）：%ld ms\n", total);

    //快速排序（枢轴存放）
    total = 0;
    for(i = 0; i < nnn; i ++)
    {
        for(l = 0; l < 100; l ++)
        {
            a[l] = arr[nnn * 100 + l];
        }
        s = clock();
        QuickSort(a, 100);
        e = clock();
        total += (e - s);
    }
    printf("快速排序（枢轴存放）：%ld ms\n", total);

    //计数排序
    total = 0;
    for(i = 0; i < nnn; i ++)
    {
        for(l = 0; l < 100; l ++)
        {
            a[l] = arr[nnn * 100 + l];
            if(arr[nnn * 100 + l] > max)
            {
                max = arr[nnn * 100 + l];
            }
        }
        s = clock();
        CountSort(a, 100, max);
        e = clock();
        total += (e - s);
    }
    printf("计数排序：%ld ms\n", total);

    //基数计数排序
    total = 0;
    for(i = 0; i < nnn; i ++)
    {
        for(l = 0; l < 100; l ++)
        {
            a[l] = arr[nnn * 100 + l];
        }
        s = clock();
        RadixCountSort(a, 100);
        e = clock();
        total += (e - s);
    }
    printf("基数计数排序：%ld ms\n", total);

    return;
}


void tipsA()
{
    printf("          *请输入对应编号*        \n");
    printf("|-----a.10000级别测试       -----|\n");
    printf("|-----b.50000级别测试       -----|\n");
    printf("|-----c.200000级别测试      -----|\n");
    printf("|-----d.自定义数据测试      -----|\n");
    printf("|-----e.返回                -----|\n");
    printf("注：abc为1~100的随机数            \n");
    printf("\n\n你的选择是：");
}
char getchd()
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
void bigData(int n, int *arr)
{
    int i, max = 0, a[200000], imax;
    int *temp;
    long s, e, l;
    char ch;
    while(1)
    {
        //选择测试的层次
        tipsA();
        ch = getchd();
        printf("            ↓\n");
        printf("            %c\n",ch);
        switch(ch)
        {
            case 'a':
                //1w
                printf("\n10000级别各排序花费时间：\n");

                big1(10000);
                big2(10000);
                printf("\n结束\n");
                break;

            case 'b':
                //5w
                printf("\n50000级别各排序花费时间：\n");

                big1(50000);
                big2(50000);
                printf("\n结束\n");
                break;

            case 'c':
                //10w
                printf("\n200000级别各排序花费时间：\n");

                big1(200000);
                big2(200000);
                printf("\n结束\n");
                break;

            case 'd':
                printf("\n%d级别各排序花费时间：\n", n);

                bign1(n, arr);
                bign2(n, arr);
                printf("\n结束\n");

            case 'e':
                return;

            default:
                printf("输入错误\n");
                break;
        }
        system("pause");
        system("cls");
    }
}
void big1(int large)
{
    int i, max = 0, a[100000], imax;
    int *temp;
    long s, e, l;
    //插入排序
    for(l = 0; l < large; l ++)
    {
        a[l] = rand() % 101;
    }
    s = clock();
    insertSort(a, large);
    e = clock();
    printf("插入排序：%ld ms\n",e - s);

    //归并排序
    for(l = 0; l < large; l ++)
    {
        a[l] = rand() % 101;
    }
    temp = (int *)malloc(large * sizeof(int));
    s = clock();
    MergeSort(a, 0, large, temp);
    e = clock();
    printf("归并排序：%ld ms\n",e - s);

    //快排（递归版）
    for(l = 0; l < large; l ++)
    {
        a[l] = rand() % 101;
    }
    s = clock();
    QuickSort_Recursion(a, 0, large);
    e = clock();
    printf("快排（递归版）：%ld ms\n",e - s);

    //快速排序（非递归版）
    for(l = 0; l < large; l ++)
    {
        a[l] = rand() % 101;
    }
    s = clock();
    QuickSort(a, large);
    e = clock();
    printf("快速排序（非递归版）：%ld ms\n",e - s);
}
void big2(int large)
{
    int i, max = 0, a[100000], imax;
    int *temp;
    long s, e, l;
    //快速排序（枢轴存放）
    for(l = 0; l < large; l ++)
    {
        a[l] = rand() % 101;
    }
    s = clock();
    Partition(a, 0, large);
    e = clock();
    printf("快速排序（枢轴存放）：%ld ms\n",e - s);

    //计数排序
    for(l = 0; l < large; l ++)
    {
        a[l] = rand() % 101;
    }
    s = clock();
    CountSort(a, large, 101);
    e = clock();
    printf("计数排序：%ld ms\n",e - s);

    //基数计数排序
    for(l = 0; l < large; l ++)
    {
        a[l] = rand() % 101;
    }
    s = clock();
    RadixCountSort(a, large);
    e = clock();
    printf("基数计数排序：%ld ms\n",e - s);
}
void bign1(int n, int *arr)
{
    int i;
    int *temp, *a;
    a = (int *)malloc(sizeof(int) * n);
    long s, e, l;
    //插入排序
    for(l = 0; l < n; l ++)
    {
        a[i] = arr[i];
    }
    s = clock();
    insertSort(a, n);
    e = clock();
    printf("插入排序：%ld ms\n",e - s);

    //归并排序
    for(l = 0; l < n; l ++)
    {
        a[i] = arr[i];
    }
    temp = (int *)malloc(n * sizeof(int));
    s = clock();
    MergeSort(a, 0, n, temp);
    e = clock();
    printf("归并排序：%ld ms\n",e - s);

    //快排（递归版）
    for(l = 0; l < n; l ++)
    {
        a[i] = arr[i];
    }
    s = clock();
    QuickSort_Recursion(a, 0, n);
    e = clock();
    printf("快排（递归版）：%ld ms\n",e - s);

    //快速排序（非递归版）
    for(l = 0; l < n; l ++)
    {
        a[i] = arr[i];
    }
    s = clock();
    QuickSort(a, n);
    e = clock();
    printf("快速排序（非递归版）：%ld ms\n",e - s);
    
    
    //快速排序（枢轴存放）
    for(l = 0; l < n; l ++)
    {
        a[i] = arr[i];
    }
    s = clock();
    Partition(a, 0, n);
    e = clock();
    printf("快速排序（枢轴存放）：%ld ms\n",e - s);
}
void bign2(int n, int *arr)
{
    int i, max;
    int *a;
    a = (int *)malloc(sizeof(int) * n);
    long s, e, l;

    //计数排序
    max = arr[0];
    for(l = 0; l < n; l ++)
    {
        a[i] = arr[i];
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    s = clock();
    CountSort(a, n, max);
    e = clock();
    printf("计数排序：%ld ms\n",e - s);

    //基数计数排序
    for(l = 0; l < n; l ++)
    {
        a[i] = arr[i];
    }
    s = clock();
    RadixCountSort(a, n);
    e = clock();
    printf("基数计数排序：%ld ms\n",e - s);
}

