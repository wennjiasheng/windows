#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>



int fun(int arr[], int a,int sz)
{
	int i = 0;
	int left = 0;
	int right = sz - 1;
	int mid = 0;
	for (i = 0; i < sz; i++)
	{
		 mid = left + (right - left) / 2;
		if (a < arr[mid])
		{
			right = mid - 1;
		}
		else if (a>arr[mid])
		{
			left = mid + 1;
		}
	}
	if (left > right)
		return -1;
	return mid;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a = 7;
	scanf("%d", &a);
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = fun(arr, a,sz);
	printf("%d", ret);
	system("pause");
	return 0;
}
