#include<iostream>
#include<string>

using namespace std;

int firstcharacter(string s)
{
	if (s.size() == 0)
	{
		return -1;
	}
	int count[256] = { 0 };
	for (int i = 0; i<s.size(); i++)
	{
		count[s[i]]++;
	}
	for (int i = 0; i<s.size(); i++)
	{
		if (1 == count[s[i]])
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	string s;
	cin >> s;
	int n = firstcharacter(s);
	if (n == -1)
	{
		cout << n << endl;
	}
	else
	{
		cout << s[n]<< endl;
	}
	system("pause");
	return 0;
}