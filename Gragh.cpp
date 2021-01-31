//
// Created by 莫莫 on 2021/1/30.
//

#include <iostream>
using namespace std;
#include <climits>

#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;
typedef int InfoType;

//～～～～～～～～～～～图的存储（邻接矩阵法）～～～～～～～～～～～
typedef struct 
{
	VertexType Vex[MaxVertexNum];   //顶点表
	EdgeType Edge[MaxVertexNum][MaxVertexNum];   //邻接矩阵（边表）
	int vexnum,arcnum;    //当前顶点数和边数（弧数）
}MGraph;

//～～～～～～～～～～～带权图的存储（邻接矩阵法）～～～～～～～～～～～
/*typedef struct   //只需将Edge设为权值，无连边设置为∞，自连0
{
	VertexType Vex[MaxVertexNum];
	EdgeType Edge[MaxVertexNum][MaxVertexNum];
	int vexnum,arcnum;
}MGraph;*/

//～～～～～～～～～～～图的存储（邻接表法）～～～～～～～～～～～
typedef struct ArcNode  //边
{
	int adjvex;   //边/弧指向的结点
	struct ArcNode *next;  //指向下一条弧的指针
	InfoType info;   //边权值
}ArcNode;

typedef struct VNode  //点
{
	VertexType data;  //顶点
	ArcNode *first;  //第一条边/弧
}VNode,AdjList[MaxVertexNum];

typedef struct   //图
{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;

//～～～～～～～～～～～图的遍历～～～～～～～～～～～
bool visited[MaxVertexNum];  //标记数组，初始为false
int TRUE = 1;
int FALSE = 0;

//查找不连通的Graph顶点
void BFSTraverse(Graph G)
{
	for(int i=0;i<G.vexnum;i++)
	{
		visited[i]=FALSE;
	}
	InitQueue(Q);
	for(int i=0;i<G.vexnum;i++)
	{
		if(!visited[i])
		{
			BFS(G,i);
		}
	}
}

//广度优先遍历BFS
void BFS(Graph G,int v)  //从顶点v出发遍历
{
	visit(v);
	visited[v] = TRUE;
	Enqueue(Q,v);
	while(!isEmpty(Q))  //初始化辅助队列Q
	{
		DeQueue(Q,v);
		for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
		{
			if(!visited[w])
			{
				visit(w);
				visited[w]=TRUE;
				EnQueue(Q,w);
			}
		}
	}
}

//查找不连通的Graph顶点
void DFSTraverse(Graph G)
{
	for(int i=0;i<G.vexnum;i++)
	{
		visited[i]=FALSE;
	}
	for(int i=0;i<G.vexnum;i++)
	{
		if(!visited[i])
		{
			DFS(G,i);
		}
	}
}

//深度优先遍历DFS
void DFS(Graph G,int v)
{
	visit(v);
	visited[v] = TRUE;
	for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
	{
		if(!visited[w])
		{
			DFS(G,w);
		}
	}
}

//～～～～～～～～～～～最小生成树～～～～～～～～～～～
/*
Prim算法(普里姆)--适合边稠密:
从某一个顶点开始构建生成树,每次将代价最小的新顶点纳入生成树,直到所有顶点都纳入为止

Kruskal算法(克鲁斯卡尔)--适合边稀疏:
每次选择一条权值最小的边,使这条边的两头连通(原本已经连通的就不选),直到所有结点都连通
*/

//～～～～～～～～～～～最短路径～～～～～～～～～～～
//BFS求无权图的单源最短路径
void BFS_MIN_Distance(Graph G,int u)  //从顶点v出发遍历
{
	//d[i]表示从u到i结点的最短路径
	for(int i=0;i<G.vexnum;i++)
	{
		d[i] = ∞;   //初始化路径长度
		path[i] = -1   //确定最短路径指向的顶点
	}
	d[u] = 0;
	visited[u] = TRUE;
	Enqueue(Q,u);
	while(!isEmpty(Q))
	{
		DeQueue(Q,u);
		for(w=FirstNeighbor(G,u);w>=0;w=NextNeighbor(G,u,w))
		{
			if(!visited[w])
			{
				d[w] = d[u]+1;  //路径长度加1
				path[w] = u;  //最短路径为u到w
				visited[w] = TRUE;
				EnQueue(Q,w);
			}
		}
	}
}

//顶点间最短路径--Floyd算法

























