#include<iostream>

using namespace std;

class Number
{
public:

	void InitNumber(int _x = 10)
	{
		x = _x;
	}
	Number operator+(int y)
	{
		Number temp(*this);
		temp.x += y;
		return temp;
	}
	Number operator-(int y)
	{
		Number temp(*this);
		temp.x -= y;
		return temp;
	}
	Number operator++(int)//后置++
	{
		Number temp(*this);
		x += 1;
		return temp;
	}
	Number operator++()//前置++；
	{
		x += 1;
		return *this;
	}
	Number operator--(int)//后置--
	{
		Number temp(*this);
		x -= 1;
		return temp;
	}
	Number operator++()//前置--；
	{
		x -= 1;
		return *this;
	}
	bool operator>(Number d)
	{
		return x > d.x;
	}
	Number *operator &()
	{
		return this;
	}
	bool operator==(Number d)
	{
		return x == d.x;
	}

	void Print()
	{
		cout << x << endl;
	}
private:
	int x;
};


int main()
{


	Number s;
	Number d;
	d.InitNumber(20);
	s.InitNumber();
	s = s + 10;
	s.Print();
	s = s - 10;
	s.Print();
	s++;
	s.Print();
	if (s > d)
	{
		cout << "s>d" << endl;
	}
	cout << "s<d" << endl;
	const Number c;
	//c只能调用const成员，const成员函数不能修改类的成员变量
	system("pause");
	return 0;
}