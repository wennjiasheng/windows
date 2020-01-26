#include<iostream>


using namespace std;

class sulution
{
public:
	int bitcount(int n)
	{
		int count = 0;
		while (n != 0)
		{
			n = n&(n - 1);
			count++;
		}
		return count;
	}
	int bitcount2(int n)
	{
		int count = 0;
		while (n != 0)
		{
			if (n % 2 != 0)
			{
				count++;
			}
			n = n>>1;
		}
		return count;
	}
	int bitcount3(int n)
	{
		int count = 0;
		while (n != 0)
		{
			count += n & 1;
			n=n/2;
		}
		return count;
	}
};

int main()
{
	int n;
	cin >> n;
	sulution st;
	cout << st.bitcount(n)<< endl;
	cout << st.bitcount3(n) << endl;
	cout << st.bitcount2(n) << endl;

	system("pause");
	return 0;
}