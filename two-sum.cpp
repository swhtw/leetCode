// https://leetcode.com/problems/two-sum/
#include "Utility.h"

struct Data
{
    int val;
    int index;
};

bool
compareData(Data const &data1, Data const &data2)
{
    return data1.val < data2.val;
}

vector<int> twoSum(vector<int> &nums, int target)
{
    Data *data = new Data[nums.size()];
    for (int i = 0; i < nums.size(); ++i)
    {
        data[i].index = i;
        data[i].val = nums[i];
    }

    sort(data, data + nums.size(), &compareData);

    vector<int> result(2, 0);

    int index_1 = 0, index_2 = nums.size() - 1;

    while (index_1 < nums.size() && index_2 >= 0)
    {
        if (data[index_1].val + data[index_2].val == target)
        {
            if (data[index_1].index < data[index_2].index)
            {
                result[0] = data[index_1].index;
                result[1] = data[index_2].index;
            }
            else
            {
                result[1] = data[index_1].index;
                result[0] = data[index_2].index;
            }
            break;
        }
        else if (data[index_1].val + data[index_2].val < target)
        {
            ++index_1;
        }
        else
        {
            --index_2;
        }
    }
    return result;
}