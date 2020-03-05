#include<iostream>

using namespace std;
/*double fun(int n)
{
	if (n == 1 )
	{
		return 1;
	}
	if (n == 2)
	{
		return 2;
	}
	return fun(n - 1) + fun(n - 2);
}
int main()
{
	int n;
	while (cin >> n)
	{
		double a = fun(n);
		cout << a << endl;
	}
	system("pause");
	return 0;
}
*/

/*int main()
{
	int n; 
	while (cin >> n)
	{
		int num = 0,a = 1, b = 2;
		for (int i = 2; i <= n/2; i++)
		{
			a = (a + b)%1000000;
			b = (b + a)%1000000;
		}
		if (n == 1)
		{
			cout << a << endl;
			continue;
		}
		else if (n == 2)
		{
			cout << b << endl;
			continue;
		}
		else
		{
			if (n % 2 == 1)
			{
				num = (a + b)%1000000;
			}
			else
			{
				num = b;
			}
		}
		cout << num << endl;
	}
	system("pause");
	return 0;
}*/

/*int main()
{
	int a[100001];
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i <= 100000; i++)
	{
		a[i] = (a[i - 2] + a[i - 1]) % 1000000;
	}
	int n = 0;
	while (cin >> n)
	{
		cout << a[n] << endl;
	}
	system("pause");
	return 0;
}*/


int main()
{
	int fib[100000];
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i <= 100000; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] = fib[i] % 1000000;//ºóÁùÎ»
	}
	int n;
	while (cin >> n)
	{
		if (n<29)
			printf("%d\n", fib[n]);
		else
			printf("%06d\n", fib[n]);
	}
	return 0;
}
