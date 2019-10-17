#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
	int count = 0;
	int i = 0;
	for (i = 100; i <= 200; i++)
	{
		int j = 0;
		for (j = 2; j <= sqrt[i]; j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (j > sqrt[i])
		{
			printf("%d", i);
			count++;
		}
	}
	printf("count=%d", count);

	return 0;
}