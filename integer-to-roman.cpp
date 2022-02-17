// https://leetcode.com/problems/integer-to-roman/
#include "Utility.h"

string intToRoman(int num)
{
	vector<char>oneChar = { 'I', 'X', 'C', 'M' };
	vector<char>fiveChar = { 'V', 'L', 'D' };
	string result = "";
	int buf = num;
	for (int i = 0; i < 4 && buf > 0; ++i, buf /= 10)
	{
		int digit = buf % 10;
		if (digit == 0)
		{
			continue;
		}
		else if (digit < 4)
		{
			for (int j = 0; j < digit; ++j)
			{
				result.push_back(oneChar[i]);
			}
		}
		else if (digit == 4)
		{
			result.push_back(fiveChar[i]);
			result.push_back(oneChar[i]);
		}
		else if (digit < 9)
		{
			for (int j = 0; j < digit - 5; ++j)
			{
				result.push_back(oneChar[i]);
			}
			result.push_back(fiveChar[i]);
		}
		else
		{
			result.push_back(oneChar[i + 1]);
			result.push_back(oneChar[i]);
		}
	}
	std::reverse(result.begin(), result.end());
	return result;
}
