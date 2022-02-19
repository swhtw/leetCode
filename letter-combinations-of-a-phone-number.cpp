// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
#include "Utility.h"

vector<string> letterCombinations(string digits) {
	if (digits.size() == 0)
	{
		vector<string> result = {};
		return result;
	}
	vector<string> data = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> result = { "" };
	for (int i = 0; i < digits.size(); ++i)
	{
		int resultSize = result.size();
		for (int j = 0; j < resultSize; ++j)
		{
			for (int k = 0; k < data[digits[i] - '0'].size(); ++k)
			{
				result.push_back(result[j] + data[digits[i] - '0'][k]);
			}
		}
		vector<string>buf(result.begin() + resultSize, result.end());
		result = buf;
	}
	return result;
}