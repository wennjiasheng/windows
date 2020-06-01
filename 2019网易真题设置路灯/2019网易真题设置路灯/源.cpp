#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string str;
		str.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> str[i];
		}
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (str[i] == '.')
			{
				count++;
				i += 2;
			}
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}