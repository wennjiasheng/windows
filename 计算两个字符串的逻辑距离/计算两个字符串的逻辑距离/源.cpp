#include<iostream>
#include<string>

using namespace std;

int foo(string str1, string str2)
{
	if (str1.size() == 0)
	{
		return str2.size();
	}
	if (str2.size() == 0)
	{
		return str1.size();
	}
	int count = str2.size() - str1.size();
	int n = 0,j;
	for (int i = 0; i < str1.size(); i++)
	{
		for(j = 0; j < str2.size(); j++)
		{
			if (str1[i] == str2[j])
			{
				str2[j] = str2[0];
				break;
			}
		}if (j == str2.size())
		{
			n++;
		}
	}
	return n + count;
}
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		if (str1.size() > str2.size())
		{
			cout << foo(str2, str1) << endl;
		}
		else
		{
			cout << foo(str1, str2) << endl;
		}
		
	}
	system("pause");
	return 0;
}