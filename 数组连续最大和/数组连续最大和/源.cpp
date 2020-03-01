#include<iostream>
#include<vector>
using namespace std;
int lengthsubstr(vector<int> a)
{
	int sum = 0;
	int max = 0;
	for (int i = 0; i<a.size(); i++)
	{
		sum = sum>0 ? sum + a[i] : a[i];
		max = max>sum ? max : sum;
	}
	return max;
}
int main()
{
	int n = 0;
	
	while (cin >> n)
	{
		vector<int> a;
		a.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << lengthsubstr(a) << endl;
	}
}