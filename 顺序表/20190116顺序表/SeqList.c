#define _CRT_SECURE_NO_WARNINGS


#include"SeqList.h"

void SeqListInit(SeqList* pc)
{

	assert(pc);
	pc->_size = 0;
	pc->_array = (DataType *)malloc(3 * sizeof(SeqList));
	if (pc->_array == NULL)
	{
		perror("use malloc");
		return;
	}
	pc->_capacity = 3;

}

void SeqListDestroy(SeqList* pc)
{
	assert(pc);
	pc->_size = 0;
	pc->_capacity = 0;
	free(pc->_array);
	pc->_array = NULL;
}


int CheckSeqList(SeqList* pc)
{
	assert(pc);
	if (pc->_capacity == pc->_size)
	{
		SeqList *str = realloc(pc->_array,
			(pc->_capacity + 3) * sizeof(SeqList));
		if (str == NULL)
		{
			return 0;
		}
		else
		{
			pc->_capacity += 3;
			return 1;
		}
	}
	return 1;
}
void SeqListPushBack(SeqList* pc, DataType data)
{
	assert(pc);
	CheckSeqList(pc);
	pc->_array[pc->_size] = data;
	pc->_size++;
}

void SeqListPopBack(SeqList* pc)
{
	assert(pc);
	pc->_size--;
}

void SeqListPushFront(SeqList* pc, DataType data)
{
	assert(pc);
	int ret = CheckSeqList(pc);
	if (ret == 0)
	{
		return;
	}
	for (int i = pc->_size - 1; i >= 0; i--)
	{
		pc->_array[i+1] = pc->_array[i];
	}
	pc->_array[0] = data;
	pc->_size++;
}

void SeqListPopFront(SeqList* pc)
{
	assert(pc);

	for (int i = 0; i <=pc->_size-1; i++)
	{
		pc->_array[i] = pc->_array[i+1];
	}
	pc->_size--;
}

void SeqListInsert(SeqList* pc, int pos, DataType datda)
{
	assert(pc);
	int ret = CheckSeqList(pc);
	if (ret == 0)
	{
		return;
	}
	for (int i = pc->_size - 1; i>=pos; i--)
	{
		pc->_array[i + 1] = pc->_array[i];
	}
	pc->_array[pos] = datda;
	pc->_size++;
}

void SeqListErase(SeqList* pc, int pos)
{
	assert(pc);

	for (int i = pos; i < pc->_size - 1; i++)
	{
		pc->_array[i] = pc->_array[i + 1];
	}
	pc->_size--;
}

int SeqListFind(SeqList* pc, DataType data)
{
	assert(pc);
	for (int i = 0; i < pc->_size; i++)
	{
		if (pc->_array[i] == data)
		{
			return i;
		}
	}
	return -1;
}

void SeqListRemove(SeqList* pc, DataType data)
{
	assert(pc);
	int pos = SeqListFind(pc, data);
	for (int i = pos; i < pc->_size - 1; i++)
	{
		pc->_array[i] = pc->_array[i + 1];
	}
	pc->_size--;
}


void SeqListRemoveAll(SeqList* pc, DataType data)
{
	assert(pc);
	for (int i = 0; i < pc->_size; i++)
	{
		if (pc->_array[i] == data)
		{
			for (int j = i; i < pc->_size - 1; j++)
			{
				pc->_array[j] = pc->_array[j + 1];
			}
			pc->_size--;
		}
	}
}

int SeqListSize(SeqList* pc)
{
	assert(pc);
	return pc->_size;
}

int SeqListCapacity(SeqList* pc)
{
	assert(pc);
	return pc->_capacity;
}

int SeqListEmpty(SeqList* pc)
{
	assert(pc);
	if (pc->_size == 0)
	{
		return -1;
	}
	return 1;
}

DataType SeqListFront(SeqList* pc)
{
	assert(pc);
	return pc->_array[0];
}

DataType SeqListBack(SeqList* pc)
{
	assert(pc);
	return pc->_array[pc->_size-1];
}

void PrintSeqList(SeqList * pc)
{
	assert(pc);
	for (int i = 0; i < pc->_size; i++)
	{
		printf("%d", pc->_array[i]);
	}
	printf("\n");
}