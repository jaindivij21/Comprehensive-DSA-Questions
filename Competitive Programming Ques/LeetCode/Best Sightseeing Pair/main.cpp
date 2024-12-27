// Leetcode: Best Sightseeing Pair
// https://leetcode.com/problems/best-sightseeing-pair

#include <iostream>

using namespace std;

class Solution
{
public:
  // (values[i] + i) + (values[j] - j)
  int maxScoreSightseeingPair(vector<int> &values)
  {
    int maxLeft = values[0];
    int ans = INT_MIN;

    for (int j = 1; j < values.size(); j++)
    {
      ans = max(ans, maxLeft + values[j] - j);

      maxLeft = max(maxLeft, values[j] + j);
    }

    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> values = {2, 2, 2};

  cout << s.maxScoreSightseeingPair(values) << endl;

  return 0;
}