#include<iostream>
using namespace std;
int main()
{
	int q;
	cin >> q;
	while (q != 0)
	{
		long long x;
		int k;
		cin >> x >> k;
		if (x == 1)
		{
			cout << "-1" << endl;
			continue;
		}
		int a = (sqrt(x) + 1);
		if (k >= a)
		{
			cout << "-1" << endl;
			continue;
		}
		if (x % 2 == 0)
		{
			int parent = x;
			while (a != k)
			{
				parent /= 2;
				a--;
			}
			cout << parent<<endl;
		}
		else
		{
			int parent = x-1;
			while (a != k)
			{
				parent /= 2;
				a--;
			}
			cout << parent << endl;
		}
		q--;
	}
	system("pause");
	return 0;
}