#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	for (i = 100; i < 1000; i++)
	{
		int sum = 0;
		int tem = i;
		while (tem)
		{
			sum = sum + (tem%10)^3;
			tem =tem/10;
		}
		if (sum==i)
			printf("%d", i);
	}
	system("pause");
	return 0;
}