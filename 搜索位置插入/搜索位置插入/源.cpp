#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (target<nums[0])
			return 0;
		if (target>nums[nums.size() - 1])
			return nums.size();

		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (target<nums[mid])
				right = mid - 1;
			else if (target>nums[mid])
				left = mid + 1;
			else if (target == nums[mid])
				return mid;
		}
		//到这里说明没有在数组里找到，但大小在数组中间
		if (target<nums[mid])
		{
			while (mid >= 0)
			{
				if (target>nums[mid])
					return mid + 1;
				mid--;
			}
		}
		else if (target>nums[mid])
		{
			while (mid<nums.size())
			{
				if (target<nums[mid])
					return mid;
				mid++;
			}
		}
		return mid;
	}
};
