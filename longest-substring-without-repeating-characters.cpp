//https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include "Utility.h"
#include <unordered_map>

using namespace std;

//??
int lengthOfLongestSubstring(string s)
{
    std::unordered_map<char, int> charMap;
    int result = 0, maxResult = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        unordered_map<char, int>::iterator it = charMap.find(s[i]);
        if (it == charMap.end())
        {
            charMap.insert({{s[i], i}});
            result += 1;
        }
        else
        {
            result = (i - it->second) > result ? result + 1 : i - it->second;
        }
        if (result > maxResult)
        {
            maxResult = result;
        }
        it->second = i;
    }
    return maxResult;
}

// using vector
int lengthOfLongestSubstring1(string s)
{
    vector<int> table(128, -1);
    int result = 0, maxResult = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (table[s[i]] == -1)
        {
            result += 1;
        }
        else
        {
            result = (i - table[s[i]]) > result ? result + 1 : i - table[s[i]];
        }
        if (result > maxResult)
        {
            maxResult = result;
        }
        table[s[i]] = i;
    }
    return maxResult;
}