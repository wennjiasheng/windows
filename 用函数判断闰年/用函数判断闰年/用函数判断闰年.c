#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>


void Is_leapyear(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		printf("%d是闰年\n", year);
	else
		printf("%d不是闰年\n", year);
}
int main()
{
	int year = 0;
	scanf("%d", &year);
	Is_leapyear(year);
	system("pause");
	return 0;
}