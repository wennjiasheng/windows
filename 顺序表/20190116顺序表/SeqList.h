//#pragma once
#ifndef _SEQLIST__H_
#define _SEQLIST__H_

#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>




typedef int DataType;


typedef struct SeqList
{
	DataType* _array; 
		int _capacity; 
		int _size; 

}SeqList;



void SeqListInit(SeqList* pc);
void SeqListDestroy(SeqList* pc);
void SeqListPushBack(SeqList* pc, DataType data);
void SeqListPopBack(SeqList* pc);
void SeqListPushFront(SeqList* pc, DataType data);
void SeqListPopFront(SeqList* pc);
void SeqListInsert(SeqList* pc, int pos, DataType datda);
void SeqListErase(SeqList* pc, int pos);
int SeqListFind(SeqList* pc, DataType data);
void SeqListRemove(SeqList* pc, DataType data);
void SeqListRemoveAll(SeqList* ps, DataType data);
int SeqListSize(SeqList* pc);
int SeqListCapacity(SeqList* ppc);
int SeqListEmpty(SeqList* pc);
DataType SeqListFront(SeqList* pc);
DataType SeqListBack(SeqList* pc);
void PrintSeqList(SeqList* pc);




#endif//_SEQLIST__H_