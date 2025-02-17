// Leetcode: Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
   public:
    // Binary Search to find the target in the rotated sorted array
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            // Find the middle index
            int mid = left + (right - left) / 2;

            // If the target is found at the mid index, return it
            if (nums[mid] == target) return mid;

            // Check if the left half of the array is sorted
            bool isLeftSorted = nums[left] <= nums[mid];

            if (isLeftSorted)
            {
                // Target is within the left sorted half
                if (nums[mid] < target)
                {
                    left = mid + 1;
                }
                else
                {
                    // Target is within the left sorted range
                    if (nums[left] <= target)
                    {
                        right = mid - 1;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }
            }
            else
            {
                // Right half is sorted
                if (nums[mid] < target)
                {
                    // Target is in the right half
                    if (target <= nums[right])
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        right = mid - 1;
                    }
                }
                else
                {
                    // Target is in the left half
                    right = mid - 1;
                }
            }
        }

        // Target not found, return -1
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    cout << solution.search(nums, 0) << endl;  // Output: 4

    return 0;
}
