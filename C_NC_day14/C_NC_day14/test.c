#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

////1.实现一个函数，可以左旋字符串中的k个字符。
////ABCD左旋一个字符得到BCDA
////ABCD左旋两个字符得到CDAB
////
//
//
//char *stmy_ing(char arr[5], int  k,int sz)
//{
//	int temp = 0;
//	char *p = arr;
//	while (k)
//	{
//		for (int i = 0; i < sz - 2; i++)
//		{
//			temp = arr[i];
//			arr[i] = arr[i + 1];
//			arr[i + 1] = temp;
//		}
//		k--;
//	}
//	return p;
//}
//int main()
//{
//	char arr[5] = "ABCD";
//	int k = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	scanf("%d", &k);
//	printf("%s", stmy_ing(arr, k,sz));
//	system("pause");
//	return 0;
//}
////2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
////例如：给定s1 = AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.
////
////AABCD左旋一个字符得到ABCDA
////AABCD左旋两个字符得到BCDAA
////
////AABCD右旋一个字符得到DAABC
////
////提交作业

int main()
{
	char arr[15] = "AABCD";
	const char *s2 = "BCDAA";
	int len = strlen(s2);
	arr[15] = strncat(arr, arr,len);
	char* ret = strstr(arr, s2);
	if (*ret!=NULL)
	{
		printf("是！");
	}
	else 
	printf("不是！");
	system("pause");
	return 0;
}