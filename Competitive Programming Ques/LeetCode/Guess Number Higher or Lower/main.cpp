// Leetcode: Guess Number Higher or Lower
// https://leetcode.com/problems/guess-number-higher-or-lower

#include <iostream>

using namespace std;

class Solution
{
   public:
    int guessNumber(int n)
    {
        int l = 1;
        int r = n;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (guess(mid) == 0)
                return mid;
            else if (guess(mid) == 1)
                l = mid + 1;
            else if (guess(mid) == -1)
                r = mid - 1;
        }

        return 0;
    }
};

int main()
{
    Solution sol;
    cout << sol.guessNumber(10) << endl;

    return 0;
}