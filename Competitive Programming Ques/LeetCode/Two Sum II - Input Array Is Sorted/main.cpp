// Leetcode: Two Sum II - Input Array Is Sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
   public:
    /**
     * Finds two numbers in a sorted array that add up to a specific target.
     * The function returns 1-based indices of the two numbers.
     */
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;

        // Use two pointers moving towards each other
        while (left < right)
        {
            int sum = numbers[left] + numbers[right];

            if (sum == target)
            {
                // Return 1-based indices as per problem requirement
                return {left + 1, right + 1};
            }

            if (sum > target)
            {
                --right;  // Decrease sum by moving the right pointer left
            }
            else
            {
                ++left;  // Increase sum by moving the left pointer right
            }
        }

        // If no solution is found, return an empty vector (problem guarantees a
        // solution, so this is for safety)
        return {};
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = sol.twoSum(nums, target);

    return 0;
}
