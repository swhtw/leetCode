// https://leetcode.com/problems/median-of-two-sorted-arrays/
#include "Utility.cpp"
#include <iostream>
#include <algorithm>
#include <vector>

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int nums1Start = 0,
        nums2Start = 0,
        nums1End = nums1.size(),
        nums2End = nums2.size(),
        lowerIndex = 0,
        upperIndex = 0;
    const int targetIndex = (nums1End + nums2End - 1) / 2;
    double result = 0.0;
    vector<int> mergeVector;
    if (nums1.size() == 0)
    {
        mergeVector = nums2;
    }
    else if (nums2.size() == 0)
    {
        mergeVector = nums1;
    }
    else if (*(nums1.end() - 1) <= *nums2.begin())
    {
        mergeVector = nums1;
        mergeVector.insert(mergeVector.end(), nums2.begin(), nums2.end());
    }
    else if (*(nums2.end() - 1) <= *nums1.begin())
    {
        mergeVector = nums2;
        mergeVector.insert(mergeVector.end(), nums1.begin(), nums1.end());
    }
    else
    {
        while ((nums1End - nums1Start > 2 || nums2End - nums2Start > 2) &&
               (lowerIndex < targetIndex) && (upperIndex < targetIndex))
        {
            int nums1MedianIndex = (nums1Start + nums1End - 1) / 2;
            int nums2MedianIndex = (nums2Start + nums2End - 1) / 2;
            if (nums1[nums1MedianIndex] >= nums2[nums2MedianIndex])
            {
                if ((nums2End - nums2MedianIndex) + (nums1End - nums1MedianIndex) + upperIndex > targetIndex + 1 &&
                    (nums2MedianIndex - nums2Start) != 0)
                {
                    lowerIndex += (nums2MedianIndex - nums2Start);
                    nums2Start = nums2MedianIndex;
                }
                else if (((nums2MedianIndex - nums2Start) + (nums1MedianIndex - nums1Start)) + lowerIndex > targetIndex + 1 &&
                         (nums1End - ((nums1Start + nums1End) / 2 + 1)) != 0)
                {
                    upperIndex += (nums1End - ((nums1Start + nums1End) / 2 + 1));
                    nums1End = (nums1Start + nums1End) / 2 + 1;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if ((nums2End - nums2MedianIndex) + (nums1End - nums1MedianIndex) + upperIndex > targetIndex + 1 &&
                    (nums1MedianIndex - nums1Start) != 0)
                {
                    lowerIndex += (nums1MedianIndex - nums1Start);
                    nums1Start = nums1MedianIndex;
                }
                else if (((nums2MedianIndex - nums2Start) + (nums1MedianIndex - nums1Start)) + lowerIndex > targetIndex + 1 &&
                         (nums2End - ((nums2Start + nums2End) / 2 + 1)) != 0)
                {
                    upperIndex += (nums2End - ((nums2Start + nums2End) / 2 + 1));
                    nums2End = (nums2Start + nums2End) / 2 + 1;
                }
                else
                {
                    break;
                }
            }
        }
        mergeVector.resize((nums1End - nums1Start) + (nums2End - nums2Start));
        merge(nums1.begin() + nums1Start, nums1.begin() + nums1End, nums2.begin() + nums2Start, nums2.begin() + nums2End, mergeVector.begin());
        sort(mergeVector.begin(), mergeVector.end());
    }
    if ((nums1.size() + nums2.size()) % 2)
    {
        result = (double)*(mergeVector.begin() + (targetIndex - lowerIndex));
    }
    else
    {
        result = (double)(*(mergeVector.begin() + (targetIndex - lowerIndex)) + *(mergeVector.begin() + (targetIndex - lowerIndex + 1))) / 2.0;
    }
    return result;
}

int main()
{
    cout << "Hello, world!" << endl;
    vector<int> nums1; // randomVector(10, 1, true);
    nums1.push_back(1);
    nums1.push_back(6);
    nums1.push_back(7);
    vector<int> nums2; // randomVector(10, 2, true);
    nums2.push_back(2);
    nums2.push_back(3);
    nums2.push_back(4);
    nums2.push_back(5);
    nums2.push_back(8);
    findMedianSortedArrays(nums1, nums2);
    return 0;
}