#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
	/**
	*  奇数位上都是奇数或者偶数位上都是偶数
	*  输入：数组arr，长度大于2
	*  len：arr的长度
	*  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
	*/
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		vector<int> num;
		int n;
		if (len % 2 == 0)
		{
			n = len / 2;
		}
		else
		{
			n = len / 2 + 1;
		}
		num.resize(n);
		for (int i = 0; i<len; i++)
		{
			if (arr[i] % 2 == 0)
			{
				num[i / 2] = i;
			}
			if (num.size() == n)
			{
				break;
			}
		}
		if (num.size() == n)
		{
			for (int i = 0; i < len; i += 2)
			{
				swap(arr[i], arr[num[i / 2]]);
			}
		}
		else
		{
			for (int i = 0; i<n; i++)
			{

			}
			for (int i = 0; i<len; i++)
			{
				if (arr[i] % 2 == 1)
				{
					num[i / 2] = i;
				}
				if (num.size() == n)
				{
					break;
				}

			}

			for (int i = 1; i < len; i += 2)
			{
				swap(arr[i], arr[num[i / 2]]);
			}
		}

	}
};

