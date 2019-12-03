#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void abcd(int n, int r)
{
	if (n / r)
		abcd(n / r, r);
	cout << n%r ;
}
int main()
{
	int n,r; 
	cin >> n >> r;
	abcd(n, r);
	system("pause");
	return 0;
}