#include <iostream>
using namespace std;
int WeekToDay(int y, int m, int c, int w, bool B)
{
	//输入哪年哪月第几个星期几，以及正数还是倒数，输出几号   
	int d, week, i;
	if (1 == m || m == 2)
	{
		m += 12;
		y--;
	}
	i = 0;
	for (d = B ? 1 : 31; d <= B ? 31 : 1; B ? (d++) : (d--))
	{
		//B：正数/倒数    2515%7   21 41 67-63 =4
		week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400+1) % 7;//基姆拉尔森公式
		if (week == w) ++i;
		if (i == c) break;
	}
	return d;
}
int main(void)
{
	int y;
	while (cin >> y)
	{
		cout << y << "-01-01" << endl;
		printf("%d-01-%02d\n", y, WeekToDay(y, 1, 3, 1, 1));
		printf("%d-02-%02d\n", y, WeekToDay(y, 2, 3, 1, 1));
		printf("%d-05-%02d\n", y, WeekToDay(y, 5, 1, 1, 0));//倒数
		cout << y << "-07-04" << endl;
		printf("%d-09-%02d\n", y, WeekToDay(y, 9, 1, 1, 1));
		printf("%d-11-%02d\n", y, WeekToDay(y, 11, 4, 4, 1));
		cout << y << "-12-25" << endl << endl;
	}
	return 0;
}

/*
int main()
{
	int week = (13 + 13 * 2 + 3 * (13 + 1) / 5 + 2020 + 2020 / 4 - 2020 / 100 + 2020 / 400+1) % 7;
	cout << week << endl;
	system("pause");
	return 0;
}
*/