#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int l1 = s1.size();
		int l2 = s2.size();
		int ret[1024][1024] = { 0 };
		if (s1[0] == s2[0])
		{
			ret[0][0] = 1;
		}
		for (int i = 1; i < l1; i++)
		{
			for (int j = 1; j < l2; j++)
			{
				if (s1[i] == s2[j])
				{
					ret[i][j] = ret[i - 1][j - 1] + 1;
				}
				else{
					ret[i][j] = max(ret[i - 1][j], ret[i][j - 1]);
				}
			}
		}
		cout << ret[l1 - 1][l2 - 1] << endl;
	}
	system("pause");
	return 0;
}