#include<iostream>


using namespace std;

template<class T>
T Add(T right, T left)
{
	cout << typeid(right).name() << endl;
	return right + left;
}
int main()
{
	//ÒþÐÎÊµÀý»¯
	cout<<Add(1, 2) << endl;
	//cout << Add<double>((1, 2.0)) << endl;
	system("pause");
	return 0;
}