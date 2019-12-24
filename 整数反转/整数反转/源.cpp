#include<iostream>

using namespace std;


class solution
{
public:
	int reserve(int n)
	{
		int a = 0;
		int sum = 0;
		while (n)
		{
			a = sum;
			sum = sum * 10 + n % 10;			
			n /= 10;
			if (sum / 10 != a)
			{
				return 0;
			}
		}
		return sum;
	}
};
int main()
{
	solution st;
	int n;	
	while (cin >> n)
	{
		cout << st.reserve(n) << endl;
	}
	system("pause");
	return 0;
}