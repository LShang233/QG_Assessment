#include <stdio.h>
#include <stdlib.h>
#include "SqStack.c"
int getint();
char getch();
void tips();
void printStack(SqStack *s);
int main()
{
    int f = 0;//f�����ж��Ƿ��ʼ��
    SqStack s;
    char ch;
    while(1) {
        tips();
        ch = getch();
        printf("            ��\n");
        printf("            %c\n",ch);
        int flag; //flag�������շ���ֵ
        int sizes, data;
        switch(ch)
        {
            //��ʼ������
            case 'a':
                if(f)
                {
                    printf("\n�ѳ�ʼ����\n");
                    break;
                }
                printf("\n������ջ�ĳ��ȣ�");
                while(1)
                {
                    sizes = getint();
                    printf("\n���������Ч����Ϊ��%d\n", sizes);
                    if(sizes > 0) break;
                    else printf("\n���������0��������");
                }

                flag = initStack(&s, sizes);
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
                flag = pushStack(&s, data);
                if(flag) printf("\n��ջ�ɹ���\n");
                else
                {
                    if(s.top == s.size) printf("\nջ������\n");
                    printf("\n��ջʧ�ܣ�\n");
                }
                break;
            //��ջ
            case 'c':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                if(isEmptyStack(&s))
                {
                    printf("\nջΪ�գ�������ջ��\n");
                    break;
                }
                if(flag = popStack(&s, &data))
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
                if(flag = clearStack(&s)) printf("\n��ճɹ���\n");
                else printf("\n���ʧ�ܣ�\n");
                break;
            //���ջ
            case 'e':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                if(isEmptyStack(&s))
                {
                    printf("\nջΪ�գ�������ջ��\n");
                    break;
                }
                printStack(&s);
                break;
            //���ջ�ĳ���
            case 'f':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                printf("\nջ���ܳ���Ϊ��%d\n", s.size);
                if(isEmptyStack(&s))
                {
                    printf("\n��ǰջΪ�գ�\n");
                }
                else
                {
                    stackLength(&s, &data);
                    printf("\n��ǰջ��Ԫ�ظ���Ϊ��%d\n", data);
                }
                break;
            //���ջ��Ԫ��
            case 'g':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                if(isEmptyStack(&s))
                {
                    printf("\nջΪ�գ�������ջ��\n");
                    break;
                }
                getTopStack(&s, &data);
                printf("\nջ��Ԫ��Ϊ��%d\n", data);
                break;
            //����ջ����������
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
void printStack(SqStack *s)
{
    int i;
    printf("\n��ǰջΪ��\n");
    putchar('\n');
    for(i = 0; i < (*s).top; i ++)
    {
        printf("%d  ", (*s).elem[i]);
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
