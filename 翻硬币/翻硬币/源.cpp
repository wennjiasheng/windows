#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, x, y;
	vector<int> t;
	cin >> n >> x >> y;
	t.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	int count = 0;
	for (int j = 0; j < n; j++)
	{
		int r = j;
		int l = j;
		if (t[j] == 0)
		{		
			while (j<n && !t[j])
			{
				j++;			
				l++;
			}
		}
		if (l - r == 0)
			continue;
		if ((l - r)*x < y)
		{
			count += (l - r)*x;
		}
		else
		{
			count += y;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}