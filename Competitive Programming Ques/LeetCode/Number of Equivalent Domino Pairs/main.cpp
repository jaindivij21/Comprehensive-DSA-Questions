// Leetcode: Number of Equivalent Domino Pairs
// https://leetcode.com/problems/number-of-equivalent-domino-pairs

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
   public:
    int numEquivDominoPairs(vector<vector<int> > &dominoes)
    {
        int ans = 0;

        unordered_map<int, int> map;
        for (auto i : dominoes)
        {
            const int val = i[0] < i[1] ? 10 * i[0] + i[1] : 10 * i[1] + i[0];

            if (map.contains(val))
            {
                ans += map[val];
            }
            map[val]++;
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    vector<vector<int> > nums = {{1, 2}, {2, 1}, {3, 4}, {5, 6}};

    cout << solution.numEquivDominoPairs(nums) << endl;

    return 0;
}
