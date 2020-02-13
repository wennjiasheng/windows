#include<iostream>


using namespace std;




class Singleton{
public:
	static Singleton& getinstance()
	{
		return m_ins;
	}
private:
	Singleton()
	{

	}
	Singleton(const Singleton&) = delete;
	static Singleton m_ins;//
};
Singleton Singleton::m_ins;
int main()
{
	Singleton::getinstance();
	return 0;
}