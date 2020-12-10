#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"adjgraph.h"

#define True 1
#define False 0
int visited[MAX_VERTEX_NUM];/*访问标志组*/

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
	//访问顶点v0，并置访问标志数组相应分量值
	printf("%3c", G.vertex[v0].data);
	visited[v0] = True;

	w = FirstAdjVertex(G, v0);
	while (w != -1)//邻接点存在
	{
		if (!visited[w])DepthFirstSearch(G, w);//递归调用DepthFirstSearch
		w = NextAdjVertex(G, v0, w);//找下一个邻接点
	}
	return;
}//DepthFirstSearch


void DFSTraverseGraph(AdjList G)
{
	int vi;
	for (vi = 0; vi < G.vexnum; vi++)
	{
		visited[vi] = False;
	}//初始化访问标志数组

	for (vi = 0; vi < G.vexnum; vi++)
		if (!visited[vi])DepthFirstSearch(G, vi);
}//DFSTraverseGragh

/*
void BreadthFirstSearch(AdjList G,int v0)
//广度优先搜索图G中v0所在的连通子图
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
	}//初始化访问标志数组

	for(vi=0;vi<G.vexnum;vi++)
		if(!visited[vi])BreadthFirstSearch(G,vi);
}//BFSTraverseGragh
*/


