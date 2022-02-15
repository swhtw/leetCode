// https://leetcode.com/problems/regular-expression-matching/
#include "Utility.h"

bool isMatch0(string s, string p) {
	smatch m;
	regex e("^" + p + "$");
	return std::regex_match(s, m, e);
}

bool isMatch(string s, string p) {
	// 4 types: a, a*, ., .*
	string::iterator sit = s.begin();
	string::iterator pit = p.begin();
	vector<int> patternType;
	vector<string> patternStr;
	while (pit < p.end())
	{
		if (*pit == '.' && (pit + 1 != p.end() && *(pit + 1) == '*'))
		{
			patternStr.push_back(".*");
			patternType.push_back(4);
			pit += 2;
		}
		else if (*pit == '.')
		{
			patternStr.push_back(".");
			patternType.push_back(3);
			pit += 1;
		}
		else
		{
			string::iterator buf = std::min(std::find(pit, p.end(), '.'), std::find(pit, p.end(), '*'));
			if (buf == p.end() || *buf == '.')
			{
				patternStr.push_back(string(pit, buf));
				patternType.push_back(1);
				pit = buf;
			}
			else
			{
				if (pit < buf - 1)
				{
					patternStr.push_back(string(pit, buf - 1));
					patternType.push_back(1);
				}
				patternStr.push_back(string(buf - 1, buf + 1));
				patternType.push_back(2);
				pit = buf + 1;
			}
		}
	}
	for (int i = 0; i < patternType.size(); ++i)
	{
		if (patternType[i] == 1)
		{
			std::size_t found = string(sit, s.end()).find(patternStr[i]);
			if (found != std::string::npos)
			{
				if (found != 0)
				{
					if (i == 0)
					{
						return false;
					}
					else if (patternType[i - 1] == 2)
					{
						for (string::iterator sit1 = sit; sit1 < sit + found; ++sit1)
						{
							if (*sit1 != patternStr[i - 1][0])
							{
								return false;
							}
						}
					}
				}
				sit = sit + found + patternStr[i].length();
			}
			else
			{
				return false;
			}
		}
		else if (patternType[i] == 3)
		{
			sit += 1;
		}
		if (i == patternType.size() - 1 && patternType[i] == 2)
		{
			for (; sit < s.end(); ++sit)
			{
				if (*sit != patternStr[i][0])
				{
					return false;
				}
			}
		}
		if (i == patternType.size() - 1 && patternType[i] == 4)
		{
			sit = s.end();
		}
	}
	return sit == s.end();
}

bool isMatch2(string s, string p) {
	bool mustMatch = true;
	string::iterator sit = s.begin();
	string::iterator pit = p.begin();
	while (sit != s.end() && pit != p.end())
	{
		if (*pit == '.' && *(pit + 1) == '*')
		{
			pit += 2;
			if (*pit >= 'a' && *pit <= 'z')
			{
				if (*(pit + 1) != '*')
				{
					sit = std::find(sit, s.end(), *pit);
					if (sit == s.end())
					{
						return false;
					}
					++sit;
					++pit;
				}
				else
				{
					while (*sit == *pit)
					{
						++sit;
					}
					pit += 2;
				}

			}
		}
		else if (*pit == '.')
		{
			++sit;
		}
		else
		{
			if (*(sit++) != *(pit++))
			{
				if (*pit != '*')
				{
					return false;
				}
			}
		}

	}
}

class Solution {
public:
	bool isMatch(string s, string p) {
		// we use 2 pointers to match, one for s and one for p.
		// for the pointer in p, if the char is not '*', then we need to look ahead
		// one char to see if it's '*'. If it is, we try to move the pointer in 
		// s one or more time, until it does not match.
		// But for .*, we need to handle it differently.
		// if the pattern is like .*ab and the string is like ccabab, then
		// we need to match .* with ccab, and then the last ab is matched.
		// we can use backtracking to solve it.
		// we use 2 functions, one is normal match, which is used to match.
		// non .* pattern, and a .* match, which is used to match .*.
		// time: O(n*m)
		// space: O(m)
		// because there is repeat computation, we can use dp to reduce the overhead.

		vector<int> dp((s.size() + 1) * p.size(), -1);

		return normalMatch(s, 0, p, 0, dp);
	}

	bool normalMatch(const string& s, int si, const string& p, int pi, vector<int>& dp) {
		if (si >= s.size() && pi >= p.size()) {
			return true;
		}

		if (dp[si * p.size() + pi] >= 0) {
			return dp[si * p.size() + pi];
		}

		int i = si;
		int j = pi;
		for (; i < s.size() && j < p.size(); ++i, ++j) {
			if (j + 1 >= p.size() || p[j + 1] != '*') {
				if (p[j] != '.') {
					if (s[i] != p[j]) {
						dp[si * p.size() + pi] = 0;
						return false;
					}
				}
			}
			else {
				bool ret = starMatch(s, i, p, j, dp);
				dp[si * p.size() + pi] = ret ? 1 : 0;
				return ret;
			}
		}
		// we may need to starMatch the end part
		if (i == s.size() && j == p.size()) {
			dp[si * p.size() + pi] = 1;
			return true;
		}
		if (j == p.size()) {
			dp[si * p.size() + pi] = 0;
			return false;
		}
		if (j + 1 < p.size()) {
			if (p[j + 1] == '*') {
				bool ret = starMatch(s, i, p, j, dp);
				dp[si * p.size() + pi] = ret ? 1 : 0;
				return ret;
			}
		}

		dp[si * p.size() + pi] = 0;
		return false;
	}

	bool starMatch(const string& s, int si, const string& p, int pi, vector<int>& dp) {
		if (dp[si * p.size() + pi] >= 0) {
			return dp[si * p.size() + pi];
		}

		if (normalMatch(s, si, p, pi + 2, dp)) {  // zero match
			dp[si * p.size() + pi] = 1;
			return true;
		}

		auto c = p[pi];
		for (; si < s.size(); ++si) {
			if (c == '.' || s[si] == c) {
				if (normalMatch(s, si + 1, p, pi + 2, dp)) {
					dp[si * p.size() + pi] = 1;
					return true;
				}
			}
			else {
				bool ret = normalMatch(s, si, p, pi + 2, dp);
				dp[si * p.size() + pi] = ret ? 1 : 0;
				return ret;
			}
		}

		dp[si * p.size() + pi] = 0;
		return false;
	}
};