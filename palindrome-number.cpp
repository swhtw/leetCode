// https://leetcode.com/problems/palindrome-number/
#include "Utility.h"

bool isPalindrome1(int x) {
	if (x < 0)
	{
		return false;
	}
	int xbuf = x;
	long long int rx = 0;
	while (xbuf > 0)
	{
		rx = (rx * 10) + (xbuf % 10);
		xbuf /= 10;
	}
	return rx == x;
}

bool isPalindrome(int x) {
	if (x < 0)
	{
		return false;
	}
	stringstream ss;
	ss << x;
	string s;
	ss >> s;
	int i = 0, j = s.length() - 1;
	while (i <= j)
	{
		if (s[i] != s[j])
		{
			return false;
		}
		++i;
		--j;
	}
	return true;
}