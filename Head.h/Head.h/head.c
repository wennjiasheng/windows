#include"head.h"
#include<assert.h>
#include<malloc.h>
#include<stdio.h>
#include<string.h>


void Swap(HPDataType* left, HPDataType * right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}
void Checkcapacity(Heap *hp)
{
	assert(hp);
	if (hp->size >= hp->capacity)
	{
		int newcapacity = 2 * hp->capacity;
		HPDataType* temp = (HPDataType *)malloc(sizeof(HPDataType)*newcapacity);
		if (temp == NULL)
		{
			assert(0);
			return;
		}
		memcpy(temp, hp->array, hp->size*sizeof(HPDataType));
		free(hp->array);
		hp->array = temp;
		hp->capacity = newcapacity;
	}
}
void AdjistDown(Heap *hp,int parent)
{
	int child = parent * 2 + 1;
	while (child<hp->size)
	{
		if (child +1 <hp->size && hp->array[child] > hp->array[child + 1])
		{
			child++;
		}
		if (hp->array[child] < hp->array[parent])
		{
			Swap(&hp->array[child], &hp->array[parent]);
			parent = child;
			child = parent * 2+1;
		}
		else
		{
			return;
		}
	}
}
void Adjistup(Heap * hp, int child)
{
	int parent = (child-1)>>1;
	while (child)
	{
		if (hp->array[child] < hp->array[parent])
		{
			Swap(&hp->array[child], &hp->array[parent]);
			child = parent;
			parent = (child - 1) >> 1;
		}
		else
		{
			return;
		}
	}
}
void CreatHeap(Heap* hp, HPDataType arr[], int size)
{
	assert(hp);
	hp->array = (HPDataType *)malloc(sizeof(HPDataType)*size);
	if (hp->array == NULL)
	{
		assert(0);
		return;
	}
	hp->capacity = size;
	memcpy(hp->array, arr, sizeof(HPDataType)*size);
	hp->size = size;

	for (int root = (size - 2) / 2; root >= 0; root--)
	{
		AdjistDown(hp, root);
	}
}
void Heappush(Heap* hp, HPDataType data)
{
	assert(hp);
	Checkcapacity(hp);
	hp->array[hp->size++] = data;
	Adjistup(hp, hp->size - 1);
}
void Heappop(Heap* hp)
{
	assert(hp);
	if (Heapempty(hp))
	{
		return;
	}
	Swap(&hp->array[0], &hp->array[hp->size-1]);
	hp->size--;
	AdjistDown(hp, 0);
}
HPDataType Heaptop(Heap* hp)
{
	assert(hp && !Heapempty(hp));
	return hp->array[0];
}
int Heapsize(Heap *hp)
{
	assert(hp);
	return hp->size;
}
int  Heapempty(Heap * hp)
{
	assert(hp);
	return hp->size == 0 ? 1 : 0;
}
void Heapdestroy(Heap * hp)
{
	assert(hp);
	if (hp->array)
	{
		free(hp->array);
		hp->array = NULL;
		hp->size = 0;
		hp->capacity = 0;
	}
}
void Text()
{
	int array[] = { 5, 3, 8, 4, 2, 7, 6, 10 };
	Heap hp;
	CreatHeap(&hp, array, sizeof(array) / sizeof(array[0]));
	printf("Heapsize = %d\n", Heapsize(&hp));
	printf("Heaptop = %d\n", Heaptop(&hp));
	Heappush(&hp, 0);
	printf("Heapsize = %d\n", Heapsize(&hp));
	printf("Heaptop = %d\n", Heaptop(&hp));
	Heappush(&hp,11);
	printf("Heapsize = %d\n", Heapsize(&hp));
	printf("Heaptop = %d\n", Heaptop(&hp));
	Heappop(&hp);
	printf("Heapsize = %d\n", Heapsize(&hp));
	printf("Heaptop = %d\n", Heaptop(&hp));
	Heapdestroy(&hp);
}
