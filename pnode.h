#define _CRT_SECURE_NO_WARNINGS 1

#include<windows.h>
#include <stdio.h>
#include <assert.h>

typedef int DATATYPE;

typedef struct Node
{
	DATATYPE data;
	struct Node *next;
}Node,*PNode;

void InitList(PNode* pHead);
void PushBack(PNode* pHead, DATATYPE data);
void PopBack(PNode* pHead);
void PushFront(PNode* pHead, DATATYPE data);
void PopFront(PNode* pHead);
PNode Find(PNode pHead, DATATYPE data);
void Insert(PNode pos, DATATYPE data);
void Erase(PNode* pHead, PNode pos);			//删除某一个数
void Remove(PNode* pHead, DATATYPE data);
void RemoveAll(PNode* pHead, DATATYPE data);
int Empty(PNode pHead);
void Clear(PNode* pHead);
void Destroy(PNode* pHead);
int Size(PNode pHead);
PNode BuyNode(DATATYPE data);
void PrintList(PNode pHead);
PNode Back(PNode pHead);
////////////////////////////////////////////////////
void ResversePrintList(PNode pHead);
void DeleteNotTailNode(PNode pos);
void InsertNotHeadNode(PNode pos,DATATYPE data);
PNode ResverseList(PNode pHead);					//逆置单链表
void BubbleSort(PNode pHead);						//冒泡排序
PNode MergeList(PNode pHead1 , PNode pHead2);		//合并两个链表
PNode FindMidNode(PNode pHead);						//查找中间结点
PNode FindLastKNode(PNode pHead,int k);				//查找倒数第K个结点
PNode JosephCircle(PNode pHead,int M);				//约瑟夫环问题
PNode ReverseList1(PNode pHead);				//奇数偶数放到一起并逆置
int IsCross(PNode pHead1, PNode pHead2);		//看两个链表是否相交
//若两个链表相交 则尾结点必相交
PNode GetCrossNode(PNode pHead1, PNode pHead2);
PNode HasCircle(PNode pHead);						//判断是否带环
int GetCircleLen(PNode pMeetNode);
PNode GetEnterNode(PNode pHead, PNode pMeetNode);  // 得到环开始的点
int IsCrossWithCircle(PNode pHead1, PNode pHead2); // 在邮件中给出带环可能相交的几种情况
void UnionSet(Node* l1, Node* l2);

