#pragma once

#include<cstdio>
#include<cstdlib>
#include<iostream>
#pragma warning(disable:4996)
using namespace std;
class Student
{
public:
	void InitStudent(char* name, char* gender, int sex);
	void PrintStudent();
private:
	char _name[20];
	char _gender[5];
	int _age;
};
#if 1
class A
{
public:
	void f1(){}
//protected:
	int _a;
	double _b;
};
class B
{
public:
	void f2(){}
};
class C
{
};
#endif