// Leetcode: Group Anagrams
// https://leetcode.com/problems/group-anagrams

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
   public:
    static vector<vector<string> > groupAnagrams(const vector<string> &strs)
    {
        unordered_map<string, vector<string> > m;

        for (const string &str : strs)
        {
            string key = str;
            ranges::sort(key);
            m[key].push_back(str);
        }

        vector<vector<string> > ans;
        for (const auto &pair : m)
        {
            ans.push_back(pair.second);
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    const vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution::groupAnagrams(strs);

    return 0;
}
