#define _CRT_SECURE_NO_WARNINGS 1


#pragma once

#include<stdio.h>
#include<assert.h>

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
typedef int HpDataType;
typedef struct heap
{
	HpDataType * arr;
	int capacity;//当前数组中元素个数
	int size;//当前数组中有效元素个数

}heap;

void HeapCreate(heap *hp, HpDataType * arr, int size);//堆的创建
void adjistHeap(heap *hp, int size, int root);//堆的调整
void Heapdestry(heap *hp);//堆的销毁
void Heapinsert(HpDataType arr, heap *hp);//堆的插入数据
void AddData(HpDataType ret, heap *hp);//
void Addcatacity(heap *hp);
void Heapafterdelete(heap * hp);//堆的最后一个元素的删除
void Heapfrontdelete(heap * hp);//堆顶元素的删除
HpDataType HeapTop(heap *hp);//堆顶元素的获取
int HeapEmpty(heap *hp);//检测堆是否为空
int HeapSize(heap *hp);//获取堆中有效元素的个数
void HeapPrint(heap *hp);//打印函数
void TEST();


