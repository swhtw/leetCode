// https://leetcode.com/problems/string-to-integer-atoi/
#include "Utility.h"

int myAtoi(string s) {
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
		if (result > 2147483647)
		{
			result = 2147483647;
		}
		else if (result < -2147483648)
		{
			result = -2147483648;
		}
	}
	return result;
}