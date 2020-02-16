#include<iostream>

#include<string>
using namespace std;

int main()
{
	string s1;
	string s2("abcd");
	string s3(s2);
	string s4(10, 'a');
	string s5(s4, 1, 5);
	cout << s1 << endl;
	cout << s2<< endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s5.size() << endl;
	cout << s5.length() << endl;
	cout << s5.capacity() << endl;
	s5.clear();//有效字符全部清空
	cout << s5 << endl;
	cout << s5.size() << endl;
	cout << s5.length() << endl;
	cout << s5.capacity() << endl;
	string s6("hello");
	cout << s6 << endl;
	cout << s6.size() << endl;
	cout << s6.capacity() << endl;
	s6.resize(10, '!');
	cout << s6 << endl;
	cout << s6.size() << endl;
	cout << s6.capacity() << endl;
	s6.resize(20);
	cout << s6 << endl;
	cout << s6.size() << endl;
	cout << s6.capacity() << endl;
	s6.reserve(100);
	cout << s6 << endl;
	cout << s6.size() << endl;
	cout << s6.capacity() << endl;
	s6 += ' ';
	s6 += s2;
	cout << s6 << endl;
	s6 += ' ';

	s6 += "!!!!";
	cout << s6 << endl;
	system("pause");
	return 0;
}