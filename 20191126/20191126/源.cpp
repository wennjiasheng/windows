#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int main()
{
	string str, str1, str2, str3;
	getline(cin, str);
	int pos = str.find("-");
	str1 = str.substr(0, pos);
	str2 = str.substr(pos + 1);
	str3 = "345678910JOKA2jokerJOKER";
	int n = count(str1.begin(), str1.end(), ' ');
	int b = count(str2.begin(), str2.end(), ' ');
	if (str1 == "joker JOKER" || str2 == "joker JOKER")
	{
		cout << "joker JOKER" << endl;

	}
	else
	{
		 if (n == 0 && b == 0)
		{
			if (str3.find(str1[0]) > str3.find(str2[0]))
			{
				cout << str1 << endl;
			}
			if (str3.find(str2[0]) > str3.find(str1[0]))
			{
				cout << str2 << endl;
			}
			else
				cout << "ERROR" << endl;
		}
		else if (n == 1 && b == 1)
		{
			if (str3.find(str1[0]) > str3.find(str2[0]))
			{
				cout << str1 << endl;
			}
			if (str3.find(str2[0]) > str3.find(str1[0]))
			{
				cout << str2 << endl;
			}
			else
				cout << "ERROR" << endl;
		}
		else if (n == 2 && b == 2)
		{
			if (str3.find(str1[0]) > str3.find(str2[0]))
			{
				cout << str1 << endl;
			}
			if (str3.find(str2[0]) > str3.find(str1[0]))
			{
				cout << str2 << endl;
			}

		}
		else if (n == 3 && b == 3)
		{
			if (str3.find(str1[0]) > str3.find(str2[0]))
			{
				cout << str1 << endl;
			}
			if (str3.find(str2[0]) > str3.find(str1[0]))
			{
				cout << str2 << endl;
			}

		}
		else if (n == 4 && b == 4)
		{
			if (str3.find(str1[0]) > str3.find(str2[0]))
			{
				cout << str1 << endl;
			}
			if (str3.find(str2[0]) > str3.find(str1[0]))
			{
				cout << str2 << endl;
			}
			else
				cout << "ERROR" << endl;
		}
		else
		{
			cout << "ERROR" << endl;
		}
	}

	system("pause");

	return 0;
}