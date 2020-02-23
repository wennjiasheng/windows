#pragma warning (disable:4996)
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
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
		//浅拷贝
		/*string(const string& s) :_str(new char[strlen(s._str) + 1])
		{
		strcpy(_str, s._str);
		}*/
		//浅拷贝
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
#if 0
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
			if (1 < (*_count))
			{
				string temp = string(_str);
				Swap(temp);
			}
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
		void Swap(string s)
		{
			swap(_str, s._str);
			swap(_count, s._count);
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
#endif



namespace bit
{
	class string{
	public:
		string(const char* str = "")
		{
			if (nullptr == str)
				str = " ";
			_size = strlen(str);
			_capacity = strlen(str) + 1;
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		string(size_t n, char c)
			:_str(new char[n+1]),
			_capacity(n+1),
			_size(n)
		{
			memset(_str, c, _size);
		}
		string(const string& s) :_str(nullptr)
		{
			string strTemp(s._str);
			std::swap(_str, strTemp._str);
		}
		string(const char* pstr, size_t n)
		{
			size_t length = strlen(pstr);
			_size = length > n ? n : length;
			_capacity = _size;
			_str = new char[_capacity + 1];
			for (int i = 0; i < _size; i++)
			{
				_str[i] = pstr[i];
			}
			_str[_size] = '\0';
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{

				char* pStr = new char[strlen(s._str) + 1];
				strcpy(pStr, s._str);
				delete[] _str;
				_str = pStr;
			}
			return *this;
		}
		size_t size()const
		{
			return _size;
		}
		size_t length()const
		{
			return _size;
		}
		size_t capacity()const
		{
			return _capacity;
		}
		bool empty()const
		{
			if (_size == 0)
			{
				return true;
			}
			return false;
		}
		void clear()
		{
			_size = 0;
			_str[0] = '\0';
		}
		//将对象中有效的元素个数改为newsize，多处的字符 ch填充

		void resize(size_t newsize, char ch = char())
		{
			size_t oldsize = size();
			if (newsize < oldsize)
			{
				_size = newsize;
				_str[_size] = '\0';

			}
			else
			{
				if (newsize>capacity())
				{
					size_t newcapacity = capacity() * 2;
					reserve(newcapacity);
				}
				memset(_str + _size, ch, newsize - oldsize);
				_size = newsize;
				_str[_size] = '\0';
			}
		}
		void reserve(size_t newcapacity)
		{
			if (newcapacity > capacity())
			{
				char* pstr = new char[newcapacity + 1];
				strcpy(pstr, _str);
				delete[] _str;
				_str = pstr;
				_capacity = newcapacity;
			}
		}
		char& operator[](size_t index)
		{
			assert(index < size());
			{
				return _str[index];
			}
		}
		const char& operator[](size_t index)const
		{
			assert(index < size());
			{
				return _str[index];
			}
		}
		string& operator+=(const string&s)
		{
			size_t  left = _capacity - _size;
			size_t  total = s._size;
			if (total>left)
			{
				reserve(size() + total);
			}
			strcpy(_str + _size, s._str);
			_size += total;
		}
		void push_back(char ch)
		{
			if (_size == _capacity)
				reserve(2 * _capacity);
			_str[_size++] = ch;
			_str[_size] = '\0';
		}
		void append(size_t n, char ch)
		{
			size_t left = _capacity - _size;
			if (n > left)
			{
				reserve(n + _size);
			}
			memset(_str + _size, ch, n);
			_size += n;
			_str[_size] = '\0';

		}
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_capacity, s._capacity);
			std::swap(_size, s._size);
		}
		const char* c_str()const
		{
			return _str;
		}
		size_t find(char ch, size_t pos = 0)
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (ch = _str[i])
				{
					return i;
				}
				return -1;
			}
		}
		size_t rfind(char ch, size_t pos = npos)
		{
			if (pos = npos)
			{
				pos = _size - 1;
			}
			for (int i = pos; i >= 0; i--)
			{
				if (ch == _str[i])
					return i;

			}
			return npos;
		}
		string strsub(size_t pos = 0, size_t n = npos)const
		{
			if (n == npos)
			{
				n = _size - pos;
			}
			return string(_str + pos, n);
		}
		char* begin()
		{
			return _str;
		}
		char * end()
		{
			return _str + _size;
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
		size_t _capacity;
		size_t _size;
		static const size_t npos;
	};
	const size_t string::npos = -1;
}



int main()
{

	system("pause");
	return 0;
}