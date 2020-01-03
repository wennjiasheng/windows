#include<iostream>

using namespace std;


int main()
{
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}
	int n = 0;
	cin >> n;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i] + arr[j] == n)
			{
				cout << i << j << endl;
				goto end;
			}
		}
	}
end:
	system("pause");
	return 0;
}


