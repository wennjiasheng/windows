#include<iostream>
#include<math.h>
using namespace std;
bool issushu(int a)
{
	if (a == 1)
		return false;
	if (a == 2 || a == 3)
		return true;
	for (int i = 2; i <= sqrt(a); i++)
	{
		if (a%i == 0)
			return false;
	}
	return true;
}
void fenjieyinshi(int a)
{
	if (issushu(a))
		cout << a << endl;
	for (int i = 2; i <= sqrt(a); i++)
	{
		if (a%i == 0)
		{
			cout << i << " * ";
			a /= i;
			fenjieyinshi(a);
			break;
		}
	}
	
}
int main()
{	
	int a;
	while (cin >> a)
	{
		cout << a << " = ";
		fenjieyinshi(a);
	}
	system("pause");
	return 0;
}