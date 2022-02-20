// https://leetcode.com/problems/generate-parentheses/
#include "Utility.h"

vector<string> generateParenthesis(int n) {
	vector<string> result = { "(" };
	vector<int> resultLeft = { 1 };
	vector<int> resultRight = { 0 };
	int i = 0;
	while (result[i].size() < n * 2)
	{
		if (resultLeft[i] < n)
		{
			result.push_back(result[i] + "(");
			resultLeft.push_back(resultLeft[i] + 1);
			resultRight.push_back(resultRight[i]);
		}
		if (resultLeft[i] > resultRight[i])
		{
			result.push_back(result[i] + ")");
			resultLeft.push_back(resultLeft[i]);
			resultRight.push_back(resultRight[i] + 1);
		}
		++i;
	}
	result = vector<string>(result.begin() + i, result.end());
	return result;
}

vector<string> generateParenthesis1(int n) {
	vector<string> result = { "()" };
	for (int i = 0; i < n - 1; ++i)
	{
		int size = result.size();
		for (int j = 0; j < size; ++j)
		{
			for (int k = 0; k < result[j].size(); ++k)
			{
				for (int l = k; l < result[j].size(); ++l)
				{
					string buf = result[j];
					buf.insert(buf.begin() + k, '(');
					buf.insert(buf.begin() + l + 1, ')');
					result.push_back(buf);
					while (result[j][l] == ')')
					{
						++l;
					}
				}
				while (result[j][k] == '(')
				{
					++k;
				}
			}
		}
		result = vector<string>(result.begin() + size, result.end());
		set<string> s(result.begin(), result.end());
		result = vector<string>(s.begin(), s.end());
	}
	return result;
}