// https://leetcode.com/problems/3sum/
#include "Utility.h"

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> result;
	if (nums.size() < 3)
	{
		return result;
	}
	std::sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 2; ++i)
	{
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}
		int j = i + 1, k = nums.size() - 1;
		while (j < k)
		{
			int a = nums[i], b = nums[j], c = nums[k];
			if (a + b == -c)
			{
				if (result.size() == 0 || a != result[result.size() - 1][0] || b != result[result.size() - 1][1] || c != result[result.size() - 1][2])
				{
					vector<int> temp{ a, b, c };
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
			else if (a + b > -c)
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