//
// Created by 莫莫 on 2021/1/27.
//
#include <iostream>
using namespace std;

#define MaxLen 255

//～～～～～～～～～～～～顺序串～～～～～～～～～～～～～～ 
typedef struct
{
	char ch[MaxLen];
	int length;
}SString;

//ch[0]废弃不用，length单独存放

//求子串：用Sub返回串S的第pos个字符起长度为len的子串
bool SubString(SString &Sub,SString S,int pos,int len)
{
	if(pos+len-1 > S.length)  //子串范围越界
	{
		return false;
	}
	for(int i = pos; i < pos+len; i++)
	{
		Sub.ch[i-pos+1] = S.ch[i];
	}
	Sub.length = len;
	return true;
}

//比较: S>T～>0,S=T～=0,S<T～<0
int StrCompare(SString S,SString T)
{
	for(int i = 1;i <= S.length && i <= T.length; i++)
	{
		if(S.ch[i] != T.ch[i])
		{
			return S.ch[i]-T.ch[i];
		}
	}
	return S.length-T.length;
}

//定位: 若主串S中存在与串T值相同的子串，则返回它在主串S中的第一次出现的位置，否则返回0
int Index(SString S,SString T)
{
	int i = 1;
	int n = StrLength(S);
	int m = StrLength(T);
	SString sub;
	while(i <= n-m+1)
	{
		SubString(sub,S,i,m);
		if(StrCompare(sub,T)!=0)
		{
			++i;
		}else{
			return i;
		}	
	}
	return 0;
}

//定位（朴素模式匹配算法一）
/*int Index(SString S,SString T)
{
	int k = 1;
	int i = k, j = 1;
	while(i <= S.length && j <= T.length)
	{
		if(S.ch[i]==T.ch[j])
		{
			++i;
			++j;
		}else{
			k++;
			i = k;
			j = 1;
		}
	}
	if(j>T.length)
	{
		return k;
	}else{
		return 0;
	}
}*/

//定位（朴素模式匹配算法二）
/*int Index(SString S,SString T)
{
	int i = 1, j = 1;
	while(i <= S.length && j <= T.length)
	{
		if(S.ch[i]==T.ch[j])
		{
			++i;
			++j;
		}else{
			i = i-j+2;
			j = 1;
		}
	}
	if(j>T.length)
	{
		return i-T.length;
	}else{
		return 0;
	}
}*/

//定位（KMP算法--优化朴素模式匹配算法）
int Index_KMP(SString S,SString T,int next[])
{
	int i = 1, j = 1;
	while(i <= S.length && j <= T.length)
	{
		if(j==0 || S.ch[i]==T.ch[j])
		{
			++i;
			++j;
		}else{
			j = next[j];
		}
	}
	if(j>T.length)
	{
		return i-T.length;
	}else{
		return 0;
	}
}

//～～～～～～～～～～～～链式串～～～～～～～～～～～～～～
typedef struct StringNode
{
	char ch;
	struct StringNode *next;
}StringNode,*String;

