#include<iostream>
using namespace std;
int main()
{
	int l, r;
	cin >> l >> r;
	int count = 0;
	for (int i = l; i <= r; i++)
	{
		if (i % 3 != 1)
			count++;
	}
	cout << count << endl;
	system("pause");
	return 0;
}