#include "test.h"

#if 0
class A
{
public:
	void Test()
	{
		cout << this << endl;
		cout << "Test()" << endl;
	}
protected:
	int _a;
};


int main()
{
	A* ps = nullptr;
	ps->Test();
	system("pause");
	return 0;
}
#endif

#if 0
#include<cstdio>
#include<cstdlib>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;

//this指针
class Student
{
public:
	void InitStudent(Student* const this, char* name, char* gender, int sex)
	{
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}
	void PrintStudent(Student* const this)
	{
		cout << this->_name << " " << this->_gender << " " << this->_age << endl;
	}
private:
	char _name[20];
	char _gender[5];
	int _age;
};

int main()
{
	Student s1;
	Student::InitStudent(&s1, "zhangsan", "男", 15);
	Student::PrintStudent(&s1);
	system("pause");
	return 0;
}
#endif

#if 1
void Student::InitStudent(char* name, char* gender, int age)
{
	strcpy(this->_name, name);
	strcpy(_gender, gender);
	_age = age;
}
void Student::PrintStudent()
{
	cout << _name << " " << _gender << " " << _age << endl;
}
int main()
{

	Student s1;
	s1.InitStudent("zhangsan", "男", 15);
	s1.PrintStudent();

	Student s2;
	s2.InitStudent("nihao", "女", 20);
	s2.PrintStudent();
	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	//cout << sizeof(A) << endl;//4  可以看出，类中有成员变量和方法时，大小跟成员方法无关
	//cout << sizeof(B) << endl;//1  只有成员方法，没有成员变量
	//cout << sizeof(C) << endl;//1  空类的大小是1，
	//如果占0个字节，创建出的对象会在同一个位置，有矛盾，所以，占了一个字节可以区分类创建出的对象
	cout << sizeof(A) << endl;//16
	cout << offsetof(A, _a) << endl;//  0
	cout << offsetof(A, _b) << endl;//8
	system("pause");
	return 0;
}
#endif