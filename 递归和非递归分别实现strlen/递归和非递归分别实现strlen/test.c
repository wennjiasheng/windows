#define _CRT_SECURE_NO_WARNINGS
//递归和非递归分别实现strlen
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


int my_strlen(const char* str)
{
	if (str == NULL)
		return 0;
	if (* str != '\0')

		return 1 + my_strlen(str+1);

}
int main()
{
	char str = "abcde";
	printf("%d", my_strlen(str));
	system("pause");
	return 0;
}