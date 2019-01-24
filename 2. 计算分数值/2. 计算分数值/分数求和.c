#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= 100; i += 2)
	{
		j = j + 1 / i;
	}
	for (i = 2; i <= 100; i += 2)
	{
		j = j - 1 / i;
	}
	printf("%d", j);
	system("pause");
	return 0;
}