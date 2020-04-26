#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main()
{
	int n,m;
	cin >> n;
	while (n != 0)
	{
		queue<int> q;
		cin >> m;
		string x;
		getline(cin, x);
		while (m != 0)
		{
			string str;
			getline(cin, str);
			if (str == "TOP")
			{
				if (q.size() == 0)
				{
					cout << "-1" << endl;
				}
				else
				{
					cout << q.front() << endl;
				}
			}
			else if (str == "POP")
			{
				if (q.size() == 0)
				{
					cout << "-1" << endl;
				}
				else
				{
					q.pop();
				}
			}
			else if (str == "SIZE")
			{
				cout << q.size() << endl;
			}
			else if (str == "CLEAR")
			{
				int i = q.size();
				while (i!=0)
				{
					q.pop();
					i--;
				}
			}
			else
			{
				string  str1 = str.substr(str.find(' ')+1);
				int num = 0;
				for (int i = 0; i < str1.size(); i++)
				{
					num = num * 10 + str1[i] - '0';
				}
				q.push(num);
			}
			m--;
		}
		n--;
	}
}