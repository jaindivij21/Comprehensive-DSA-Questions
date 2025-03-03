// Leetcode: Partition Array According to Given Pivot
// https://leetcode.com/problems/partition-array-according-to-given-pivot

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
   public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int lessCount = 0, moreCount = 0, totalCount = nums.size();

        for (int num : nums)
        {
            lessCount += (num < pivot);
            moreCount += (num > pivot);
        }

        int i = 0, j = totalCount - moreCount;
        for (int num : nums)
        {
            if (num < pivot)
            {
            }
        }

        return nums;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {9, 12, 3, 5, 14, 10, 10};
    int pivot = 10;

    vector<int> result = s.pivotArray(nums, pivot);

    for (int i : result)
    {
        cout << i << " ";
    }

    return 0;
}