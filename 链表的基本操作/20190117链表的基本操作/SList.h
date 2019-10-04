#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef int SDataType;

typedef struct SListNode
{
	SDataType _data;
	struct SListNode* _pNext;
}Node;



typedef struct SList
{
	Node* _pHead;
}SList;


void SListInit(SList* pl);
void SListPushBack(SList* pl, SDataType data);
void SListPopBack(SList* pl);
void SListPushFront(SList* pl, SDataType data);
void SListPopFront(SList* pl);
void SListInsertAfter(SList* pl, Node* pos, SDataType data);
void SListErase(SList* pl, Node* pos);
Node* SListFind(SList* pl, SDataType data);
void SListDestroy(SList* pl);
int SListSize(SList* pl);
int SListEmpty(SList* pl);
Node* SListFront(SList* pl);
Node* SListBack(SList* pl);
void SListRemove(SList* pl, SDataType data);
void SListRemoveAll(SList* pl, SDataType data);
void PrintList(SList* pl);
