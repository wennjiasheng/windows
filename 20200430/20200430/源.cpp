#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/*int add(int x, int y)
{
	return x + y;
}
int main()
{
	int x, y, z;
	scanf("%d%d", &x, &y);
	z = add(x, y);
	printf("z=%d\n", z);
	system("pause");
	return 0;
}*/
/*
int sum(int x[], int n)
{
	int m = 0;
	for(int i = 0; i < n; i++)
	{
		if (x[i] < 0)
		{
			m++;
		}
	}
	return m;
}
int main()
{
	int x[6], i, y;
	for (i = 0; i < 6; i++)
	{
		scanf("%d", &x[i]);
	}
	y = sum(x, 6);
	printf("%d", y);
	system("pause");
	return 0;
}*/

/*int fun(int a, int b)
{
	int r;
	r = a%b;
	while (r != 0)
	{
		a = b;
		b = r;
	}
	return b;
}
/*
int fun(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return fun(b, a%b);
	}
}*/
/*int main()
{
	int n1, n2;
	scanf("%d%d", &n1, &n2);
	int n = fun(n1, n2);
	printf("辗转相除法n1 n2最大公约数为：%d\n", n);
	system("pause");
	return 0;
}*/

