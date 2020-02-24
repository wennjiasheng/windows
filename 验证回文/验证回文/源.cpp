#include<iostream>
#include<string>

using namespace std;


class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty() || s.size() == 1)
		{
			return true;
		}
		int begin = 0;
		int end = s.size() - 1;
		while (begin<end)
		{
			while (begin<end)
			{
				if (ischar(s[begin]))
				{
					break;
				}
				begin++;
			}
			while (begin<end)
			{
				if (ischar(s[end]))
				{
					break;
				}
				end--;
			}
			if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
			{
				return false;
			}
			begin++;
			end--;
		}
		return true;
	}
	bool ischar(char a)
	{
		if (('a' <= a&&a <= 'z') || ('A' <= a&&a <= 'Z') || ('0' <= a&&a <= '9'))
		{
			return true;
		}
		return false;
	}
};
int main()
{
	Solution s;
	string str;
	cin >> str;
	if (s.isPalindrome(str))
	{
		cout << "yes" << endl;
	}
	else
	{
		cout << "no" << endl;
	}
	system("pause");
	return 0;
}