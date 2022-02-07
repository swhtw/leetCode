#ifndef UTILITY_H
#define UTILITY_H
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void test(string s);
vector<int> randomVector(int size, int seed, bool needSort);

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
int lengthOfLongestSubstring(string s);
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2);
ListNode *mergeKLists(vector<ListNode *> &lists);
vector<int> twoSum(vector<int> &nums, int target);

#endif