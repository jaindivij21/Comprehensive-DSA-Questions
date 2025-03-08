// Leetcode: Maximum Subsequence Score
// https://leetcode.com/problems/maximum-subsequence-score

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
   public:
    static long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        const size_t n = nums1.size();
        vector<pair<int, int> > pairedValues;

        // Pair elements from nums1 and nums2 together
        pairedValues.reserve(n);
        for (size_t i = 0; i < n; i++)
        {
            pairedValues.emplace_back(nums1[i], nums2[i]);
        }

        // Sort pairs in descending order based on nums2 values
        ranges::sort(pairedValues,
                     [](const pair<int, int> &a, const pair<int, int> &b)
                     { return a.second > b.second; });

        priority_queue<int, vector<int>, greater<> >
            minHeap;  // Min-heap to maintain k largest values from nums1
        long long sumNums1 = 0, maxScore = 0;

        // Iterate over the sorted pairs
        for (const auto &[num1, num2] : pairedValues)
        {
            minHeap.push(num1);
            sumNums1 += num1;

            // Ensure only k elements are considered
            if (minHeap.size() > k)
            {
                sumNums1 -= minHeap.top();
                minHeap.pop();
            }

            // If we have exactly k elements, update maxScore
            if (minHeap.size() == k)
            {
                maxScore = max(maxScore, sumNums1 * num2);
            }
        }

        return maxScore;
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {5, 4, 3, 2, 1};
    int k = 3;

    cout << "Maximum Subsequence Score: " << solution.maxScore(nums1, nums2, k)
         << endl;

    return 0;
}
