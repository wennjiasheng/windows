#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int i = 10;
	int j = 120;
	i = i^j;
	j = i^j;
	i = i^j;
	printf("j=%d i=%d", i, j);
	system("pause");
	return 0;
}