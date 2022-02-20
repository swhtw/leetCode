// https://leetcode.com/problems/swap-nodes-in-pairs/
#include "Utility.h"

ListNode* swapPairs(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}
	ListNode* fakeHead = new ListNode(-1, head);
	ListNode* now = fakeHead;
	while (now != nullptr && now->next != nullptr && now->next->next != nullptr)
	{
		// now->t1->t2->t3
		ListNode* t2 = now->next->next;
		now->next->next = t2->next; // t1->next = t3
		t2->next = now->next; // t2->next = t1
		now->next = t2;
		now = now->next->next;
	}
	return fakeHead->next;
}