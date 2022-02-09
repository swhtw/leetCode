// https://leetcode.com/problems/reverse-integer/

#include "Utility.h"

int reverse_integer(int x) {
	long long int buf = abs(x), result = 0;
	bool native = x < 0;
	while (true)
	{
		result += buf % 10;
		buf /= 10;
		if (buf > 0)
		{
			result *= 10;
			if (-2147483648 > result || result > 2147483647)
			{
				return 0;
			}
		}
		else
		{
			break;
		}
	}
	if (native)
	{
		result *= -1;
	}
	return result;
}