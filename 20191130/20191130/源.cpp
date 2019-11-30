//求两个字符串的最长公共字串长度    动态规划
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	;
	string str1, str2;
	int max = 0;
	while (cin >> str1 >> str2)
	{
		vector<vector<int>> num(str1.length(),vector<int> (str2.length()));
		for (int i = 0; i < static_cast<int>(str1.length()); ++i)
		{
			for (int j = 0; j < static_cast<int>(str2.length()); j++)
			{
				if (str1[i] == str2[j])
				{
					if (i == 0 || j == 0)
					{
						num[i][j] = 1;
					}
					else
					{
						num[i][j] = num[i - 1][j - 1] + 1;
					}
				}
				else
				{
					num[i][j] = 0;
				}
				if (num[i][j] > max)
				{
					max = num[i][j];
				}
			}			
		}
		cout << max << endl;
	}
	system("pause");
	return 0;
}