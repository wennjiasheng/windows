#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>



void Is_prime(int i)
{
	int j = 0;
	for (j = 2; j <= i - 1; j++)
	{
		if (i%j == 0)
			break;
	}
	if (j > i - 1)
		printf("%d是素数。\n", i);
	else
		printf("%d不是素数。\n", i);
}
int main()
{
	int i = 0;
	scanf("%d", &i);
	Is_prime(i);
	system("pause");
	return 0;
}