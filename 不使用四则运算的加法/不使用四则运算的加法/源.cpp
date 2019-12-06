/*class Solution {
public:
	int Add(int num1, int num2)
	{
		if (num1 == 0)
			return num2;
		if (num2 == 0)
			return num1;
		int n, sum;
		do{
			n = num1^num2;
			sum = (num1&num2) << 1;
			num1 = n;
			num2 = sum;
		} while (sum != 0);
		return n;
	}
};*/
#include<iostream>

using namespace std;

int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		if ((a + b>c) && (a + c>b) && (b + c>a))
		{
			cout << "Yes" << endl;
		}
		else
			cout << "No" << endl;
	}
	return 0;
}