#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		vector <int> arr(nums.size(),0);
		for (int i = 0; i <nums.size(); i++)
		{
			arr[nums[i]]++;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (arr[i] == 2)
				return i;
		}
	}
};
int main()
{
	int myints[] = {1,2,3,4,5,6,7,8,9,1};
	std::vector<int> s(myints, myints + sizeof(myints) / sizeof(int));
	Solution t;
	cout << t.findDuplicate(s) << endl;
	system("pause");
	return 0;
}