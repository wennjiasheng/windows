//递归和非递归分别实现求n的阶乘
#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>


//int my(int n)
//{
//	if (n == 1)
//		return 1;
//	return n*my(n - 1);
//}
int my(int n)
{
	int i = 0;
	int sum = 1;
	for (i = 1; i <= n; i++)
	{
		sum = sum*i;
	}
	return  sum;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d", my(n));
	system("pause");
	return 0;
}