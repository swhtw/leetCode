// https://leetcode.com/contest/weekly-contest-281/
#include "Utility.h"
#include <iostream>

int digitSum(int num)
{
	int result = 0;
	while (num > 0)
	{
		result += num % 10;
		num /= 10;
	}
	return result;
}

int countEven(int num) {
	int count = 0;
	for (int i = 1; i <= num; ++i)
	{
		if (digitSum(i) % 2 == 0)
		{
			++count;
		}
	}
	return count;
}

ListNode* mergeNodes(ListNode* head) {
	ListNode* result = new ListNode(-1, nullptr);
	ListNode* resultHead = result;
	int sumVal = 0;
	head = head->next;
	while (head != nullptr)
	{
		if (head->val == 0)
		{
			ListNode* buf = new ListNode(sumVal, nullptr);
			result->next = buf;
			result = result->next;
			sumVal = 0;
		}
		else
		{
			sumVal += head->val;
		}
		head = head->next;
	}
	return resultHead->next;
}

string repeatLimitedString(string s, int repeatLimit) {
	std::sort(s.begin(), s.end());
	std::reverse(s.begin(), s.end());
	vector<int> counter(26,0);
	for (int i = 0; i < s.size(); ++i)
	{
		++counter[s[i] - 'a'];
	}
	string result = "";
	bool lookBack = false;
	int lookBackIndex = -1;
	for (int i = 25; i >= 0; --i)
	{
		if (counter[i] > 0)
		{
			if (lookBack)
			{
				result.push_back('a' + i);
				--counter[i];
				lookBack = false;
				i = lookBackIndex + 1;
			}
			else
			{
				int repeatCounter = 0;
				for (; repeatCounter < repeatLimit && counter[i] > 0; ++repeatCounter, --counter[i])
				{
					result.push_back('a' + i);
				}
				if (repeatCounter == repeatLimit && counter[i] > 0)
				{
					lookBack = true;
					lookBackIndex = i;
				}
				else
				{
					lookBack = false;
				}
			}
		}
	}
	return result;
}

unsigned int gcd(unsigned int n1, unsigned int n2) {
	return (n2 == 0) ? n1 : gcd(n2, n1 % n2);
}

long long coutPairs(vector<int>& nums, int k) {
	int cnt[100001] = {};
	vector<int> a; //k计栋
	for (int i = 1; i * i <= k; ++i)
	{
		if (k % i == 0)
		{
			a.push_back(i);
			if (i * i != k)
			{
				a.push_back(k / i);
			}
		}
	}
	long long result = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		result += cnt[k / gcd(k, nums[i])]; // result计秖 k 籔 nums 程そ计
		for (auto j : a)
			cnt[j] += nums[i] % j == 0;
	}
	return result;
}
