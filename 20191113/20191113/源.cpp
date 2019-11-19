#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*class Solution {
public:
	int StrToInt(string str) {
		int sum = 0;
		int i = 0;
		if (str[0] == '+' || str[0] == '-')
		{
			i = 1;
		}
		for (; i<str.length(); i++)
		{

			if (str[i] >= '0' && str[i] <= '9')
			{
				sum = sum * 10 + (str[i] - 48);
			}
			else
			{
				return 0;
			}
		}
		if (str[0] == '-')
		{
			sum = (sum | (-1));
		}
		return sum;
	}
};


int main()
{

	Solution s;
	string str;
	getline(cin, str);
	int n = s.StrToInt(str);
	cout << n << endl;
	system("pause");
	return 0;
}*/
int main()
{
	int W, H;
	while (cin >> W >> H)
	{
		vector<int> n;
		n.resize = W*H;
		int count = 1;
		for (int i = 0; i < W; i++)
		{
			for (int j = 0; j < H; j++)
			{

			}
		}
	}
	system("pause");
	return 0;
}