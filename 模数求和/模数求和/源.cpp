#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		long res = 0;
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			res += temp - 1;
		}
		cout << res << endl;
	}
	return 0;
}