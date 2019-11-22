#include <iostream>
#include<vector>
using namespace std;

/*int fun(int m, int n)
{
	int ret = 0;
	while (n > 0)
	{
		ret = m%n;
		m = n;
		n = ret;
	}
	return m;
}
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << a*b / fun(a, b) << endl;
	}
	system("pause");
	return 0;
}*/


int iszidian(vector<char *>a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < strlen(a[i]); j++)
		{
			if ((a[i])[j] - (a[i + 1])[j] < 0)
			{
				return 0;
			}
		}
	}
	return 1;
}
int islengths(vector<char *>a,int n)
{
	for (int i = 0; i < n-1; i++)
	{
		if (strlen(a[i])>strlen(a[i + 1]))
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n;
	cin >> n;
	vector<char *>a;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (islengths(a, n) && iszidian(a, n))
	{
		cout << "both" << endl;
	}
	else if (islengths(a, n))
	{
		cout << "lengths" << endl;
	}
	else if (iszidian(a, n))
	{
		cout << "lexicographically" << endl;
	}
	else
	{
		cout << "none" << endl;
	}
	system("pause");
	return 0;
}