// Leetcode: Find the Highest Altitude
// https://leetcode.com/problems/find-the-highest-altitude

#include <iostream>

using namespace std;

class Solution
{
public:
  int largestAltitude(vector<int> &gain)
  {
    int runningSum = 0;
    int maxSum = 0;

    for (auto i : gain)
    {
      runningSum += i;
      maxSum = max(maxSum, runningSum);
    }

    return maxSum;
  }
};

int main()
{
  Solution sol;
  vector<int> gain = {-5, 1, 5, 0, -7};
  cout << sol.largestAltitude(gain) << endl;

  return 0;
}