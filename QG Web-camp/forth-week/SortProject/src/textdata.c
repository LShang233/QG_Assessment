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
    printf("        *�������Ӧ���*        \n");
    printf("|-----a.������������      -----|\n");
    printf("|-----b.����С�������    -----|\n");
    printf("|-----c.�˳�              -----|\n");
    printf("ps:�Զ������ݻ����ڵ�����⣬ʵ��debug��������orz\n");
    printf("pss����������һëһ��orz\n");
    printf("\n\n���ѡ���ǣ�");
}
char getchabc()
{
    //�ҵ����������ĵ�һ���ַ�
    char str[100] = {0};
    int i;
    gets(str);
    //���ݴ�Сд
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
        //ѡ����ԵĲ��
        tipsB();
        ch = getchc();
        printf("            ��\n");
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
                printf("�������\n");
                break;
        }
        system("pause");
        system("cls");
    }

}
void tipsB()
{
    printf("          *�������Ӧ���*        \n");
    printf("|-----a.100 * 100k����      -----|\n");
    printf("|-----b.�Զ������ݲ���      -----|\n");
    printf("|-----c.����                -----|\n");
    printf("ע��aΪ1~100�������            \n");
    printf("\n\n���ѡ���ǣ�");
}
char getchc()
{
    //�ҵ����������ĵ�һ���ַ�
    char str[100] = {0};
    int i;
    gets(str);
    //���ݴ�Сд
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
    printf("\n100������ * 100k�����򻨷�ʱ�䣺\n");
    //��������
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
    printf("��������%ld ms\n", total);

    //�鲢����
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
    printf("�鲢����%ld ms\n", total);

    //���ţ��ݹ�棩
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
    printf("���ţ��ݹ�棩��%ld ms\n", total);

    //�������򣨷ǵݹ�棩
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
    printf("�������򣨷ǵݹ�棩��%ld ms\n", total);

    //�������������ţ�
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
    printf("�������������ţ���%ld ms\n", total);

    //��������
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
    printf("��������%ld ms\n", total);

    //������������
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
    printf("������������%ld ms\n", total);

    return;
}
void smallSelf(int n, int *arr)
{
    if(n < 100)
    {
        printf("����100��������");
        return;
    }
    printf("ÿ100������Ϊһ�飬ʣ���100�����ݲ����ԣ�");
    int nnn = n / 100;

    int i, max = 0, a[100], imax;
    long s, e, l, total;
    char ch;
    printf("\n100������ * %d�����򻨷�ʱ�䣺\n", nnn);

    //��������
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
    printf("��������%ld ms\n", total);

    //�鲢����
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
    printf("�鲢����%ld ms\n", total);

    //���ţ��ݹ�棩
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
    printf("���ţ��ݹ�棩��%ld ms\n", total);

    //�������򣨷ǵݹ�棩
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
    printf("�������򣨷ǵݹ�棩��%ld ms\n", total);

    //�������������ţ�
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
    printf("�������������ţ���%ld ms\n", total);

    //��������
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
    printf("��������%ld ms\n", total);

    //������������
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
    printf("������������%ld ms\n", total);

    return;
}


void tipsA()
{
    printf("          *�������Ӧ���*        \n");
    printf("|-----a.10000�������       -----|\n");
    printf("|-----b.50000�������       -----|\n");
    printf("|-----c.200000�������      -----|\n");
    printf("|-----d.�Զ������ݲ���      -----|\n");
    printf("|-----e.����                -----|\n");
    printf("ע��abcΪ1~100�������            \n");
    printf("\n\n���ѡ���ǣ�");
}
char getchd()
{
    //�ҵ����������ĵ�һ���ַ�
    char str[100] = {0};
    int i;
    gets(str);
    //���ݴ�Сд
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
        //ѡ����ԵĲ��
        tipsA();
        ch = getchd();
        printf("            ��\n");
        printf("            %c\n",ch);
        switch(ch)
        {
            case 'a':
                //1w
                printf("\n10000��������򻨷�ʱ�䣺\n");

                big1(10000);
                big2(10000);
                printf("\n����\n");
                break;

            case 'b':
                //5w
                printf("\n50000��������򻨷�ʱ�䣺\n");

                big1(50000);
                big2(50000);
                printf("\n����\n");
                break;

            case 'c':
                //10w
                printf("\n200000��������򻨷�ʱ�䣺\n");

                big1(200000);
                big2(200000);
                printf("\n����\n");
                break;

            case 'd':
                printf("\n%d��������򻨷�ʱ�䣺\n", n);

                bign1(n, arr);
                bign2(n, arr);
                printf("\n����\n");

            case 'e':
                return;

            default:
                printf("�������\n");
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
    //��������
    for(l = 0; l < large; l ++)
    {
        a[l] = rand() % 101;
    }
    s = clock();
    insertSort(a, large);
    e = clock();
    printf("��������%ld ms\n",e - s);

    //�鲢����
    for(l = 0; l < large; l ++)
    {
        a[l] = rand() % 101;
    }
    temp = (int *)malloc(large * sizeof(int));
    s = clock();
    MergeSort(a, 0, large, temp);
    e = clock();
    printf("�鲢����%ld ms\n",e - s);

    //���ţ��ݹ�棩
    for(l = 0; l < large; l ++)
    {
        a[l] = rand() % 101;
    }
    s = clock();
    QuickSort_Recursion(a, 0, large);
    e = clock();
    printf("���ţ��ݹ�棩��%ld ms\n",e - s);

    //�������򣨷ǵݹ�棩
    for(l = 0; l < large; l ++)
    {
        a[l] = rand() % 101;
    }
    s = clock();
    QuickSort(a, large);
    e = clock();
    printf("�������򣨷ǵݹ�棩��%ld ms\n",e - s);
}
void big2(int large)
{
    int i, max = 0, a[100000], imax;
    int *temp;
    long s, e, l;
    //�������������ţ�
    for(l = 0; l < large; l ++)
    {
        a[l] = rand() % 101;
    }
    s = clock();
    Partition(a, 0, large);
    e = clock();
    printf("�������������ţ���%ld ms\n",e - s);

    //��������
    for(l = 0; l < large; l ++)
    {
        a[l] = rand() % 101;
    }
    s = clock();
    CountSort(a, large, 101);
    e = clock();
    printf("��������%ld ms\n",e - s);

    //������������
    for(l = 0; l < large; l ++)
    {
        a[l] = rand() % 101;
    }
    s = clock();
    RadixCountSort(a, large);
    e = clock();
    printf("������������%ld ms\n",e - s);
}
void bign1(int n, int *arr)
{
    int i;
    int *temp, *a;
    a = (int *)malloc(sizeof(int) * n);
    long s, e, l;
    //��������
    for(l = 0; l < n; l ++)
    {
        a[i] = arr[i];
    }
    s = clock();
    insertSort(a, n);
    e = clock();
    printf("��������%ld ms\n",e - s);

    //�鲢����
    for(l = 0; l < n; l ++)
    {
        a[i] = arr[i];
    }
    temp = (int *)malloc(n * sizeof(int));
    s = clock();
    MergeSort(a, 0, n, temp);
    e = clock();
    printf("�鲢����%ld ms\n",e - s);

    //���ţ��ݹ�棩
    for(l = 0; l < n; l ++)
    {
        a[i] = arr[i];
    }
    s = clock();
    QuickSort_Recursion(a, 0, n);
    e = clock();
    printf("���ţ��ݹ�棩��%ld ms\n",e - s);

    //�������򣨷ǵݹ�棩
    for(l = 0; l < n; l ++)
    {
        a[i] = arr[i];
    }
    s = clock();
    QuickSort(a, n);
    e = clock();
    printf("�������򣨷ǵݹ�棩��%ld ms\n",e - s);
    
    
    //�������������ţ�
    for(l = 0; l < n; l ++)
    {
        a[i] = arr[i];
    }
    s = clock();
    Partition(a, 0, n);
    e = clock();
    printf("�������������ţ���%ld ms\n",e - s);
}
void bign2(int n, int *arr)
{
    int i, max;
    int *a;
    a = (int *)malloc(sizeof(int) * n);
    long s, e, l;

    //��������
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
    printf("��������%ld ms\n",e - s);

    //������������
    for(l = 0; l < n; l ++)
    {
        a[i] = arr[i];
    }
    s = clock();
    RadixCountSort(a, n);
    e = clock();
    printf("������������%ld ms\n",e - s);
}

