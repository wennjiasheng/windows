#include<iostream>

using namespace std;
int main()
{
	int from, to;
	while (cin >> from >> to)
	{
		int n = to - from +1;
		int sum = 1;
		if (n == 1)
		{
			cout << sum << endl;
			continue;
		}
		if (n == 2)
		{
			sum++;
			cout << sum << endl;
			continue;
		}
		int a = 1, b = 1;
		sum = 2;
		for (int i = 2; i <= n / 2; i++)
		{
			a = a + b;
			sum += a;
			b = a + b;
			sum += b;
		}
		if (n % 2 == 1)
		{
			a = a + b;
			sum += a;
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}