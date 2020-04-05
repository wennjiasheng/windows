#include<iostream>
using namespace std;

void CountSort(int* array, int size)//¼ÆÊıÅÅĞò
{
	int i = 0;
	int a[10];
	int b[20];
	for (i = 0; i < 20; i++)
	{
		b[i] = 0;
	}
	for (i = 0; i < 10; i++)
	{
		b[array[i]] += 1;
	}
	for (i = 1; i < 20; i++)
	{
		b[i] = b[i] + b[i - 1];
	}
	for (i = 9; i >= 0; i--)
	{
		a[b[array[i]] - 1] = array[i];
		b[array[i]] -= 1;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
}


int main()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int size = sizeof(arr);
	CountSort(arr, size);
	system("pause");
	return 0;
}