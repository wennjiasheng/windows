#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		int len = s.size();
		if (len <= numRows || numRows == 1) return s;
		int T = 2 * (numRows - 1);
		string res;
		for (int i = 0; i < numRows; ++i){
			//cout << "i: " << i << endl;
			int j = i, step = T - 2 * i;
			if (step == 0){
				step = T;
			}
			while (j < len){
				//cout << "j: " << j << endl;
				res += s[j];
				j += step;
				if (step < T){
					step = T - step;
				}
			}
		}
		return res;
	}
};


int main()
{
	Solution t;
	string s("abcdefghijkl");
	cout << t.convert(s, 4)<<endl;
	system("pause");
	return 0;
}