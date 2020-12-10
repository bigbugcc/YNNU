#include<stdlib.h>
#include<stdio.h>
#define TRUE   1
#define FALSE  0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef  int Status;
typedef  char ElemType;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

/*�������Ķ�������洢�ṹ����*/
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode* lchild, * rchild;      //���Һ���ָ��
}BiTNode, * BiTree;

/*ջ��˳��洢�ṹ����*/
typedef BiTree SElemType;
typedef struct
{
	SElemType* base;
	SElemType* top;
	int  stacksize;
}SqStack;


//1-����������
//�������������������н���ֵ��һ���ַ�����#�ַ���ʾ����
Status CreateBiTree(BiTree& T);

//2-�������������(�ݹ��㷨)
//�������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit
Status PreOrderTraverse(BiTree T, Status(*Visit)(ElemType e));

//3-�������������(�ݹ��㷨)
//�������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit
Status InOrderTraverse(BiTree T, Status(*Visit)(ElemType));

//4-�������������(�ݹ��㷨)
//�������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
Status PostOrderTraverse(BiTree T, Status(*Visit)(ElemType));

//5-�������������(�ǵݹ��㷨)
//�������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit���ǵݹ��㷨��
//����ջ��Ϊ�����ṹ��ע��ջ�д洢������������ָ��������ָ��
Status InOrderTraverse1(BiTree T, Status(*Visit)(ElemType));

//6-��α���������
//��α���������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit�����ö�����Ϊ�����ṹ
Status LevelOrderTraverse(BiTree T, Status(*Visit)(ElemType));

//7-ͳ������Ҷ�ӽ�����
Status CountLeafs(BiTree T, int& numofleafs);

//8-ͳ�����Ĳ����
Status CountLevels(BiTree T);

//��ӡԪ��
Status PrintElement(BiTree T);

//����һ����ջ
Status InitStack(SqStack& S);

//��ջ
Status Push(SqStack& S, SElemType e);

//��ջ
Status Pop(SqStack& S, SElemType& e);

//�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack S);

// �������������������н���ֵ��һ���ַ������ո��ַ���ʾ������
  // ������������ʾ�Ķ�����T��
Status CreateBiTree(BiTree& T)
{
	ElemType ch;
	ch = getchar();
	if (ch == ' ') T = NULL;
	else
	{

		if (!(T = (BiTNode*)malloc(sizeof(BiTNode))))  exit(OVERFLOW);
		T->data = ch;              // ���ɸ����
		CreateBiTree(T->lchild);      // ����������
		CreateBiTree(T->rchild);      // ����������
	}
	return OK;
} 
// CreateBiTree


//��ӡԪ��
Status PrintElement(ElemType e)
{
	printf("%c ", e);
	return OK;
}

//2-�������������(�ݹ��㷨)
//�������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit
Status PreOrderTraverse(BiTree T, Status(*Visit)(ElemType e))
{
	if (T)
	{
		if (Visit(T->data))
			if (PreOrderTraverse(T->lchild, Visit))
				if (PreOrderTraverse(T->rchild, Visit)) return OK;
		return ERROR;
	}
	else return OK;
}
//PreOrderTraverse



//3-�������������(�ݹ��㷨)
//�������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit
Status InOrderTraverse(BiTree T, Status(*Visit)(ElemType))
{
	if (T)
	{
		if (InOrderTraverse(T->lchild, Visit))
			if (Visit(T->data))
				if (InOrderTraverse(T->rchild, Visit))
					return OK;
		return ERROR;
	}
	else return OK;
}//PreOrderTraverse


//4-�������������(�ݹ��㷨)
//�������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
Status PostOrderTraverse(BiTree T, Status(*Visit)(ElemType))
{
	if (T)
	{
		if (PostOrderTraverse(T->lchild, Visit))
			if (PostOrderTraverse(T->rchild, Visit))
				if (Visit(T->data))  return OK;
		return ERROR;
	}
	else return OK;
}
//PreOrderTraverse


//����һ����ջ
Status InitStack(SqStack& S)
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) {
		printf("ջ�����\n");
		exit(OVERFLOW);
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

//��ջ
Status Push(SqStack& S, SElemType e)
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base)
		{
			printf("ջ���!\n");
			return OVERFLOW;
		}
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}//��ջ����׷�Ӵ洢�ռ�
	*S.top++ = e;
	return OK;
}

//��ջ
Status Pop(SqStack& S, SElemType& e)
{
	if (StackEmpty(S))
		return ERROR; //�п�
	e = *(--S.top);
	return OK;
}

//�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}



//5-�������������(�ǵݹ��㷨)
//�������������T�ķǵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
//����ջ��Ϊ�����ṹ��ע��ջ�д洢������������ָ��������ָ��
Status InOrderTraverse1(BiTree T, Status(*Visit)(ElemType))
{
	SqStack S;
	BiTree p;
	p = T;
	InitStack(S);
	while (p || !StackEmpty(S))
	{
		if (p) { Push(S, p);  p = p->lchild; }  // �ǿ�ָ���ջ���������
		else {       // �ϲ�ָ����ջ����������ָ��㣬�����ҽ�
			Pop(S, p);
			if (!Visit(p->data))
				return ERROR;
			p = p->rchild;
		}
	}
	return OK;
} 
// InOrderTraverse



//6-��α���������
//��α���������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit�����ö�����Ϊ�����ṹ
Status LevelOrderTraverse(BiTree T, Status(*Visit)(ElemType))
{
	BiTNode* Queue[100], * p = T;
	int  front = 0, rear = 0;
	if (p != NULL)
	{
		Queue[++rear] = p;    /*   ��������  */
		while (front < rear)
		{
			p = Queue[++front];  Visit(p->data);
			if (p->lchild != NULL)
				Queue[++rear] = p->lchild;    /*   �������  */
			if (p->rchild != NULL)
				Queue[++rear] = p->rchild;    /*   �������  */
		}
		return OK;
	}
	return ERROR;
}



//7-ͳ������Ҷ�ӽ�����
Status CountLeafs(BiTree T, int& numofleafs)
{
	if (T)
	{
		if (T->lchild == NULL && T->rchild == NULL) numofleafs++;
		CountLeafs(T->lchild, numofleafs);
		CountLeafs(T->rchild, numofleafs);
		return OK;
	}
	else
		return ERROR;
}


//8-ͳ�����Ĳ����
Status CountLevels(BiTree T)
{
	int levelsoflchild = 0;
	int levelsofrchild = 0;
	if (T)
	{
		levelsoflchild = CountLevels(T->lchild);
		levelsofrchild = CountLevels(T->rchild);
		if (levelsoflchild > levelsofrchild)
			return 1 + levelsoflchild;
		else return 1 + levelsofrchild;
	}
	else   return 0;
}


int main()
{
	BiTree T;
	int n = 0;
	printf("�������������������н���ֵ��һ���ַ������ո����:\n");
	getchar();
	CreateBiTree(T);
	CountLeafs(T, n);
	printf("����Ҷ�ӽ�����Ϊ:%d", n);
	printf("\n���Ĳ����Ϊ:%d\n", CountLevels(T));
	printf("�������������(�ݹ��㷨):");
	PreOrderTraverse(T, PrintElement);
	printf("\n�������������(�ݹ��㷨):");
	InOrderTraverse(T, PrintElement);
	printf("\n�������������(�ݹ��㷨):");
	PostOrderTraverse(T, PrintElement);
	printf("\n�������������(�ǵݹ��㷨):");
	InOrderTraverse1(T, PrintElement);
	printf("\n��α���������(�ݹ��㷨):");
	LevelOrderTraverse(T, PrintElement);
	printf("\n");
}
