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
        printf("\n输入内容为空！\n\n");
        return ERROR;
    }
    int i;
    for(i = 0; c[i] != '\0'; i ++)
    {
        if(!iscaculate(c[i]) && !isNumber(c[i]))
        {
            printf("\n错误字符！请重新输入！\n\n");
            return ERROR;
        }
    }
    return SUCCESS;
}

char getch()
{
    //找到符合条件的第一个字符
    char str[100] = {0};
    int i;
    gets(str);
    //兼容大小写
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
        //初始化树 
		InitBiTree(T); 
        //输入公式
        printf("注：未加验证，请输入正确的前缀表达式！\n");
        printf("输入需要计算的前缀表达式：");
        char c[100], d[100];
        int i, j;
        for(i = 0; i < 100; i ++) c[i] = d[i] = '\0';
        gets(d);
        if(NULL == d || !isRightFormula(d) || '\0' == d[0]) continue;
        //前缀转后缀 
        for(i = 0; i < 100; i ++) 
        	if(d[i] == '\0') break;
        for(i = i - 1, j = 0; i >= 0; i --, j ++)
        {
        	c[j] = d[i];
        }
        //字符串转换为树
        T = CreateBiTree(T, c);
        //输出树结构
        printf("\n先序遍历：\n");
		PreOrderTraverse(T, printTreeNode);
		printf("\n中序遍历：\n");
		InOrderTraverse(T, printTreeNode);
		printf("\n后序遍历：\n");
		PostOrderTraverse(T, printTreeNode);
        printf("\n层序遍历：\n");
		LevelOrderTraverse(T, printTreeNode);
        //计算 
        float ans;
        ans = Value(T);
        printf("\n计算结果为：%f\n\n", ans);
        printf("是否继续计算？\n输入‘N’退出，任意键继续……\n\n");
        char ch;
        ch = getch();
        if(ch == 'n') return 0;
    }

    return 0;
}
