// https://leetcode.com/problems/palindrome-linked-list/
#include "Utility.h"

bool isPalindrome(ListNode* head) {
	vector<int> v;
	while (head != nullptr)
	{
		if (v.size() >= 1 && head->val == *(v.end() - 1))
		{
			v.erase(v.end() - 1);
		}
		else if (v.size() >= 2 && head->val == *(v.end() - 2))
		{
			v.erase(v.end() - 2, v.end());
		}
		else
		{
			v.push_back(head->val);
		}
		head = head->next;
	}
	return v.size() < 2;
}

bool isPalindrome1(ListNode* head) {
	string s = "";
	while (head != nullptr)
	{
		s.push_back(head->val + '0');
		head = head->next;
	}
	string s1 = s;
	reverse(s1.begin(), s1.end());
	return s == s1;
}