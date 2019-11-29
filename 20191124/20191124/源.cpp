#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int>a;
	
	int n;
	int count = 0;

	cin >> n;
	while (n)
	{
		n &= (n - 1);
		count++;
	}
	cout << count << endl;
	system("pause");
	return 0;
	
}