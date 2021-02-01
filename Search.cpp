//
// Created by 莫莫 on 2021/2/1.
//
//
#include <iostream>
using namespace std;

typedef int ElemType;


//～～～～～～～～～～顺序查找（线性查找）～～～～～～～～～～

typedef struct    //查找表的数据结构--顺序表
{
	ElemType *elem;   //动态数组基址
	int TableLen;    //表长
}SSTable;

//顺序查找
int Search_Seq(SSTable ST,ElemType key)
{
	int i;
	for(i=0; i<ST.TableLen && ST.elem[i]!=key;i++);
	return i==ST.TableLen? -1:i;  //查找成功返回下标，否则返回-1
}

//顺序查找（哨兵）
/*int Search_Seq(SSTable ST,ElemType key)
{
	ST.elem[0] = key;   //哨兵
	int i;
	for(i=ST.TableLen; ST.elem[i]!=key; i--);  //从后往前
	return i;  //查找成功返回下标，失败返回0
}*/


//～～～～～～～～～～折半(二分)查找（有序顺序表）～～～～～～～～～～

int Binary_Search(SSTable L,ElemType key)
{
	int low = 0, high = L.TableLen-1, mid;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(L.elem[mid]==key)
		{
			return mid;
		}else if(L.elem[mid]>key){
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
	return -1;
}


//～～～～～～～～～～分块查找(索引顺序查找）～～～～～～～～～～

typedef struct 
{
	ElemType maxValue;
	int low,high;
}Index;

//顺序表存储实际元素
ElemType List[100];

//～～～～～～～～～～二分查找树 BST～～～～～～～～～～

typedef struct BSTNode
{
	int key;
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

//～～～～～～～～～～哈希表(散列表)～～～～～～～～～～
/*

除留余数法：H(key) = key % 13

处理冲突：
1. 拉链法
2. 开放定址法：Hi = (H (key) + di) % m   //di增量序列  m散列表表长
     
*/
