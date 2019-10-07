#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"
#include<stdio.h>
#include<stdlib.h>


void HeapCreate(heap *hp, HpDataType * arr, int size)//堆的创建
{
	assert(hp);
	hp->arr = (HpDataType*)malloc(sizeof(HpDataType)*size);
	if (hp->arr == NULL)
	{
		return;
	}
	memcpy(hp->arr, arr, sizeof(HpDataType)*size);
	hp->size = size;
	hp->capacity = size;
	
	for (int root = (size - 2) / 2; root >= 0; root--)
	{
		adjistHeap(hp, size, root);
	}

}

void adjistHeap(heap *hp, int size, int root)//堆的调整
{
	int parent = root;
	int child = 2 * parent + 1;
	HpDataType temp = 0;
	while (child<size)
	{
		if (child + 1 < size&&hp->arr[child] > hp->arr[child + 1])
		{
			child += 1;
		}
		if (hp->arr[parent]>hp->arr[child])
		{
			temp = hp->arr[parent];
			hp->arr[parent] = hp->arr[child];
			hp->arr[child] = temp;
			parent = child;
			child = 2 * parent + 1;

		}
		else
			return;
	}
}
void Heapdestry(heap *hp)//堆的销毁
{
	assert(hp);
	if (hp->arr == NULL)
	{
		return;
	}
	hp->capacity = 0;
	hp->size = 0;
	free(hp->arr);
	hp->arr = NULL;
	return;
}
void Heapinsert(HpDataType arr, heap *hp)//堆的插入数据
{
	assert(hp);
	Addcatacity(hp);
	AddData(arr, hp);
}
void AddData(HpDataType ret, heap *hp)
{
	assert(hp);
	hp->arr[hp->size] = ret;
	hp->size += 1;
}
void Addcatacity(heap *hp)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		hp->arr = (HpDataType *)realloc(hp->arr,sizeof(HpDataType)*(hp->capacity + 2));
		if (hp->arr == NULL)
		{
			printf("增溶失败：>\n");
			return;
		}
		hp->capacity = hp->size + 2;
	}
}
void Heapafterdelete(heap * hp)//堆的最后一个元素的删除
{
	assert(hp);
	if (hp->size == 0)
	{
		return;

	}
	hp->size = hp->size - 1;

}
void Heapfrontdelete(heap * hp)//堆顶元素的删除
{
	HpDataType ret;
	assert(hp);
	if (hp->size == 0)
	{
		return;
	}
	ret = hp->arr[0];
	hp->arr[0] = hp->arr[hp->size - 1];
	hp->arr[hp->size - 1] = ret;
	Heapafterdelete(hp);

}
HpDataType HeapTop(heap *hp)//堆顶元素的获取
{
	assert(hp);
	if (hp->size == 0)
	{
		return 0;
	}
	return hp->arr[0];
}
int HeapEmpty(heap *hp)//检测堆是否为空
{
	assert(hp);
	return hp->size;
}
int HeapSize(heap *hp)//获取堆中有效元素的个数
{
	assert(hp);
	return hp->size;
}
void HeapPrint(heap *hp)//打印函数
{
	assert(hp);
	if (hp->size == 0)
	{
		return;
	}
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->arr[i]);
	}
	printf("\n");
}
void TEST()
{
	heap hp;
	int arr[] = { 1, 6, 4, 5, 9, 8, 7, 3, 0 };
	int ret = sizeof(arr) / sizeof(arr[0]);
	HeapCreate(&hp, arr, ret);

	HeapPrint(&hp);

	Heapinsert(20, &hp);
	HeapPrint(&hp);

	Heapafterdelete(&hp);
	HeapPrint(&hp);

	Heapfrontdelete(&hp);
	HeapPrint(&hp);

	printf("%d \n", HeapTop(&hp));
	if (0 == HeapEmpty(&hp))
	{
		printf("堆为空：>\n");
	}
	else
	{
		printf("堆不为空：>\n");

	}
	printf("堆中有效元素个数：%d \n", HeapSize(&hp));
	HeapPrint(&hp);
	Heapdestry(&hp);//堆的销毁

 }