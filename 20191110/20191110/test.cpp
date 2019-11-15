

#include<stdio.h>
#include<stdlib.h>


int main()
{
	while (1)
	{
		int a, b, c, d;
		scanf_s("%d %d %d %d", &a, &b, &c, &d);
		int A, B, C;
		A = (a + c) / 2;
		B = (b + d) / 2;
		C = (d - B);
		printf("%d %d %d", A, B, C);
	}
	system("pause");
	return 0;
}