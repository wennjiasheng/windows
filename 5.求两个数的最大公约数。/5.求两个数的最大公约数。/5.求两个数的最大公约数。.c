#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a = 5;
	int b = 25;
	int c = 0;
	scanf("%d %d", &a, &b);
	while (a%b != 0)
	{
		c = a%b;
		a = b;
		b = c;
	}
	printf("%d", c);
	system("pause");
	return 0;
}
