#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stdlib.h>
using namespace std;
/*int main()
{
	int n = 0;
	cin >> n;		
	vector<int> v;
	v.resize(3 * n);
	for (int i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	long long sum = 0;
	int x = n;
	for (int i = v.size() - 2; i > 0 && n>0; i = i - 2, n--)
	{
		sum += v[i];
	}
	cout << sum << endl;
	
	system("pause");
	return 0;
}
*/
int main()
{

	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	int hashtable[256] = { 0 };
	for (size_t i = 0; i < str2.size(); i++)
	{
		hashtable[str2[i]]++;
	}
	string ret;
	for (size_t i = 0; i < str1.size(); i++)
	{
		if (hashtable[str1[i]] == 0)
		{
			ret += str1[i];
		}
	}
	cout << ret << endl;
	system("pause");
	return 0;
}