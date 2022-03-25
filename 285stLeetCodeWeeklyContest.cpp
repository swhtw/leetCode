// https://leetcode.com/contest/weekly-contest-285/
#include "Utility.h"

int countHillValley(vector<int>& nums) {
	int result = 0;
	for (int i = 1; i < nums.size() - 1;)
	{
		int j = i + 1;
		int next = 0;
		for (; j < nums.size(); ++j)
		{
			if (nums[j] != nums[i])
			{
				next = j;
				break;
			}
		}
		if (next == 0)
		{
			break;
		}
		if (nums[i] > nums[i - 1] && nums[i] > nums[next])
		{
			++result;
		}
		if (nums[i] < nums[i - 1] && nums[i] < nums[next])
		{
			++result;
		}
		i = j;
	}
	return result;
}

int countCollisions(string directions) {
	int result = 0;
	for (int i = 0; i < directions.length() - 1; ++i)
	{
		if (directions[i] == 'R' && directions[i + 1] == 'L')
		{
			result += 2;
			directions[i] = 'S';
			directions[i + 1] = 'S';
			continue;
		}
		if (directions[i] == 'R' && directions[i + 1] == 'S')
		{
			++result;
			directions[i] = 'S';
			directions[i + 1] = 'S';
			continue;
		}
		if (directions[i] == 'S' && directions[i + 1] == 'L')
		{
			++result;
			directions[i] = 'S';
			directions[i + 1] = 'S';
			continue;
		}
	}
	return result;
}

int countCollisions(string directions) {
	vector<int> temp(directions.length(), 0);
	int result = 0;
	for (int i = 0; i < directions.length() - 1; ++i)
	{
		if (directions[i] == 'R')
		{
			if (directions[i + 1] == 'S')
			{
				directions[i] = 'S';
				result += ++temp[i + 1];
			}
			else if (directions[i + 1] == 'L')
			{
				directions[i] = 'S';
				directions[i + 1] = 'S';
				++temp[i];
				++temp[i + 1];
				result += 2;
			}
			else
			{
				continue;
			}
		}
		else if (directions[i] == 'S')
		{
			if (directions[i + 1] == 'L')
			{
				directions[i + 1] = 'S';
				result += ++temp[i];
			}
		}
	}
	return result;
}

int countCollisions(string directions) {
	vector<int> temp(directions.length() * 2, 0);
	int result = 0;
	for (int i = 0; i < directions.length() - 1; ++i)
	{
		if (directions[i] == 'R')
		{
			if (directions[i + 1] == 'S')
			{
				directions[i] = 'S';
				result += ++temp[i * 2];
			}
			else if (directions[i + 1] == 'L')
			{
				directions[i] = 'S';
				directions[i + 1] = 'S';
				temp[i * 2 + 1] += 2;
				result += 2;
			}
			else
			{
				continue;
			}
		}
		else if (directions[i] == 'S')
		{
			if (directions[i + 1] == 'L')
			{
				directions[i + 1] = 'S';
				result += ++temp[i * 2];
			}
		}
	}
	return result;
}