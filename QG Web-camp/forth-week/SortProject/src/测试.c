#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"textdata.c"

int main()
{
    FILE *fp;
    //�ļ��򿪴���
    if((fp = fopen("arrey.txt", "r")) == NULL)
    {
        printf("error open!");
        system("PAUSE");
        exit(0);
    }

    //�ó�����
    int n;
    fscanf(fp, "%d", &n);
    fscanf(fp, "\n");
    int i, *arr;
    arr = (int *)malloc(sizeof(int) * n);
    //��ȡ������
    for(i = 0; i < n; i ++)
    {
        fscanf(fp, "%d", &arr[i]);
        fscanf(fp, "\n");
    }
    //�ر��ļ�
    fclose(fp);


    char ch;
    while(1)
    {
        //ѡ����������
        tips();
        ch = getchabc();
        printf("            ��\n");
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
            printf("\n��������ȷ��ţ�\n");
            break;
        }

        putchar('\n');
        system("pause");
        system("cls");
    }
    return 0;
}

