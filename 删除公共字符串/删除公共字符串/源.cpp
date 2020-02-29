#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int hashback[256] = { 0 };
	for (int i = 0; i < s2.size(); i++)
	{
		hashback[s2[i]]++;
	}
	string str;
	for (int j = 0; j < s1.size(); j++)
	{
		if (hashback[s1[j]] == 0)
		{
			str += s1[j];
		}
	}
	cout << str << endl;
	system("pause");
	return 0;
}