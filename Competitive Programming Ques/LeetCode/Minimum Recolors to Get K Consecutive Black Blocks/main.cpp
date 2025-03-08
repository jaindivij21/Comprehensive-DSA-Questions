// Leetcode: Minimum Recolors to Get K Consecutive Black Blocks
// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
   public:
    int minimumRecolors(string &blocks, int k)
    {
        int whiteCount = 0, minRecolors = INT_MAX;

        // Count the number of 'W' in the first window of size k
        for (int i = 0; i < k; i++)
        {
            if (blocks[i] == 'W') whiteCount++;
        }
        minRecolors = whiteCount;

        // Sliding window technique to find the minimum number of 'W' in any
        // k-sized window
        for (int left = 0, right = k; right < blocks.size(); left++, right++)
        {
            // Include the new character in the window
            if (blocks[right] == 'W') whiteCount++;

            // Remove the character that is sliding out of the window
            if (blocks[left] == 'W') whiteCount--;

            // Update the minimum recolors needed
            minRecolors = min(minRecolors, whiteCount);
        }

        return minRecolors;
    }
};

int main()
{
    Solution solution;
    string blocks = "WBWBBBW";

    cout << solution.minimumRecolors(blocks, 2) << endl;

    return 0;
}
