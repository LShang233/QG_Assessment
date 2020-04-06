#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
typedef struct calculate  //���ڴ����һ����������  �Լ�  ��׺���ʽ
{
	_Bool f;   //f=0ʱΪ���֣�f=1ʱΪ�ַ�
	int number;
	char oper;
	struct calculate *next;
}calculate, *calculateP;

struct numNode
{
    float a[50];
    int top;
};

typedef enum Status
{
    ERROR = 0,
	SUCCESS = 1
} Status;

void tips();
char getch();
Status isNumber(char ch);//�Ƿ�Ϊ����
Status isOper(char ch);//�Ƿ�Ϊ�����
void printfCal(calculate *head);//��head�������
calculateP deAllCal(calculate *head);//�������
Status calcuSuffix(calculate *head);//����
calculateP scanfCalculate(calculate *head);//���빫ʽ����������
Status isRightFormula(calculate *head);//�ж��Ƿ�Ϊ��ȷ�ı��ʽ
calculateP toSuffixExpression(calculate *head); //����׺���ʽת���ɺ�׺
calculateP push(calculate *head, calculate *node);//��ջ��ͷ�巨��
calculateP addNodeToTail(calculate *head, calculate *node);//���������β�巨��


void tips()
{
    printf("          **��ʾ**          \n");
    printf("1.�ü�����ֻ֧����������������\n");
    printf("2.������0-9�������Լ�()\n");
    printf("3.ע����Ӣ�ĵ�����\n");
    printf("4.����س�����\n\n");
    printf("��������Ĺ�ʽ��");
}

Status calcuSuffix(calculate *head)
{
    calculate *p, *t;
    struct numNode node;
    node.top = 0;
    p = head;
    while(p)
    {
        if(!p->f)//�������֣����ջ
        {
            node.a[node.top] = p->number;
            node.top ++;
            t = p;
            p = p->next;
            free(t);
        }
        else
        {
            char ch;
            ch = p->oper;
            switch(ch)
            {
                case '+':
                    node.a[node.top - 2] = node.a[node.top - 2] + node.a[node.top - 1];
                    break;
                case '-':
                    node.a[node.top - 2] = node.a[node.top - 2] - node.a[node.top - 1];
                    break;
                case '*':
                    node.a[node.top - 2] = node.a[node.top - 2] * node.a[node.top - 1];
                    break;
                case '/':
                    if(node.a[node.top - 1] == 0)
                    {
                        printf("\n��ĸ����Ϊ0����\n\n");
                        return ERROR;
                    }
                    node.a[node.top - 2] = node.a[node.top - 2] / node.a[node.top - 1];
                    break;
            }
            node.top --;
            t = p;
            p = p->next;
            free(t);
        }
    }
    printf("\n������Ϊ��%.2f\n\n", node.a[0]);
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

calculateP push(calculate *head, calculate *node)//��ջ��ͷ�巨��
{
    node->next = head;
    head = node;
    return head;
}

calculateP addNodeToTail(calculate *head, calculate *node)//���������β�巨��
{
    if(NULL == head)
    {
        head = node;
        node->next = NULL;
        return head;
    }
    calculate *p, *tail;
    p = tail = head;
    while(p)
    {
        tail = p;
        p = p->next;
    }
    tail->next = node;
    node->next = NULL;
    return head;
}

calculateP toSuffixExpression(calculate *head)//����׺���ʽת���ɺ�׺
{
    calculate *p, *tempOper, *fina, *t;
    fina = t = tempOper = NULL;
    p = head;
    //�ȱ�������һ����׺���ʽ
    while(p)
    {
        if(!p->f)//�ڵ�Ϊ����
        {
            //ֱ�������fina
            t = p->next;
            fina = addNodeToTail(fina, p);
            p = t;
        }
        else//�ڵ�Ϊ�ַ�
        {
            if(p->oper == '(' || !tempOper)
            {
                //ֱ����ջ��tempOper
                t = p->next;
                tempOper = push(tempOper, p);
                p = t;
            }
            else if(p->oper == ')')
            {
                //��ջ�ٳ�ջ��ֱ�������š����Ų������
                while(tempOper->oper != '(')
                {
                    t = tempOper;
                    tempOper = tempOper->next;
                    fina = addNodeToTail(fina, t);
                }
                //��ʱջ��Ϊ��   �ͷŸýڵ�
                t = tempOper;
                tempOper = tempOper->next;
                free(t);
                //��ʱpָ�򣩵Ľڵ�  �ͷ��ڴ�
                t = p;
                p = p->next;
                free(t);
            }
            else//�����+-*/
            {
                if(tempOper->oper == '(')
                {
                    //������ֱ����ջ
                    t = p->next;
                    tempOper = push(tempOper, p);
                    p = t;
                }
                else if(p->oper == '+' || p->oper == '-')//�����+-
                {
                    //���ȼ���С  ջ��Ԫ�س�ջ   ������ջ��Ԫ�رȽ�
                    //��Ϊ+-�����ֻ���ڣ�    ����һֱ��ջֱ��������
                    while(tempOper && tempOper->oper != '(')
                    {
                        t = tempOper;
                        tempOper = tempOper->next;
                        fina = addNodeToTail(fina, t);
                    }

                    //��ʱp��ָ����׺���ʽ��+-    ��p��ջ
                    t = p->next;
                    tempOper = push(tempOper, p);
                    p = t;
                }
                else//�����*/
                {
                    //�����*/���ȼ�ֻС�ڣ��������������֮ǰ�Ѵ���  �����ж�ֻͬ�ȼ�
                    while((tempOper && tempOper->oper == '*') || (tempOper && tempOper->oper == '/'))
                    {
                        //ͬ�ȼ�һֱ��ջ
                        t = tempOper;
                        tempOper = tempOper->next;
                        fina = addNodeToTail(fina, t);
                    }

                    t = p->next;
                    tempOper = push(tempOper, p);
                    p = t;
                }
            }
        }
    }
    //��������   ��tempoperʣ��Ľڵ��ջ
    while(tempOper)
    {
        t = tempOper;
        tempOper = tempOper->next;
        fina = addNodeToTail(fina, t);
    }
    return fina;
}

Status isRightFormula(calculate *head)
{
    calculate *p;
    p = head;
    int count = 0;
    while(p)
    {
        if(p->f) //�ýڵ�Ϊ�����
        {
            if(p->oper == '(') count ++;
            else if(p->oper == ')') count --;
            else //�ýڵ�����Ϊ+-*/
            {
                if(p->next) //��һ���ڵ����
                {
                    if(p->next->f && p->next->oper != '(')//����һ���ڵ�Ϊ�ַ�
                    {
                        printf("\n�������ӦΪ���֣�\n\n");
                        return ERROR;
                    }
                    if(p->oper == '/' && !p->next->f && !p->next->number)
                    {
                        printf("\n��ĸ����Ϊ0��\n\n");
                        return ERROR;
                    }
                }
            }

            if(count < 0)
            {
                printf("\n����ƥ�����\n\n");
                return ERROR;
            }
        }
        p = p->next;
    }
    return SUCCESS;
}

Status isOper(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')')
        return SUCCESS;
    else return ERROR;
}

Status isNumber(char ch)
{
    if(ch >= '0' && ch <= '9')
        return SUCCESS;
    else return ERROR;
}

calculateP scanfCalculate(calculate *head)//���빫ʽ����������
{
    calculate *tail;
    tail = head;
    char ch[102];
    int i, num;
    for(i = 0; i < 102; i ++) ch[i] = '\0';
    gets(ch);
    if(ch[100])
    {
        printf("\n��������100���ַ������������룡\n");
        return NULL;
    }
    i = 0;
    //������
    while(ch[i])
    {
        //���ٽڵ�ռ�
        calculate *newnode;
        newnode = (calculate *)malloc(sizeof(calculate));
        newnode->next = NULL;
        //��������
        if(ch[i] == ' ')
        {
            i ++;
        }
        else if(isOper(ch[i])) //��Ϊ�ַ�
        {
            if(ch[0] == '*' || ch[0] == '/')
            {
                printf("\n�˳����ܷ��ڿ�ͷ��\n");
                return NULL;
            }
            if((ch[i] == '*' || ch[i] == '/') && ch[i+1] == '\0')
            {
                printf("\n�˳����ܷ���ĩβ��\n");
                return NULL;
            }
            //�ж��Ƿ�Ϊ����
            if((ch[i] == '-' && !i) || (ch[i] == '-' && ch[i-1] == '('))
            {
                i++;
                num = 0;
                for(; isNumber(ch[i]); i++)
                {
                    num = num * 10 + (ch[i] - '0');
                }
                newnode->f = 0;
                newnode->number = (-1) * num;
            }
            //������д��+num
            else if((ch[i] == '+' && !i) || (ch[i] == '+' && ch[i-1] == '('))
            {
                i++;
                num = 0;
                for(; isNumber(ch[i]); i++)
                {
                    num = num * 10 + (ch[i] - '0');
                }
                newnode->f = 0;
                newnode->number = num;
            }
            else
            {
                newnode->f = 1;
                newnode->oper = ch[i];
                i++;
            }

        }
        else if(isNumber(ch[i]))
        {
            num = 0;
            for(; isNumber(ch[i]); i++)
            {
                num = num * 10 + (ch[i] - '0');
            }
            newnode->f = 0;
            newnode->number = num;
        }
        else//�������
        {
            printf("\n��������ַ������������룡\nע��ʹ��Ӣ�ĵ����ţ�\n");
            return NULL;
        }
        //��������β�巨
        if(!head)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    //���������
    return head;
}
//�������
void printfCal(calculate *head)
{
    calculate *p;
    p = head;
    while(p)
    {
        if(p->f)
            printf("%c ", p->oper);
        else
            printf("%d ", p->number);
        p = p->next;
    }
}
//�������
calculateP deAllCal(calculate *head)
{
    calculate *p;
    p = head;
    while(p)
    {
        p = head->next;
        free(head);
        head = p;
    }
    return NULL;
}


#endif
