#include<iostream>
#include<stack>
#include<string>
using namespace std;
class myqueue {
public:
	
	void push(int x) {
		InputStack.push(x);
	}
	int pop() {
		while (!InputStack.empty())
		{
			OutputStack.push(InputStack.top());
			InputStack.pop();
		}
		int top = OutputStack.top();
		OutputStack.pop();
		while (!OutputStack.empty())
		{
			InputStack.push(OutputStack.top());
			OutputStack.pop();
		}
		return top;
	}
	int peek() {
		while (!InputStack.empty())
		{
			OutputStack.push(InputStack.top());
			InputStack.pop();
		}
		int top = OutputStack.top();
		while (!OutputStack.empty())
		{
			InputStack.push(OutputStack.top());
			OutputStack.pop();
		}
		return top;
	}
	bool empty() {
		if (OutputStack.empty() && InputStack.empty())
			return true;
		return false;
	}
private:
	stack<int> InputStack;
	stack<int> OutputStack;
};
int main()
{
	int n;
	cin >> n;
	string x;
	getline(cin, x);
	myqueue q;
	while (n != 0)
	{
		string str;
		getline(cin, str);
		if (str == "peek")
		{
			cout << q.peek() << endl;;
		}
		else if (str == "poll")
		{
			q.pop();
		}
		else
		{
			string  str1 = str.substr(str.find(' ') + 1);
			int num = 0;
			for (int i = 0; i < str1.size(); i++)
			{
				num = num * 10 + str1[i] - '0';
			}
			q.push(num);
		}
		n--;
	}
	system("pause");
	return 0;
}