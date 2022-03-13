// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
#include "Utility.h"

vector<int> findSubstring(string s, vector<string>& words) {
	if (s.empty() || words.empty()) return {};

	unordered_map<string, int> wordsCount;
	int sumLength = 0;
	for (int i = 0; i < words.size(); ++i)
	{
		sumLength += words[i].length();
		++wordsCount[words[i]];
	}
	vector<int> result = {};
	int i = 0;
	int limitSize = (int)(s.length()) - sumLength;
	while (i <= limitSize)
	{
		unordered_map<string, int> wordsCountBuf = wordsCount;
		bool flag = false;
		int j = 0;
		do
		{
			flag = false;
			for (unordered_map<string, int>::iterator it = wordsCountBuf.begin(); it != wordsCountBuf.end(); ++it)
			{
				if (it->second == 0)
				{
					continue;
				}
				else if (s.substr(i + j, it->first.length()) == it->first)
				{
					--it->second;
					j += it->first.length();
					flag = true;
					break;
				}
			}
			if (j == sumLength)
			{
				break;
			}
		} while (flag);
		if (flag)
		{
			result.push_back(i);
		}
		++i;
	}
	return result;
}