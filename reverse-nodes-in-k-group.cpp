// https://leetcode.com/problems/reverse-nodes-in-k-group/
#include "Utility.h"

ListNode* reverseKGroup(ListNode* head, int k) {
	ListNode* fakeHead = new ListNode(-1, head);
	ListNode* temp = fakeHead;
	while (temp != nullptr)
	{
		ListNode* start = temp;
		for (int i = 0; i < k; ++i)
		{
			temp = temp->next;
			if (temp == nullptr)
			{
				return fakeHead->next;
			}
		}
		ListNode* nextStart = start->next;
		ListNode* end = temp;
		ListNode* prev = end->next;
		ListNode* current = start->next;
		ListNode* next = current->next;
		for (int i = 0; i < k; ++i)
		{
			current->next = prev;
			prev = current;
			current = next;
			if (next != nullptr)
			{
				next = next->next;
			}
		}
		start->next = temp;
		temp = nextStart;
	}
	return fakeHead->next;
}

ListNode* reverseKGroup1(ListNode* head, int k) {
	ListNode* fakeHead = new ListNode(-1, head);
	ListNode* temp = fakeHead->next;
	while (temp != nullptr)
	{
		ListNode* temp1 = temp;
		stack<int>vals;
		for (int i = 0; i < k; ++i)
		{
			if (temp == nullptr)
			{
				return fakeHead->next;
			}
			vals.push(temp->val);
			temp = temp->next;
		}
		for (int i = 0; i < k; ++i)
		{
			temp1->val = vals.top();
			temp1 = temp1->next;
			vals.pop();
		}
	}
	return fakeHead->next;
}