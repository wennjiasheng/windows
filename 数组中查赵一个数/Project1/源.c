#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/*
int main()
{
	int a[10];
	int i = 0;
	while (i < 10)
	{
		scanf("%d", &a[i]);
		i++;
	}
	for (i = 0; i < 10; i++)
	{
		if (a[i] == 3)
		{
			printf("%d\n", i + 1);
			break;
		}
	}
	if (i == 10)
	{
		printf("not found!\n");
	}
	system("pause");
	return 0;
}
*/
int main()
{
	char  a[10];
	char b[10];
	int i, j;
	gets(a);
	for (i = 0,j = 0; a[i] != '\0'; i++)
	{
		if (a[i] <= '0' || a[i] >= '9')
		{
			b[j] = a[i];
			j++;
		}
	}
	b[j] = '\0';
	puts(b);
	system("pause");
	return 0;
}