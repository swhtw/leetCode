#ifndef UTILITY_H
#define UTILITY_H
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <regex>
#include <sstream>
#include <stack>
#include <set>
#include <numeric>
#include <unordered_map>

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

vector<int> randomVector(int size, int seed, bool needSort);
ListNode *randomList(int size, int seed);
ListNode *randomSortedList(int size, int seed);
ListNode *randomSortedList(int size);

vector<vector<int>> threeSum(vector<int>& nums);
int threeSumClosest(vector<int>& nums, int target);
vector<vector<int>> fourSum(vector<int>& nums, int target);
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
int maxArea(vector<int>& height);
int divide(int dividend, int divisor);
vector<string> generateParenthesis(int n);
string intToRoman(int num);
vector<string> letterCombinations(string digits);
string longestPalindrome(string s);
int lengthOfLongestSubstring(string s);
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2);
ListNode *mergeKLists(vector<ListNode *> &lists);
int mincostTickets(vector<int>& days, vector<int>& costs);
bool isPalindrome(ListNode* head); // palindrome-linked-list 
bool isPalindrome(int x); // palindrome-number
bool isMatch(string s, string p);
ListNode* removeNthFromEnd(ListNode* head, int n);
int reverse_integer(int x);
ListNode* reverseKGroup(ListNode* head, int k);
int search(vector<int>& nums, int target);
int myAtoi(string s);
vector<int> findSubstring(string s, vector<string>& words);
ListNode* swapPairs(ListNode* head);
vector<int> twoSum(vector<int> &nums, int target);
string zigzag_conversion(string s, int numRows);
// 281st LeetCode Weekly Contest
int countEven(int num);
ListNode* mergeNodes(ListNode* head);
string repeatLimitedString(string s, int repeatLimit);
long long coutPairs(vector<int>& nums, int k);
// 283st LeetCode Weekly Contest
vector<string> cellsInRange(string s);
long long minimalKSum(vector<int>& nums, int k);
// 285st LeetCode Weekly Contest


#endif