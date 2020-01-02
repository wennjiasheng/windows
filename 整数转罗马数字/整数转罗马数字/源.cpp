#include<iostream>


using namespace std;


class Solution {
public:
	string intToRoman(int num) {
		if (num <= 0) return "";
		string ret = "";
		static int number[13] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		static string flags[13] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

		for (int i = 0; i < 13 && num > 0; i++){
			if (num < number[i]) continue;
			// cout<< i << " " << number[i] << " - " <<flags[i] << endl;  
			while (num >= number[i]){
				num -= number[i];
				ret += flags[i];
			}

		}
		return ret;
	}

};

int main()
{
	Solution st;
	string s = st.intToRoman(5);
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << endl;
	}
	system("pause");
	return 0;
}