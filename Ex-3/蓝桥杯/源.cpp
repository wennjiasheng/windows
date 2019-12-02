#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		vector<int> num;
		num.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> num[i];
		}
		sort(num.begin(), num.end());
		if (num.size() == 1)
		{
			if (k == 1)
			{
				cout << num[0];
				return 0;
			}
			else
			{
				cout << "NO RESULT" << endl;
			}
		}
		if (k == 1)
		{
			cout << num[0] << endl;
			return 0;
		}
		k--;
		for (int j = 1; j < n; j++)
		{
			if (num[j-1] == num[j])
			{
				continue;
			}
			k--;
			if (k == 0)
			{
				cout << num[j];
				break;
			}
		}
		if (k > 0)
		{
			cout << "NO RESULT" << endl;
		}
	}

	system("pause");
	return 0;
}