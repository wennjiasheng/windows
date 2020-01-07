#include<iostream>

using namespace std;
class Solution {
public:
	int reverse(int x) {
		int num = x;
		int res = 0;
		bool is_overflow = false;

		while (num){
			int d = num % 10;

			if (INT_MAX / 10 < res || res < INT_MIN / 10)
				is_overflow = true;
			else
				res = res * 10;
			if (num < 0){
				if (INT_MIN - d > res)
					is_overflow = true;
				else
					res = res + d;
			}

			if (num > 0){
				if (INT_MAX - d < res)
					is_overflow = true;
				else
					res = res + d;
			}
			num = num / 10;
		}
		if (is_overflow) return 0;
		return res;
	}
};

int main()
{
	Solution st;
	int a;
	cin >> a;
	cout << st.reverse(a) << endl;;
	system("pause");
	return 0;
}