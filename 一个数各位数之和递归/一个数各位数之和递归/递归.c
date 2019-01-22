#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>



int DigitSum(int n)
{
	if (n < 0)
		return 0;
	return n%10 + DigitSum(n / 10);
}int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = DigitSum(n);
	printf("%d", i);   
	system("pause");
	return 0;
}

/*
int main()
{
	int n = 0;
	int sum = 0;
	scanf("%d", &n);
	while (n)
	{
		sum = sum + n % 10;
		n = n / 10;
*/