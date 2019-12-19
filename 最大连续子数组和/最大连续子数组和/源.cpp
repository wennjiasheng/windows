#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
public:
	int FindGreatestSumOfSubArray(vector<int> array){
		if (array.empty()){
			return -1;
		}
		// F(i)初始化
		int sum = array[0];
		// maxsum初始化
		int maxsum = array[0];
		for (int i = 1; i < array.size(); i++){
			// F(i) = max(F(i-1) + array[i]，array[i])
			sum = (sum > 0) ? sum + array[i] : array[i];
			// maxsum = max( maxsum，F(i))
			maxsum = (sum < maxsum) ? maxsum : sum;
		}
		return maxsum;
	}
};

int main()
{
	vector<int> arr;
	arr = { 1, 5, 9, -10, 7, 6, 9, -3, 6 };
	Solution s;
	cout << s.FindGreatestSumOfSubArray(arr) << endl;
	system("pause");
	return 0;
}