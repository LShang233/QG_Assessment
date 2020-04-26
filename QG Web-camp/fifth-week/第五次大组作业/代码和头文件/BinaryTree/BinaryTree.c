#include <stdio.h>
#include <stdlib.h>
#include "../head/BinaryTree.h"

Status iscaculate(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/') return SUCCESS;
    return ERROR;
}

//操作结果：构造空二叉树T
Status InitBiTree(BiTree T)
{
    T = (BiTree)malloc(sizeof(BiTNode));
    if(!T) return ERROR;
    T->num = 0;
    T->lchild = T->rchild = NULL;
    return SUCCESS;
}

//初始条件：二叉树T存在
//操作结果：摧毁二叉树T
Status DestroyBiTree(BiTree T)
{
    if(T->lchild)
    {
        DestroyBiTree(T->lchild);
        T->lchild = NULL;
    }
    if(T->rchild)
    {
        DestroyBiTree(T->rchild);
        T->rchild = NULL;
    }
    free(T);
    return SUCCESS;
}

//初始条件： definition给出二叉树的定义
//操作结果：按definition构造二叉树T

//栈
struct LinkStack
{
    struct StackNode *top;
    int	count;
};    
//栈节点
struct StackNode
{
    //放树的节点地址
    BiTree tree;
    //下一个节点
    struct StackNode *next;
};
//将NewTreeNode入栈head，返回新的head
struct LinkStack *push(BiTree NewTreeNode, struct LinkStack *head)
{
    //建栈节点
    struct StackNode *p;
    p = (struct StackNode *)malloc(sizeof(struct StackNode));
    //栈节点入栈
    p->tree = NewTreeNode;
    p->next = head->top;
    //更新链栈的数据
    head->top = p;
    head->count ++;
    return head;
};

//definition为后缀表达式
//建造计算用的树
BiTree CreateBiTree(BiTree T, char* definition)
{	
    //初始化栈
    struct LinkStack *head;
    head = (struct LinkStack *)malloc(sizeof(struct LinkStack));
    head->count = 0;
    head->top = NULL;

    //将字符串转换为树
    int i = 0;
    while(definition[i])//遍历字符串
    {
        //数字直接入栈
        if(definition[i] >= '0' && definition[i] <= '9')
        {
            //将字符变为树的节点
            BiTNode *newnode;
            newnode = (BiTNode *)malloc(sizeof(BiTNode));
            newnode->data = definition[i];
            newnode->lchild = newnode->rchild = NULL;
            newnode->num = 0;
            //入栈
            head = push(newnode, head);
        }
        //运算符出栈建树
        else if(iscaculate(definition[i]))
        {
            //建新树
            struct BiTNode *root;
            root = (struct BiTNode *)malloc(sizeof(struct BiTNode));
            root->data = definition[i];
            root->lchild = root->rchild = NULL;
            root->num = 0;

            //处理第一个数据
            struct StackNode *p;
            p = head->top;
            head->top = head->top->next;
            //更新新树的左节点
            root->lchild = p->tree;
            free(p);
            head->count --;

            //处理第二个数据
            p = head->top;
            head->top = head->top->next;
            //更新新树的右节点
            root->rchild = p->tree;
            free(p);
            head->count --;

            //将新树入栈
            head = push(root, head);
        }
        i ++;
    }

    //此时栈内应只剩一个节点，即为所需的树
    //T = ;
    //T->num = head->top->tree->num;
    //T->rchild = head->top->tree->rchild;
    //T->lchild = head->top->tree->lchild;
    
    //free(head->top);
    //free(head);

    return head->top->tree;
}



//以下部分函数定义未指定参数类型


//初始条件：二叉树T存在，visit为对结点的操作的应用函数
//操作结果：先序遍历T，对每个结点调用visit函数一次且仅一次，一旦visit失败，则操作失败
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    //到最底
    if(NULL == T) return SUCCESS;
    //根
    if(ERROR == visit(T->data)) return ERROR;
    //左
    if(ERROR == PreOrderTraverse(T->lchild, visit))
        return ERROR;
    //右
    return PreOrderTraverse(T->rchild, visit);
}

//中序遍历
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    //到最底
    if(NULL == T) return SUCCESS;
    //左
    if(ERROR == InOrderTraverse(T->lchild, visit))
        return ERROR;
    //根
    if(ERROR == visit(T->data))
        return ERROR;
    //右
    return InOrderTraverse(T->rchild, visit);
}

//后序遍历
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    //到最底
    if(NULL == T) return SUCCESS;
    //左
    if(ERROR == InOrderTraverse(T->lchild, visit))
        return ERROR;
    //右
    if(ERROR == InOrderTraverse(T->rchild, visit))
        return ERROR;
    //根
    return visit(T->data);
}


Status printTreeNode(TElemType e)
{
    printf("%c  ", e);
    return SUCCESS;
}
Status pop(struct LinkStack *head)
{
	if(head->top == NULL) return ERROR;
	struct StackNode *p;
	p = head->top;
	//只有一个 
	if(p->next == NULL)
	{
		head->top = NULL;
		free(p);
		head->count --;
		return SUCCESS;
	}
	//找到倒数第二个 
	while(p->next->next == NULL)
	{
		p = p->next;
	}
	free(p->next);
	p->next = NULL;
	head->count --;
	return SUCCESS;
}
//队节点 
typedef struct node
{
    BiTree tree;                  
    struct node *next;           
} Node;
//队列 
typedef struct Lqueue
{
    Node *front;   //队头     
    Node *rear;     //队尾    
    int length;    
} LQueue;
//将tree节点插入LQueue链表
Status EnLQueue(LQueue *Q, BiTree tree)
{
	Node *newnode;
    newnode = (Node *)malloc(sizeof(Node));
    newnode->tree = tree;
    newnode->next = NULL;
    
    if(Q->front)
        Q->rear->next = newnode;
    else
        Q->front = newnode;
    Q->rear = newnode;
    Q->length ++;
    return SUCCESS;
}
//出队 
Status DeLQueue(LQueue *Q)
{
    Node *p;
    p = Q->front;
    Q->front = Q->front->next;
    free(p);
    Q->length --;
    return SUCCESS;
}
//层序遍历
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    //初始化队列 
    struct Lqueue *head;
    head = (struct Lqueue *)malloc(sizeof(struct Lqueue));
    head->length = 0;
    head->front = head->rear = NULL;

    //第一层先入队
    EnLQueue(head, T);
    //printTreeNode(head->top->tree->data);
    
    while(head->length)
    {
    	Node *i;
    	//找到队头节点 
		i = head->front;
    	visit(i->tree->data);
    	//printTreeNode(i->tree->data);
    	//左子树入队
        if(i->tree->lchild)
        {
            EnLQueue(head, i->tree->lchild);
        }
        //右子树入队 
        if(i->tree->rchild)
        {
            EnLQueue(head, i->tree->rchild);
        }
        //遍历过的节点出队 
		DeLQueue(head);
	}

    /*do//按层数遍历
    {
        struct StackNode *i, *j;
        //拿出每层栈的头节点
        i = head->top;
        //清空head，重新入栈下一层的数据
        head->top = NULL;
        //逐个遍历该层元素
        printf("jj");
        while(NULL == i)
        {
			printf("hh");
            visit(i->tree->data);
            //左子树入栈
            if(T->lchild)
            {
                push(T->lchild, head);
            }
            //右子树入栈
            if(T->rchild)
            {
                push(T->rchild, head);
            }
            //i前进
            j = i;
            i = i->next;
            free(j);
        }
        putchar('\n');
    }while(NULL == head->top);*/

    return SUCCESS;
}

//构造出的二叉树求值
float Value(BiTree T)
{
    if(iscaculate(T->lchild->data))
        Value(T->lchild);
    if(iscaculate(T->rchild->data))
        Value(T->rchild);
    //获取r数据
    float r, l;
    if(iscaculate(T->rchild->data) || T->rchild->data == '#')
        r = T->rchild->num;
    else r = (float)(T->rchild->data - '0');
    //获取l数据
    if(iscaculate(T->lchild->data) || T->lchild->data == '#')
        l = T->lchild->num;
    else l = (float)(T->lchild->data - '0');
    //计算
    switch(T->data)
    {
        case '+':
            T->num = r + l;
            break;
        case '-':
            T->num = r - l;
            break;
        case '*':
            T->num = r * l;
            break;
        case '/':
            T->num = r / l;
            break;
        defalt:
        	printf("error");
        	break;
    }
    T->data = '#';//表示已计算
    return T->num;
}
/*
提示：可在结点结构体中设置个Tag值标志数字与操作符来构造二叉树，
可根据需要自行增加操作.
*/
