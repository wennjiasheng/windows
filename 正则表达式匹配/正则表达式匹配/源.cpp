#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class stat{
public:
	int s_pos;
	int p_pos;
	stat(int s, int p){
		s_pos = s;
		p_pos = p;
	}

};
class Solution {
public:
	bool isMatch(string s, string p) {
		queue<stat>q;
		q.push(stat(0, 0));
		//记录访问过哪些状态
		vector<vector<int>>memo(s.size() + 2, vector<int>(p.size() + 2, 0));
		while (!q.empty()){
			stat top = q.front();
			q.pop();
			if (memo[top.s_pos][top.p_pos] == 1)
				continue;
			memo[top.s_pos][top.p_pos] = 1;
			//终止条件，能够完全匹配
			if (top.s_pos >= s.size() && top.p_pos >= p.size())
				return true;
			if (top.p_pos >= p.size())
				continue;
			if (p[top.p_pos] >= 'a' && p[top.p_pos] <= 'z'){
				if (top.p_pos + 1 < p.size() && p[top.p_pos + 1] == '*'){
					q.push(stat(top.s_pos, top.p_pos + 2)); //重复0次
					//枚举*的重复的次数
					for (int repeat = 1; repeat + top.s_pos <= s.size(); repeat++){
						if (p[top.p_pos] == s[top.s_pos + repeat - 1]){
							q.push(stat(top.s_pos + repeat, top.p_pos + 2));
						}
						else
							break;
					}
				}
				else{
					//只能匹配一个字符
					if (top.s_pos < s.size() && p[top.p_pos] == s[top.s_pos])
						q.push(stat(top.s_pos + 1, top.p_pos + 1));
				}
			}
			else if (p[top.p_pos] == '.'){
				//.可以匹配任何字符，因此不需要判断字符是否相等，只需要枚举repeat次数即可
				if (top.p_pos + 1 < p.size() && p[top.p_pos + 1] == '*'){
					q.push(stat(top.s_pos, top.p_pos + 2)); //重复0次
					for (int repeat = 1; repeat + top.s_pos <= s.size(); repeat++){
						q.push(stat(top.s_pos + repeat, top.p_pos + 2));
					}
				}
				else if (top.s_pos < s.size())
					q.push(stat(top.s_pos + 1, top.p_pos + 1));
			}
		}
		return false;
	}
};
