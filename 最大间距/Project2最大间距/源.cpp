#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size()<2)
		{
			return 0;
		}
		sort(nums.begin(), nums.end());
		int Max = 0;
		for (int i = 0; i<nums.size() - 1; i++)
		{
			Max = max(nums[i + 1] - nums[i], Max);
		}
		return Max;
	}
};
int main()
{
	vector<int> arr = { 2, 3, 9, 5, 7, 1 };
	Solution s;
	cout<<s.maximumGap(arr)<<endl;
	system("pause");
	return 0;
}