// Leetcode: Maximum Difference Between Even and Odd Frequency I
// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
   public:
    int maxDifference(string &s)
    {
        // Initialize frequency array for all 26 lowercase letters.
        vector<int> frequency(26, 0);

        // Count frequencies of each character.
        for (char c : s)
        {
            frequency[c - 'a']++;
        }

        // Initialize maxOddFreq to smallest possible and minEvenFreq to largest
        // possible.
        int maxOddFreq = INT_MIN;
        int minEvenFreq = INT_MAX;

        for (int freq : frequency)
        {
            if (freq == 0) continue;  // Skip characters not in the string.

            if (freq % 2 == 0)
            {
                minEvenFreq = min(minEvenFreq, freq);
            }
            else
            {
                maxOddFreq = max(maxOddFreq, freq);
            }
        }

        // If either value wasn't updated, return -1 to indicate no valid
        // result.
        if (maxOddFreq == INT_MIN || minEvenFreq == INT_MAX) return -1;

        return maxOddFreq - minEvenFreq;
    }
};

int main()
{
    Solution sol;
    string s = "aaaaabbc";

    cout << sol.maxDifference(s) << endl;

    return 0;
}
