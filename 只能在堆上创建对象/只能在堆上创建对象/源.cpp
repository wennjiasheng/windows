#include<iostream>
using namespace std;
class HeapOnly
{
public:
	static HeapOnly* CreateObject()//静态成员函数可以不通过对象调用
	{
		return new HeapOnly;
	}
	~HeapOnly()
	{}
private:
	//C++98
	HeapOnly(const HeapOnly&);//只给声明（我们不需要实现）
	//在C++11，下面这个更方便，因为不用管权限
	//HeapOnly(const HeapOnly&) = delete;//不用管权限
private:
	HeapOnly()//构造函数
	{}
};
int main()
{
	HeapOnly *p = HeapOnly::CreateObject();//在堆上创建对象（1.开辟空间2.调用构造函数）
	return 0;
}
