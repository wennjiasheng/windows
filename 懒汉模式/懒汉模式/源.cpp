//懒汉模式 第一次使用时创建 延迟加载

#include<iostream>
#include<mutex>
#include<thread>


using namespace std;

class Slingleton{
public:
	static volatile Slingleton* getinstrance()
	{
		if (m_pIns == nullptr)
		{
			m_mutex.lock();
			if (m_pIns == nullptr)
			{
				m_pIns = new Slingleton;
			}
			m_mutex.unlock();
		}
		return m_pIns;
	}
private:
	Slingleton()
	{

	}
	Slingleton(const Slingleton &) = delete;
	Slingleton &operator=(const Slingleton &) = delete;
	static volatile Slingleton* m_pIns ;
	static mutex m_mutex;
};

volatile Slingleton* Slingleton::m_pIns = nullptr;
mutex Slingleton::m_mutex;


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