// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
#include "Utility.h"

ListNode* removeNthFromEnd(ListNode* head, int n) {
	if (head->next == nullptr)
	{
		return nullptr;
	}
	ListNode* beforeHead = new ListNode(-1, head);
	ListNode* temp1 = beforeHead;
	ListNode* temp2 = head;
	head = beforeHead;
	for (int i = 0; i < n; ++i)
	{
		temp2 = temp2->next;
	}
	while (temp2 != nullptr)
	{
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	temp1->next = temp1->next->next;
	return head->next;
}