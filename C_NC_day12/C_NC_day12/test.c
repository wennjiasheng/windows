#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832
//

//unsigned int reverse_bit(unsigned int value)
//{
//	int i = 5;
//	int j = 0;
//	for (j = 0; j < 32; j++)
//	{
//		i = i + ((value >> j) & 1)*pow(2, 31 - j);
//	}
//	return i;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", reverse_bit(n));
//	system("pause");
//	return 0;
//}
//2.不使用（a + b） / 2这种方式，求两个数的平均值。

//int reverse_bit(int a, int b)
//{
//	return a&b + ((a^b) >> 1);
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("%d", reverse_bit(a, b));
//	system("pause");
//	return 0;
//}
//3.编程实现：
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）


//int here(int *arr, int sz)
//{
//	int n = *arr;
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		n ^= (*arr);
//	}
//	return n;
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("%d", here(arr, sz));
//	system("pause");
//}
//4.
//有一个字符数组的内容为:"student a am i",
//			请你将数组的内容改为"i am a student".
//			要求：
//			不能使用库函数。
//			只能开辟有限个空间（空间个数和字符串的长度无关）。
//
//
//
//			提交作业

int Srlen(char *q)
{
	int count = 0;
	while ((*q!='\0')&&(*q!=' '))
	{
		count++;
		q++;
	}
	return count;
}
int Strlen(char *arr)
{
	int count = 0;
	while (*arr)
	{
		count++;
		arr++;
	}
	return count;
}
void Reverse_bit(char  *arr, int  sz)
{
	char* left = arr;
	char* right = arr + (sz - 1);
	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = *left;
		right--;
		left++;
	}
}
void reverse_bit(char *arr, int  sz)
{
	//将所有字符翻转
	Reverse_bit(arr, sz);
	//将每个单词翻转"student a am i"
	while (arr)
	{
		char* q = arr;
		while ((*arr!=' ')&&(*arr!='\0'))
		{
			 *q++=*arr++;

		}
		int len = Srlen(q);
		Reverse_bit(q, len);
		int i = 0;
		printf("%s", q);
		if (*arr != '\0')
		{
			arr++;
		}
	}
}
int main()
{
	char arr[] = "student a am i";
	char sz = Strlen(arr);
	reverse_bit(arr, sz);
	system("pause");
	return 0;
}