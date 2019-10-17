#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
	int count = 0;
	int n = 0;
	for (n = 100; n <= 200; n++)
	{
		int i = 0;
		for (i = 2; i <= sqrt(i); i++)
		{
			if (n%i == 0)
				break;
		}
		if (i > sqrt(n))
		{
			printf("%d", n);
			count++;
		}
	}
	printf("count=%d", count);

	return 0;
}