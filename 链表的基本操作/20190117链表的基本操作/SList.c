#define _CRT_SECURE_NO_WARNINGS

#include "SList.h"

// 链表的初始化 
void SListInit(SList* pl)
{
	assert(pl);
	
	pl->_pHead = NULL;
}


Node* BuyListNode(SDataType data)
{
	Node* PNode = (Node*)malloc(sizeof(Node));
	if (NULL == PNode)
	{
		perror("use malloc");
		return NULL;
	}
	PNode->_data = data;
	PNode->_pNext = NULL;
	return PNode;
}
// 在链表中尾插值为data的节点 
void SListPushBack(SList* pl, SDataType data)
{
	Node *Pcur = NULL;
	assert(pl);

	if (pl->_pHead == NULL)
	{
		pl->_pHead = BuyListNode(data);
	}
	else
	{
		Pcur = pl->_pHead;
		while (Pcur->_pNext)
		{
			Pcur = Pcur->_pNext;
		}
		Pcur->_pNext = BuyListNode(data);
	}

}

// 删除链表最后一个节点 
void SListPopBack(SList* pl)
{
	Node* Pcur = NULL;
	assert(pl);
	Pcur = pl->_pHead;
	if (pl->_pHead == NULL)
	{
		return;
	}
	if (pl->_pHead->_pNext == NULL)
	{
		free(pl->_pHead);
		pl->_pHead = NULL;
	}
	else
	{
		while (pl->_pHead->_pNext->_pNext)
		{
			Pcur = Pcur->_pNext;
		}
		free(Pcur->_pNext);
		Pcur->_pNext = NULL;
	}
}

// 在链表第一个元素前插入值为data的节点 
void SListPushFront(SList* pl, SDataType data)
{
	Node*NewData = NULL;
	assert(pl);
	NewData = BuyListNode(data);
	NewData->_pNext = pl->_pHead;
	pl->_pHead = NewData;
}

// 删除链表中第一个节点 
void SListPopFront(SList* pl)
{
	Node* Pcur = NULL;
	assert(pl);
	if(NULL == pl->_pHead)
	{
		return;
	}
	else
	{
		Pcur = pl->_pHead;
		pl->_pHead = Pcur->_pNext;
		free(Pcur);
		Pcur = NULL;
	}
}


// 在链表pos位置后插入置为data的节点 
void SListInsertAfter(SList* pl,Node* pos, SDataType data)
{
	Node*NewData = BuyListNode(data);
	Node* Pcur = NULL;
	assert(pl);
	assert(pos);
	if (pos == NULL)
	{
		return;
	}
	Pcur = pos->_pNext;

	pos->_pNext = NewData;
	pos->_pNext->_pNext = Pcur;
}

// 删除链表中值为data的节点 
void SListErase(SList* pl, Node* pos)
{
	Node *pcur = NULL;
	assert(pl);
	assert(pos);
	if (pl->_pHead == NULL || pos == NULL)
	{
		return;
	}
	if (pos == pl->_pHead)
	{
		pl->_pHead = pos->_pNext;
		free(pos);
		pos = NULL;
		return;
	}
	pcur = pl->_pHead;
	while (pcur->_pNext != pos)
	{
		pcur = pcur->_pNext;
	}
	pcur->_pNext = pos->_pNext;
	free(pos);
	pos = NULL;
}

// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回空 
Node* SListFind(SList* pl, SDataType data)
{
	Node * cur = NULL;
	assert(pl);
	cur = pl->_pHead;
	while (cur->_data != data &&cur != NULL)
	{
		cur = cur->_pNext;
	}
	return cur;
}

// 销毁链表 
void SListDestroy(SList* pl)
{
	Node *pcur = NULL;
	assert(pl);
	pcur = pl->_pHead;
	while (pcur)
	{
		pl->_pHead = pcur->_pNext;
		free(pcur);
		pcur = pl->_pHead;
	}
	pl->_pHead = NULL;
}

// 获取链表中有效节点的个数 
int SListSize(SList* pl)
{
	Node *pcur = NULL;
	assert(pl);
	int count = 0;
	while (pcur)
	{
		count++;
		pcur = pcur->_pNext;
	}
	return count;
}

// 检测链表是否为空 
int SListEmpty(SList* pl)
{
	assert(pl);
	if (NULL!= pl->_pHead) 
	{
		return 1;
	}
	return 0;
}

// 获取链表的第一个节点 
Node* SListFront(SList* pl)
{
	assert(pl);
	return pl->_pHead;
}

// 获取链表的最后一个节点 
Node* SListBack(SList* pl)
{
	Node* pcur = NULL;
	assert(pl);
	pcur = pl->_pHead;
	while (pcur->_pNext)
	{
		pcur = pcur->_pNext;
	}
	return pcur;
}

void SListRemove(SList* pl, SDataType data)
{
	assert(pl);
	if (pl == NULL)
	{
		printf("链表为空：>");
	}
	Node *ret = SListFind( pl,  data);
	if (NULL == ret)
	{
		return;
	}
	SListErase(pl,ret);
}
void SListRemoveAll(SList* pl, SDataType data)
{
	Node* pcur = NULL;
	Node *next = NULL;
	assert(pl);
	if (pl == NULL)
	{
		printf("链表为空：>");
	}
	next = pl->_pHead;
	while (next->_pNext)
	{
		if (next->_pNext->_data == data)
		{
			pcur = next->_pNext;
			next->_pNext = next->_pNext->_pNext;
			free(pcur);
			continue;
		}
		next = next->_pNext;
	}
	if (pl->_pHead->_data == data)
	{
		pcur = pl->_pHead;
		pl->_pHead = pcur->_pNext;
		free(pcur);
	}
	if (next->_data == data)
	{
		SListPopBack(pl);
	}
}

void PrintList(SList* pl)
{
	Node *pcur = NULL;
	assert(pl);
	pcur = pl->_pHead;
	while (pcur)
	{
		printf("%d---> ", pcur->_data);
		pcur = pcur->_pNext;
	}
	printf("NULL\n");
}


