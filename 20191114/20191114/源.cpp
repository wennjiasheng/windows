#include<iostream>
#include<stack>
using namespace std;

class Parenthesis {
public:

	int check(char a, char b)
	{
		if (a == '(')
		{
			if (b == ')')
				return 1;
		}
		if (a == '[')
		{
			if (b == ']')
				return 1;
		}
		if (a == '{')
		{
			if (b == '}')
				return 1;
		}
		return 0;
	}
	bool chkParenthesis(string A, int n) {
		// write code here
		stack<char>a;
		for (int i = 0; i < n; i++)
		{
			if ((A[i] == '(') || (A[i] == '[') || (A[i] == '{') || (A[i] == '(') || (A[i] == '[') || (A[i] == '{'))
			{
				if ((A[i] == '(') || (A[i] == '[') || (A[i] == '{'))
				{
					a.push(A[i]);
				}
				if ((A[i] == '(') || (A[i] == '[') || (A[i] == '{'))
				{
					if (a.empty() == 1)
					{
						return false;
					}
					if (check(A[i], a.top()))
					{
						a.pop();
					}
					return false;
				}
			}
			else
			{
				return false;
			}
		
		}
		if (a.empty() == 1)
		{
			return true;
		}
		else
			return false;
	}
};