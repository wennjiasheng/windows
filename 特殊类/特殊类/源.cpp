#include<iostream>

using namespace std;

class heaponly
{
public:
	static heaponly* creatobject()
	{
		return new heaponly;
	}
private:
	heaponly()//将构造函数设置为私有，编译器不能调用构造函数
	{

	}
	heaponly(const heaponly&);//声明不实现，不需要用到拷贝构造函数，设置为私有，防止自己实现拷贝构造
	//heaponly(const heaponly&)c++11 告诉编译器不需要拷贝构造
};

int main()
{
	heaponly *p = heaponly::creatobject();
	return 0;
}