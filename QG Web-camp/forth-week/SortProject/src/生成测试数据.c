#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
            if(str[i-1] == '-')
                f = 1;
            for(j = i; j < 50 && (str[j] >= '0' && str[j] <= '9'); j++)
            {

                num = num * 10 + (str[j] - '0');
            }
            break;
        }
    }
    //�ж��Ƿ�Ϊ����
    if(f == 1)
        num *= (-1);
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
                printf("\n�����������ݣ�");
                //��������
                return getint();
            default:
                printf("\n��Ŵ�����������ȷ��ţ�\n");
            }
        }
    }
    //�ж��Ƿ������int��
    if(num > 2147483647 || num <= 0)
    {
        printf("\n�������,���������뷶Χ�ڵ����֣�\n");
        printf("\n�������ݣ�");
        //��������
        return getint();
    }
    else
        return num;
}
void write(int n, int min, int max)
{
    //�ļ�ָ��,���ļ�
    FILE *fp;
    fp = fopen("arrey.txt", "w");
    //������
    int i = 0, *a, t;
    a = (int *)malloc(sizeof(int) * n);
    srand((unsigned) time (NULL)); //�������

    for(i = 0; i < n; i ++)
    {
        a[i] = rand() % (max - min + 1) + min;
    }

    //����������
    fprintf(fp, "%d", n);
    fprintf(fp, "\n");
    //��ʽ��д���ļ�
    for(i = 0; i < n; i ++)
    {
        fprintf(fp, "%d", a[i]);
        fprintf(fp, "\n");
    }
    //�ر��ļ�
    fclose(fp);
}
void tips()
{
    printf("        *�������Ӧ���*        \n");
    printf("         *ѡ����������*         \n");
    printf("|-----a. 10k              -----|\n");
    printf("|-----b. 50k              -----|\n");
    printf("|-----c. 200k             -----|\n");
    printf("|-----d. 100 * 100k       -----|\n");
    printf("|-----e. �Զ���           -----|\n");
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
    //ѡ����������
    while(n == 0)
    {
        tips();
        char ch;
        ch = getchabc();
        printf("            ��\n");
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
                printf("\n����������ݵĳ��ȣ�");
                n = getint();
                break;
            default:
                printf("\n��������ȷ��ţ�\n");
                break;
        }
    }
    printf("\n����������ݵ���Сֵ��");
    min = getint();

    while(1)
    {
        printf("\n����������ݵ����ֵ��");
        max = getint();
        if(min > max)
        {
            printf("\n���ֵӦ������Сֵ��\n");
        }
        else
        {
            break;
        }
    }
    write(n, min, max);

    printf("\n���ɳɹ���\n");
    return 0;
}
