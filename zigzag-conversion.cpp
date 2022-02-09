// https://leetcode.com/problems/zigzag-conversion/

#include "Utility.h"

string zigzag_conversion(string s, int numRows) {
	int loopSize = numRows * 2 - 2;
	int totalLoop = loopSize > 0 ? (s.length() % loopSize == 0 ? s.length() / loopSize : s.length() / loopSize + 1) : s.length();
	if (loopSize == 0)
	{
		loopSize = 1;
	}
	string result = "";
	for (int i = 0; i < totalLoop; ++i)
	{
		result.push_back(s[i * loopSize]);
	}
	for (int j = 1; j < numRows - 1; ++j)
	{
		for (int i = 0; i < totalLoop; ++i)
		{
			if (i * loopSize + j < s.length())
			{
				result.push_back(s[i * loopSize + j]);
			}
			if (i * loopSize + loopSize - j < s.length())
			{
				result.push_back(s[i * loopSize + loopSize - j]);
			}
		}
	}
	if (numRows >= 2)
	{
		for (int i = 0; i < totalLoop; ++i)
		{
			if (i * loopSize + numRows - 1 < s.length())
			{
				result.push_back(s[i * loopSize + numRows - 1]);
			}
		}
	}
	return result;
}

//PAHNAPLSIIGYIR