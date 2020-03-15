#include<iostream>
#include<iomanip>
using namespace std;
double nowinnerprobability(int n)
{
	if (n == 1)
	{
		return 0;
	}
	if (n == 2)
	{
		return 1;
	}
	return (n - 1)*(nowinnerprobability(n - 1) + nowinnerprobability(n - 2));
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		double a = nowinnerprobability(n);
		double all = 1;
		for (int i = n; i > 0; i--)
		{
			all *= i;
		}
		cout << a << endl;
		a = a / all * 100;
		cout << setprecision(2) << std::fixed << a << '%' << endl;
	}
	system("pause");
	return 0;
}