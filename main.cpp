// problem url
#include <iostream>
#include "Utility.h"

using namespace std;

int main()
{
	test("Hello, world!");

	vector<int> v1 = randomVector(3, 5, true);
	vector<int> v2 = randomVector(2, 2, true);

	cout << findMedianSortedArrays(v1, v2) << endl;

    return 0;
}