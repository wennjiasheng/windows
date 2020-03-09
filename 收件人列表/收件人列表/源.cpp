// write your code here cpp
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int n = 0;
	while (cin >> n)
	{
		string p;
		getline(cin, p);
		vector<string> a;
		a.resize(n);
		for (int i = 0; i < n; i++)
		{
			getline(cin, a[i]);
		}
		for (int j = 0; j < n-1; j++)
		{
			int num = a[j].find(',');
			int ret = a[j].find(' ');
			if (num!=a[j].npos||ret!=a[j].npos)
			{
				string str1;
				str1.push_back('"');
				str1 += a[j];
				str1.push_back('"');
				a[j] = str1;
			}
			a[j].push_back(',');
		}
		if (a[n - 1].find(' ') != -1 || a[n - 1].find(',')!=-1)
		{
			string str1;
			str1.push_back('"');
			str1 += a[n-1];
			str1.push_back('"');
			a[n-1] = str1;
		}
		for (int k = 0; k < n-1; k++)
		{
			cout << a[k]<<' ';
		}
		cout << a[n-1]<<endl;
	}
	system("pause");
	return 0;
}