#include<iostream>
#include<string>
using namespace std;

int numroot(int sum)
{
	int nroot = 0;
	while (sum > 0)
	{
		nroot += sum % 10;
		sum /= 10;
	}
	while (nroot > 9)
	{
		nroot = numroot(nroot);
	}
	return nroot;
}
int main()

{
	string orgin;
	while (cin >> orgin)
	{
		int num = 0;
		for (int i = 0; i < orgin.length(); i++)
		{
			num += orgin[i] - '0';
		}
		cout << numroot(num) << endl;
	}
	system("pause");
	return 0;
}