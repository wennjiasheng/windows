#pragma once

#include<stdio.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType * array;
	int capacity;
	int  size;

}Heap;

void HeapInit(Heap *hp);
void CreatHeap(Heap* hp,HPDataType arr[],int size);
void Heappush(Heap* hp,HPDataType data);
void Heappop(Heap* hp);
HPDataType Heaptop(Heap* hp);
int Heapsize(Heap *hp);
int  Heapempty(Heap * hp);
void Heapdestroy(Heap * hp);
void Text();

