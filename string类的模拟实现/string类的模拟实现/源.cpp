#pragma warning (disable:4996)
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#if 0
namespace bit
{
	class string{
	public:
		string(const char* str = "")
		{/*
		 if (nullptr == str)
		 {
		 _str = new char[1];
		 *_str = '\0';
		 }
		 else
		 {
		 _str = new char[strlen(str) + 1];
		 strcpy(_str, str);
		 }*/
			if (nullptr == str)
				str = " ";
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		string(const string& s) :_str(nullptr)
		{
			string strTemp(s._str);
			swap(_str, strTemp._str);
		}
		//Ç³¿½±´
		/*string(const string& s) :_str(new char[strlen(s._str) + 1])
		{
		strcpy(_str, s._str);
		}*/
		//Ç³¿½±´
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				/*
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
				*/
				char* pStr = new char[strlen(s._str) + 1];
				strcpy(pStr, s._str);
				delete[] _str;
				_str = pStr;
			}
			return *this;
		}
		~string()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	private:
		char* _str;

	};
}

int main()
{
	char* str = new char[10];
	char* p = "123456";
	strcpy(str, p);
	cout << str << endl;
	system("pause");
	return 0;
}
#endif 


namespace bite
{
	class string
	{
	public:
		string(const char*str = "")
		{
			if (nullptr == str)
			{
				str = "";
			}
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
			_count = new int(1);
		}
		string(string& s) :_str(s._str), _count(s._count)
		{
			(*_count)++;
		}
		string &operator=(const string& s)
		{
			if (this != &s)
			{
				if (_str && 0 == --(*_count))
				{
					delete[] _str;
					_str = nullptr;
				}
				_str = s._str;
				_count = s._count;
				++_count;
			}
			return *this;
		}
		char &operator[](size_t index)
		{
			return _str[index];
		}
		const char &operator[](size_t index)const
		{
			return _str[index];
		}
		~string()
		{
			if (_str&&0 == --(*_count))
			{
				delete[] _str;
				delete _count;
				_count = nullptr;
				_str = nullptr;
			}
		}
	private:
		char* _str;
		int* _count;
	};
}

void Teststring()
{
	bite::string s1("hello");
	bite::string s2(s1);
	bite::string s3("world");
	bite::string s4(s3);
	s1 = s3;
	s2 = s4;
	s1[0] = 'w';
}
int main()
{

	Teststring();
	system("pause");
	return 0;
}