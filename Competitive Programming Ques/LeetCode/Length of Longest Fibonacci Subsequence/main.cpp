// Leetcode: Length of Longest Fibonacci Subsequence
// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
   public:
    int lenLongestFibSubseq(vector<int>& arr)
    {
        int n = arr.size();

        // Memoization table to store Fibonacci-like sequence lengths
        vector<vector<int>> memo(n, vector<int>(n, -1));

        // Hashmap to store value -> index mapping
        unordered_map<int, int> indexMap;
        for (int i = 0; i < n; i++) indexMap[arr[i]] = i;

        int maxAns = 0;  // Stores the longest sequence length

        // Precompute possible Fibonacci pairs
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int sum = arr[i] + arr[j];

                // If sum exists in the array, store the index in memo
                if (indexMap.find(sum) != indexMap.end())
                {
                    memo[i][j] = indexMap[sum];
                }
            }
        }

        // Iterate through the memoization table
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int x = i, y = j;
                int length = 0;

                // Build Fibonacci sequence from (i, j)
                while (x < n - 1 && y < n - 1 && memo[x][y] != -1)
                {
                    int nextIdx =
                        memo[x][y];  // Next element in Fibonacci sequence
                    x = y;
                    y = nextIdx;
                    length++;
                }

                // Only count sequences of length 2 and above
                if (length > 0)
                {
                    maxAns = max(maxAns, length + 2);
                }
            }
        }

        return maxAns;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << s.lenLongestFibSubseq(arr) << endl;

    return 0;
}