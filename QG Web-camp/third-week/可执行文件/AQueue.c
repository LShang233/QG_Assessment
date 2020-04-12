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
    //f�ж��Ƿ��ʼ��
    //flag:����ö�ٷ���ֵ
    while(1)
    {
        //ch����
        tips();
        ch = getch();
        printf("            ��\n");
        printf("            %c\n",ch);

        switch(ch)
        {
            //a.��ʼ������
            case 'a':
                if(f)
                {
                    printf("\n�ѳ�ʼ����\n");
                    break;
                }
                Q = (AQueue*)malloc(sizeof(AQueue));
                InitAQueue(Q);
                printf("\n��ʼ���ɹ���\n");
                f = 1;
                break;
            //b.���
            case 'b':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                char chtype;
                //���
                flag = 1;
                int intdata;
                double doubledata;
                char chardata[100];
                while(flag)
                {
                    //������ȷ��datatype
                    datatips();
                    datatype[Q->rear] = getchtype();
                    printf("            ��\n");
                    printf("            %c\n", datatype[Q->rear]);
                    switch(datatype[Q->rear])
                    {
                        case 'i':
                            printf("\n������ӵ����ݣ�");
                            intdata = getint();
                            printf("\n���������Ч�����ǣ�%d\n", intdata);
                            *(int *)e = intdata;
                            EnAQueue(Q, e);
                            flag = 0;
                            break;
                        case 'd':
                            printf("\n������ӵ����ݣ�");
                            doubledata = getdouble();
                            printf("\n���������Ч�����ǣ�%lf\n", doubledata);
                            *(double *)e = doubledata;
                            EnAQueue(Q, e);
                            flag = 0;
                            break;
                        case 'c':
                        case 's':
                            printf("\n������ӵ����ݣ�");
                            for(i = 0; i < 50; i++) chardata[i] = '\0';
                            gets(chardata);
                            if(datatype[Q->rear] == 'c')
                            {
                                printf("\n���������Ч�����ǣ�%c\n", chardata[0]);
                                *(char *)e = chardata[0];
                            }
                            else
                            {
                                strcpy((char *)e, chardata);
                                printf("\n���������Ч�����ǣ�%s\n", (char *)e);
                            }
                            EnAQueue(Q, e);
                            flag = 0;
                            break;
                        default:
                            printf("\n��Ŵ���!\n���������룡\n\n");
                    }
                }
                printf("\n��ӳɹ���\n");
                break;
            //c.����
            case 'c':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                if(IsEmptyAQueue(Q))
                {
                    printf("\n����Ϊ�գ�����ӣ�\n");
                    break;
                }
                DeAQueue(Q);
                //������
                printf("\n�ѳ��ӣ�\n");
                break;
            //d.��ն���
            case 'd':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                if(IsEmptyAQueue(Q))
                {
                    printf("\n����Ϊ�գ�����ӣ�\n");
                    break;
                }
                ClearAQueue(Q);
                //������
                printf("\n����գ�\n");
                break;
            //e.�������
            case 'e':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                if(IsEmptyAQueue(Q))
                {
                    printf("\n����Ϊ�գ�����ӣ�\n");
                    break;
                }
                printf("\n��ǰ����Ϊ��\n");
                TraverseAQueue(Q, APrint);
                putchar('\n');
                break;
            //f.ȷ�����г���
            case 'f':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                printf("\n���г���Ϊ��%d\n", LengthAQueue(Q));
                break;
            //g.�鿴��ͷԪ��
            case 'g':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                if(IsEmptyAQueue(Q))
                {
                    printf("\n����Ϊ�գ�����ӣ�\n");
                    break;
                }
                printf("\n��ͷԪ��:");
                GetHeadAQueue(Q, e);
                break;
            //h.�������Ƿ�����
            case 'h':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                //������
                if(IsFullAQueue(Q))
                {
                    printf("\n����������\n");
                }
                else
                {
                    printf("\n����δ����\n");
                    printf("\n��ǰ����Ϊ��%d\n", Q->length);
                }
                break;
            //i.�������Ƿ�Ϊ��
            case 'i':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                //������
                if(IsEmptyAQueue(Q))
                {
                    printf("\n����Ϊ�գ�\n");
                }
                else
                {
                    printf("\n���в�Ϊ�գ�\n");
                    printf("\n��ǰ����Ϊ��%d\n", Q->length);
                }
                break;
            //j.���ٶ���,��������
            case 'j':
                if(f)
                    DestoryAQueue(Q);
                return 0;
            default:
                printf("\n��������Ч��ţ�\n");
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
            if(str[i-1] == '-') f = 1;
            for(j = i; j < 50 && (str[j] >= '0' && str[j] <= '9'); j++)
            {

                num = num * 10 + (str[j] - '0');
            }
            break;
        }
    }
    //�ж��Ƿ�Ϊ����
    if(f == 1) num *= (-1);
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
                    printf("\n�������ݣ�");
                    //��������
                    return getint();
                default:
                    printf("\n��Ŵ�����������ȷ��ţ�\n");
            }
        }
    }
    //�ж��Ƿ������int��
    if(num > 2147483647 || num < -2147483648)
    {
        printf("\n�������,����������intֵ��Χ�ڵ����֣�\n");
        printf("\n����q�ڵ����ݣ�");
        //��������
        return getint();
    }
    else
        return num;
}
double getdouble()
{
    //�������������
    double num = 0;
    int i, j, f = 0;
    char str[50], ch[10];
    for(i = 0; i < 50; i++)
    {
        str[i] = '\0';
    }
    gets(str);
    //ȡ���ַ����ڳ��ֵĵ�һ������
    for(i = 0; i < 50; i++)
    {
        //�ҵ���һ������
        if(str[i] >= '0' && str[i] <= '9')
        {
            if(str[i-1] == '-') f = 1;
            //˳���ҵ�һ������
            for(j = i; j < 50 && (str[j] >= '0' && str[j] <= '9'); j++)
            {

                num = num * 10 + (str[j] - '0');
            }
            break;
        }
    }
    //��ʱjָ���ַ������ֺ���ַ�
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
    //�ж��Ƿ�Ϊ����
    if(f == 1) num *= (-1);
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
                    printf("\n�������ݣ�");
                    //��������
                    return getdouble();
                default:
                    printf("\n��Ŵ�����������ȷ��ţ�\n");
            }
        }
    }
    return num;
}
void tips()
{
    printf("        *�������Ӧ���*        \n");
    printf("|-----a.��ʼ������        -----|\n");
    printf("|-----b.���              -----|\n");
    printf("|-----c.����              -----|\n");
    printf("|-----d.��ն���          -----|\n");
    printf("|-----e.�������          -----|\n");
    printf("|-----f.ȷ�����г���      -----|\n");
    printf("|-----g.�鿴��ͷԪ��      -----|\n");
    printf("|-----h.�������Ƿ�����  -----|\n");
    printf("|-----i.�������Ƿ�Ϊ��  -----|\n");
    printf("|-----j.���ٶ���,�������� -----|\n");
    printf("\n\n���ѡ���ǣ�");
}
void datatips()
{
    printf("        *�������Ӧ���*        \n");
    printf("|-----i.����              -----|\n");
    printf("|-----d.������            -----|\n");
    printf("|-----c.�ַ���            -----|\n");
    printf("|-----s.�ַ���            -----|\n");
    printf("\n\n���ѡ���ǣ�");
}
char getchtype()
{
    //�ҵ����������ĵ�һ���ַ�
    char str[100] = {0};
    int i;
    gets(str);
    //���ݴ�Сд
    for(i = 0; i < 100; i++){
        if(str[i] == 'i' || str[i] == 'd' || str[i] == 'c' || str[i] == 's') return str[i];
        if(str[i] == 'I' || str[i] == 'D' || str[i] == 'C' || str[i] == 'S') return str[i] + 32;
    }
    return 'z';
}
char getch()
{
    //�ҵ����������ĵ�һ���ַ�
    char str[100] = {0};
    int i;
    gets(str);
    //���ݴ�Сд
    for(i = 0; i < 100; i++){
        if((str[i] >= 'a') && (str[i] <= 'j')) return str[i];
        if((str[i] >= 'A') && (str[i] <= 'J')) return str[i] + 32;
    }
    return 'z';
}
