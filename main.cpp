// problem url
#include <iostream>
#include "Utility.h"

using namespace std;

int main()
{
	ListNode * input = randomSortedList(6);
	reverseKGroup(input, 5);
	return 0;
}