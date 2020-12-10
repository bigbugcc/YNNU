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
	//初始化
	printf("输入图的顶点数和弧数,以逗号分隔：");
	scanf("%d,%d", &G->vexnum, &G->arcnum);
	getchar();
	printf("输入顶点信息\n");
	for (i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &G->vertex[i].data);
	}
	getchar();
	for (i = 0; i < G->vexnum; i++)
		G->vertex[i].firstarc = NULL;
	//建立图的邻接表
	printf("请输入图的信息，即输入边的顶点以及权值");
	for (k = 0; k < G->arcnum; k++)
	{
		printf("\n输入弧的顶点v1=");
		scanf("%c", &v1); getchar();
		printf("\n输入弧的顶点v2=");
		scanf("%c", &v2); getchar();
		printf("\n输入弧的权值weight=");
		scanf("%d", &w); getchar();
		//定位
		i = LocateVertex(G, v1);
		j = LocateVertex(G, v2);
		//建立边（弧）结点
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->weight = w;
		//将该结点插入相应的链表中：头部插入
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
	//初始化
	printf("输入图的顶点数和弧数,以逗号分隔：");
	scanf("%d,%d", &G->vexnum, &G->arcnum);
	getchar();
	printf("输入顶点信息\n");
	for (i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &G->vertex[i].data);
	}
	getchar();
	for (i = 0; i < G->vexnum; i++)
		G->vertex[i].firstarc = NULL;
	//建立图的邻接表
	printf("请输入图的信息，即输入边的顶点以及权值");
	for (k = 0; k < G->arcnum; k++)
	{
		printf("\n输入弧的顶点v1=");
		scanf("%c", &v1); getchar();
		printf("\n输入弧的顶点v2=");
		scanf("%c", &v2); getchar();
		printf("\n输入弧的权值weight=");
		scanf("%d", &w); getchar();
		//定位
		i = LocateVertex(G, v1);
		j = LocateVertex(G, v2);
		//建立第一个边（弧）结点
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->weight = w;
		//将该结点插入相应的链表中：头部插入
		p->nextarc = G->vertex[i].firstarc;
		G->vertex[i].firstarc = p;

		//建立第二个边（弧）结点
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->weight = w;
		//将该结点插入相应的链表中：头部插入
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
	printf("输出该图的邻接表:\n");
	OutPutGraph(G);

	system("pause");
	//getch();
	return 0;
}







