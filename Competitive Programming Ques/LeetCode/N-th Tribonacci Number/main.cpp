// Leetcode: N-th Tribonacci Number
// https://leetcode.com/problems/n-th-tribonacci-number

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
   public:
    unordered_map<int, int> memo;

    int tribonacci(int n)
    {
        // Base Case
        if (memo.contains(n)) return memo[n];
        if (n <= 2) return n == 0 ? 0 : 1;

        // Recursive Cases
        int ans = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        memo[n] = ans;
        return ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.tribonacci(4) << endl;

    return 0;
}