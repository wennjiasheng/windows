#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class Date
{
	friend ostream& operator<<(ostream& _cout, const Date& d);//友元函数 访问类里私有成员
	friend istream& operator>>(istream& _cin, Date& d);
public:
	Date(int year = 1888, int month = 11, int day = 1)
		:_year(year),
		_month(month),
		_day(day)
	{
		cout << "Date():" << this << endl;
	}
	Date(const Date& d)
	{
		cout << "Date&():" << this << endl;
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void PrintDate()
	{
		cout << _year << "--" << _month << "--" << _day << endl;
	}
	//下面这个不能重载operator<<
	//void operator<<(const Date& d)//ostream是cout的一个对象
	//{
	//	_cout << _year << "--" << _month << "--" << _day << endl;
	//}
	~Date()
	{
		cout << "~Date():" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
//重载成全局的函数
ostream& operator<<(ostream& _cout, const Date& d)//ostream是cout的一个对象
{
	_cout << d._year << "--" << d._month << "--" << d._day;
	return _cout;
}
istream& operator>>(istream& _cin, Date& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;
	return _cin;
}
int main()
{
	Date d;
	cin >> d;
	d.PrintDate();//打印
	cout << d << endl;
	system("pause");
	return 0;
}
