// https://leetcode.com/problems/3sum-closest/
#include "Utility.h"

int threeSumClosest(vector<int>& nums, int target) {
	if (nums.size() == 3)
	{
		return std::accumulate(nums.begin(), nums.end(), 0);
	}
	sort(nums.begin(), nums.end());
	int result = 0;
	int diff = INT_MAX;
	for (int i = 0; i < nums.size() - 2; ++i)
	{
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}
		int j = i + 1, k = nums.size() - 1;
		while (j < k)
		{
			int threeSum = nums[i] + nums[j] + nums[k];
			if (threeSum == target)
			{
				return threeSum;
			}
			else if (threeSum > target)
			{
				--k;;
			}
			else
			{
				++j;
			}
			if (std::abs(threeSum - target) < diff)
			{
				diff = std::abs(threeSum - target);
				result = threeSum;
			}
		}
	}
	return result;
}