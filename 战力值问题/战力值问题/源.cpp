/*#include<iostream>
#include<vector>

using namespace std;


int abcd(int m, int n)
{
	int sum;
	while (n>0)
	{
		sum = m%n;
		m = n;
		n = sum;
	}
	return m;
}
int main()
{
	int n, a;
	vector<int> b;
	while (cin >> n >> a)
	{
		b.resize(n);
		for (int i = 0; i<n; i++)
		{
			cin >> b[i];
			if (a >= b[i])
			{
				a += b[i];
			}
			if (a<b[i])
			{
				a += abcd(b[i], a);
			}
		}
		cout << a << endl;
	}
	return 0;
}
*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int i, j;
	for (i = 0; i<str.size(); i++)
	{
		for (j = i + 1; j<str.size(); j++)
		{
			if (str[i] == str[j])
			{
				break;
			}

		}
		if (j == str.size())
		{
			cout << str[i] << endl;
			break;
		}
	}
	system("pause");
	return 0;
}