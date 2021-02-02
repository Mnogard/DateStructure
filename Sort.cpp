//
// Created by 莫莫 on 2021/2/1.
//
#include <iostream>
using namespace std;

//～～～～～～～～～～～～插入排序～～～～～～～～～～～～

//直接插入排序
void InsertSort(int A[],int n)  //一个n个数据的数组A
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		if(A[i]<A[i-1])
		{
			temp = A[i];
			for(j=i-1;j>=0 && A[j]>temp;j--)
			{
				A[j+1] = A[j];
			}
			A[j+1] = temp;
		}
	}
}

//直接插入排序（带哨兵）
void InsertSortS(int A[],int n)
{
	int i,j;
	for(i=2;i<=n;i++)
	{
		if(A[i]<A[i-1])
		{
			A[0] = A[i];
			for(j=i-1;A[0]<A[j];j--)
			{
				A[j+1] = A[j];
			}
			A[j+1] = A[0];
		}
	}
}

//直接插入排序--折半插入（带哨兵）
void InsertSortZ(int A[],int n)
{
	int i,j,low,high,mid;
	for(i=2;i<=n;i++)
	{
		A[0] = A[i];
		low = 1;high = i-1;
		while(low<=high)
		{
			mid = (low+high)/2;
			if(A[mid]>A[0])
			{
				high = mid-1;
			}else{
				low = mid+1;
			}
		}
		for(j=i-1;j>=high+1;j--)
		{
			A[j+1] = A[j];
		}
		A[high+1] = A[0];
	}
}

//希尔排序（不稳定，仅适用于顺序表）
void ShellSort(int A[],int n)
{
	int d,i,j;
	//A[0]只是暂存单元，不是哨兵，当j<=0时，插入位置已到
	for(d=n/2;d>=1;d=d/2)
	{
		for(i=d+1;i<=n;i++)
		{
			if(A[i]<A[i-d])
			{
				A[0] = A[i];
				for(j=i-d;j>0 && A[0]<A[j];j-=d)
				{
					A[j+d] = A[j];
				}
				A[j+d] = A[0];
			}
		}
	}
}

//～～～～～～～～～～～～交换排序～～～～～～～～～～～～

//冒泡排序
void BubbleSort(int A[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		bool flag = false;
		for(int j=n-1;j>i;j--)
		{
			if(A[j-1]>A[j])
			{
				int temp = A[j-1];
				A[j-1] = A[j];
				A[j] = temp;
				flag = true;
			}
		}
		if(flag==false)
		{
			return;
		}
	}
}

//快速排序（不稳定）

int Partition(int A[],int low,int high)  //用第一个元素将待排序序列划分成左右两部分
{
	int pivot = A[low];   //第一个元素作为枢轴
	while(low<high)
	{
		while(low<high && A[high]>=pivot)
		{
			high--;
		}
		A[low] = A[high];   //比枢轴小的元素移动到左端
		while(low<high && A[low]<=pivot)
		{
			low++;
		}
		A[high] = A[low];  //比枢轴大的元素移动到右端
	}
	A[low] = pivot;
	return low;
}

void QuickSort(int A[],int low,int high)
{
	if(low<high)   //递归跳出的条件
	{
		int pivotpos = Partition(A,low,high);  //划分
		QuickSort(A,low,pivotpos-1);  //划分左子表
		QuickSort(A,pivotpos+1,high);  //划分右子表
	}
}




























