#define _CRT_SECURE_NO_WARNINGS 1

#include<windows.h>
#include "pnode.h"

void InitList(PNode* pHead)       //初始化
{
	assert(pHead);
	*pHead = NULL;
}

PNode BuyNode(DATATYPE data)	 //创建结点
{
	PNode pTemp = (PNode)malloc(sizeof(Node));
	if (pTemp)
	{
		pTemp->data = data;
		pTemp->next = NULL;
	}
	return pTemp;
}

void PushBack(PNode* pHead, DATATYPE data)		//尾插
{
	assert(pHead);
	if (NULL == *pHead)
	{
		*pHead = BuyNode(data);
	}
	else
	{
		PNode pTailNode = *pHead;
		while (pTailNode->next)
		{
			pTailNode = pTailNode->next;
		}
		pTailNode->next = BuyNode(data);
	}
}

void PopBack(PNode* pHead)						//尾删
{
	assert(pHead);
	if (NULL == *pHead)
	{
		return;
	}
	if (NULL == (*pHead)->next)
	{
		free(*pHead);
		*pHead = NULL;
	}
	else
	{
		PNode pDelNode = *pHead;
		PNode pPreNode = *pHead;
		while (pDelNode->next)
		{
			pPreNode = pDelNode;
		}
	
	free(pDelNode);
	pPreNode->next = NULL;
	}
}

void PushFront(PNode* pHead, DATATYPE data)
{
	PNode pNewNode = NULL;
	assert(pHead);
	pNewNode = BuyNode(data);
	if (pNewNode)
	{
		pNewNode->next = *pHead;
		*pHead = pNewNode;
	}
}

void PopFront(PNode* pHead)
{
	assert(pHead);
	if (*pHead == NULL)
	{
		return;
	}
	else
	{
		PNode pDelNode = *pHead;
		*pHead = (*pHead)->next;
		free(pDelNode);
		pDelNode = NULL;
	}
}

PNode Find(PNode pHead, DATATYPE data)
{
	PNode pCurNode = pHead;
	while (pCurNode)
	{
		if (pCurNode->data == data)
		{
			return pCurNode;
		}
		pCurNode = pCurNode->next;
	}
	return NULL;
}

void Insert(PNode pos, DATATYPE data)
{
	PNode PNewNode = NULL;
	if (NULL == pos)
	{
		return;
	}
	PNewNode = BuyNode(data);
	if (PNewNode)
	{
		PNewNode->next = pos->next;
		pos->next = PNewNode;
	}
}

void Erase(PNode* pHead, PNode pos)			//删除某一个数
{
	assert(pHead);
	if (NULL == pHead && NULL == pos)
	{
		return;
	}
	if (*pHead == pos)
	{
		*pHead = pos->next;
		free(pos);
	}
	else
	{
		PNode pPrePos = *pHead;
		while (pPrePos->next != pos && pPrePos)
		{
			pPrePos = pPrePos->next;
		}
		pPrePos->next = pos->next;
		free(pos);
	}
}

void Remove(PNode* pHead, DATATYPE data)
{
	assert(pHead);
	Erase(pHead,Find(*pHead,data));
}

void RemoveAll(PNode* pHead, DATATYPE data)
{
	PNode node = *pHead;  
	assert(pHead); 
	while (node = Find(*pHead,data))
	{
		Erase(pHead,node);
	}
}

void ResversePrintList(PNode pHead)
{
	if (NULL == pHead)
	{
		return;
	}
	else
	{
		ResversePrintList(pHead->next);
		printf("%d->",pHead->data);
	}
}
void DeleteNotTailNode(PNode pos)
{
	PNode pDelNode = NULL;
	if (NULL == pos||NULL == pos->next)
	{
		return;
	}
	pDelNode = pos->next;
	pos->data = pDelNode->data;
	pos->next = pDelNode->next;
	free(pDelNode);
}
void InsertNotHeadNode(PNode pos,DATATYPE data)
{
	PNode pNewNode = NULL;
	if (pos == NULL)
	{
		return;
	}
	pNewNode = BuyNode(data);
	pNewNode->next = pos->next;
	pos->next = pNewNode;
	pos->data = data;
}
void Clear(PNode* pHead)
{
	assert(pHead);
	(*pHead)->next = NULL;
}

void Destroy(PNode* pHead)
{
	assert(pHead);
	Clear(pHead);
}

int Size(PNode pHead)
{
	DATATYPE count = 0;
	while(pHead->next != NULL)
	{
		pHead = pHead->next;
		count++;
	}
	return count;
}

int Empty(PNode pHead)
{
	if (pHead == NULL)
	{
		return 0;
	}
	else
		return 1;
}


void PrintList(PNode pHead)
{
	while(pHead != NULL)
	{
		printf("%d->",pHead->data);
		pHead = pHead->next;
	}
	printf("NULL\n");
}

PNode JosephCircle(PNode pHead,int M)
{
	int count = M;
	PNode pos = pHead;
	PNode pDel = NULL;
	if (pHead == NULL || M<=0)
	{
		return NULL;
	}
	while (pHead->next != NULL)
	{
		pHead = pHead->next;
	}
	pHead->next = pos;
	pHead = pHead->next;
	while (pos->next != pos)
	{
		M = count;
		while (--M)
		{
			pos = pos->next;
		}
		pDel = pos->next;
		pos->data = pDel->data;
		pos->next = pDel->next;
		free(pDel);
	}
		return pos;
}

PNode ResverseList(PNode pHead)
{
	PNode pPreNode = NULL;
	PNode pNode = NULL;
	PNode pNodeNext = NULL;
	if(NULL == pHead || NULL == pHead->next)
	{
		return pHead;
	}
	pPreNode = pHead;
	pNode = pPreNode->next;
	pNodeNext = pNode->next;
	while(pNodeNext)
	{
		pNode->next = pPreNode;
		pPreNode = pNode;
		pNode = pNodeNext;
		pNodeNext = pNodeNext->next;
	}
	pHead->next = NULL;
	pNode->next = pPreNode;
	return pNode;
}

void BubbleSort(PNode pHead)
{
	PNode pTailNode = NULL;
	PNode prePos = pHead;
	PNode pos = NULL;
	while (pHead != pTailNode)
	{
		prePos = pHead;
		pos = prePos->next;
		while (pos != pTailNode)
		{
			if (prePos->data > pos->data)
			{
				DATATYPE temp = prePos->data;
				prePos->data = pos->data;
				pos->data = temp;
			}
			pos = pos->next;
			prePos = prePos->next;
		}
		pTailNode = prePos;
	}
}

PNode MergeList(PNode pHead1 , PNode pHead2)
{
	PNode pNewHead = NULL;
	PNode PL1 = pHead1;
	PNode PL2 = pHead2;
	PNode pTailNode = NULL;
	if (NULL == pHead1)
	{
		return pHead2;
	}
	if (NULL == pHead2)
	{
		return pHead1;
	}
	if (PL1->data <= PL2->data)
	{
		pNewHead = PL1;
		pTailNode = PL1;
		PL1 = PL1->next;
	}
	if (PL1->data >= PL2->data)
	{
		pNewHead = PL2;
		pTailNode = PL2;
		PL2 = PL2->next;
	}
	while (PL1 && PL2)
	{
		if (PL1->data < PL2->data)
		{
			pTailNode->next = PL1;
			PL1 = PL1->next;
		}
		else
		{
			pTailNode->next = PL2;
			PL2 = PL2->next;
		}
		pTailNode = pTailNode->next;
	}
	if (PL1 == NULL)
	{
		pTailNode = PL2;
	}
	if (PL2 == NULL)
	{
		pTailNode = PL1;
	}
	return pNewHead;
}

PNode FindMidNode(PNode pHead)
{
	PNode pFast = pHead;
	PNode pSlow = pHead;
	while (pFast && pFast->next)
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}

PNode FindLastKNode(PNode pHead,int k)
{
	PNode pFast = pHead;
	PNode pSlow = pHead;
	if (NULL == pHead || k <= 0)
	{
		return NULL;
	}
	while (k--)
	{
		if (NULL == pFast)
		{
			return NULL;
		}
		pFast = pFast->next;
	}
	while (pFast)
	{
		pFast = pFast->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}

PNode ReverseList1(PNode pHead)
{
	PNode PNewHead = NULL;
	PNode PCurNode = pHead;
	PNode PCurNext = pHead;
	if (NULL == pHead || NULL == pHead->next)
	{
		return pHead;
	}
	PCurNext = PCurNode->next;
	while (PCurNext != NULL)
	{
		PCurNode->next = PNewHead;
		PNewHead = PCurNode;
		PCurNode = PCurNext;
		PCurNext = PCurNext->next;
	}
	PCurNode->next = PNewHead;
	PNewHead = PCurNode;
	return PNewHead;
}

PNode Back(PNode pHead)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	while (pHead->next != NULL)
	{
		pHead = pHead->next;
	}
	return pHead;
}

int IsCross(PNode pHead1, PNode pHead2)
{
	PNode PNode1 = pHead1;
	PNode PNode2 = pHead2;
	if (pHead1 == NULL || pHead2 == NULL)
	{
		return 0;
	}
	while (pHead1->next != NULL)
	{
		pHead1 = pHead1->next;
	}
	while (pHead2->next != NULL)
	{
		pHead2 = pHead2->next;
	}
	if (pHead1 == pHead2)
		return 1;
	else
		return 0;

}

PNode GetCrossNode(PNode pHead1, PNode pHead2)
{
	int Node1size = 0;
	int Node2size = 0;
	int step = 0;
	PNode Node1 = pHead1;
	PNode Node2 = pHead2;
	while (NULL != pHead1)
	{
		Node1size++;
		pHead1 = pHead1->next;
	}
	while (NULL != pHead2)
	{
		Node2size++;
		pHead2 = pHead2->next;
	}
	step = Node1size - Node2size;
	if (step > 0)
	{
		while (step--)
		{
			Node1 = Node1->next;
		}
	}
	else
	{
		while (step--)
		{
			Node2 = Node2->next;
		}
	}
	while (Node1 != Node2)
	{
		Node1 = Node1->next;
		Node2 = Node2->next;
	}
	return Node1;
}

PNode HasCircle(PNode pHead)
{
	PNode pFast = pHead;
	PNode pSlow = pHead;
	while (pFast && pFast->next)
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;
		if (pFast == pSlow)
		{
			return pFast;
		}
	}
	return NULL;
}

//获取环的长度 只需环的下一个不是交点即可
int GetCircleLen(PNode pMeetNode)
{
	PNode pCurNode = pMeetNode;
	int count = 1;					//因为没算最后一个结点
	if (NULL == pMeetNode)
	{
		return 0;
	}
	while(pMeetNode != pCurNode->next)
	{
		pCurNode = pCurNode->next;
		count++;
	}
	return count;
}

//假设链表呈6字型 
//环外的长度为L 相交点距离环起点的长度为X 环的整个长度为R 则剩余部分为R-X
//若快的指针以慢速的两倍速度走  则能得到以下等式 2(L+X)=NR+X+L 化简得L+X=NR
//所以得 两个点必会相交 L = NR-X 一定会在交点相交
PNode GetEnterNode(PNode pHead, PNode pMeetNode) 
{
	PNode pH = pHead;
	PNode pM = pMeetNode;
	if(NULL == pHead || NULL == pMeetNode)
	{
		return NULL;
	}
	while (pH != pM)
	{
		pH = pH->next;
		pM = pM->next;
	}
	return pH;
}

int IsCrossWithCircle(PNode pHead1, PNode pHead2)
{
	
	/*第一种情况：两个带环的链表不共用环的入口处。
		交点的解法：则交点则是整个环
    第二种情况：两个带环的链表共用环的入口处
		交点的解法：将环的入口处链接到某一个链表的第一个结点，再求出环的入口处，此时环的入口处则是两个带环的链表的交点处。*/
	PNode PMeetNode1 = HasCircle(pHead1);
	PNode PMeetNode2 = HasCircle(pHead2);
	if (NULL == PMeetNode1 && NULL == PMeetNode2)
	{
		PNode pTailNode1 = pHead1;
		PNode pTailNode2 = pHead2;
		if (NULL == pHead1 || NULL == pHead2)
		{
			return 0;
		}
		while (pTailNode1->next)
		{
			pTailNode1 = pTailNode1->next;
		}
		if (pTailNode1 == pTailNode2)
		{
			return 1;
		}
	}

	if (NULL != PMeetNode1 && NULL != PMeetNode2)
	{
		PNode pCurNode = PMeetNode1;
		while (pCurNode->next != PMeetNode1)
		{
			if (pCurNode == PMeetNode2)
			{
				return 2;
			}
			pCurNode = pCurNode->next;
		}
		if (PMeetNode2 == pCurNode)
		{
			return 2;
		}
		return 0;
	}
	
}

void UnionSet(Node* l1, Node* l2)
{
	
	
}
