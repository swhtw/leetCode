// https://leetcode.com/problems/string-to-integer-atoi/
#include "Utility.h"

int myAtoi(string s) {
	char phase = 0;
	bool isNative = false;
	long long int result = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == ' ') // phase 0
		{
			if (phase == 0)
			{
				continue;
			}
			else
			{
				break;
			}
		}
		else if (s[i] == '+' || s[i] == '-') // phase 1
		{
			if (phase == 0)
			{
				phase = 1;
				isNative = (s[i] == '-');
			}
			else
			{
				break;
			}
		}
		else if (s[i] >= '0' && s[i] <= '9') // phase 2
		{
			if (phase != 3)
			{
				phase = 2;
				result = result * 10 + (isNative ? (-s[i] + '0') : (s[i] - '0'));
				if (result > INT_MAX)
				{
					result = INT_MAX ;
					break;
				}
				else if (result < INT_MIN)
				{
					result = INT_MIN;
					break;
				}
			}
			else
			{
				break;
			}
		}
		else // phase 3
		{
			break;
		}
	}
	return result;
}

int myAtoi1(string s) {
	stringstream ss;
	long long int result = 0;
	smatch m;
	regex e("(^[ ]*)([+|-]?[0-9]+)");
	string data = s;
	if (std::regex_search(data, m, e)) {
		data = m[0];
		data = regex_replace(data, e, "$2");
		ss << data;
		ss >> result;
		if (result > INT_MAX)
		{
			result = INT_MAX ;
		}
		else if (result < INT_MIN)
		{
			result = INT_MIN;
		}
	}
	return result;
}