#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int fib(int n)
{
	int ret = 1;
	int fn1 = 1;
	int fn2 = 1;
	int i = 0;
	for (i = 3; i <= n; i++)
	{
		ret = fn1 + fn2;
		fn1 = fn2;
		fn2 = ret;
	}
	return ret;

}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = fib(n);
	printf("%d",i );
	system("pause");
	return 0;
}