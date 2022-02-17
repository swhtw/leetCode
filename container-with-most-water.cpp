// https://leetcode.com/problems/container-with-most-water/
#include "Utility.h"

int maxArea(vector<int>& height) {
	int result = 0, l = 0, r = height.size() - 1;
	while (l < r)
	{
		result = std::max(result, std::min(height[l], height[r]) * (r - l));
		if (height[l] < height[r])
		{
			++l;
		}
		else if (height[l] > height[r])
		{
			--r;
		}
		else
		{
			++l;
			--r;
		}
	}
	return result;
}

int maxArea1(vector<int>& height) {
	int result = 0;
	vector<int>::iterator l = height.begin();
	vector<int>::iterator r = height.end() - 1;
	while (l < r)
	{
		int buf = std::min(*l, *r) * (r - l);
		if (buf > result)
		{
			result = buf;
		}
		if (*l < *r)
		{
			++l;
		}
		else if (*l > *r)
		{
			--r;
		}
		else
		{
			++l;
			--r;
		}
	}
	return result;
}