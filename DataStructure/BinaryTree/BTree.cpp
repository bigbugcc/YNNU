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

/*二叉树的二叉链表存储结构定义*/
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode* lchild, * rchild;      //左右孩子指针
}BiTNode, * BiTree;

/*栈的顺序存储结构定义*/
typedef BiTree SElemType;
typedef struct
{
	SElemType* base;
	SElemType* top;
	int  stacksize;
}SqStack;


//1-创建二叉树
//按先序次序输入二叉树中结点的值（一个字符），#字符表示空树
Status CreateBiTree(BiTree& T);

//2-先序遍历二叉树(递归算法)
//先序遍历二叉树T的递归算法，对每个数据元素调用函数Visit
Status PreOrderTraverse(BiTree T, Status(*Visit)(ElemType e));

//3-中序遍历二叉树(递归算法)
//中序遍历二叉树T的递归算法，对每个数据元素调用函数Visit
Status InOrderTraverse(BiTree T, Status(*Visit)(ElemType));

//4-后序遍历二叉树(递归算法)
//后序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
Status PostOrderTraverse(BiTree T, Status(*Visit)(ElemType));

//5-中序遍历二叉树(非递归算法)
//中序遍历二叉树T的递归算法，对每个数据元素调用函数Visit，非递归算法，
//采用栈作为辅助结构，注意栈中存储的数据类型是指向树结点的指针
Status InOrderTraverse1(BiTree T, Status(*Visit)(ElemType));

//6-层次遍历二叉树
//层次遍历二叉树T的递归算法，对每个数据元素调用函数Visit，采用队列作为辅助结构
Status LevelOrderTraverse(BiTree T, Status(*Visit)(ElemType));

//7-统计树的叶子结点个数
Status CountLeafs(BiTree T, int& numofleafs);

//8-统计树的层次数
Status CountLevels(BiTree T);

//打印元素
Status PrintElement(BiTree T);

//构造一个空栈
Status InitStack(SqStack& S);

//进栈
Status Push(SqStack& S, SElemType e);

//退栈
Status Pop(SqStack& S, SElemType& e);

//判断栈是否为空
Status StackEmpty(SqStack S);

// 按先序次序输入二叉树中结点的值（一个字符），空格字符表示空树，
  // 构造二叉链表表示的二叉树T。
Status CreateBiTree(BiTree& T)
{
	ElemType ch;
	ch = getchar();
	if (ch == ' ') T = NULL;
	else
	{

		if (!(T = (BiTNode*)malloc(sizeof(BiTNode))))  exit(OVERFLOW);
		T->data = ch;              // 生成根结点
		CreateBiTree(T->lchild);      // 构造左子树
		CreateBiTree(T->rchild);      // 构造右子树
	}
	return OK;
} 
// CreateBiTree


//打印元素
Status PrintElement(ElemType e)
{
	printf("%c ", e);
	return OK;
}

//2-先序遍历二叉树(递归算法)
//先序遍历二叉树T的递归算法，对每个数据元素调用函数Visit
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



//3-中序遍历二叉树(递归算法)
//中序遍历二叉树T的递归算法，对每个数据元素调用函数Visit
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


//4-后序遍历二叉树(递归算法)
//后序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
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


//构造一个空栈
Status InitStack(SqStack& S)
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) {
		printf("栈溢出！\n");
		exit(OVERFLOW);
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

//进栈
Status Push(SqStack& S, SElemType e)
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!S.base)
		{
			printf("栈溢出!\n");
			return OVERFLOW;
		}
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}//若栈满，追加存储空间
	*S.top++ = e;
	return OK;
}

//出栈
Status Pop(SqStack& S, SElemType& e)
{
	if (StackEmpty(S))
		return ERROR; //判空
	e = *(--S.top);
	return OK;
}

//判断栈是否为空
Status StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}



//5-中序遍历二叉树(非递归算法)
//中序遍历二叉树T的非递归算法，对每个数据元素调用函数Visit，
//采用栈作为辅助结构，注意栈中存储的数据类型是指向树结点的指针
Status InOrderTraverse1(BiTree T, Status(*Visit)(ElemType))
{
	SqStack S;
	BiTree p;
	p = T;
	InitStack(S);
	while (p || !StackEmpty(S))
	{
		if (p) { Push(S, p);  p = p->lchild; }  // 非空指针进栈，继续左进
		else {       // 上层指针退栈，访问其所指结点，再向右进
			Pop(S, p);
			if (!Visit(p->data))
				return ERROR;
			p = p->rchild;
		}
	}
	return OK;
} 
// InOrderTraverse



//6-层次遍历二叉树
//层次遍历二叉树T的递归算法，对每个数据元素调用函数Visit，采用队列作为辅助结构
Status LevelOrderTraverse(BiTree T, Status(*Visit)(ElemType))
{
	BiTNode* Queue[100], * p = T;
	int  front = 0, rear = 0;
	if (p != NULL)
	{
		Queue[++rear] = p;    /*   根结点入队  */
		while (front < rear)
		{
			p = Queue[++front];  Visit(p->data);
			if (p->lchild != NULL)
				Queue[++rear] = p->lchild;    /*   左结点入队  */
			if (p->rchild != NULL)
				Queue[++rear] = p->rchild;    /*   左结点入队  */
		}
		return OK;
	}
	return ERROR;
}



//7-统计树的叶子结点个数
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


//8-统计树的层次数
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
	printf("按先序次序输入二叉树中结点的值（一个字符），空格结束:\n");
	getchar();
	CreateBiTree(T);
	CountLeafs(T, n);
	printf("树的叶子结点个数为:%d", n);
	printf("\n树的层次数为:%d\n", CountLevels(T));
	printf("先序遍历二叉树(递归算法):");
	PreOrderTraverse(T, PrintElement);
	printf("\n中序遍历二叉树(递归算法):");
	InOrderTraverse(T, PrintElement);
	printf("\n后序遍历二叉树(递归算法):");
	PostOrderTraverse(T, PrintElement);
	printf("\n中序遍历二叉树(非递归算法):");
	InOrderTraverse1(T, PrintElement);
	printf("\n层次遍历二叉树(递归算法):");
	LevelOrderTraverse(T, PrintElement);
	printf("\n");
}
