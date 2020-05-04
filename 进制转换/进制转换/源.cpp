#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string>
using namespace std;
int main()
{
	int num;//定义一个十进制数
	int n;//需要转化的进制数
	cin >> num >> n;

	string ret, total = "0123456789ABCDEF";
	//如果是负数
	bool flag = false;
	if (num < 0)
	{
		num = 0 - num;
		flag = true;
	}
	while (num)
	{
		ret += total[num % n];
		num /= n;
	}
	if (flag) ret += '-';
	reverse(ret.begin(), ret.end());
	cout << ret << endl;
	system("pause");
	return 0;
}