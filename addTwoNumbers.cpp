// https://leetcode.com/problems/add-two-numbers/
//#include

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *result = l1, *l1Prev, *l2Prev;
    int summery = 0;
    while (l1 && l2)
    {
        summery = summery + l1->val + l2->val;
        l1->val = summery > 9 ? summery - 10 : summery;
        summery = summery > 9;
        l1Prev = l1, l2Prev = l2;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (!l1)
    {
        l1Prev->next = l2;
        l1 = l2;
    }
    while (l1)
    {
        summery += l1->val;
        l1->val = summery > 9 ? summery - 10 : summery;
        summery = summery > 9;
        l1Prev = l1;
        l1 = l1->next;
    }
    if (summery == 1)
    {
        ListNode *addNode = new ListNode;
        addNode->val = 1;
        addNode->next = nullptr;
        l1Prev->next = addNode;
    }
    return result;
}

int main()
{
    return 0;
}