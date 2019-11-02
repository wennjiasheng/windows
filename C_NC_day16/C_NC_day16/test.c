#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//1.实现strcpy 字符串拷贝


//char* my_strcpy(char *dest,const char *str)
//{
//	char *count = dest;
//	while (*str)
//	{
//		*dest = *str;
//		dest++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[10] = { 0 };
//	my_strcpy(arr, "wen jia");
//	printf("%s", arr);
//	system("pause");
//	return 0;
//}
//2.实现strcat 字符串追加


//char *my_strcat( char *p, const char *s)
//{
//    assert(p);
//	  assert(s);
//	char *count = p;
//	while (*p)
//	{
//		p++;
//	}
//	while ((*p++ = *s++)!='\0')
//	{
//
//	}
//	return count;
//}
//int main()
//{
//	char arr[10] = "abc";
//	char *s = "def";
//	printf("%s", my_strcat(arr, s));
//	system("pause");
//	return 0;
//}
//3.实现strstr 字符串中查找字符串

//char *my_strstr(const char *arr1, const char *arr2)
//{
//	assert(arr1);
//	assert(arr2);
//	char *q = arr1;
//	while (*q)
//	{
//		
//		while (*arr1 == *arr2)
//		{
//			arr1++;
//			arr2++;
//			if (*arr2 == '\0')
//			{
//				return q;
//			}
//		}
//		arr1 = ++q;
//	}
//	return NULL;
//}
//int main()
//{
//	const char arr1[10] = "abcde";
//	const char *q = "bcd";
//	printf("%s\n", strstr(arr1, q));
//	printf("%s\n", my_strstr(arr1, q));
//	system("pause");
//	return 0;
//}
//4.实现strchr 字符串中查找字符，返回字符串中第一次出现的地址
//char *my_strchr(char *arr, int a)
//{
//	while (*arr++)
//	{
//		if (*arr == a)
//		{
//			return arr;
//		}
//	}
//	return NULL;
//}
//int main()
//{
//	const char arr[] = "abcde";
//	const char a = 'c';
//	printf("%s\n", strchr(arr, a));
//	printf("%s\n", my_strchr(arr, a));
//	system("pause");
//	return 0;
//}
//5.实现strcmp 字符串比较，s1>s2 返回正数 s1<s2返回负数  s1=s2返回0


//int my_strcmp(const char *str, const char* dest)
//{
//	assert(str);
//	assert(dest);
//	while ((*str++ >= *dest++)&&(*str!='\0'))
//	{
//
//	}
//	return (*str) - (*dest);
//}
//int main()
//{
//	 char str[] = "abcdhfn";
//	 char dest[] = "abcd";
//	printf("%d\n", strcmp(str, dest));
//	printf("%d\n", my_strcmp(str, dest));
//	system("pause");
//	return 0;
//}
//6.实现memcpy 拷贝多少个字节到字符串中
//void *my_memcpy(void *str, void* dest, size_t n)
//{
//	
//	char *a = (char *)str;
//	char *ret = (char *)dest;
//	if (ret > a)
//	{
//		while (n--)
//		{
//			*a = *ret;
//			a++;
//			ret++;
//		}
//	}
//	else
//	{
//		n--;
//	    a+=n;
//		ret+=n;
//		while (n--)
//		{
//			*a-- = *ret--;
//		}
//	}
//	return str;
//}
//int main()
//{
//	char str[] = "abcdef";
//	printf("%s\n", memcpy(str+2, str,4 ));
//	printf("%s\n", my_memcpy(str + 2, str, 4));
//	system("pause");
//	return 0;
//}
//7.实现memmove 比较字符大小，有字符个数限制



char *my_memmove( char *str, const char* dest,size_t n)
{
	assert(str);
	assert(dest);
	char *a = str;
		const char *ret = dest;
		if (ret > a)
		{
			while (n--)
			{
				*a = *ret;
				a++;
				ret++;
			}
		}
		else
		{
			n--;
		    a+=n;
			ret+=n;
			while (n--)
			{
				*a-- = *ret--;
			}
		}
		return str;
	
}
int main()
{
	char str[] = "abcdhfn";

	printf("%s\n", memmove(str+1,str,4));
	printf("%s\n", my_memmove(str+1, str, 4));
	system("pause");
	return 0;
}
