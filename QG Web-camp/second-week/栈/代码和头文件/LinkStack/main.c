#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.c"
void tips();
int getint();
char getch();
void printLStack(LinkStack *s);
int main()
{
    int f = 0;//f�����ж��Ƿ��ʼ��
    LinkStack *s;
    char ch;
    while(1) {
        tips();
        ch = getch();
        printf("            ��\n");
        printf("            %c\n",ch);
        int flag; //flag�������շ���ֵ
        int data;
        switch(ch)
        {
            //��ʼ������
            case 'a':
                if(f)
                {
                    printf("\n�ѳ�ʼ����\n");
                    break;
                }
                s = (LinkStack *)malloc(sizeof(LinkStack));
                flag = initLStack(s);
                f = 1;
                if(flag) printf("\n��ʼ���ɹ���\n");
                else printf("\n��ʼ��ʧ�ܣ�\n");
                break;
            //��ջ
            case 'b':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                printf("\n��������ջ�����֣�");
                data = getint();
                printf("\n���������Ч����Ϊ��%d\n", data);
                flag = pushLStack(s, data);
                if(flag) printf("\n��ջ�ɹ���\n");
                else printf("\n��ջʧ�ܣ�\n");
                break;
            //��ջ
            case 'c':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                if(isEmptyLStack(s))
                {
                    printf("\nջΪ�գ�������ջ��\n");
                    break;
                }
                if(flag = popLStack(s, &data))
                {
                    printf("\n��ջ�ɹ���\n");
                    printf("\nջ��Ԫ��Ϊ��%d\n", data);
                }
                else
                {
                    printf("\n��ջʧ�ܣ�\n");
                }
                break;
            //���ջ
            case 'd':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                if(flag = clearLStack(s)) printf("\n��ճɹ���\n");
                else printf("\n���ʧ�ܣ�\n");
                break;
            //���ջ
            case 'e':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                if(isEmptyLStack(s))
                {
                    printf("\nջΪ�գ�������ջ��\n");
                    break;
                }
                printLStack(s);
                break;
            //���ջ�ĳ���
            case 'f':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                if(isEmptyLStack(s))
                {
                    printf("\n��ǰջΪ�գ�\n");
                }
                else
                {
                    LStackLength(s, &data);
                    printf("\n��ǰջ��Ԫ�ظ���Ϊ��%d\n", (*s).count);
                }
                break;
            //���ջ��Ԫ��
            case 'g':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                if(isEmptyLStack(s))
                {
                    printf("\nջΪ�գ�������ջ��\n");
                    break;
                }
                getTopLStack(s, &data);
                printf("\nջ��Ԫ��Ϊ��%d\n", data);
                break;
            //����ջ����������
            case 'h':
                return 0;
        }

        putchar('\n');
        system("pause");
        system("cls");
    }
    return 0;
}
void tips()
{
    printf("        *�������Ӧ���*        \n");
    printf("|-----a.��ʼ��ջ          -----|\n");
    printf("|-----b.��ջ              -----|\n");
    printf("|-----c.��ջ              -----|\n");
    printf("|-----d.���ջ            -----|\n");
    printf("|-----e.���ջ            -----|\n");
    printf("|-----f.���ջ����        -----|\n");
    printf("|-----g.���ջ��Ԫ��      -----|\n");
    printf("|-----h.����ջ����������  -----|\n");
    printf("\n\n���ѡ���ǣ�");
}
void printLStack(LinkStack *s)
{
    int i;
    LinkStackPtr p;
    p = (*s).top;
    printf("\n��ǰջΪ��\n");
    putchar('\n');
    while(p)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
    putchar('\n');
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
                    printf("\n�����������ݣ�");
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
char getch()
{
    //�ҵ����������ĵ�һ���ַ�
    char str[100] = {0};
    int i;
    gets(str);
    //���ݴ�Сд
    for(i = 0; i < 100; i++){
        if((str[i] >= 'a') && (str[i] <= 'h')) return str[i];
        if((str[i] >= 'A') && (str[i] <= 'H')) return str[i] + 32;
    }
    return 'z';
}
