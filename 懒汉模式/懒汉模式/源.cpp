//懒汉模式 第一次使用时创建 延迟加载
#include<iostream>
#include<mutex>
#include<thread>
using namespace std;
class Slingleton{
public:
	static volatile Slingleton* getinstrance()
	{
		if (m_pIns == nullptr)//防止线程阻塞
		{
			m_mutex.lock();
			if (m_pIns == nullptr)//volatile Slingleton* Slingleton::m_pIns = nullptr;
								  //将定义的静态变量初始化为空，第一次使用时创建对象，后面在调用
								  //指针不为空就无法创建对象

			{
				m_pIns = new Slingleton;
			}
			m_mutex.unlock();
		}
		return m_pIns;
	}
	class Gc{
	public:
		~Gc()
		{
			if (m_pIns)
			{
				delete m_pIns;
				m_pIns = nullptr;
			}
		}
	};
private:
	Slingleton()
	{
	}
	Slingleton(const Slingleton &) = delete;
	Slingleton &operator=(const Slingleton &) = delete;
	static volatile Slingleton* m_pIns ;
	static mutex m_mutex;
	static Gc m_gc;//静态成员变量在程序结束时销毁，m_gc在程序结束时析构函数释放new开辟的空间
};
volatile Slingleton* Slingleton::m_pIns = nullptr;
mutex Slingleton::m_mutex;
Slingleton::Gc m_gc;


void Treadfunc()
{
	cout << Slingleton::getinstrance() << endl;
}
void Test()
{
	thread t1(Treadfunc);	
	thread t2(Treadfunc);
	thread t3(Treadfunc);
	thread t4(Treadfunc);
	thread t5(Treadfunc);
	thread t6(Treadfunc);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
}
int main()
{
	Test();
	return 0;
}