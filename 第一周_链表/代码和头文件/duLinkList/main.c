#include "../head/duLinkedList.h"
#include "duLinkedList.c"
#include <stdio.h>
#include <stdlib.h>
void tips();
char getch();
int getint();
DuLNode* SetDuLNode(ElemType e);
void printList(DuLinkedList L);
DuLNode* FindList(DuLinkedList L, ElemType e);
int main ()
{
    DuLinkedList L;
    L = NULL;
    while(1)
    {
        char ch;
        int flag, p, e;
        //flag:����ö�ٷ���ֵ
        DuLNode *q;

        //ch����
        tips();
        ch = getch();
        printf("            ��\n");
        printf("            %c\n",ch);

        switch(ch)
        {
            //a.��ʼ������
            case 'a':
                if(InitList_DuL(&L))
                {
                    printf("\n��ʼ���ɹ���\n");
                }
                else
                {
                    printf("\n��ʼ��ʧ�ܣ�\n");
                }
                break;

            //b.�������
            case 'b':
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

            //c.ɾ���ڵ�
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
                printf("\ng��ɾ��p��ĵ�һ���ڵ㣬����ȡ��ֵ��\n");
                printList(L);
                printf("\n��ѡ��p�ڵ����ݣ�");
                p = getint();
                printf("%d",p);
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
                    DeleteList_DuL(q, &e);
                    printf("\np��һ���ڵ��ֵΪ��%d\n", e);
                }
                break;

            //d.p֮�����ڵ�
            case 'd':
                if(NULL == L)
                {
                    printf("\n���ȳ�ʼ��\n");
                    break;
                }
                printf("\nd���ڽڵ�p֮�����ڵ�q\n");
                //����p�ڵ�
                printf("\n��������q�ڵ�����ݣ�int����");
                q = SetDuLNode(getint());
                printf("\n���������Ч����Ϊ��%d\n", q->data);
                //�жϲ�����q�ڵ�
                if(NULL == L->next)
                {
                    printf("\n��ǰ����Ϊ�գ�Ĭ�Ͻ�q���뵽ͷ��㡣\n");
                    flag = InsertAfterList_DuL(L, q);
                }
                else
                {
                    printList(L);
                    printf("\n��ѡ��p�ڵ�����ݣ�");
                    p = getint();
                    printf("\n���������Ч����Ϊ��%d\n", p);
                    flag = InsertAfterList_DuL(FindList(L, p), q);
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
                                flag = InsertBeforeList_DuL(L->next, q);
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

            //e.p֮ǰ����ڵ�
            case 'e':
                if(NULL == L)
                {
                    printf("\n���ȳ�ʼ��\n");
                    break;
                }
                printf("\ne���ڽڵ�p֮ǰ����ڵ�q\n");
                //����p�ڵ�
                printf("\n��������q�ڵ�����ݣ�int����");
                q = SetDuLNode(getint());
                printf("\n���������Ч����Ϊ��%d\n", q->data);
                //�жϲ�����q�ڵ�
                if(NULL == L->next)
                {
                    printf("\n��ǰ����Ϊ�գ�Ĭ�Ͻ�q���뵽ͷ��㡣\n");
                    flag = InsertAfterList_DuL(L, q);
                }
                else
                {
                    printList(L);
                    printf("\n��ѡ��p�ڵ�����ݣ�");
                    p = getint();
                    printf("\n���������Ч����Ϊ��%d\n", p);
                    flag = InsertBeforeList_DuL(FindList(L, p), q);
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
                                flag = InsertAfterList_DuL(L, q);
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

            //f.��������,��������
            case 'f':
                DestroyList_DuL(&L);
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
void tips()
{
    printf("        *�������Ӧ���*        \n");
    printf("|-----a.��ʼ������        -----|\n");
    printf("|-----b.�������          -----|\n");
    printf("|-----c.ɾ���ڵ�          -----|\n");
    printf("|-----d.p֮�����ڵ�     -----|\n");
    printf("|-----e.p֮ǰ����ڵ�     -----|\n");
    printf("|-----f.��������,�������� -----|\n");
    printf("\n\n���ѡ���ǣ�");
}
DuLNode* FindList(DuLinkedList L, ElemType e)
{
    //��L���ҵ�����Ϊe�Ľڵ㣬���ظýڵ��ַ
    if(NULL == (L = L->next)) return NULL;
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
DuLNode* SetDuLNode(ElemType e)
{
    //�����½ڵ㣬����Ϊe
    DuLNode *New;
    New = (DuLNode *)malloc(sizeof(DuLNode));
    New->data = e;
    return New;
}
void printList(DuLinkedList L)
{
    //�������
    printf("\n��ǰ����Ϊ��\n");
    TraverseList_DuL(L, print);
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
        if((str[i] >= 'a') && (str[i] <= 'f')) return str[i];
        if((str[i] >= 'A') && (str[i] <= 'F')) return str[i] + 32;
    }
    return 'z';
}
