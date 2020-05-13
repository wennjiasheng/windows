#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Parenthesis {
public:
	bool chkParenthesis(string s) {
		// write code here
		if (s.length() % 2 == 0)
		{
			stack<char> sc;
			for (int i = 0; i < s.length(); i++)
			{
				if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				{
					sc.push(s[i]);
				}
				if (s[i] == ')')
				{
					if (sc.empty() || sc.top() != '(')
					{
						return false;
					}
					else
						sc.pop();
				}
				if (s[i] == ']')
				{
					if (sc.empty() || sc.top() != '[')
					{
						return false;
					}
					else
						sc.pop();
				}
				if (s[i] == '}')
				{
					if (sc.empty() || sc.top() != '{')
					{
						return false;
					}
					else
						sc.pop();
				}
			}
			if (sc.empty())
			{
				return true;
			}
			return false;
		}
	}
};

int main()
{
	Parenthesis a;
	string s;
	cin >> s;
	if (a.chkParenthesis(s))
	{
		cout << "À¨ºÅÆ¥Åä" << endl;
	}
	else
		cout << "À¨ºÅnoÆ¥Åä" << endl;
	system("pause");
	return 0;
}