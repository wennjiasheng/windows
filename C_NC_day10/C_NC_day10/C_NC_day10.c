//1.
//写一个函数返回参数二进制中 1 的个数
//比如： 15 0000 1111 4 个 1
//程序原型：
//int count_one_bits(unsigned int value)
//{
	// 返回 1的位数 
//}

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


//int count_one_bits(unsigned int value)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if ((value >> i) && 1 == 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", count_one_bits(n));
//	system("pause");
//	return 0;
//}
//2.获取一个数二进制序列中所有的偶数位和奇数位，
//分别输出二进制序列。

//void count_one_bits(const int n)
//{
//	int i = 0;
//	printf("偶数序列\n");
//	for (i = 31; i >= 1; i -= 2)
//	{
//		printf("%d", ((n >> i) & 1));
//	}
//	printf("\n");
//	printf("奇数序列\n");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d", ((n >> i) & 1));
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	count_one_bits(n);
//	system("pause");
//	return 0;
//}
//3. 输出一个整数的每一位。
//void count_one_bits(int n)
//{
//	if (n >= 10)
//	count_one_bits(n / 10);
//	printf("%d", n % 10);
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	count_one_bits(n);
//	system("pause");
//	return 0;
//}
//4.编程实现：
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子 :
//1999 2299
//输出例子 : 7

int count_one_bits(int i, int  j)
{
	int count = 0;
	int n = i^j;
	while ( n != 0 )
	{
		n &=(n-1);
		count++;
	}
	return count;

}
int main()
{
	int i = 1999;
	int j = 2299;
	printf("%d", count_one_bits(i, j));
	system("pause");
	return 0;
}
//	   5.写博客总结C语言操作符，博客链接发给我，并分享到群里。