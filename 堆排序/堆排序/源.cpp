#include<iostream>

using namespace std;

/*
void Adjistdown(int array[],int size,int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size&&array[child] > array[child + 1])
		{
			child += 1;
		}
		if (array[child] < array[parent])
		{
			int temp = array[parent];
			array[parent] = array[child];
			array[child] = temp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

void heapsort(int array[],int size)
{
	for (int root = (size - 2) >> 1; root >= 0; root--)
	{
		Adjistdown(array, size, root);
	}
	int end = size - 1;
	while (end)
	{
		int temp = array[end];
		array[end] = array[0];
		array[0] = temp;		
		Adjistdown(array, end, 0);
		end--;
		
	}
}
*/

void qsort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i-1; j++)
		{
			if (array[j]<array[j+1])
			{
				swap(array[j], array[j + 1]);
			}
		}
	}
}
int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 6, 8, 9 };
	qsort(array, sizeof(array) / sizeof(array[0]));
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", array[i]);
	}
	system("pause");
	return 0;
}

