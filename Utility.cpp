#include "Utility.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

vector<int> randomVector(int size, int seed, bool needSort)
{
    srand(seed);
    vector<int> v;
	for (int i = 0; i < size; ++i)
	{
		v.push_back(rand() % size * 2);
	}
    if (needSort)
    {
        sort(v.begin(), v.end());
    }
    return v;
}

ListNode *randomList(int size, int seed)
{
	srand(seed);
	ListNode * next = nullptr;
	for (int i = 0; i < size; ++i)
	{
		ListNode *listNode = new ListNode(rand() % size * 2, next);
		next = listNode;
	}
	return next;
}

ListNode *randomSortedList(int size, int seed)
{
	int minNum = 0;
	srand(seed);
	ListNode * next = nullptr;
	for (int i = 0; i < size; ++i)
	{
		minNum += rand() % 5;
		ListNode *listNode = new ListNode(minNum, next);
		next = listNode;
	}
	return next;
}

ListNode *randomSortedList(int size)
{
	ListNode * next = nullptr;
	for (int i = 0; i < size; ++i)
	{
		ListNode *listNode = new ListNode(size - i, next);
		next = listNode;
	}
	return next;
}