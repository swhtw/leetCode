#include "Utility.h"
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

vector<int> randomVector(int size, int seed, bool needSort)
{
    srand(seed);
    vector<int> v(size);
    generate(v.begin(), v.end(), std::rand);
    if (needSort)
    {
        sort(v.begin(), v.end());
    }
    return v;
}