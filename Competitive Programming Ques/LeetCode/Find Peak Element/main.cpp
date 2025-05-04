// Leetcode: Find Peak Element
// https://leetcode.com/problems/find-peak-element

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
   public:
    int findPeakElement(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[mid + 1])
            {
                // If mid is greater than next element, peak must be on the left
                // (including mid)
                r = mid;
            }
            else
            {
                // Otherwise, the peak must be on the right
                l = mid + 1;
            }
        }

        return l;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2};

    cout << solution.findPeakElement(nums) << endl;

    return 0;
}
