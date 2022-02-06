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
    if (listNode1 == nullptr)
    {
        return false;
    }
    if (listNode2 == nullptr)
    {
        return true;
    }
    return listNode1->val > listNode2->val;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.empty())
    {
        return nullptr;
    }
    std::make_heap(lists.begin(), lists.end(), &listNodeCompare);
    ListNode *result = nullptr;
    ListNode *resultFront = nullptr;
    while (!lists.empty())
    {
        std::pop_heap(lists.begin(), lists.end(), &listNodeCompare);
        if (lists.back() != nullptr)
        {
            if (resultFront == nullptr)
            {
                result = resultFront = lists.back();
            }
            else
            {
                result->next = lists.back();
                result = result->next;
            }
        }
        if (lists.back() != nullptr)
        {
            lists.back() = lists.back()->next;
            if (lists.back() != nullptr)
            {
                std::push_heap(lists.begin(), lists.end(), &listNodeCompare);
            }
            else
            {
                lists.pop_back();
            }
        }
        else
        {
            lists.pop_back();
        }
    }
    return resultFront;
}
}

int main()
{
    cout << "Hello, world!" << endl;
    return 0;
}