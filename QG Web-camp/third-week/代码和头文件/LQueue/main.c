#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LQueue.c"
void tips();
char getch();

int main()
{
    LQueue *Q;
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
                Q = (LQueue*)malloc(sizeof(LQueue));
                InitLQueue(Q);
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
                EnLQueue(Q, e);
                printf("\n��ӳɹ���\n");
                break;
            //c.����
            case 'c':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                if(Q->length == 0)
                {
                    printf("\n����Ϊ�գ�����ӣ�\n");
                    break;
                }
                DeLQueue(Q);
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
                if(Q->length == 0)
                {
                    printf("\n����Ϊ�գ�����ӣ�\n");
                    break;
                }
                ClearLQueue(Q);
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
                if(Q->length == 0)
                {
                    printf("\n����Ϊ�գ�����ӣ�\n");
                    break;
                }
                printf("\n��ǰ����Ϊ��\n");
                TraverseLQueue(Q, LPrint);
                putchar('\n');
                break;
            //f.ȷ�����г���
            case 'f':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                printf("\n���г���Ϊ��%d\n", LengthLQueue(Q));
                break;
            //g.�鿴��ͷԪ��
            case 'g':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                if(Q->length == 0)
                {
                    printf("\n����Ϊ�գ�����ӣ�\n");
                    break;
                }
                printf("\n��ͷԪ��:");
                GetHeadLQueue(Q, e);
                break;
            //h.�������Ƿ�Ϊ��
            case 'h':
                if(!f)
                {
                    printf("\n���ȳ�ʼ����\n");
                    break;
                }
                //������
                if(Q->length == 0)
                {
                    printf("\n����Ϊ�գ�����ӣ�\n");
                }
                else
                {
                    printf("\n���в�Ϊ�գ�\n");
                    printf("\n��ǰ����Ϊ��%d\n", Q->length);
                }
                break;
            //i.���ٶ���,��������
            case 'i':
                if(f)
                    DestoryLQueue(Q);
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
    printf("|-----b.���              -----|\n");
    printf("|-----c.����              -----|\n");
    printf("|-----d.��ն���          -----|\n");
    printf("|-----e.�������          -----|\n");
    printf("|-----f.ȷ�����г���      -----|\n");
    printf("|-----g.�鿴��ͷԪ��      -----|\n");
    printf("|-----h.�������Ƿ�Ϊ��  -----|\n");
    printf("|-----i.���ٶ���,�������� -----|\n");
    printf("\n\n���ѡ���ǣ�");
}
char getch()
{
    //�ҵ����������ĵ�һ���ַ�
    char str[100] = {0};
    int i;
    gets(str);
    //���ݴ�Сд
    for(i = 0; i < 100; i++){
        if((str[i] >= 'a') && (str[i] <= 'i')) return str[i];
        if((str[i] >= 'A') && (str[i] <= 'I')) return str[i] + 32;
    }
    return 'z';
}
