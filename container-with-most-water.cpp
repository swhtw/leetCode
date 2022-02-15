// https://leetcode.com/problems/container-with-most-water/
#include "Utility.h"

struct Status
{
	int left;
	int right;
	int resultLL;
	int resultLR;
	int resultRL;
	int resultRR;
	Status() : left(0), right(0), resultLL(-1), resultLR(-1), resultRL(-1), resultRR(-1) {}
	Status(vector<int>& height) : left(0), right(height.size() - 1), resultLL(-1), resultLR(-1), resultRL(-1), resultRR(-1) {}
};

int maxArea0(vector<int>& height) {
	int result = 0;
	//stack<Status> status;
	//status.push(Status(height));
	//while (!status.empty())
	//{
	//	// conquer
	//	if (status.top().right - status.top().left == 1)
	//	{
	//		int resultL = status.top().left;
	//		int resultR = status.top().right;
	//		status.pop();
	//		if (status.top().resultLL == -1)
	//		{
	//			status.top().resultLL = resultL;
	//			status.top().resultLR = resultR;
	//		}
	//		else
	//		{
	//			status.top().resultRL = resultL;
	//			status.top().resultRR = resultR;
	//		}
	//	}
	//	else if (status.top().right - status.top().left == 2)
	//	{
	//		int result1 = status.top().left;
	//		int result2 = status.top().left + 1;
	//		int result3 = status.top().right;
	//		status.pop();
	//		if (status.top().resultLL == -1)
	//		{
	//			status.top().resultLL = resultL;
	//			status.top().resultLR = resultR;
	//		}
	//		else
	//		{
	//			status.top().resultRL = resultL;
	//			status.top().resultRR = resultR;
	//		}
	//	}
	//	else
	//	{

	//	}
	//}
	return result;
}

int maxArea1(vector<int>& height) {
	int result = 0;
	bool left = true;
	vector<int>::iterator l = height.begin();
	vector<int>::iterator r = height.end() - 1;
	while (l < r)
	{
		int buf = std::min(*l, *r) * std::abs(r - l);
		if (buf > result)
		{
			result = buf;
		}
		if (left)
		{
			++l;
		}
		else
		{
			--r;
		}
		left = !left;
	}
	return result;
}

int maxArea(vector<int>& height) {
	vector<int> leftIndex, rightIndex;
	int LMin = 0, RMin = 0;
	for (int i = 0; i < height.size(); ++i)
	{
		if (height[i] > LMin)
		{
			leftIndex.push_back(i);
			LMin = height[i];
		}
		if (height[height.size() - 1 - i] > RMin)
		{
			rightIndex.push_back(height.size() - 1 - i);
			RMin = height[height.size() - 1 - i];
		}
	}
	int result = 0;
	for (int l = 0; l < leftIndex.size(); ++l)
	{
		for (int r = 0; r < rightIndex.size(); ++r)
		{
			int buf = std::min(height[leftIndex[l]], height[rightIndex[r]]) * std::abs(rightIndex[r] - leftIndex[l]);
			if (buf > result)
			{
				result = buf;
			}
		}
	}
	return result;
}