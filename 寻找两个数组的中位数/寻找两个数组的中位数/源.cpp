#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size() + nums2.size();
		vector<double> nums;
		nums.reserve(n);
		for (int i = 0, j = 0; i != nums1.size() || j != nums2.size();)
		{
			if (i == nums1.size()&&j!=nums2.size())
			{
				nums.push_back(nums2[j]);
				j++;
				continue;
			}
			if (i != nums1.size() && j == nums2.size())
			{
				nums.push_back(nums1[i]);
				i++;
				continue;
			}
			if (nums1[i] < nums2[j])
			{
				nums.push_back(nums1[i]);
				i++;
			}
			else if (nums1[i]>nums2[j])
			{
				nums.push_back(nums2[j]);
				j++;
			}
			else{
				nums.push_back(nums1[i]);
				nums.push_back(nums2[j]);
				i++;
				j++;
			}
		}
		if (n % 2 == 1)
		{
			return nums[n / 2];
		}
		else{
			return (nums[n / 2] + nums[n / 2 - 1]) / 2;
		}
	}
};

int main()
{
	vector<int> a = { 1, 2 };
	vector<int> b = { 3, 4 };
	Solution t;
	cout << t.findMedianSortedArrays(a, b) << endl;
	system("pause");
	return 0;
}