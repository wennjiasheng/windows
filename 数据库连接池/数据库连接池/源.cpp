#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int sum = 0;
		int max = 0;
		string id, con;
		for (int i = 0; i < n; i++)
		{
			cin >> id >> con;
			if (con == "connect")
			{
				sum++;
			}
			else if (con == "disconnect")
			{
				sum--;
			}
			if (max < sum)
			{
				max = sum;
			}

		}
		cout << max << endl;
	}
	system("pause");
	return 0;
}