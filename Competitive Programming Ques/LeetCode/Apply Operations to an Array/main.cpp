// Leetcode: Apply Operations to an Array
// https://leetcode.com/problems/apply-operations-to-an-array

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
   public:
    vector<int> applyOperations(vector<int> &nums)
    {
        vector<int> ans(nums.size(),
                        0);  // Initialize the result array with zeros
        int i = 0, j = 0;  // i for iteration, j for inserting nonzero elements

        // Iterate through the array, stopping before the last element
        for (; i < nums.size() - 1; i++)
        {
            // If adjacent elements are not equal or the current element is
            // zero, just copy nonzero elements
            if (nums[i] != nums[i + 1] || nums[i] == 0)
            {
                if (nums[i] != 0)
                    ans[j++] = nums[i];  // Store nonzero elements in ans
                continue;
            }

            // If adjacent elements are equal, double the current element and
            // set the next to zero
            nums[i] *= 2;
            nums[i + 1] = 0;
            ans[j++] = nums[i];  // Store the updated value in ans
        }

        // Handle the last element separately (if it's nonzero)
        if (nums[i] != 0) ans[j++] = nums[i];

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};

    vector<int> result = s.applyOperations(nums);

    for (int i : result)
    {
        cout << i << " ";
    }

    return 0;
}