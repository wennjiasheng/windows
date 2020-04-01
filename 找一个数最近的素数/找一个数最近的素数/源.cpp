#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int fun(int n)
{
	int i;
	for (i = 2; i <= sqrt(n); i++)
	if (n%i == 0)
		return 0;
	return 1;
}
int main()
{
	int i, n, s1 = 0, s2 = 0;
	while (cin >> n)
	{
		for (i = n - 1; i >= 2; i--)
		{
			if (fun(i))
			{
				s1 = i;
				break;
			}
		}
		for (i = n + 1;; i++)
		{
			if (fun(i))
			{
				s2 = i;
				break;
			}
		}
		if (n - s1 > s2 - n)
			cout << s2 << endl;
		else if (n - s1 < s2 - n)
			cout << s1 << endl;
		else
		{
			cout << s1 << endl;
		}
	}

	system("pause");
	return 0;
}
