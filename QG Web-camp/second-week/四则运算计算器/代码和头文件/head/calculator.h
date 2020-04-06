#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
typedef struct calculate  //用于储存第一次输入数据  以及  后缀表达式
{
	_Bool f;   //f=0时为数字，f=1时为字符
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
Status isNumber(char ch);//是否为数字
Status isOper(char ch);//是否为运算符
void printfCal(calculate *head);//从head输出链表
calculateP deAllCal(calculate *head);//清空链表
Status calcuSuffix(calculate *head);//计算
calculateP scanfCalculate(calculate *head);//输入公式，建立链表
Status isRightFormula(calculate *head);//判断是否为正确的表达式
calculateP toSuffixExpression(calculate *head); //将中缀表达式转换成后缀
calculateP push(calculate *head, calculate *node);//入栈（头插法）
calculateP addNodeToTail(calculate *head, calculate *node);//用于输出（尾插法）


void tips()
{
    printf("          **提示**          \n");
    printf("1.该计算器只支持整数的四则运算\n");
    printf("2.请输入0-9的数字以及()\n");
    printf("3.注意是英文的括号\n");
    printf("4.输入回车计算\n\n");
    printf("请输入你的公式：");
}

Status calcuSuffix(calculate *head)
{
    calculate *p, *t;
    struct numNode node;
    node.top = 0;
    p = head;
    while(p)
    {
        if(!p->f)//若是数字，则进栈
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
                        printf("\n分母不能为0！！\n\n");
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
    printf("\n计算结果为：%.2f\n\n", node.a[0]);
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

calculateP push(calculate *head, calculate *node)//入栈（头插法）
{
    node->next = head;
    head = node;
    return head;
}

calculateP addNodeToTail(calculate *head, calculate *node)//用于输出（尾插法）
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

calculateP toSuffixExpression(calculate *head)//将中缀表达式转换成后缀
{
    calculate *p, *tempOper, *fina, *t;
    fina = t = tempOper = NULL;
    p = head;
    //先遍历处理一遍中缀表达式
    while(p)
    {
        if(!p->f)//节点为数字
        {
            //直接输出至fina
            t = p->next;
            fina = addNodeToTail(fina, p);
            p = t;
        }
        else//节点为字符
        {
            if(p->oper == '(' || !tempOper)
            {
                //直接入栈至tempOper
                t = p->next;
                tempOper = push(tempOper, p);
                p = t;
            }
            else if(p->oper == ')')
            {
                //出栈再出栈，直到左括号。括号不作输出
                while(tempOper->oper != '(')
                {
                    t = tempOper;
                    tempOper = tempOper->next;
                    fina = addNodeToTail(fina, t);
                }
                //此时栈顶为（   释放该节点
                t = tempOper;
                tempOper = tempOper->next;
                free(t);
                //此时p指向）的节点  释放内存
                t = p;
                p = p->next;
                free(t);
            }
            else//运算符+-*/
            {
                if(tempOper->oper == '(')
                {
                    //左括号直接入栈
                    t = p->next;
                    tempOper = push(tempOper, p);
                    p = t;
                }
                else if(p->oper == '+' || p->oper == '-')//运算符+-
                {
                    //优先级最小  栈顶元素出栈   继续与栈顶元素比较
                    //因为+-运算符只大于（    所以一直出栈直到遇见（
                    while(tempOper && tempOper->oper != '(')
                    {
                        t = tempOper;
                        tempOper = tempOper->next;
                        fina = addNodeToTail(fina, t);
                    }

                    //此时p还指向中缀表达式的+-    将p入栈
                    t = p->next;
                    tempOper = push(tempOper, p);
                    p = t;
                }
                else//运算符*/
                {
                    //运算符*/优先级只小于），这两种情况在之前已处理  所以判断只同等级
                    while((tempOper && tempOper->oper == '*') || (tempOper && tempOper->oper == '/'))
                    {
                        //同等级一直出栈
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
    //结束遍历   把tempoper剩余的节点出栈
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
        if(p->f) //该节点为运算符
        {
            if(p->oper == '(') count ++;
            else if(p->oper == ')') count --;
            else //该节点数据为+-*/
            {
                if(p->next) //下一个节点存在
                {
                    if(p->next->f && p->next->oper != '(')//若下一个节点为字符
                    {
                        printf("\n运算符后应为数字！\n\n");
                        return ERROR;
                    }
                    if(p->oper == '/' && !p->next->f && !p->next->number)
                    {
                        printf("\n分母不能为0！\n\n");
                        return ERROR;
                    }
                }
            }

            if(count < 0)
            {
                printf("\n括号匹配错误！\n\n");
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

calculateP scanfCalculate(calculate *head)//输入公式，建立链表
{
    calculate *tail;
    tail = head;
    char ch[102];
    int i, num;
    for(i = 0; i < 102; i ++) ch[i] = '\0';
    gets(ch);
    if(ch[100])
    {
        printf("\n最多可输入100个字符！请重新输入！\n");
        return NULL;
    }
    i = 0;
    //建链表
    while(ch[i])
    {
        //开辟节点空间
        calculate *newnode;
        newnode = (calculate *)malloc(sizeof(calculate));
        newnode->next = NULL;
        //输入数据
        if(ch[i] == ' ')
        {
            i ++;
        }
        else if(isOper(ch[i])) //若为字符
        {
            if(ch[0] == '*' || ch[0] == '/')
            {
                printf("\n乘除不能放在开头！\n");
                return NULL;
            }
            if((ch[i] == '*' || ch[i] == '/') && ch[i+1] == '\0')
            {
                printf("\n乘除不能放在末尾！\n");
                return NULL;
            }
            //判断是否为负数
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
            //若有人写了+num
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
        else//输入错误
        {
            printf("\n输入错误字符！请重新输入！\n注意使用英文的括号！\n");
            return NULL;
        }
        //插入链表（尾插法
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
    //链表构建完成
    return head;
}
//输出链表
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
//清空链表
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
