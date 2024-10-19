// Leetcode: Find Greatest Common Divisor of Array
// https://leetcode.com/problems/find-greatest-common-divisor-of-array

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  int findGCD(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    return gcd(nums[nums.size() - 1], nums[0]);
  }

private:
  int gcd(int a, int b)
  {
    // Base Case
    if (b == 0)
      return a;

    // Recursive Case
    return gcd(b, a % b);
  }
};

int main()
{
  Solution s;
  vector<int> nums = {2, 5, 6, 9, 10};
  cout << s.findGCD(nums) << endl;

  return 0;
}
