#include<iostream>

using namespace std;


int main()
{
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0)
		{
			return 0;
		}
		int count = 0;
		while (1)
		{
			if (n == 3||n==2)
			{
				count++;
				break;
			}
			if (n == 1)
			{
				break;
			}
			n = n / 2;
			count++;
			
		}
		cout << count << endl;

	}
	return 0;
}