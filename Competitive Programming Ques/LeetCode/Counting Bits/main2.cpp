// Leetcode: Counting Bits
// https://leetcode.com/problems/counting-bits

#include <iostream>

using namespace std;

class Solution
{
   public:
    vector<int> countBits(int n)
    {
        // DP: Memoization - Create a vector to store computed set bit counts,
        // initialized with -1
        vector<int> setBits(n + 1, -1);

        // Result vector to store final answers
        vector<int> ans;

        // Compute the number of set bits for each number from 0 to n
        for (int i = 0; i <= n; i++)
        {
            int noOfBits = calSetBits(setBits, i);
            setBits[i] = noOfBits;

            ans.push_back(noOfBits);
        }

        return ans;
    }

   private:
    // Recursive function to calculate the number of set bits in a number
    int calSetBits(vector<int> &setBits, int i)
    {
        // Base Cases
        if (i == 0) return 0;
        if (setBits[i] != -1) return setBits[i];

        // Recurrence Relation:
        // The number of set bits in 'i' is equal to:
        // - The number of set bits in (i / 2) (right shift by 1)
        // - Plus 1 if the least significant bit (LSB) is set (i & 1)
        return setBits[i] = (i & 1) + calSetBits(setBits, i >> 1);
    }
};

int main()
{
    Solution solution;
    vector<int> result = solution.countBits(5);

    return 0;
}