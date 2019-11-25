#include<iostream>

using namespace std;

int getday(int year, int month, int day)
{
	int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int sum = 0;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		days[2] = 29;
	}
	for (int i = 0; i<=month - 1; i++)
	{
		sum += days[i];
	}
	return sum + day;
}
int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		int n = getday(year, month, day);
		cout << n << endl;
	}

	return 0;
}