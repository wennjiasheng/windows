#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	int j = 0;
	int sz = 7;
	for (i = 1; i <= sz; i++)
	{
		for (j = 0; j < (2 * i) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 1; i < sz; i++)
	{
		for (j = 0; j < 2 * (sz - i) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}