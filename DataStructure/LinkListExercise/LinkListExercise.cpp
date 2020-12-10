#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct Node{

	ElemType data;

	struct Node* next;

}Node,*LinkList;


//初始化
void InitList(LinkList *L1,LinkList *L2) {
	(*L1) = (Node*)malloc(sizeof(Node));
	(*L1)->next = NULL;

	(*L2) = (Node*)malloc(sizeof(Node));
	(*L2)->next = NULL;
}

//暂停方法
void cPause() {
	printf("\n");
	system("pause");
}

//打印单链表
void PrintList(LinkList L) {
	int j = 0;
	
	printf("当前链表元素为：");
	while (L->next != NULL) {
		j++;
		L = L->next;
		printf("%d ", L->data);
	}
	printf("\n当前链表长度为：%d", j);

	cPause();
}

//创建单链表
bool CreatList(LinkList L)
{
	int n;

	printf("请输入要创建的单链表长度:");

	scanf("%d", &n);

	printf("请输入%d个数:", n);


	if (n > 0 ) {

		Node* r, * s;

		r = L;

		for (int i = 0; i < n; i++)
		{
			s = (Node*)malloc(sizeof(Node));

			scanf("%d", &s->data);

			r->next = s;

			r = s;
		}
		r->next = NULL;
	}
	else
	{
		printf("====== 参数不合法！=======");

		return false;
	}


	return true;
}

//(头部)插入
void InsertHead(LinkList L) {

	int v;

	Node *s;

	printf("请输入要在头部插入的数：");

	s = (Node*)malloc(sizeof(Node));

	scanf("%d",&s->data);
	
	s->next = L->next;

	L->next = s;

	PrintList(L);
}

//(尾部)插入
void InsertEnd(LinkList L) {

	Node* s;

	printf("请输入要在尾部插入的数：");

	s = (Node*)malloc(sizeof(Node));

	s->next = NULL;

	scanf("%d", &s->data);

	while (L->next!=NULL)
	{
		L = L->next;
	}

	L->next = s;
}

//删除元素
void Del(LinkList L) {
	printf("请输入要删除元素的位置:");

	int p;

	scanf("%d",&p);

	Node* s,*c;

	int j = 0;

	while (L->next!=NULL)
	{
		L = L->next;
		j++;

		if (j==p-1) {
			c =L->next;
			L->next = c->next;
			break;
		}
	}
	
}

//查找元素
void Locate(LinkList L) {

	printf("请输入要查找元素的位置：");

	int p;
	scanf("%d",&p);

	int j = 0;
	while (L->next!=NULL)
	{
		j++;
		L = L->next;
		if (j==p) {
			printf("查找结果为：%d",L->data);
			cPause();
			break;
		}
	}

}

//合并单链表
void Merge(LinkList L1,LinkList L2) {

	
	while (L1->next!=NULL)
	{
		L1 = L1->next;
	}
	L1->next = L2->next;
}


bool CreatLink2(LinkList L2) {
	int n;

	printf("请输入单链表二的长度:");

	scanf("%d", &n);

	printf("请输入%d个数:", n);


	if (n > 0) {

		Node* r, * s;

		r = L2;

		for (int i = 0; i < n; i++)
		{
			s = (Node*)malloc(sizeof(Node));

			scanf("%d", &s->data);

			r->next = s;

			r = s;
		}
		r->next = NULL;
	}
	else
	{
		printf("====== 参数不合法！=======");

		return false;
	}


	return true;
}

//菜单
int menu() {
	//清屏
	system("cls");

	int loca;
	printf("=====菜单==== \n");
	printf("1. 查看元素及链表长度 \n");
	printf("2. 插入元素(头部插入) \n");
	printf("3. 插入元素(尾部插入) \n");
	printf("4. 删除元素 \n");
	printf("5. 查找元素 \n");
	printf("6. 合并单链表 \n");
	printf("7. 退出程序 \n");
	printf("请输入操作的序号：\n");
	scanf("%d", &loca);

	return loca;
}


int main() {
	LinkList linklist;

	LinkList linklist2;

	//初始化
	InitList(&linklist,&linklist2);

	//创建数组
	CreatList(linklist);

	PrintList(linklist);

	while (true){
		int a = menu();
		switch (a)
		{
		case 1:
			PrintList(linklist);
			break;

		case 2:
			InsertHead(linklist);
			PrintList(linklist);
			break;

		case 3:
			InsertEnd(linklist);
			PrintList(linklist);
			break;

		case 4:
			Del(linklist);
			PrintList(linklist);
			break;

		case 5:
			Locate(linklist);
			break;
			
		case 6:
			CreatLink2(linklist2);
			Merge(linklist,linklist2);
			PrintList(linklist);
			 break;

		case 7:
			return 0;

		default:
			printf("未找到选项，操作失败！");
			break;
		}
	}
}