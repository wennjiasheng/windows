#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int Numberof1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (flag &n)
			count++;
		flag = flag << 1;
	}
	return count;
	
}
int Numberof2(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (n)
	{
		if (flag &n)
			count++;
		n = n >> 1;
	}
	return count;
}
int Numberof3(int n)
{
	int count = 0;
	while (n)
	{
		
		count++;
		n = (n - 1)&n;
	}
	return count;
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", Numberof3(n));
	printf("%d\n", Numberof2(n));
	printf("%d\n", Numberof1(n));
	system("pause");
	return 0;
}