//
// Created by 莫莫 on 2021/1/25.
//
#include <iostram>
using namespace std;

#define MaxSize 10
typedef int ElemType;

//～～～～～～～～～～～～顺序栈～～～～～～～～～～～～～～
typedef struct
{
	ElemType data[MaxSize];
	int top;    //栈顶指针
}SqStack;     //sequence--顺序

 void InitStack(SqStack &S)
 {
 	S.top = -1;   //让初始时top指向-1（空栈可通过判断top是否为-1）
 }

 bool Push(SqStack &S,ElemType x)
 {
 	if(S.top == MaxSize -1)  //栈满--报错
 	{
 		return false;
 	}
 	S.top = S.top +1;
 	S.data[S.top] = x;  //S.data[++S.top] = x;
 	return true;
 }

 bool Pop(SqStack &S,ElemType &x)
 {
 	if(S.top == -1)
 	{
 		return false;
 	}
 	x = S.data[S.top];
 	S.top = S.top -1;   //x = S.data[S.top--];
 	return true;
 }

 //读栈顶元素
 bool GetTop(SqStack &S,ElemType &x)
 {
 	if(S.top == -1)
 	{
 		return false;
 	}
 	x = S.data[S.top];
 	return true;
 }
 //销毁只需top=-1，因为声明栈时分配内存，没有malloc，函数运行结束后系统自动回收内存

//～～～～～～～～～～～～共享栈～～～～～～～～～～～～～～
typedef struct
{
	ElemType data[MaxSize];
	int top0;
	int top1;
}ShStack;

void InitStack(ShStack &S)
{
	S.top0 = -1;
	S.top1 = MaxSize;
}

//～～～～～～～～～～～～链栈～～～～～～～～～～～～～～
typedef struct Linknode
{
	ElemType data;
	struct Linknode *next;
}*LiStack;
