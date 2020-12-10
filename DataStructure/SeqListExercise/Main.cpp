#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct {
	int data[MAXSIZE];
	int length;
}SeqList;

//初始化表 
void InitList(SeqList *list,SeqList *list2) {
	list->length = 0;
	list2->length = 0;
	printf("初始化表成功！\n");
}

//添加数据
bool CreatList(SeqList *L)
{
	int n;
	printf("请输入顺序表长度:");

	scanf("%d", &n);

	printf("请输入%d个数:", n);


	if (n>0 && n<MAXSIZE) {
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &L->data[i]);

			L->length++;
		}
	}
	else
	{
		printf("====== 参数不合法！=======");
		
		return false;
	}

	
	return true;
}

//暂停方法
void cPause() {
	printf("\n");
	system("pause");
}

//打印元素
void printLists(SeqList *L) {

	printf("当前顺序表所有元素: ");

	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}

	cPause();
}

//菜单
int menu() {
	//清屏
	system("cls");

	int loca;
	printf("=====菜单==== \n");
	printf("1. 查看元素 \n");
	printf("2. 插入元素 \n");
	printf("3. 删除元素 \n");
	printf("4. 查找元素 \n");
	printf("5. 合并顺序表 \n");
	printf("6. 退出程序 \n");
	printf("请输入操作的序号：\n");
	scanf("%d", &loca);

	return loca;
}


//插入元素
void Insert(SeqList* list) {
	int p, v;

	printf("请输入要插入的位置和要插入的数(空格隔开)：\n");

	scanf("%d%d", &p, &v);

	if (list->length>=p&&p>=1) {

		for(int i = list->length-1;i>=p-1;i--)
		{
			list->data[i+1] = list->data[i];
		}
		list->data[p-1] = v;
		list->length++;
		printLists(list);
	}else if(p == list->length+1)
	{
		list->data[p - 1] = v;
		list->length++;
		printLists(list);
	}
	else
	{
		printf("插入位置不合法！");
	}
}


//删除元素
void Delete(SeqList* list) {
	int p;

	printf("请输入要删除的位置：\n");

	scanf("%d", &p);

	if (list->length >= p && p >= 1) {

		for (int i = 0; i<list->length;i++)
		{
			if (i>=p-1) {
				list->data[i] =list->data[i + 1];
			}
		}
		list->length--;
		printLists(list);
	}
	else
	{
		printf("删除位置不合法！");
		cPause();
	}
}

//顺序表2数据添加
bool creatList2(SeqList *list) {
	int n;
	printf("请输入第二个顺序表长度: \n");

	scanf("%d", &n);

	printf("请输入%d个数:", n);


	if (n > 0 && n < MAXSIZE) {
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &list->data[i]);

			list->length++;
		}
	}
	else
	{
		printf("====== 参数不合法！======");

		return false;
	}
	return true;
}

//合并顺序表
void Merge(SeqList *list1,SeqList *list2) {
	if (list1->length>0&&list2->length>0) {
		int len = list1->length + list2->length;

		for (int i = list1->length-1; i< len-1;i++) {
			list1->data[i + 1] = list2->data[len -2 - i];
			list1->length++;
		}
	}
	printLists(list1);
}

//查找元素
void Locate(SeqList *list) {
	if (list!=NULL) {
		printf("请输入元素位置查找元素: ");
		int p;
		scanf("%d",&p);
		if (p<=list->length&&p>0) {
			int va = list->data[p - 1];
			printf("该元素是：%d",va);
			cPause();
		}
		else
		{
			printf("元素下表不合法！");
		}
	}
}

//主方法
int main() {
	int p, v;
	p = v = 0;
	SeqList list;

	SeqList list2;

	//初始化表
	InitList(&list,&list2);

	//添加表的默认元素
	CreatList(&list);

	//打印元素
	printLists(&list);

	while (true)
	{
		int a = menu();
		switch (a)
		{
		    case 1:
				printLists(&list);
			break;

			case 2:
				Insert(&list);
				break;

			case 3:
				Delete(&list);
				break;

			case 4:
				Locate(&list);
				break;

			case 5:
				if (creatList2(&list2)) {
					Merge(&list,&list2);
				}
			case 6:
				return 0;
			default:
				printf("未找到当前选项！重新输入");
				cPause();
				break;
		}
	}
}