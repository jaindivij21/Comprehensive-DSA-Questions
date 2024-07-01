// Leetcode: https://leetcode.com/problems/three-consecutive-odds/
// Three Consecutive Odds

#include <iostream>
#include <vector>

using namespace std;

bool threeConsecutiveOdds(vector<int> &arr)
{
  int count = 0;
  for (auto num : arr)
  {
    if (num % 2 != 0)
    {
      count++;

      if (count == 3)
        return true;
    }
    else
    {
      count = 0;
    }
  }

  return false;
}

int main()
{
  vector<int> nums = {1, 2, 34, 3, 4, 5, 7, 23, 12};
  cout << threeConsecutiveOdds(nums) << endl;
  return 0;
}