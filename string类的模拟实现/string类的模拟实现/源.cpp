#include<iostream>

using namespace std;
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
		string(const string& s)
		{
			string strTemp(s._str);
			swap(_str, strTemp._str);
		}
		//Ç³¿½±´
		string(const string& s) :_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}
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
	system("pause");
	return 0;
}