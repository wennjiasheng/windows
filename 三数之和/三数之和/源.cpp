//给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
//使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#if 0
class Solution {
public:
	vector<vector<int> > threeSum(vector<int>& nums) {
		vector<vector<int> > ret;
		int len = nums.size() - 2;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < len; i++)
		{
			int left = i + 1;
			int right = len + 1;
			while (left < right)
			{
				if (nums[i] + nums[left] < -nums[right])
				{
					left++;
				}
				else if (nums[i] + nums[left]>-nums[right])
				{
					right--;
				}
				else
				{
					if (i + 1 == left)
					{
						ret.push_back({ nums[i], nums[left], nums[right] });
					}
					else if (nums[left] != nums[left - 1])
					{
						ret.push_back({ nums[i], nums[left], nums[right] });
					}

					right--;
					left++;
				}
			}
		}
		return ret;
	}
};

int main()
{
	Solution t;
	int nu[] = { -1,0,1,2,-1,-4 };
	vector<int> nums(nu , nu + sizeof(nu)/sizeof(int));
	t.threeSum(nums);
	system("pause");
	return 0;
}
#endif
class Solution {
public:
	vector<vector<int> > threeSum(vector<int>& nums) {
		vector<vector<int> > ret;
		vector<int > vtemp;
		int len = nums.size();
		sort(nums.begin(), nums.end());//sort the input
		for (int i = 0; i<len - 2; i++){
			
			if (i == 0 || (i>0 && nums[i] != nums[i - 1])){
				int p1 = i + 1, p2 = len - 1; 
				while (p1 < p2){
					if (nums[p1] + nums[p2] < -nums[i]){
						p1++;
					}
					else if (nums[p1] + nums[p2] == -nums[i]){
						if (p1 == i + 1){
							vector<int > vtemp{ nums[i], nums[p1], nums[p2] };
							ret.push_back(vtemp);
							vtemp.clear();

						}
						else if (nums[p1] != nums[p1 - 1]){
							vector<int > vtemp{ nums[i], nums[p1], nums[p2] };
							ret.push_back(vtemp);
							vtemp.clear();

						}
						p1++, p2--;
					}
					else{
						p2--;
					}
				}
			}


		}
		return ret;

	}
};


int main()
{
	Solution t;
	int nu[] = { -1, 0, 1, 2, -1, -4 };
	vector<int> nums(nu , nu + sizeof(nu)/sizeof(int));
	t.threeSum(nums);
	system("pause");
	return 0;
}


#if 0
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int i = 0;
		for (int j = 1; j<nums.size(); j++){
			if (nums[i] != nums[j]){
				++i;
				//i++;
				nums[i] = nums[j];
			}
		}

		return i + 1;


	}
};

int main()
{
	vector<int> nums{ 0, 0, 1, 1, 1, 2, 3, 7};
	Solution t;
	t.removeDuplicates(nums);
	system("pause");
	return 0;
}
#endif