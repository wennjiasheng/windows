#include<iostream>
#include<string>
using namespace std;

#if 0
class Person
{
public:
	virtual void BuyTickets()
	{
		cout << "成人票" << endl;
	}
};
class Student:public Person
{
public:
	virtual void BuyTickets()
	{
		cout << "学生票" << endl;
	}
};
void SellTickets(Person &p)
{
	p.BuyTickets();
}
int main()
{
	Person p;
	SellTickets(p);
	Student s;
	SellTickets(s);
	system("pause");
	return 0;
}
#endif
#if 0
//特例--协变
class A
{};
class B :public A
{};
class Person
{
public:
	//virtual Person* BuyTickets()
	virtual A* BuyTickets()
	{
		cout << "成人票" << endl;
		return nullptr;
	}
};
class Student :public Person
{
public:
	//virtual Student* BuyTickets()
	virtual B* BuyTickets()//只要对应的子类和基类是继承关系就行
	{
		cout << "学生票" << endl;
		return nullptr;
	}
};
void SellTickets(Person &p)
{
	p.BuyTickets();
}
int main()
{
	Person p;
	SellTickets(p);
	Student s;
	SellTickets(s);
	system("pause");
	return 0;
}
#endif

#if 0//虚函数重写的例外
class Person
{
public:
	virtual Person* BuyTickets()
	{
		cout << "成人票" << endl;
		return nullptr;
	}
	virtual ~Person()
	{
		cout << "~Person()" << endl;
	}
};
class Student :public Person
{
public:
	virtual Student* BuyTickets()
	{
		cout << "学生票" << endl;
		return nullptr;
	}
	virtual ~Student()
	{
		cout << "~Student()" << endl;
	}
};

int main()
{
	Person *p = new Person;//通过基类指针或引用去调用
	p->BuyTickets();
	delete p;
	
	p = new Student;
	p->BuyTickets();
	delete p;
	system("pause");
	return 0;
}
#endif

#if 0
//多继承
class B1
{
public:
	virtual void TestFunc1()
	{
		cout << "B1:TestFunc1():" << endl;
	}
	virtual void TestFunc2()
	{
		cout << "B1:TestFync2():" << endl;
	}
public:
	int _b1;
};
class B2
{
public:
	virtual void TestFunc3()
	{
		cout << "B2:TestFunc3():" << endl;
	}
	virtual void TestFunc4()
	{
		cout << "B2:TestFunc4():" << endl;
	}
public:
	int _b2;
};
class D:public B1,public B2//8+8+4
{
public:
	virtual void TestFunc1()
	{
		cout << "D:TestFunc1():" << endl;
	}
	virtual void TestFunc4()
	{
		cout << "D:TestFunc4():" << endl;
	}
	virtual void TestFunc5()
	{
		cout << "D:TestFunc5():" << endl;
	}
public:
	int _d;
};

///打印虚函数表
typedef void(*PVF)();//函数指针
void PrintVFT(B1 &b,string str)
{
	cout << str << endl;
	//从对象前四个字节获取虚表的地址
	PVF* pvf = (PVF*)*(int*)(&b);
	while (*pvf)
	{
		(*pvf)();
		++pvf;
	}
	cout << endl;
}
void PrintVFT(B2 &b, string str)
{
	cout << str << endl;
	//从对象前四个字节获取虚表的地址
	PVF* pvf = (PVF*)*(int*)(&b);
	while (*pvf)
	{
		(*pvf)();
		++pvf;
	}
	cout << endl;
}
//对象模型
//派生类的虚表
int main()
{
	//cout << sizeof(D) << endl;//20
	D d;
	d._b1 = 1;
	d._b2 = 2;
	d._d = 3;
	B1& b1 = d;
	PrintVFT(b1, "B1 VFT:");

	B2& b2 = d;
	PrintVFT(b2,"B2 VFT:");

	system("pause");
	return 0;
}
#endif
#if 1
class A//8
{
public:
	virtual void TestFunc1()
	{
		cout << "A:TestFunc1():" << endl;
	}
	virtual void TestFunc2()
	{
		cout << "A:TestFunc2():" << endl;
	}
	int _a;
};

class B1:public A//8+4
{
public:
	virtual void TestFunc1()//对A中Func1进行重写
	{
		cout << "B1:TestFunc1():" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "B1:TestFunc3():" << endl;
	}
	int _b1;
};
class B2:public A//8+4
{
public:
	virtual void TestFunc2()//对A中Func2进行重写
	{
		cout << "B2:TestFunc2():" << endl;
	}
	virtual void TestFunc4()
	{
		cout << "B2:TestFunc4():" << endl;
	}
	int _b2;
};
class D :public B1, public B2
{//12+12+4=28
public:
	virtual void TestFunc1()
	{
		cout << "D:TestFunc1():" << endl;
	}
	virtual void TestFunc3()
	{
		cout << "D:TestFunc3():" << endl;
	}
	virtual void TestFunc4()
	{
		cout << "D:TestFunc4():" << endl;
	}
	virtual void TestFunc5()
	{
		cout << "D:TestFunc5():" << endl;
	}
	int _d;
};
//D对象的模型以及虚表的内容
typedef void(*PVF)();//函数指针
void PrintVFT(B1 &b, string str)
{
	cout << str << endl;
	//从对象前四个字节获取虚表的地址
	PVF* pvf = (PVF*)*(int*)(&b);
	while (*pvf)
	{
		(*pvf)();
		++pvf;
	}
	cout << endl;
}
void PrintVFT(B2 &b, string str)
{
	cout << str << endl;
	//从对象前四个字节获取虚表的地址
	PVF* pvf = (PVF*)*(int*)(&b);
	while (*pvf)
	{
		(*pvf)();
		++pvf;
	}
	cout << endl;
}
int main()
{
	cout << sizeof(D) << endl;//
	D d;
	d.B1::_a = 1;
	d.B2::_a = 2;
	d._b1 = 3;
	d._b2 = 4;
	d._d = 5;
	B1& b1 = d;
	PrintVFT(b1, "B1 VFT:");//从B1继承下来的虚表
	B2& b2 = d;
	PrintVFT(b2, "B2 VFT:");//从B2继承下来的虚表
	
	system("pause");
	return 0;
}
#endif
