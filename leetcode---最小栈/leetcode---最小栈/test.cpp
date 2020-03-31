/*设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
push(x) --将元素 x 推入栈中。
pop() --删除栈顶的元素。
top() --获取栈顶元素。
getMin() --检索栈中的最小元素。
示例 :
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 - 3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 - 2.
来源：力扣（LeetCode*/


#include<iostream>
#include<stack>
using namespace std;
class MinStack 
{
public:     
	MinStack()     {}     
	void push(int x) 
	{      
		_data.push(x);
		// 如果x小于_min中栈顶的元素，将x再压入_min中        
		if(_min.empty() || x <= _min.top())      
			_min.push(x);  
	}    
	void pop()  
	{    	 
		if (_min.top() == _data.top())
			_min.pop();           
		_data.pop();
	}        
	int top()    
	{       
		return _data.top();
	}       
	int getMin()    
	{       
		return _min.top();  
	}
private:  
	// 保存栈中的元素  
	std::stack<int> _data;   
	// 保存栈的最小值   
	std::stack<int> _min;
};