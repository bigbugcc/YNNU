#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"adjgraph.h"

#define True 1
#define False 0
int visited[MAX_VERTEX_NUM];/*���ʱ�־��*/

int FirstAdjVertex(AdjList G, int v0)
{
	int v = -1;
	ArcNode* p;

	p = G.vertex[v0].firstarc;
	if (p)
	{
		//	printf("\n%d  ",p->adjvex);
		v = p->adjvex;
	}
	return v;

}// FirstAdjVertex




int NextAdjVertex(AdjList G, int v0, int w)
{
	int v = -1;
	ArcNode* p;

	p = G.vertex[v0].firstarc;
	while (p != NULL)
	{
		if (p->adjvex != w) { v = p->adjvex; break; }
		else p = p->nextarc;
	}
	return v;
}



void DepthFirstSearch(AdjList G, int v0)
{
	int w;
	//���ʶ���v0�����÷��ʱ�־������Ӧ����ֵ
	printf("%3c", G.vertex[v0].data);
	visited[v0] = True;

	w = FirstAdjVertex(G, v0);
	while (w != -1)//�ڽӵ����
	{
		if (!visited[w])DepthFirstSearch(G, w);//�ݹ����DepthFirstSearch
		w = NextAdjVertex(G, v0, w);//����һ���ڽӵ�
	}
	return;
}//DepthFirstSearch


void DFSTraverseGraph(AdjList G)
{
	int vi;
	for (vi = 0; vi < G.vexnum; vi++)
	{
		visited[vi] = False;
	}//��ʼ�����ʱ�־����

	for (vi = 0; vi < G.vexnum; vi++)
		if (!visited[vi])DepthFirstSearch(G, vi);
}//DFSTraverseGragh

/*
void BreadthFirstSearch(AdjList G,int v0)
//�����������ͼG��v0���ڵ���ͨ��ͼ
{
	int v, w;
	int Queue[MAX_VERTEX_NUM];
	int f,r;
	f=r=-1;

	printf("%3c",G.vertex[v0].data);
	visited[v0]=True;

	r=(r+1)%MAX_VERTEX_NUM;
	Queue[r]=v0;
	while(f!=r)
	{
		f=(f+1)%MAX_VERTEX_NUM;
		v=Queue[f];
		w=FirstAdjVertex(G,v);
		while(w!=-1)
		{
			if(!visited[w])
			{
				printf("%3c",G.vertex[w].data);
				visited[w]=True;
				r=(r+1)%MAX_VERTEX_NUM;
				Queue[r]=w;
			}
			w=NextAdjVertex(G,v,w);
		}
	}
}



void BFSTraversGraph(AdjList G)

{
	int vi;
	for(vi=0;vi<G.vexnum;vi++)
	{
		visited[vi]=False;
	}//��ʼ�����ʱ�־����

	for(vi=0;vi<G.vexnum;vi++)
		if(!visited[vi])BreadthFirstSearch(G,vi);
}//BFSTraverseGragh
*/


