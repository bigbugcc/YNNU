#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//#include"adjgraph.h"
#include"visit.cpp"

int  LocateVertex(AdjList* G, char v)
{
	int j = -1;
	int k;
	for (k = 0; k < G->vexnum; k++)
		if (G->vertex[k].data == v)
			return k;
	return j;
}

int CreateDN(AdjList* G)
{
	int i, j, k, w;
	char v1, v2;
	ArcNode* p;
	//��ʼ��
	printf("����ͼ�Ķ������ͻ���,�Զ��ŷָ���");
	scanf("%d,%d", &G->vexnum, &G->arcnum);
	getchar();
	printf("���붥����Ϣ\n");
	for (i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &G->vertex[i].data);
	}
	getchar();
	for (i = 0; i < G->vexnum; i++)
		G->vertex[i].firstarc = NULL;
	//����ͼ���ڽӱ�
	printf("������ͼ����Ϣ��������ߵĶ����Լ�Ȩֵ");
	for (k = 0; k < G->arcnum; k++)
	{
		printf("\n���뻡�Ķ���v1=");
		scanf("%c", &v1); getchar();
		printf("\n���뻡�Ķ���v2=");
		scanf("%c", &v2); getchar();
		printf("\n���뻡��Ȩֵweight=");
		scanf("%d", &w); getchar();
		//��λ
		i = LocateVertex(G, v1);
		j = LocateVertex(G, v2);
		//�����ߣ��������
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->weight = w;
		//���ý�������Ӧ�������У�ͷ������
		p->nextarc = G->vertex[i].firstarc;
		G->vertex[i].firstarc = p;
	}
	return 1;
}
int CreateUDN(AdjList* G)
{
	int i, j, k, w;
	char v1, v2;
	ArcNode* p;
	//��ʼ��
	printf("����ͼ�Ķ������ͻ���,�Զ��ŷָ���");
	scanf("%d,%d", &G->vexnum, &G->arcnum);
	getchar();
	printf("���붥����Ϣ\n");
	for (i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &G->vertex[i].data);
	}
	getchar();
	for (i = 0; i < G->vexnum; i++)
		G->vertex[i].firstarc = NULL;
	//����ͼ���ڽӱ�
	printf("������ͼ����Ϣ��������ߵĶ����Լ�Ȩֵ");
	for (k = 0; k < G->arcnum; k++)
	{
		printf("\n���뻡�Ķ���v1=");
		scanf("%c", &v1); getchar();
		printf("\n���뻡�Ķ���v2=");
		scanf("%c", &v2); getchar();
		printf("\n���뻡��Ȩֵweight=");
		scanf("%d", &w); getchar();
		//��λ
		i = LocateVertex(G, v1);
		j = LocateVertex(G, v2);
		//������һ���ߣ��������
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->weight = w;
		//���ý�������Ӧ�������У�ͷ������
		p->nextarc = G->vertex[i].firstarc;
		G->vertex[i].firstarc = p;

		//�����ڶ����ߣ��������
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->weight = w;
		//���ý�������Ӧ�������У�ͷ������
		p->nextarc = G->vertex[j].firstarc;
		G->vertex[j].firstarc = p;


	}
	return 1;
}

void OutPutGraph(AdjList G)
{
	int i;
	ArcNode* p;

	for (i = 0; i < G.vexnum; i++)
	{
		printf("\n");
		printf("%c", G.vertex[i].data);
		p = G.vertex[i].firstarc;
		while (p != NULL)
		{
			printf("->%3d,%3d", p->adjvex, p->weight);
			p = p->nextarc;
		}
	}
}




int main()
{
	AdjList G;

	//	CreateDN(&G);
	CreateDN(&G);
	printf("�����ͼ���ڽӱ�:\n");
	OutPutGraph(G);

	system("pause");
	//getch();
	return 0;
}







