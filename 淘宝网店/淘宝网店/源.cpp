#include<iostream>

using namespace std;

int main()
{
	//2 28 3 31 5 31 7 31 11 30
	//1 31 4 30 6 30 8  31 9 30 10 30 12 31
	int year, month, day, year1, month1, day1;
	int arr[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (cin >> year)
	{
		int sum = 0;

		cin >> month >> day >> year1 >> month1 >> day1;
		for (int i = year; i < year1; i++)
		{
			if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			{
				sum += 580;
			}
			else
			{
				sum += 579;
			}

		}
		for (int j = 1; j < month; j++)
		{
			if ((year % 4 == 0 && year % 100 != 0 || year % 40 == 0) && j == 2)
			{
				sum--;
			}
			if (j == 2 || j == 3 || j == 5 || j == 7 || j == 11)
			{
				sum -= arr[j];
			}
			else
			{
				sum -= arr[j] * 2;
			}
		}
		for (int j = 1; j < month1; j++)
		{
			if ((year1 % 4 == 0 && year1 % 100 != 0 || year1 % 40 == 0) && j == 2)
			{
				sum++;
			}
			if (j == 2 || j == 3 || j == 5 || j == 7 || j == 11)
			{
				sum += arr[j];
			}
			else
			{
				sum += arr[j] * 2;
			}
		}


		if (month == 2 || month == 3 || month == 5 || month == 7 || month == 11)
		{
			day = day;
		}
		else{
			day = 2 * day;
		}
		if (month1 == 2 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 11)
		{
			day1 = day1 + 1;
		}
		else{
			day1 = 2 * day1 + 2;
		}
		sum = sum + day1 - day;
		cout << sum << endl;

	}
	system("pause");
	return 0;
}