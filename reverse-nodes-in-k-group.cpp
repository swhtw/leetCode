// https://leetcode.com/problems/reverse-nodes-in-k-group/
#include "Utility.h"

ListNode* reverseKGroup(ListNode* head, int k) {
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