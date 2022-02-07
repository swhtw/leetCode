#include "Utility.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

void test(string s)
{
	cout << s;
}

vector<int> randomVector(int size, int seed, bool needSort)
{
    srand(seed);
    vector<int> v;
    generate(v.begin(), v.end(), std::rand);
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