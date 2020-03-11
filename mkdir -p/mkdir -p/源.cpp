#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> list(n);
		vector<bool> flag(n, true);
		for (int i = 0; i < n; i++)
		{
			cin >> list[i];
		}
		sort(list.begin(), list.end());
		for (int i = 0; i < n-1; i++)
		{
			if (list[i] == list[i + 1])
			{
				flag[i] = false;
			}
			else if (list[i].size() < list[i + 1].size() &&
				list[i + 1].find(list[i]) != -1 &&
				list[i + 1][list[i].size()] == '/')
			{
				flag[i] = false;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (flag[i])
			{
				cout << "mkdir -p " << list[i] << endl;;
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;

}