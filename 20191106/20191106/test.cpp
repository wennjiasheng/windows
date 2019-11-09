#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>

using namespace std;
int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> v;
		v.resize(n);
		int i = 0;
		for (; i < v.size(); i++)
		{
			cin >> v[i];
		}

		int count = 1;
		if (n < 3)
		{
			cout << count << endl;
		}
		else
		{
			for (i = 2; i < v.size(); i++)
			{
				if ((v[i - 2]<v[i - 1]) && (v[i - 1]>v[i]))
				{
					count++;
				}
				if ((v[i - 2]>v[i - 1]) && (v[i - 1]<v[i]))
				{
					count++;
				}
			}
			cout << count << endl;
		}
		
	}
	
	system("pause");
	return 0;
}
