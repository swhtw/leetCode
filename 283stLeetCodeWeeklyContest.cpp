// https://leetcode.com/contest/weekly-contest-283/
#include "Utility.h"

vector<string> cellsInRange(string s) {
	vector<string> result;
	for (char c1 = s[0]; c1 <= s[3]; ++c1)
	{
		for (char c2 = s[1]; c2 < s[4]; ++c2)
		{
			string s1 = "";
			s1.push_back(c1);
			s1.push_back(c2);
			result.push_back(s1);
		}
	}
	return result;
}

long long minimalKSum(vector<int>& nums, int k) {
	sort(nums.begin(), nums.end());
	long long result = 0;
	int count = 0;
	long long int base = 1;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] <= base)
		{
			base = nums[i] + 1;
			continue;
		}
		if (count + nums[i] - base >= k)
		{
			long long int temp = ((base + base + k - count - 1) * (k - count)) / 2;
			result += temp;
			return result;
		}
		long long int temp = ((base + nums[i] - 1) * (nums[i] - base)) / 2;
		result += temp;
		count += (nums[i] - base);
		base = nums[i] + 1;
	}
	if (count < k)
	{
		long long int temp = ((base + base + k - count - 1) * (k - count)) / 2;
		result += temp;
	}
	return result;
}