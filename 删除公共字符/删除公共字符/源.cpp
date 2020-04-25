#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	int hashtable[256] = { 0 };
	for (int i = 0; i < str1.size(); i++)
	{
		hashtable[str1[i]]++;
	}
	string str;
	for (int i = 0; i < str2.size(); i++)
	{
		if (hashtable[str2[i]] == 0)
		{
			str += str2[i];
		}
	}
	cout << str << endl;
	system("pause");
	return 0;
}