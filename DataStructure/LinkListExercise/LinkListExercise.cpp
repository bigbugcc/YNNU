#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct Node{

	ElemType data;

	struct Node* next;

}Node,*LinkList;


//��ʼ��
void InitList(LinkList *L1,LinkList *L2) {
	(*L1) = (Node*)malloc(sizeof(Node));
	(*L1)->next = NULL;

	(*L2) = (Node*)malloc(sizeof(Node));
	(*L2)->next = NULL;
}

//��ͣ����
void cPause() {
	printf("\n");
	system("pause");
}

//��ӡ������
void PrintList(LinkList L) {
	int j = 0;
	
	printf("��ǰ����Ԫ��Ϊ��");
	while (L->next != NULL) {
		j++;
		L = L->next;
		printf("%d ", L->data);
	}
	printf("\n��ǰ������Ϊ��%d", j);

	cPause();
}

//����������
bool CreatList(LinkList L)
{
	int n;

	printf("������Ҫ�����ĵ�������:");

	scanf("%d", &n);

	printf("������%d����:", n);


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
		printf("====== �������Ϸ���=======");

		return false;
	}


	return true;
}

//(ͷ��)����
void InsertHead(LinkList L) {

	int v;

	Node *s;

	printf("������Ҫ��ͷ�����������");

	s = (Node*)malloc(sizeof(Node));

	scanf("%d",&s->data);
	
	s->next = L->next;

	L->next = s;

	PrintList(L);
}

//(β��)����
void InsertEnd(LinkList L) {

	Node* s;

	printf("������Ҫ��β�����������");

	s = (Node*)malloc(sizeof(Node));

	s->next = NULL;

	scanf("%d", &s->data);

	while (L->next!=NULL)
	{
		L = L->next;
	}

	L->next = s;
}

//ɾ��Ԫ��
void Del(LinkList L) {
	printf("������Ҫɾ��Ԫ�ص�λ��:");

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

//����Ԫ��
void Locate(LinkList L) {

	printf("������Ҫ����Ԫ�ص�λ�ã�");

	int p;
	scanf("%d",&p);

	int j = 0;
	while (L->next!=NULL)
	{
		j++;
		L = L->next;
		if (j==p) {
			printf("���ҽ��Ϊ��%d",L->data);
			cPause();
			break;
		}
	}

}

//�ϲ�������
void Merge(LinkList L1,LinkList L2) {

	
	while (L1->next!=NULL)
	{
		L1 = L1->next;
	}
	L1->next = L2->next;
}


bool CreatLink2(LinkList L2) {
	int n;

	printf("�����뵥������ĳ���:");

	scanf("%d", &n);

	printf("������%d����:", n);


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
		printf("====== �������Ϸ���=======");

		return false;
	}


	return true;
}

//�˵�
int menu() {
	//����
	system("cls");

	int loca;
	printf("=====�˵�==== \n");
	printf("1. �鿴Ԫ�ؼ������� \n");
	printf("2. ����Ԫ��(ͷ������) \n");
	printf("3. ����Ԫ��(β������) \n");
	printf("4. ɾ��Ԫ�� \n");
	printf("5. ����Ԫ�� \n");
	printf("6. �ϲ������� \n");
	printf("7. �˳����� \n");
	printf("�������������ţ�\n");
	scanf("%d", &loca);

	return loca;
}


int main() {
	LinkList linklist;

	LinkList linklist2;

	//��ʼ��
	InitList(&linklist,&linklist2);

	//��������
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
			printf("δ�ҵ�ѡ�����ʧ�ܣ�");
			break;
		}
	}
}