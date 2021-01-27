//
// Created by 莫莫 on 2021/1/27.
//
#include <iostream>
using namespace std;

#define MaxSize 10
typedef int ElemType;

//～～～～～～～～～～～～顺序队列～～～～～～～～～～～～～～ 
typedef struct
{
	ElemType data[MaxSize];
	int front,rear;   //队头指针和队尾指针
}SqQueue;

void InitQueue(SqQueue &Q)
{
	Q.rear = Q.front = 0;
}

//判断队列是否为空
bool QueueEmpty(SqQueue Q)
{
	if(Q.rear==Q.front)
	{
		return true;
	}else{
		return false;
	}
}

//入队
bool EnQueue(SqQueue &Q,ElemType x)
{
	if((Q.rear+1)%MaxSize==Q.front)  //队满报错（逻辑环状，留一个空位
	{
		return false;
	}
	Q.data[Q.rear] = x;  //将x插入队尾
	Q.rear = (Q.rear +1)%MaxSize;  //队尾指针后移（逻辑环状）
	return true;
}

//出队
bool DeQueue(SqQueue &Q,ElemType &x)
{
	if(Q.rear==Q.front)  //队空报错
	{
		return false;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front+1)%MaxSize;
	return true;
}

//获得队头元素的值，用x返回
bool GetHead(SqQueue &Q,ElemType &x)
{
	if(Q.rear==Q.front)  //队空报错
	{
		return false;
	}
	x = Q.data[Q.front];
	return true;
}

//～～～～～～～～～～～～链式队列～～～～～～～～～～～～～～ 
typedef struct LinkNode
{
	ElemType data;
	struct LinkNode *next;
}LinkNode;

typedef struct
{
	LinkNode *front,*rear;
}LinkQueue;

//初始化（带头）
void InitQueue(LinkQueue &Q)
{
	Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q)
{
	if(Q.front==Q.rear)
	{
		return true;
	}else{
		return false;
	}
}

void EnQueue(LinkQueue &Q,ElemType x)
{
	LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;  //新结点插入到rear之后
	Q.rear = s;
}

bool DeQueue(LinkQueue &Q,ElemType &x)
{
	if(Q.front==Q.rear)  //空队报错
	{
		return false;
	}
	LinkNode *p = Q.front->next;
	x = p->data;
	Q.front->next = p->next;
	if(Q.rear = p)
	{
		Q.rear = Q.front;
	}
	free(p);
	return true;
}

//初始化（不带头）
/*void InitQueue(LinkQueue &Q)
{
	Q.front = NULL;
	Q.rear = NULL;
}

bool IsEmpty(LinkQueue Q)
{
	if(Q.front==NULL)
	{
		return true;
	}else{
		return false;
	}
}

void EnQueue(LinkQueue &Q,ElemType x)
{
	LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	if(Q.front==NULL)
	{
		Q.front = s;
		Q.rear = s;
	}else{
		Q.rear->next = s;
		Q.rear = s;
	}
}

bool DeQueue(LinkQueue &Q,ElemType &x)
{
	if(Q.front==NULL)  //空队报错
	{
		return false;
	}
	LinkQueue *p = Q.front;
	x = p->data;
	Q.front = p->next;
	if(Q.rear = p)
	{
		Q.rear = NULL;
		Q.front = NULL;
	}
	free(p);
	return true;
}
*/

















