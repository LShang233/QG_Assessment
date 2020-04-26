#include "BinaryTree.c"
Status isNumber(char ch)
{
    if(ch >= '0' && ch <= '9')
        return SUCCESS;
    else return ERROR;
}

Status isRightFormula(char *c)
{
    if(c == NULL)
    {
        printf("\n��������Ϊ�գ�\n\n");
        return ERROR;
    }
    int i;
    for(i = 0; c[i] != '\0'; i ++)
    {
        if(!iscaculate(c[i]) && !isNumber(c[i]))
        {
            printf("\n�����ַ������������룡\n\n");
            return ERROR;
        }
    }
    return SUCCESS;
}

char getch()
{
    //�ҵ����������ĵ�һ���ַ�
    char str[100] = {0};
    int i;
    gets(str);
    //���ݴ�Сд
    for(i = 0; i < 100; i++){
        if(str[i] == 'n') return str[i];
        if(str[i] == 'N') return str[i] + 32;
    }
    return 'z';
}



int main()
{
    while(1)
    {
        BiTNode *T;
        _Bool flag;
        //��ʼ���� 
		InitBiTree(T); 
        //���빫ʽ
        printf("ע��δ����֤����������ȷ��ǰ׺���ʽ��\n");
        printf("������Ҫ�����ǰ׺���ʽ��");
        char c[100], d[100];
        int i, j;
        for(i = 0; i < 100; i ++) c[i] = d[i] = '\0';
        gets(d);
        if(NULL == d || !isRightFormula(d) || '\0' == d[0]) continue;
        //ǰ׺ת��׺ 
        for(i = 0; i < 100; i ++) 
        	if(d[i] == '\0') break;
        for(i = i - 1, j = 0; i >= 0; i --, j ++)
        {
        	c[j] = d[i];
        }
        //�ַ���ת��Ϊ��
        T = CreateBiTree(T, c);
        //������ṹ
        printf("\n���������\n");
		PreOrderTraverse(T, printTreeNode);
		printf("\n���������\n");
		InOrderTraverse(T, printTreeNode);
		printf("\n���������\n");
		PostOrderTraverse(T, printTreeNode);
        printf("\n���������\n");
		LevelOrderTraverse(T, printTreeNode);
        //���� 
        float ans;
        ans = Value(T);
        printf("\n������Ϊ��%f\n\n", ans);
        printf("�Ƿ�������㣿\n���롮N���˳����������������\n\n");
        char ch;
        ch = getch();
        if(ch == 'n') return 0;
    }

    return 0;
}
