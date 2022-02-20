// https://leetcode.com/problems/divide-two-integers/
#include "Utility.h"

int divide(int dividend, int divisor) {
	long long int temp1 = std::abs((long long int)dividend), temp2 = std::abs((long long int)divisor);
	long long int result = temp1 / temp2;

	if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
	{
		result = -result;
	}
	if (result > INT_MAX)
	{
		result = INT_MAX;
	}
	else if (result < INT_MIN)
	{
		result = INT_MIN;
	}
	return result;
}