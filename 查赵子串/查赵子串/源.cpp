#include<iostream>
#include<string>
using namespace std;
int Rfind(string s, int pos, char a)
{
	for (int i = pos; i >= 0; i--)
	{
		if (s[i] = a)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int pos = s1.size() - 1;
	for (int i = s2.size() - 1; i >= 0; i--)
	{
		pos = Rfind(s1, pos, s2[i])-1;
	}
	pos+=2;
	cout << pos << endl;
	system("pause");
	return 0;
}