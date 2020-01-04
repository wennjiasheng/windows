#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
		// 马拉车算法
		string longestPalindrome(string s) {
		//初始化
		int n = s.size();
		// v[i][j] 表示第i个字符到第j个字符是否是回文串
		vector<vector<int> > v(n, vector<int>(n, 0));
		int len = 0, left = 0, right = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			for (int j = 0; j < i; ++j) // 从j到i，所以不可能超过i
			{
				// 当s[i]等于s[j]的情况下，要么i和j相邻，要么v[j][i]是由v[j + 1][i - 1]扩充得到
				// 总的来说，如果里面是回文串，且s[i]和s[j]相等，外层也是回文串
				v[j][i] = (s[i] == s[j] && ((i - j < 2) || v[j + 1][i - 1]));
				// 每次判断当前i-j+1是否是最大长度
				if (v[j][i] && i - j + 1 > len)
				{
					len = i - j + 1;
					left = j;
					right = i;
				}
			}
			v[i][i] = 1; // 一个字符肯定是回文串
		}

		return s.substr(left, right - left + 1);
	}
};

int main()
{
	string st = "ababacd";
	Solution p;
	string s = p.longestPalindrome(st);
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i];
	}
	system("pause");
	return 0;
}