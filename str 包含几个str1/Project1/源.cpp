#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str, str1;
	while (cin >> str >> str1)
	{
		int pos = 0;
		int count = str.find(str1, pos);;
		while (pos != str.npos)
		{
			pos = str.find(str1, pos+str1.size());
			count++;
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}