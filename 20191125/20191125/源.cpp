#include<iostream>
#include<algorithm>
#include<string>


using namespace std;

/*bool isperfectnumber(int n)
{
	int sum = 0;
	for (int i = 1; i < n; i++)
	{
		if (n%i == 0)
		{
			sum += i;
		}
	}
	if (sum == n)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			if (isperfectnumber(i) == true)
			{
				count++;
			}
		}
		cout << count << endl;
	}

	return 0;
}*/






int main()
{
	string str,str1,str2,str3;
	getline(cin, str);
	int pos = str.find("-");
	str1 = str.substr(0, pos);
	str2 = str.substr(pos + 1);
	str3 = "345678910JOKA2jokerJOKER";
	cout << str1 << endl;
	cout << str2 << endl;
	int n = count(str1.begin(), str1.end(), " ");
	int b = count(str2.begin(), str1.end(), " ");/*
	if (str1 == "joker JOKER" || str2 == "joker JOKER")
	{
		cout << "joker JOKER" << endl;
	}
	else if (n==0&&b==0)
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
			cout << "ERROR"<<endl;
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
	
	system("pause");
	return 0;
}
*/