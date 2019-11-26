#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool getxinyundai(vector<int> a,int n)
{
	int sum = 0;
	int sum1 = 1;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
		sum1 *= a[i];
	}
	if (sum>sum1)
	{
		return true;
	}
	return false;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		vector<int> a;
		a.resize(n);
		for (int i = 0; i<n; i++)
		{
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < n - 1; i++)
		{
			if (getxinyundai(a, n - i) == true)
			{
				count++;
			}
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}