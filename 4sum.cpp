// https://leetcode.com/problems/4sum/
#include "Utility.h"

vector<vector<int>> threeSum(vector<int>& nums, long long int target, int firstNumber, vector<vector<int>> result) {
	for (int i = 0; i < nums.size() - 2; ++i)
	{
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}
		int j = i + 1, k = nums.size() - 1;
		while (j < k)
		{
			long long int a = nums[i], b = nums[j], c = nums[k];
			if (a + b + c == target)
			{
				if (result.size() == 0 || a != result[result.size() - 1][0] || b != result[result.size() - 1][1] || c != result[result.size() - 1][2])
				{
					vector<int> temp{ firstNumber, int(a), int(b), int(c) };
					result.push_back(temp);
				}
				do
				{
					--k;
				} while (nums[k] == c && j < k);
				do
				{
					++j;
				} while (nums[j] == b && j < k);
			}
			else if (a + b + c > target)
			{
				do
				{
					--k;
				} while (nums[k] == c && j < k);
			}
			else
			{
				do
				{
					++j;
				} while (nums[j] == b && j < k);
			}
		}
	}
	return result;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> result;
	if (nums.size() < 4)
	{
		return result;
	}
	std::sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 3; ++i)
	{
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}
		vector<int> buf(nums.begin() + i + 1, nums.end());
		result = threeSum(buf, target - nums[i], nums[i], result);
	}
	return result;
}