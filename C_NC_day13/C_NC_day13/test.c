#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//1.调整数组使奇数全部都位于偶数前面。
//
//题目：
//
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。

//void my(int arr[], int sz)
//{
//	int i = 0;
//	while (sz>1)
//	{
//		for (i = 0; i < sz - 1; i++)
//		{
//			if (arr[i]%2==0)
//			{
//				int temp = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = temp;
//			}
//		}
//		sz--;
//	}
//}

//void my(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz;
//	int temp = 0;
//	while (left < right)
//	{
//		//查找偶数
//		while ((arr[left] % 2 != 0) && (left<right))
//		{
//			left++;
//		}
//		//查找奇数
//		while ((arr[right] % 2 == 0) && (left<right))
//		{
//			right--;
//		}
//		temp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = temp;
//	}
//}
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	my(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	system("pause");
//	return 0;
//}
//2.
////杨氏矩阵 
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//
//数组：
//1 2 3
//2 3 4
//3 4 5
//
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9

int find(int arr[3][3], int row, int col, int k)
{
	int i;
	int j = col - 1;
	for (i = 0; i <3; i++)
	{
		if (arr[i][j]==k)
		{
			return 1;
		}
		if (arr[i][j>k])
			break;
	}
	if (i >= 3)
	{
		return 0;
	}
	if (arr[i][j - 1] == k)
	{
		return 1;
	}
	else if (arr[i][j - 2] == k)
	{
		return 1;
	}
	else
		return 0;
}

int main()
{
	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int ret = find(arr, 7, 3, 13);
	if (ret == 0)
	{
		printf("不存在:>");
	}
	else
	{
		printf("存在：>");
	}
	system("pause");
	return 0;
}