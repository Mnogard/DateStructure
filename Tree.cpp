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
#define Max_Tree_Size 100
typedef int ElemType;

ThreadNode *pre = NULL;

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
void InOrder(BiTree T)
{
	if(T!=NULL)
	{
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}

//后序遍历
void PostOrder(BiTree T)
{
	if(T!=NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
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

//～～～～～～～～～～～～线索二叉树(线索链表）～～～～～～～～～～～～
typedef struct ThreadNode 
{
	ElemType data;
	struct ThreadNode *lchild,*rchild;
	int ltag,rtag;   //tag=0:指针指向孩子  tag=1:指针指向线索
}ThreadNode,*ThreadTree;

/*void visit(BiTNode *q)
{
	if(q==p)
	{
		final = pre;
	}else{
		pre = q;
	}
}*/

//中序线索化二叉树T
void CreateInThread(ThreadTree T)
{
	pre = NULL;
	if(T!=NULL)
	{
		InThread(T);
		if(pre->rchild==NULL)
		{
			pre->rtag = 1;
		}
	}
}

//中序遍历（一边遍历一边线索化）
void InThread(ThreadTree T)
{
	if(T!=NULL)
	{
		InThread(T->lchild);
		visit(T);
		InThread(T->rchild);
	}
}

void visit(ThreadNode *q)
{
	if(q->lchild==NULL)
	{
		q->lchild = pre;
		q->ltag = 1;
	}
	if(pre!=NULL && pre->rchild==NULL)
	{
		pre->rchild = q;
		pre->rtag = 1;
	}
	pre = q;
}

//先序线索化二叉树T
void CreatePreThread(ThreadTree T)
{
	pre = NULL;
	if(T!=NULL)
	{
		PreThread(T);
		if(pre->rchild==NULL)
		{
			pre->rtag = 1;
		}
	}
}

//先序遍历（一边遍历一边线索化）
void PreThread(ThreadTree T)
{
	if(T!=NULL)
	{
		visit(T);
		if(T->ltag==0)   //lchild不是前驱线索
		{
			InThread(T->lchild);
		}
		InThread(T->rchild);
	}
}

//后序线索化二叉树T
void CreatePostThread(ThreadTree T)
{
	pre = NULL;
	if(T!=NULL)
	{
		PostThread(T);
		if(pre->rchild==NULL)
		{
			pre->rtag = 1;
		}
	}
}

//后序遍历（一边遍历一边线索化）
void PostThread(ThreadTree T)
{
	if(T!=NULL)
	{
		InThread(T->lchild);
		InThread(T->rchild);
		visit(T);
	}
}

//--------中序线索二叉树找中序后继

//找到以p为根的子树中，第一个被中序遍历的结点
ThreadNode *Firstnode(ThreadNode *p)
{
	while(p->ltag==0)
	{
		p = p->lchild;
	}
	return p;
}

//在中序线索二叉树中找到p的后继结点
ThreadNode *Nextnode(ThreadNode *p)
{
	if(p->rtag==0)
	{
		return Firstnode(p->rchild);
	}else{
		return p->rchild;
	}
}

//对中序线索二叉树进行中序遍历（利用线索实现的非递归算法）
void Inorder(ThreadNode *T)
{
	for(ThreadNode *p=Firstnode(T);p!=NULL;p=Nextnode(p))
	{
		visit(p);
	}
}

//---------中序线索二叉树找中序前驱

//找到以p为根的子树中，最后一个被中序遍历的结点
ThreadNode *Lastnode(ThreadNode *p)
{
	while(p->rtag==0)
	{
		p = p->rchild;
	}
	return p;
}

//在中序线索二叉树中找到p的前驱结点
ThreadNode *Prenode(ThreadNode *p)
{
	if(p->ltag==0)
	{
		return Lastnode(p->lchild);
	}else{
		return p->lchild;
	}
}

//对中序线索二叉树进行中序遍历（利用线索实现的非递归算法）
void Inorder(ThreadNode *T)
{
	for(ThreadNode *p=Lastnode(T);p!=NULL;p=Prenode(p))
	{
		visit(p);
	}
}

//～～～～～～～～～～～～树～～～～～～～～～～～～

//双亲表示法
typedef struct   //树的结点定义
{
	ElemType data;
	int parent;  //双亲位置域
}PTNode;

typedef struct   //树的类型定义
{
	PTNode nodes[Max_Tree_Size];  //双亲表示
	int n;   //结点数
}PTree;

//孩子表示法(顺序+链式存储)
struct CTNode
{
	int child;  //孩子结点在数组中的位置
	struct CTNode *next;   //下一个孩子
};

typedef struct 
{
	ElemType data;
	struct CTNode *fisrtChild;  //第一个孩子
}CTBox;

typedef struct 
{
	CTBox nodes[Max_Tree_Size];
	int n,r;  //结点数和根位置
}CTree;

//孩子兄弟表示法（链式存储）
typedef struct CSNode
{
	ElemType data;
	struct CSNode *firstchild,*nextsibling;  //第一个孩子和右兄弟指针
}CSNode,*CSTree;




























