#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


//1.理解数组指针
//数组指针是指指向数组地址的指针，本质为指针，应注意区分数组指针与指针数组
//指针数组是指数组的元素是指针类型。

//2.理解函数指针和定义
//函数指针包含函数的入口地址，可以通过话术指针来调用函数，把一个函数的地址赋值给
//指针，把这个指针称为函数指针，可以通过这个指针来调用函数
//指针函数是指函数返回的是一个地址值，经常使用在返回数组的某一元素地址


//3.理解函数指针数组和定义，转移表
//函数指针数组是数组，只不过数组的元素是函数指针（指向函数入口地址的指针）；


//4.理解指向函数指针数组的指针和定义
//把函数指针数组的地址赋值给一个指针，把这个指针称为指向函数指针数组的指针，
//本是指针。


//5.理解回调函数的使用
//回调函数是指函数的入口（函数指针）地址作为参数传给别的函数，通过别的函
//数调用实现自己的函数


//6.完成课堂代码和练习。


//7.练习使用qsort函数排序各种类型的数据。


//int cmp(const void *a, const void *b)
//{
//	return(*(int *)a - *(int *)b);//从小到大的顺序排序
////return(*(int *)b - *(int *)a);//从大到小的顺序排序
//}
//int main()
//{
//
//	int arr[1000] ;
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//	for(i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	 qsort(arr, n, sizeof(arr[0]), cmp);
//	 
//	 for (i = 0; i < n; i++)
//	 {
//		 printf("%d", arr[i]);
//	 }
//	system("pause");
//	return 0;
//}
//

//int cmp(const void *a, const void *b)
//{
//	return(*(double *)a > *(double *)b ? 1 : -1);//从小到大的顺序排序
//	//return(*(int *)b - *(int *)a);//从大到小的顺序排序
//}
//
//
//int main()
//{
//
//	double arr[10];
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%f", &arr[i]);
//	}
//	qsort(arr, n, sizeof(arr[0]), cmp);
//
//	for (i = 0; i < n; i++)
//	{
//		printf("%f", arr[i]);
//	}
//	system("pause");
//	return 0;
//}

//8.模仿qsort的功能实现一个通用的冒泡排序。


void my_qsort(int arr[], int n)
{
	//升序
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - 1 - i; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
}
	
int main()
{
	int arr[1000];
	int n = 0;//输入想要输入的个数
	scanf("%d", &n);
	//初始化数组
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	my_qsort(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
	}
	system("pause");
	return 0;
}