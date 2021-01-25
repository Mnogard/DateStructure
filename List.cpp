//
// Created by 莫莫 on 2021/1/25.
//
#include <iostream>
using namespace std;

#define MaxSize 10
typedef int ElemType;

//～～～～～～～～～～～～顺序表～～～～～～～～～～～～～～
typedef struct
{
    ElemType data[MaxSize];
    int length;   //顺序表当前长度
}SqList;     //顺序表类型定义

void InitList(SqList &L)
{
    //for循环可省略
    for(int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }
    L.length = 0;
}

bool ListInsert(SqList &L,int i,ElemType e)
{
    if(i < 1 || i > L.length+1)
    {
        return false;
    }
    if(L.length >= MaxSize)
    {
        return false;
    }

    for(int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L,int i,ElemType &e)
{
    if(i < 1 || i > L.length)
    {
        return false;
    }
    if(L.length == 0)
    {
        return false;
    }
    e = L.data[i-1];
    for(int j = i; j < L.length; j++)
    {
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}

//按位查找（返回值）
ElemType GetElem(SqList &L,int i)
{
    return L.data[i-1];
}

//按值查找(返回位序）
int LocateElem(SqList &L,ElemType e)
{
    for(int i = 0; i < L.length; i++)
    {
        if(L.data[i] == e)
        {
            return i+1;
        }
    }
    return 0;
}

//～～～～～～～～～～～～单链表～～～～～～～～～～～～～～
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//初始化单链表（不带头）
/*bool InitList(LinkList &L)
{
    L = NULL;
    return true;
}*/

//初始化单链表（带头）
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));  //分配一个头节点
    if(L == NULL)
    {
        return false;
    }
    L->next = NULL;  //头节点之后暂时没有节点
    return true;
}

//按位插入（不带头）
/*bool ListInsert(LinkList &L,int i,ElemType e)
{
    if(i<1)
    {
        return false;
    }
    if(i==1)   //插入第一个结点的操作与其他不同
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }
    LNode *p;
    int j = 1;
    p = L;
    while(p != NULL && j<i-1)
    {
        p = p->next;
        j++
    }
    if(p == NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}*/

//按位插入（带头）
bool ListInsert(LinkList &L,int i,ElemType e)
{
    if(i<1)
    {
        return false;
    }
    LNode *p;  //指针p指向当前扫描到的结点
    int j = 0;  //当前p指向的结点位序
    p = L;  //L指向头结点
    while(p != NULL && j < i-1)
    {
        p = p->next;
        j++;
    }
    if(p == NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//指定结点后插
bool InsertNextNode(LNode *p,ElemType e)
{
    if(p==NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s==NULL)
    {
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}


//指定结点前插
bool InsertPriorNode(LNode *p,ElemType e)
{
    if(p==NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s==NULL)
    {
        return false;
    }
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

//按位删除
bool ListDelete(LinkList &L,int i,ElemType &e)
{
    if(i<1)
    {
        return false;
    }
    LNode *p;
    int j = 0;
    p = L;
    while(p != NULL && j<i-1)
    {
        p = p->next;
        j++;
    }
    if(p == NULL)
    {
        return false;
    }
    if(p->next == NULL)
    {
        return false;
    }
    LNode *q = p->next;  //令q指向被删除的结点
    e = q->data;  //用e返回元素的值
    p->next = q->next;  //将*q结点从中断开
    free(q);  //释放q结点的存储空间
    return true;
}

//删除指定点
bool DeleteNode(LNode *p)
{
    if(p==NULL)
    {
        return false;
    }
    LNode *q = p->next;  //先将p的next存在q
    p->data = p->next->data;  //数据前赋
    p->next = q->next;  //q的next赋给p
    free(q);  //释放q
    return true;
}

//按位查找
LNode *GetElem(LinkList L,int i)
{
    if(i<1)
    {
        return NULL;
    }
    LNode *p;  //指针p指向当前扫描到的结点
    int j = 0;  //当前p指向的结点位序
    p = L;  //L指向头结点
    while(p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

//按值查找
LNode *LocateElem(LinkList L,ElemType e)
{
    LNode *p = L->next;
    while(p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}

//单链表的建立--尾插法
LinkList List_TailInsert(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s,*r = L;
    cin >> x;
    while(x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        cin >> x;
    }
    r->next = NULL;
    return L;
}

//单链表的建立--头插法
LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));  //创建头结点
    L->next = NULL;  //初始为空链表
    cin >> x;
    while(x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        cin >> x;
    }
    return L;
}

//求表长
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while(p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

//～～～～～～～～～～～～双链表～～～～～～～～～～～～～～
typedef struct DNode
{
    ElemType data;
    struct DNode *prior,*next;
}DNode,*DLinkList;

//双链表初始化（带头）
bool InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if(L==NULL)
    {
        return false;
    }
    L->prior = NULL;
    L->next = NULL;
    return true;
}

//后插
bool InsertNextDNode(DNode *p,DNode *s)
{
    if(p==NULL || s==NULL)
    {
        return false;
    }
    s->next = p->next;
    if(p->next != NULL)
    {
        p->next->prior = s;
    }
    
    s->prior = p;
    p->next = s;
}

//删除p结点的后继结点
bool DeleteDNode(DNode *p)
{
    if(p==NULL)
    {
        return false;
    }
    DNode *q = p->next;
    if(q==NULL)
    {
        return false;
    }
    p->next = q->next;
    if(q->next != NULL)
    {
        q->next->prior = p;
    }
    free(q);
    return true;
}

//～～～～～～～～～～～～循环单链表～～～～～～～～～～～～～～
typedef struct CLNode
{
    ElemType data;
    struct CLNode *next;
}CLNode,*CLinkList;

bool InitCLinkList(CLinkList &L)
{
    L = (CLNode *)malloc(sizeof(CLNode));
    if(L==NULL)
    {
        return false;
    }
    L->next = L;  //头结点的next指向头结点
    return true;
}

//判断结点p是否为循环单链表的表尾结点
bool isTail(CLinkList L,CLNode *p)
{
    if(p->next==L)
    {
        return true;
    }else{
        return false;
    }
}

//～～～～～～～～～～～～循环双链表～～～～～～～～～～～～～～
typedef struct CDNode
{
    ElemType data;
    struct CDNode *prior,*next;
}CDNode,*CDLinkList;

bool InitCDLinkList(CDLinkList &L)
{
    L = (CDNode *)malloc(sizeof(CDNode));
    if(L==NULL)
    {
        return false;
    }
    L->prior = L;
    L->next = L;
    return true;
}

//～～～～～～～～～～～～静态链表～～～～～～～～～～～～～～
/*struct Node
{
    ElemType data;
    int next;
};

void testSLinkList()
{
    struct Node a[MaxSize];
}*/

//另一种
typedef struct 
{
   ElemType data;
   int next; 
}SLinkList[MaxSize];

//～～～～～～～～～～～～～～～～～～～～～～～～～～～～～～

int main()
{
    SqList L;
    InitList(L);
    ListInsert(L,3,3);

    return 0;
}

