//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*
int lengfirst(string s, int i)
{
	int num = 1;
	for (int j = i + 1; j<s.size(); j++)
	{
		for (int k = j-1; k>=i; k--)
		{
			if (s[k] == s[j])
			{
				return num;
			}
		}
		num++;
	}
	return num;
}
int lengthOfLongestSubstring(string s) {
	int count = 0;
	int i;
	for ( i = 0; i<s.size() - 1; i++)
	{
		count = lengfirst(s, i)>count ? lengfirst(s, i) : count;
	}
	return count;
}
*//*
class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		//s[start,end) 前面包含 后面不包含
		int start(0), end(0), length(0), result(0);
		int sSize = int(s.size());
		while (end < sSize)
		{
			length = 0;
			for (int i = 0; i<end; i++)
			{
				if (s[i] == s[end])
				{
					length = end - i-1;
				}
			}
			length++;
			end++;
			result = result > length ? result : length;
		}
		return result;
	}
}
*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> a(128, -1);
		int left = -1;
		int max1 = 0;
		for (int i = 0; i<s.size(); i++)
		{
			left = max(left, a[s[i]]);
			a[s[i]] = i;
			max1 = max(max1, i - left);
		}
		return max1;
	}
};


int main()
{
	string s("abcabcbb");
	Solution t;
	int count = t.lengthOfLongestSubstring(s);
	cout << count<<endl;
	system("pause");
	return 0;
}