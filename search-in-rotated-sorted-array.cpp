// https://leetcode.com/problems/search-in-rotated-sorted-array/
#include "Utility.h"

int search(vector<int>& nums, int target) {
	if (nums.size() <= 3)
	{
		vector<int>::iterator it = std::find(nums.begin(), nums.end(), target);
		if (it == nums.end())
		{
			return -1;
		}
		return it - nums.begin();
	}
	else
	{
		int rangeLeft = 0, rangeRight = nums.size();
		int left = (rangeRight - rangeLeft) / 3, right = (rangeRight - rangeLeft) / 3 * 2;
	}
}