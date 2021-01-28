//
// Created by 莫莫 on 2021/1/28.
//
/*
先序遍历：根--左--右
中序遍历：左--根--右
后序遍历：左--右--根
*/

#include <iostream>
using namespace std;

#define MaxSize 100
typedef int ElemType;

//～～～～～～～～～～～～顺序二叉树～～～～～～～～～～～～
struct TreeNode
{
	ElemType value;  //结点中的数据
	bool isEmpty;    //结点是否为空
};
TreeNode t[MaxSize];

//～～～～～～～～～～～～链式二叉树(二叉树结点）～～～～～～～～～～～～
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild,*rchild;
	struct BiTNode *parent;   //父结点指针
}BiTNode,*BiTree;

//先序遍历
void PreOrder(BiTree T)
{
	if(T!=NULL)
	{
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

//中序遍历
void IneOrder(BiTree T)
{
	if(T!=NULL)
	{
		PreOrder(T->lchild);
		visit(T);
		PreOrder(T->rchild);
	}
}

//后序遍历
void PostOrder(BiTree T)
{
	if(T!=NULL)
	{
		PreOrder(T->lchild);
		PreOrder(T->rchild);
		visit(T);
	}
}

//～～～～～～～～～～～～链式二叉树(链式队列结点）～～～～～～～～～～～～
//链式队列结点
typedef struct LinkNode
{
	BiTNode *data;  //只需要保存指针
	struct LinkNode *next;
}LinkNode;

typedef struct
{
	LinkNode *front,*rear;
}LinkQueue;

/*层序遍历
1.初始化一个辅助队列
2.根结点入队
3.若队列非空，则队头结点出队，访问该结点，并将其左右孩子插入队尾
4.重复3直到队列空
*/
void LevelOrder(BiTree T)
{
	LinkQueue Q;
	InitQueue(Q);
	BiTree p;
	EnQueue(Q,T);
	while(!isEmpty(Q))
	{
		DeQueue(Q,p);
		visit(p);
		if(p->lchild!=NULL)
		{
			EnQueue(Q,p->lchild);
		}
		if(p->rchild!=NULL)
		{
			EnQueue(Q,p->rchild);
		}
	}
}


































