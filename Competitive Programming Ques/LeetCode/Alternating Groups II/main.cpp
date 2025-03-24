// Leetcode: Alternating Groups II
// https://leetcode.com/problems/alternating-groups-ii

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
   public:
    // Function to count the number of alternating groups of length k
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int n = colors.size();

        // Start and end pointers for the sliding window
        if (k > n) return 0;

        // Start and end pointers for the sliding window
        int start = 0, end = 1;
        int windows = 0;

        // Start and end pointers for the sliding window
        while (end < n + k - 1)
        {
            // If two consecutive elements are the same, reset the start
            // position
            if (colors[end % n] == colors[(end - 1) % n]) start = end;

            // Ensure the window size does not exceed k
            if (end - start + 1 > k) start++;

            // If the window size is exactly k, count it as a valid alternating
            // group
            if (end - start + 1 == k) windows++;

            end++;
        }

        return windows;
    }
};

int main()
{
    Solution solution;
    vector<int> colors = {0, 1, 0, 1, 0};
    const int k = 3;

    cout << "Number of alternating groups: "
         << solution.numberOfAlternatingGroups(colors, k) << endl;

    return 0;
}
