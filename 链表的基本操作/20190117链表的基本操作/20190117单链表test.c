#define _CRT_SECURE_NO_WARNINGS


#include "SList.h"


//1. 熟悉链表的结构
//2. 熟悉带头链表与不带头链表的区别
//3. 完成无头单链表的以下操作：
//不带头节点的单链表 
//typedef int SDataType;

// 节点结构 
//typedef struct SListNode
//{
//	SDataType _data;
//	struct SListNode* _pNext;
//}Node;


// 给一个链表结构 
//typedef struct SList
//{
//	Node* _pHead;
//}SList;
//
//
//// 链表的初始化 
//void SListInit(SList* pl);
//
//// 在链表中尾插值为data的节点 
//void SListPushBack(SList* pl, SDataType data);
//
//// 删除链表最后一个节点 
//void SListPopBack(SList* pl);
//
//// 在链表第一个元素前插入值为data的节点 
//void SListPushFront(SList* pl, SDataType data);
//
//// 删除链表中第一个节点 
//void SListPopFront(SList* pl);
//
//// 在链表pos位置后插入置为data的节点 
//void SListInsertAfter(Node* pos, SDataType data);
//
//// 删除链表中值为data的节点 
//void SListErase(SList* pl, Node* pos);
//
//// 在链表中查找值为data的节点，找到返回该节点的地址，否则返回空 
//Node* SListFind(SList* pl, SDataType data);
//
//// 销毁链表 
//void SListDestroy(SList* pl);
//
//// 获取链表中有效节点的个数 
//int SListSize(SList* pl);
//
//// 检测链表是否为空 
//int SListEmpty(SList* pl);
//// 获取链表的第一个节点 
//Node* SListFront(SList* pl);
//
//// 获取链表的第二个节点 
//Node* SListBack(SList* pl);
//
//void SListRemove(SList* pl, SDataType data);
//void SListRemoveAll(SList* pl, SDataType data);

void test1()
{
	SList con;
	SListInit(&con);
	SListPushBack(&con, 1);
	SListPushBack(&con, 2);
	SListPushBack(&con, 3);
	SListPushBack(&con, 4);
	SListPushBack(&con, 5);
	SListPushBack(&con, 6);
	PrintList(&con);
	SListPushFront(&con, 2);
	SListPushFront(&con, 2);
	SListPushFront(&con, 2);
	SListPushFront(&con, 2);
	PrintList(&con);
	SListPopFront(&con);
	PrintList(&con);
	Node*ret = SListFind(&con, 2);
	SListInsertAfter(&con,ret , 6);
	PrintList(&con);
	SListErase(&con, ret);
	PrintList(&con);
	printf("%d \n", SListSize(&con));
	int a = SListEmpty(&con);
	if (a == 1)
		printf("链表不为空：>\n");
	else
		printf("链表为空：>\n");
	SListRemove(&con, 6);
	PrintList(&con);
	SListRemoveAll(&con, 2);
	PrintList(&con);
	SListDestroy(&con);
}
int main()
{
	
	test1();
	system("pause");
	return 0;
}