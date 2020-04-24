#include<iostream> 
#include<algorithm> 
#include<vector> 
using namespace std;
int main()
{
	int n;
	while (cin>>n)
	{
		long long sum = 0;
		vector <int> arr;
		arr.resize(3 * n);
		for (int i = 0; i < 3 * n; i++)
		{
			cin >> arr[i];
		}
	    sort(arr.begin(), arr.end());
		for (int i = n; i <= 3 * n - 2; i += 2)
		{
			sum += arr[i];
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}