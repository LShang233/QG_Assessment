#include <stdio.h>
#include <stdlib.h>
#include "../head/BinaryTree.h"

Status iscaculate(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/') return SUCCESS;
    return ERROR;
}

//�������������ն�����T
Status InitBiTree(BiTree T)
{
    T = (BiTree)malloc(sizeof(BiTNode));
    if(!T) return ERROR;
    T->num = 0;
    T->lchild = T->rchild = NULL;
    return SUCCESS;
}

//��ʼ������������T����
//����������ݻٶ�����T
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

//��ʼ������ definition�����������Ķ���
//�����������definition���������T

//ջ
struct LinkStack
{
    struct StackNode *top;
    int	count;
};    
//ջ�ڵ�
struct StackNode
{
    //�����Ľڵ��ַ
    BiTree tree;
    //��һ���ڵ�
    struct StackNode *next;
};
//��NewTreeNode��ջhead�������µ�head
struct LinkStack *push(BiTree NewTreeNode, struct LinkStack *head)
{
    //��ջ�ڵ�
    struct StackNode *p;
    p = (struct StackNode *)malloc(sizeof(struct StackNode));
    //ջ�ڵ���ջ
    p->tree = NewTreeNode;
    p->next = head->top;
    //������ջ������
    head->top = p;
    head->count ++;
    return head;
};

//definitionΪ��׺���ʽ
//��������õ���
BiTree CreateBiTree(BiTree T, char* definition)
{	
    //��ʼ��ջ
    struct LinkStack *head;
    head = (struct LinkStack *)malloc(sizeof(struct LinkStack));
    head->count = 0;
    head->top = NULL;

    //���ַ���ת��Ϊ��
    int i = 0;
    while(definition[i])//�����ַ���
    {
        //����ֱ����ջ
        if(definition[i] >= '0' && definition[i] <= '9')
        {
            //���ַ���Ϊ���Ľڵ�
            BiTNode *newnode;
            newnode = (BiTNode *)malloc(sizeof(BiTNode));
            newnode->data = definition[i];
            newnode->lchild = newnode->rchild = NULL;
            newnode->num = 0;
            //��ջ
            head = push(newnode, head);
        }
        //�������ջ����
        else if(iscaculate(definition[i]))
        {
            //������
            struct BiTNode *root;
            root = (struct BiTNode *)malloc(sizeof(struct BiTNode));
            root->data = definition[i];
            root->lchild = root->rchild = NULL;
            root->num = 0;

            //�����һ������
            struct StackNode *p;
            p = head->top;
            head->top = head->top->next;
            //������������ڵ�
            root->lchild = p->tree;
            free(p);
            head->count --;

            //����ڶ�������
            p = head->top;
            head->top = head->top->next;
            //�����������ҽڵ�
            root->rchild = p->tree;
            free(p);
            head->count --;

            //��������ջ
            head = push(root, head);
        }
        i ++;
    }

    //��ʱջ��Ӧֻʣһ���ڵ㣬��Ϊ�������
    //T = ;
    //T->num = head->top->tree->num;
    //T->rchild = head->top->tree->rchild;
    //T->lchild = head->top->tree->lchild;
    
    //free(head->top);
    //free(head);

    return head->top->tree;
}



//���²��ֺ�������δָ����������


//��ʼ������������T���ڣ�visitΪ�Խ��Ĳ�����Ӧ�ú���
//����������������T����ÿ��������visit����һ���ҽ�һ�Σ�һ��visitʧ�ܣ������ʧ��
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    //�����
    if(NULL == T) return SUCCESS;
    //��
    if(ERROR == visit(T->data)) return ERROR;
    //��
    if(ERROR == PreOrderTraverse(T->lchild, visit))
        return ERROR;
    //��
    return PreOrderTraverse(T->rchild, visit);
}

//�������
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    //�����
    if(NULL == T) return SUCCESS;
    //��
    if(ERROR == InOrderTraverse(T->lchild, visit))
        return ERROR;
    //��
    if(ERROR == visit(T->data))
        return ERROR;
    //��
    return InOrderTraverse(T->rchild, visit);
}

//�������
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    //�����
    if(NULL == T) return SUCCESS;
    //��
    if(ERROR == InOrderTraverse(T->lchild, visit))
        return ERROR;
    //��
    if(ERROR == InOrderTraverse(T->rchild, visit))
        return ERROR;
    //��
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
	//ֻ��һ�� 
	if(p->next == NULL)
	{
		head->top = NULL;
		free(p);
		head->count --;
		return SUCCESS;
	}
	//�ҵ������ڶ��� 
	while(p->next->next == NULL)
	{
		p = p->next;
	}
	free(p->next);
	p->next = NULL;
	head->count --;
	return SUCCESS;
}
//�ӽڵ� 
typedef struct node
{
    BiTree tree;                  
    struct node *next;           
} Node;
//���� 
typedef struct Lqueue
{
    Node *front;   //��ͷ     
    Node *rear;     //��β    
    int length;    
} LQueue;
//��tree�ڵ����LQueue����
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
//���� 
Status DeLQueue(LQueue *Q)
{
    Node *p;
    p = Q->front;
    Q->front = Q->front->next;
    free(p);
    Q->length --;
    return SUCCESS;
}
//�������
Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    //��ʼ������ 
    struct Lqueue *head;
    head = (struct Lqueue *)malloc(sizeof(struct Lqueue));
    head->length = 0;
    head->front = head->rear = NULL;

    //��һ�������
    EnLQueue(head, T);
    //printTreeNode(head->top->tree->data);
    
    while(head->length)
    {
    	Node *i;
    	//�ҵ���ͷ�ڵ� 
		i = head->front;
    	visit(i->tree->data);
    	//printTreeNode(i->tree->data);
    	//���������
        if(i->tree->lchild)
        {
            EnLQueue(head, i->tree->lchild);
        }
        //��������� 
        if(i->tree->rchild)
        {
            EnLQueue(head, i->tree->rchild);
        }
        //�������Ľڵ���� 
		DeLQueue(head);
	}

    /*do//����������
    {
        struct StackNode *i, *j;
        //�ó�ÿ��ջ��ͷ�ڵ�
        i = head->top;
        //���head��������ջ��һ�������
        head->top = NULL;
        //��������ò�Ԫ��
        printf("jj");
        while(NULL == i)
        {
			printf("hh");
            visit(i->tree->data);
            //��������ջ
            if(T->lchild)
            {
                push(T->lchild, head);
            }
            //��������ջ
            if(T->rchild)
            {
                push(T->rchild, head);
            }
            //iǰ��
            j = i;
            i = i->next;
            free(j);
        }
        putchar('\n');
    }while(NULL == head->top);*/

    return SUCCESS;
}

//������Ķ�������ֵ
float Value(BiTree T)
{
    if(iscaculate(T->lchild->data))
        Value(T->lchild);
    if(iscaculate(T->rchild->data))
        Value(T->rchild);
    //��ȡr����
    float r, l;
    if(iscaculate(T->rchild->data) || T->rchild->data == '#')
        r = T->rchild->num;
    else r = (float)(T->rchild->data - '0');
    //��ȡl����
    if(iscaculate(T->lchild->data) || T->lchild->data == '#')
        l = T->lchild->num;
    else l = (float)(T->lchild->data - '0');
    //����
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
    T->data = '#';//��ʾ�Ѽ���
    return T->num;
}
/*
��ʾ�����ڽ��ṹ�������ø�Tagֵ��־������������������������
�ɸ�����Ҫ�������Ӳ���.
*/
