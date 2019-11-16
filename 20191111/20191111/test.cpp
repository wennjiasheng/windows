#include<iostream>

using namespace std;

void  chang(int n, int m)
{
	int arr[32];
	int i = 0;
	if (n == 0)
	{
		cout << i;
		return;
	}
	while (n > 0)
	{
		arr[i] = n%m;
		n = n / m;
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
	{
		if (arr[j] > 9)
		{
			switch (arr[j])
			{
			case 10:
				printf("A");
				continue;
			case 11:
				printf("B");
				continue;
			case 12:
				printf("C");
				continue;
			case 13:
				printf("D");
				continue;
			case 14:
				printf("E");
				continue;
			case 15:
				printf("F");
				continue;

			}
		}
		printf("%d",arr[j]);
	}
	printf("\n");
}
int main()
{

	int n, m;
	while (1)
	{
		cin >> n;
		cin >> m;
		chang(n, m);
	}
	return 0;
}