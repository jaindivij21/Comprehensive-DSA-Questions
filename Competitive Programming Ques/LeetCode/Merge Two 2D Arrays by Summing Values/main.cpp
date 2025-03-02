// Leetcode: Merge Two 2D Arrays by Summing Values
// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
   public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1,
                                    vector<vector<int>> &nums2)
    {
        vector<vector<int>> res;  // Resultant merged array

        int i = 0, j = 0;

        // Merge elements from both arrays while both have elements left
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i][0] == nums2[j][0])
            {
                // If both arrays have the same key, sum their values
                res.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            }
            else if (nums1[i][0] < nums2[j][0])
            {
                // If nums1 has a smaller key, add it to the result and move
                // forward
                res.push_back({nums1[i][0], nums1[i][1]});
                i++;
            }
            else
            {
                // If nums2 has a smaller key, add it to the result and move
                // forward
                res.push_back({nums2[j][0], nums2[j][1]});
                j++;
            }
        }

        // Append any remaining elements from nums1
        while (i < nums1.size())
        {
            res.push_back({nums1[i][0], nums1[i][1]});
            i++;
        }

        // Append any remaining elements from nums2
        while (j < nums2.size())
        {
            res.push_back({nums2[j][0], nums2[j][1]});
            j++;
        }

        return res;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> nums1 = {{1, 2}, {3, 4}};
    vector<vector<int>> nums2 = {{5, 6}, {7, 8}};

    vector<vector<int>> result = sol.mergeArrays(nums1, nums2);

    return 0;
}