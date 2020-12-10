#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 50
#define FALSE 0 
#define TRUE 1
typedef int QueueElemType;

typedef struct
{
	QueueElemType element[MAXSIZE];
	int top;
	int rear;
}SeqQueue;

//初始化队列
void InitQueue(SeqQueue* Seq)
{
	Seq->top = Seq->rear = 0;
}

int EnterQueue(SeqQueue* Seq, QueueElemType x)//入队
{
	if ((Seq->rear + 1) % MAXSIZE == Seq->top)///队列已经满了
		return FALSE;
	Seq->element[Seq->rear] = x;
	Seq->rear = (Seq->rear + 1) % MAXSIZE;
	return TRUE;
}

int DelQueue(SeqQueue* Seq, QueueElemType* x)//出对列
{
	if (Seq->top == Seq->rear)
		return FALSE;
	*x = Seq->element[Seq->top];
	Seq->top = (Seq->top + 1) % MAXSIZE;

	return TRUE;
}
int GetHead(SeqQueue* Q, QueueElemType* x)//取对头元素
{
	if (Q->top == Q->rear)
		return FALSE;
	*x = Q->element[Q->top];
	return TRUE;

}
int IsEmpty(SeqQueue* Q)
{
	if (Q->rear == Q->top)
		return TRUE;
	else
		return FALSE;
}


void YanghuiTriangle(int N)
{
	int n, i, x, temp;
	SeqQueue Q;
	InitQueue(&Q);
	EnterQueue(&Q, 1);//第一行元素入队
	for (n = 2; n <= N; n++)
	{
		EnterQueue(&Q, 1);//入队
		for (i = 1; i <= n - 2; i++)
		{
			DelQueue(&Q, &temp);//出队的数赋给temp
			printf("%d ", temp);
			GetHead(&Q, &x);
			temp = temp + x;
			EnterQueue(&Q, temp);
		}
		DelQueue(&Q, &x);//出队
		printf("%d ", x);
		EnterQueue(&Q, 1);
		printf("\n");
	}
	while (!IsEmpty(&Q))
	{
		DelQueue(&Q, &x);
		printf("%d ", x);

	}
}
void main()
{
	int N;
	printf("输入三角的行数:");
	scanf("%d", &N);
	YanghuiTriangle(N);
	printf("\n");
	system("pause");
}