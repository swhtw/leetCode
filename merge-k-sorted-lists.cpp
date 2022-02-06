// https://leetcode.com/problems/merge-k-sorted-lists/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool listNodeCompare(ListNode *const &listNode1, ListNode *const &listNode2)
{
    return listNode1->val < listNode2->val;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.empty())
    {
        return nullptr;
    }
    ListNode *result = nullptr;
    ListNode *resultFront = nullptr;
    std::make_heap(lists.begin(), lists.end(), &listNodeCompare);
    result = resultFront = *lists.begin();
    while (!lists.empty())
    {
        if (*lists.begin() != nullptr)
        {
            result->next = *lists.begin();
            result = result->next;
            *lists.begin() = (*lists.begin())->next;
        }
        else
        {
            lists.erase(lists.begin());
        }
        std::make_heap(lists.begin(), lists.end(), &listNodeCompare);
    }
    return resultFront;
}

int main()
{
    cout << "Hello, world!" << endl;
    return 0;
}