// Leetcode: Successful Pairs of Spells and Potions
// https://leetcode.com/problems/successful-pairs-of-spells-and-potions

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Sort the potions array to allow binary search (lower_bound)
        ranges::sort(potions);

        // Result vector to store the count of successful pairs for each spell
        vector<int> result(spells.size());

        // Iterate through each spell
        for (size_t i = 0; i < spells.size(); ++i) {
            // Compute the minimum potion strength required to meet or exceed the success threshold
            // This formula ensures ceil(success / spells[i]) without floating-point division
            long long minPotion = (success + spells[i] - 1) / spells[i];

            // Use binary search to find the first potion >= minPotion
            auto it = ranges::lower_bound(potions, minPotion);

            // All potions from 'it' to the end will be successful with this spell
            result[i] = distance(it, potions.end());
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> spells = {5, 1, 3};
    vector<int> potions = {1, 2, 3, 4, 5};
    constexpr long long success = 7;

    for (const vector<int> result = solution.successfulPairs(spells, potions, success); const int i: result) {
        cout << i << " ";
    }

    return 0;
}
