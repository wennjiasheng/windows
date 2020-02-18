#include<iostream>
#include<string>

using namespace std;

int StrToInt(string s)
{
	long long a = 0;
	int f = 0;
	if (s.empty())
	{
		return a;
	}
	int n = s.size();
	if (s[0] == '+')
	{
		f = 1;
	}
	else if (s[0] == '-')
	{
		f = -1;
	}
	else if ('0' <= s[0] && s[0] <= '9')
	{
		a = s[0] - '0';
	}
	else
	{
		return a;
	}
	if (n == 1)
	{
		return a;
	}
	for (int i = 1; i < n; i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			a = a * 10 + s[i] - '0';
		}
		else
			return 0;
	}
	if (f >= 0 && a <= INT_MAX)
	{
		return a;
	}
	if (f<0)
	{
		a = a*f;
		if (a >= INT_MIN)
		{
			return a;
		}

	}
	return 0;
}

int main()
{
	string s;
	cin >> s;
	cout << StrToInt(s) << endl;
	system("pause");
	return 0;
}