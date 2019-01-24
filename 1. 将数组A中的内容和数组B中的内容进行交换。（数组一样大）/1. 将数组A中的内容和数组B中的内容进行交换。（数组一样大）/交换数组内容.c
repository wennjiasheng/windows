#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


void  swap(int arr1[], int  arr2[], int  sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		
		arr1[i] = arr1[i] ^ arr2[i];
		arr2[i] = arr1[i] ^ arr2[i];
		arr1[i] = arr1[i] ^ arr2[i];
		
	}
}
int main()
{
	int arr1[] = { 1, 2, 3, 4};
	int arr2[] = { 2, 3, 4, 6};
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	swap(arr1, arr2,sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("arr1[%d]=%d", i, arr1[i]);
	}
	for (i = 0; i < sz; i++)
	{
		printf("arr2[%d]=%d", i, arr2[i]);
	}
	system("pause");
	return 0;
}