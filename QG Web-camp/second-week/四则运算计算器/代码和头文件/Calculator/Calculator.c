#include <stdlib.h>
#include <stdio.h>
#include "../head/calculator.h"

int main()
{
    while(1)
    {
        calculate *head = NULL;
        _Bool flag;
        //输入公式
        tips();
        head = scanfCalculate(head);
        if(!head || !isRightFormula(head)) continue;
        //转为后缀
        printf("\n后缀表达式为：");
        head = toSuffixExpression(head);
        printfCal(head);
        putchar('\n');
        //计算
        calcuSuffix(head);
        printf("是否继续计算？\n输入‘N’退出，任意键继续……\n\n");
        char ch;
        ch = getch();
        if(ch == 'n') return 0;
    }
}
