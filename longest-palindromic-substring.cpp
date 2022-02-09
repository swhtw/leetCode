// https://leetcode.com/problems/longest-palindromic-substring/
#include "Utility.h"

string longestPalindrome(string s) {
	if (s.length() <= 1)
	{
		return s;
	}
	vector<vector<int>> counter(s.length());
	int maxLength = 1;
	int maxPosition = 0;
	counter[0].push_back(0);
	for (int i = 1; i < s.length(); ++i)
	{
		counter[i].push_back(0);
		counter[i].push_back(1);

		for (int j = 0; j < counter[i - 1].size(); ++j)
		{
			if (s[i] == s[i - 1 - counter[i - 1][j]])
			{
				if (i - (counter[i - 1][j] + 2) >= 0)
				{
					counter[i].push_back(counter[i - 1][j] + 2);
				}
				if (counter[i - 1][j] + 2 > maxLength)
				{
					maxLength = counter[i - 1][j] + 2;
					maxPosition = i;
				}
			}
		}
	}
	string result = s.substr(maxPosition - maxLength + 1, maxLength);
	return result;
}