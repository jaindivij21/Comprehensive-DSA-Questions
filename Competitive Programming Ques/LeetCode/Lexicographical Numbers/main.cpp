// Leetcode: Lexicographical Numbers
// https://leetcode.com/problems/lexicographical-numbers

#include <iostream>
#include <vector>
using namespace std;

// Recursive: DFS Solution
class Solution
{
   public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> result;
        // Start DFS from 1 to 9 as valid starting digits for lexicographical
        // order
        for (int i = 1; i <= 9; ++i)
        {
            dfs(i, n, result);
        }
        return result;
    }

   private:
    // Recursive DFS helper to build numbers in lexicographical order
    void dfs(const int current, const int limit, vector<int>& result)
    {
        // Base Case
        if (current > limit) return;

        // Recursive Cases
        result.push_back(current);

        for (int i = 0; i <= 9; ++i)
        {
            const int next = current * 10 + i;
            if (next > limit) break;
            dfs(next, limit, result);
        }
    }
};

int main()
{
    Solution sol;
    vector<int> result = sol.lexicalOrder(13);

    return 0;
}
