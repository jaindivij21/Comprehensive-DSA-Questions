// Leetcode: Counting Bits
// https://leetcode.com/problems/counting-bits

#include <iostream>

using namespace std;

class Solution
{
   public:
    vector<int> countBits(int n)
    {
        // Vector to store the count of set bits for numbers from 0 to n
        vector<int> ans;

        // Iterate from 0 to n and calculate the number of set bits for each
        // number
        for (int i = 0; i <= n; i++)
        {
            ans.push_back(
                calSetBits(i));  // Call helper function to count set bits
        }

        return ans;
    }

   private:
    // Helper function to count the number of set bits (1s) in the binary
    // representation of a number
    int calSetBits(int i)
    {
        int ans = 0;

        // Loop until all bits are processed
        while (i != 0)
        {
            // Check if the least significant bit is set (1)
            ans += (i & 1);
            // Right shift the number by 1 to process the next bit
            i >>= 1;
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> result = solution.countBits(5);

    return 0;
}