#include<iostream>
#include<vector>
#include<string>
using namespace std;








class Solution {
public:
	bool isValid(string s) {
		if (s.empty())
			return true;
		vector<char> p;
		for (int i = 0; i<s.size(); i++)
		{
			if (p.empty())
			{
				p.push_back(s[i]);
			}
			else
			{
				if ((p.back() == '('&&s[i] == ')') || \
					(p.back() == '['&&s[i] == ']') || \
					(p.back() == '{'&&s[i] == '}'))
				{
					p.pop_back();
				}
				else
				{
					p.push_back(s[i]);
				}
			}
		}
		//空则返回true,说明匹配完
		if (p.empty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


int main()
{

	Solution st;
	string q = { '[', ']', '{', '}' };
	if (st.isValid(q) == true)
	{
		cout << "yes" << endl;
	}
	system("pause");
	return 0;
}