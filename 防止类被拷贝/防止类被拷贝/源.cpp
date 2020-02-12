#include<iostream>


using namespace std;

class Test
{
public:
	Test()
	{}
private:
	//C++98
	Test(Test& t);
	Test& operator=(const Test&);
	//C++11
	//Test(Test& t) = delete;
	//Test& operator=(const Test&) = delete;
};

int main()
{

	Test s;
	return 0;
}