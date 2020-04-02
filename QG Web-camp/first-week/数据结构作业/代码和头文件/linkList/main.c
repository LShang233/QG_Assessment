#include "../head/linkedList.h"
#include "linkedList.c"
#include <stdio.h>
#include <stdlib.h>
void tips();
char getch();
int getint();
LNode* SetLNode(ElemType e);
void printList(LinkedList L);
LNode* FindList(LinkedList L, ElemType e);
int main()
{
    LinkedList L;
    L = NULL;
    while(1)
    {
        char ch;
        int flag, p, e;
        //flag:����ö�ٷ���ֵ
        LNode *q;

        //ch����
        tips();
        ch = getch();
        printf("            ��\n");
        printf("            %c\n",ch);

        switch(ch)
        {
            //a.��ʼ������
            case 'a':
                if(InitList(&L))
                {
                    printf("\n��ʼ���ɹ���\n");
                }
                else printf("\n��ʼ��ʧ�ܣ�\n");
                break;
            //b.����ڵ�
            case 'b':
                if(NULL == L)
                {
                    printf("\n���ȳ�ʼ��\n");
                    break;
                }
                printf("\nb����q�ڵ���뵽p�ڵ��\n");
                //����p�ڵ�
                printf("\n��������q�ڵ�����ݣ�int����");
                q = SetLNode(getint());
                printf("\n���������Ч����Ϊ��%d\n", q->data);
                //�жϲ�����q�ڵ�
                if(NULL == L->next)
                {
                    printf("\n��ǰ����Ϊ�գ�Ĭ�Ͻ�p���뵽ͷ��㡣\n");
                    flag = InsertList(L, q);
                }
                else
                {
                    printList(L);
                    printf("\n��ѡ��q�ڵ�����ݣ�");
                    p = getint();
                    printf("\n���������Ч����Ϊ��%d\n", p);
                    flag = InsertList(FindList(L, p), q);
                }
                //���������
                if(flag)
                {
                    printf("\n����ɹ���\n");
                }
                else
                {
                    if(NULL == FindList(L, p))
                    {
                        printf("\nδ�ҵ�p�ڵ�\n");
                    }
                    else
                        printf("\n����ʧ�ܣ�\n");
                    //�Ƿ������ͷ���
                    int i = 1;
                    char ch[20];
                    while(i)
                    {
                        printf("\n�Ƿ������ͷ�ڵ㣿\n1.��\n2.��\n\n��Ļش�");
                        gets(ch);
                        switch(ch[0])
                        {
                            case '1':
                                flag = InsertList(L, q);
                                if(flag)
                                {
                                    printf("\n�ɹ�����ͷ�ڵ㣡\n");
                                }
                                else
                                {
                                    printf("\n����ʧ�ܣ�\n");
                                }
                                i = 0;
                                break;
                            case '2':
                                i = 0;
                                printf("\n����ʧ�ܣ�\n");
                                break;
                            default:
                                printf("\n��Ŵ�����������ȷ��ţ�\n");
                        }
                    }
                }
                break;
            //c.�������
            case 'c':
                if(NULL == L)
                {
                    printf("\n���ȳ�ʼ��\n");
                    break;
                }
                if(NULL == L->next)
                {
                    printf("\n����Ϊ�գ�������ڵ����ݣ�\n");
                    break;
                }
                printList(L);
                break;
            //d.���������б�
            case 'd':
                if(NULL == L)
                {
                    printf("\n���ȳ�ʼ��\n");
                    break;
                }
                if(NULL == L->next)
                {
                    printf("\n����Ϊ�գ�������ڵ����ݣ�\n");
                    break;
                }
                printList(L);
                flag = ReverseList(&L);
                //������
                if(flag)
                {
                    printf("\n�������Ӻ�Ϊ��\n");
                    TraverseList(L, print);
                    putchar('\n');
                }
                else
                {
                    printf("\n����ʧ�ܣ�\n");
                }
                break;
            //e.������ż˳��
            case 'e':
                if(NULL == L)
                {
                    printf("\n���ȳ�ʼ��\n");
                    break;
                }
                if(NULL == L->next)
                {
                    printf("\n����Ϊ�գ�������ڵ����ݣ�\n");
                    break;
                }
                printf("\ne��������ż˳��\ne.g:input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3\n");
                //�޸�ǰ
                printList(L);
                L = ReverseEvenList(&L);
                //�޸ĺ�
                printf("\n�޸ĺ�����Ϊ��\n");
                TraverseList(L, print);
                putchar('\n');
                break;
            //f.�ҵ��м�ڵ�
            case 'f':
                if(NULL == L)
                {
                    printf("\n���ȳ�ʼ��\n");
                    break;
                }
                if(NULL == L->next)
                {
                    printf("\n����Ϊ�գ�������ڵ����ݣ�\n");
                    break;
                }
                printList(L);
                q = FindMidNode(&L);
                //qΪ�ҵ����м�ڵ�
                if(NULL != q)
                    printf("\n��ǰ������м�ڵ������Ϊ��%d\n", q->data);
                else
                    printf("\n����Ϊ�գ�������ڵ����ݣ�\n");
                break;
            //g.ɾ���ڵ㲢ȡֵ
            case 'g':
                if(NULL == L)
                {
                    printf("\n���ȳ�ʼ��\n");
                    break;
                }
                if(NULL == L->next)
                {
                    printf("\n����Ϊ�գ�������ڵ����ݣ�\n");
                    break;
                }
                printf("\ng��ɾ��p��ĵ�һ���ڵ㣬����ȡ��ֵ��\n");
                printList(L);
                printf("\n��ѡ��p�ڵ����ݣ�\n");
                p = getint();
                //�ҵ�p�ڵ�,���ж�p�ڵ��λ��
                q = FindList(L, p);
                if(NULL == q)
                {
                    printf("\nδ�ҵ�p�ڵ�\n");
                }
                else if(NULL == q->next)
                {
                    printf("\npΪ���һ���ڵ�\n");
                }
                else
                {
                    //������������ڵ�
                    DeleteList(q, &e);
                    printf("\np��һ���ڵ��ֵΪ��%d\n", e);
                }
                break;
            //h.��ѯ�ڵ��Ƿ����
            case 'h':
                if(NULL == L)
                {
                    printf("\n���ȳ�ʼ��\n");
                    break;
                }
                if(NULL == L->next)
                {
                    printf("\n����Ϊ�գ�������ڵ����ݣ�\n");
                    break;
                }
                printf("\n��Ҫ��ѯ�Ľڵ�����Ϊ��");
                p = getint();
                flag = SearchList(L, p);
                //������
                if(flag)
                    printf("\n�ڵ���ڣ�\n");
                else
                    printf("\nδ�ҵ��ýڵ㣡\n");
                break;
            //i.�ж������Ƿ�ɻ�
            case 'i':
                if(NULL == L)
                {
                    printf("\n���ȳ�ʼ��\n");
                    break;
                }
                if(NULL == L->next)
                {
                    printf("\n����Ϊ�գ�������ڵ����ݣ�\n");
                    break;
                }
                //������
                if(IsLoopList(L))
                {
                    printf("\n����ɻ���\n");
                }
                else
                {
                    printf("\n����δ�ɻ���\n");
                }
                break;
            //j.��������,��������
            case 'j':
                DestroyList(&L);
                return 0;

            default:
                printf("\n��������Ч��ţ�\n");
                break;
        }
        putchar('\n');
        system("pause");
        system("cls");
    }
}
void tips()
{
    printf("        *�������Ӧ���*        \n");
    printf("|-----a.��ʼ������        -----|\n");
    printf("|-----b.����ڵ�          -----|\n");
    printf("|-----c.�������          -----|\n");
    printf("|-----d.���������б�      -----|\n");
    printf("|-----e.������ż˳��      -----|\n");
    printf("|-----f.�ҵ��м�ڵ�      -----|\n");
    printf("|-----g.ɾ���ڵ㲢ȡֵ    -----|\n");
    printf("|-----h.��ѯ�ڵ��Ƿ����  -----|\n");
    printf("|-----i.�ж������Ƿ�ɻ�  -----|\n");
    printf("|-----j.��������,�������� -----|\n");
    printf("\n\n���ѡ���ǣ�");
}
LNode* SetLNode(ElemType e)
{
    //�����½ڵ㣬����Ϊe
    LNode *New;
    New = (LNode *)malloc(sizeof(LNode));
    New->data = e;
    return New;
}
void printList(LinkedList L)
{
    //�������
    printf("\n��ǰ����Ϊ��\n");
    TraverseList(L, print);
    putchar('\n');
}
LNode* FindList(LinkedList L, ElemType e)
{
    //��L���ҵ�����Ϊe�Ľڵ㣬���ظýڵ��ַ
    if(NULL == (L = L->next) || NULL == L) return NULL;
    while(L)
    {
        if(L->data == e)
        {
            return L;
        }
        L = L->next;
    }
    return NULL;
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
                    printf("\n����q�ڵ����ݣ�");
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
        if((str[i] >= 'a') && (str[i] <= 'j')) return str[i];
        if((str[i] >= 'A') && (str[i] <= 'J')) return str[i] + 32;
    }
    return 'z';
}
