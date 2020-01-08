#include<iostream>
#include<string>
using namespace std;
class sulution {
public:

	int reverse(int x) {
		int flag = 0;
		string s = to_string(x);
		if (s[0] == '-'){
			flag = 1;
			s = s.substr(1);
		}
		std::reverse(s.begin(), s.end());
		long long val = atoll(s.c_str());
		if (flag)
		{
			val = -val;		
		}
		if (val >= INT_MAX || val <= INT_MIN)
			return 0;
		return val;
	}
};

int main()
{
	int n;
	cin >> n;
	sulution st;
	cout << st.reverse(n) << endl;;
	system("pause");
	return 0;
}