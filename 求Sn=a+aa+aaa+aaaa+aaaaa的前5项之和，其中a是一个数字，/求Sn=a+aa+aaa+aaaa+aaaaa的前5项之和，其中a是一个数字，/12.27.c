#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


int Fun(int a, int Sn)
{
	int i = 0;
	int sum = 0;
	for (i = 0; i < 5; i++)
	{
		sum = sum* 10 + a;
		Sn = Sn + sum;
	}
	return Sn;
}
int main()
{
	int Sn = 0;
	int a = 0;
	scanf("%d", &a);
	int ret = Fun(a, Sn);
	printf("%d", ret);
	system("pause");
	return 0;
}