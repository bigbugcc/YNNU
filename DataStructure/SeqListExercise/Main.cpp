#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct {
	int data[MAXSIZE];
	int length;
}SeqList;

//��ʼ���� 
void InitList(SeqList *list,SeqList *list2) {
	list->length = 0;
	list2->length = 0;
	printf("��ʼ����ɹ���\n");
}

//�������
bool CreatList(SeqList *L)
{
	int n;
	printf("������˳�����:");

	scanf("%d", &n);

	printf("������%d����:", n);


	if (n>0 && n<MAXSIZE) {
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &L->data[i]);

			L->length++;
		}
	}
	else
	{
		printf("====== �������Ϸ���=======");
		
		return false;
	}

	
	return true;
}

//��ͣ����
void cPause() {
	printf("\n");
	system("pause");
}

//��ӡԪ��
void printLists(SeqList *L) {

	printf("��ǰ˳�������Ԫ��: ");

	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}

	cPause();
}

//�˵�
int menu() {
	//����
	system("cls");

	int loca;
	printf("=====�˵�==== \n");
	printf("1. �鿴Ԫ�� \n");
	printf("2. ����Ԫ�� \n");
	printf("3. ɾ��Ԫ�� \n");
	printf("4. ����Ԫ�� \n");
	printf("5. �ϲ�˳��� \n");
	printf("6. �˳����� \n");
	printf("�������������ţ�\n");
	scanf("%d", &loca);

	return loca;
}


//����Ԫ��
void Insert(SeqList* list) {
	int p, v;

	printf("������Ҫ�����λ�ú�Ҫ�������(�ո����)��\n");

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
		printf("����λ�ò��Ϸ���");
	}
}


//ɾ��Ԫ��
void Delete(SeqList* list) {
	int p;

	printf("������Ҫɾ����λ�ã�\n");

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
		printf("ɾ��λ�ò��Ϸ���");
		cPause();
	}
}

//˳���2�������
bool creatList2(SeqList *list) {
	int n;
	printf("������ڶ���˳�����: \n");

	scanf("%d", &n);

	printf("������%d����:", n);


	if (n > 0 && n < MAXSIZE) {
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &list->data[i]);

			list->length++;
		}
	}
	else
	{
		printf("====== �������Ϸ���======");

		return false;
	}
	return true;
}

//�ϲ�˳���
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

//����Ԫ��
void Locate(SeqList *list) {
	if (list!=NULL) {
		printf("������Ԫ��λ�ò���Ԫ��: ");
		int p;
		scanf("%d",&p);
		if (p<=list->length&&p>0) {
			int va = list->data[p - 1];
			printf("��Ԫ���ǣ�%d",va);
			cPause();
		}
		else
		{
			printf("Ԫ���±��Ϸ���");
		}
	}
}

//������
int main() {
	int p, v;
	p = v = 0;
	SeqList list;

	SeqList list2;

	//��ʼ����
	InitList(&list,&list2);

	//��ӱ��Ĭ��Ԫ��
	CreatList(&list);

	//��ӡԪ��
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
				printf("δ�ҵ���ǰѡ���������");
				cPause();
				break;
		}
	}
}