//题目描述
//请实现一个函数，将一个字符串中的每个空格替换成“ % 20”。
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are % 20Happy。
#include<iostream>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL || length <= 0)
			return;
		int i = 0, count = 0, NowLen = 0;
		while (str[i] != '\0')
		{
			NowLen++;
			if (str[i] == ' ')   count++;
			i++;
		}

		int newLength = NowLen + count * 2;
		if (newLength>length) return;

		int before = NowLen;
		int now = newLength;
		while (before<now&&before >= 0)
		{
			if (str[before] == ' ')
			{
				str[now--] = '0';
				str[now--] = '2';
				str[now--] = '%';
			}
			else
				str[now--] = str[before];
			before--;
		}
	}
};
