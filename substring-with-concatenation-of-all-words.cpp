// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
#include "Utility.h"

struct WordIndex
{
	int length;
	vector<int> index;
};

bool compare(WordIndex const &left, WordIndex const &right)
{
	return left.index[0] > right.index[0];
}

vector<int> findSubstring(string s, vector<string>& words) {
	vector<int> result = {};

	vector<WordIndex> wordIndex(words.size());
	for (int i = 0; i < words.size(); ++i)
	{
		wordIndex[i].length = words[i].length();
		string buf = s;
		int offset = 0;
		size_t foundIndex = buf.find(words[i]);
		while (foundIndex != std::string::npos)
		{
			wordIndex[i].index.push_back(offset + foundIndex);
			offset += (foundIndex + 1);
			buf = buf.substr(foundIndex + 1);
			foundIndex = buf.find(words[i]);
		}
		if (wordIndex[i].index.size() == 0)
		{
			return result;
		}
	}
	std::sort(wordIndex.begin(), wordIndex.end(), &compare);
	std::make_heap(wordIndex.begin(), wordIndex.end(), &compare);
	return result;
}