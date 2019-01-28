#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	if (a < b)
	{
		a = a^b;
		b = a^b;
		a = a^b;
	}
	if (a < c)
	{
		a = a^c;
		c = a^c;
		a = a^c;
	}
	if (b < c)
	{
		b = b^c;
		c = b^c;
		b = b^c;
	}
	printf("%d%d%d", a, b, c);
	system("pause");
	return 0;
}