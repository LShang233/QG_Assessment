#include <stdlib.h>
#include <stdio.h>
#include "../head/calculator.h"

int main()
{
    while(1)
    {
        calculate *head = NULL;
        _Bool flag;
        //���빫ʽ
        tips();
        head = scanfCalculate(head);
        if(!head || !isRightFormula(head)) continue;
        //תΪ��׺
        printf("\n��׺���ʽΪ��");
        head = toSuffixExpression(head);
        printfCal(head);
        putchar('\n');
        //����
        calcuSuffix(head);
        printf("�Ƿ�������㣿\n���롮N���˳����������������\n\n");
        char ch;
        ch = getch();
        if(ch == 'n') return 0;
    }
}
