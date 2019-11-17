#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;
/*bool checkhuiwen(string s1)
{
	int i = 0;
	int j = s1.length() - 1;

	while (i<j)
	{
		if (s1[i] != s1[j])
		{
			return false;
		}
		i++;
		j--;
	}	
	return true;
	
}
int main()
{
	int count = 0;
	string s1,s2;
	cout << "请输入第一个回文字符串：" << endl;
	cin >> s1;
	while (checkhuiwen(s1)==false)
	{
		cout << "输入字符串有误，请重新输入：" << endl;
		cin >> s1;

	}
	cout << "请输入第二个回文字符串：" << endl;
	cin >> s2;
	while (checkhuiwen(s2)==false)
	{
		cout << "输入字符串有误，请重新输入：" << endl;
		cin >> s2;;
	}
	for (int i = 0; i < s1.length(); i++)
	{
		string s = s1;
		s.insert(i,s2);
		if (checkhuiwen(s)==true)
		{
			count++;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}
*/
int main()
{
	int n;    
	while (cin >> n)
	{
		long long sum = 0;
		long long sum1 = 0;
		vector<int> a;
		a.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			
			if (a[i] < 0)
			{
				if (sum>sum1)
				{
					sum1 = 0;
				}
				else
				{
					sum = sum1;
					sum1 = 0;
				}
				continue;
			}
			sum1 += a[i];
		}
		if (sum1 > sum)
		{
			cout << sum1 << endl;
		}
		else
		{
			cout << sum << endl;
		}
	}

	system("pause");
	return 0;
}