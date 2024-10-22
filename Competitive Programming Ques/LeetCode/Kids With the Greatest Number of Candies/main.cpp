// Leetcode: Kids With the Greatest Number of Candies
// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

#include <vector>

using namespace std;

class Solution
{
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
  {
    int maxCandies = 0;
    for (auto i : candies)
    {
      maxCandies = max(maxCandies, i);
    }

    vector<bool> ans;
    for (auto i : candies)
    {
      ans.push_back(i + extraCandies >= maxCandies);
    }

    return ans;
  }
};

int main()
{
  vector<int> candies = {2, 3, 5, 1, 3};
  int extraCandies = 3;
  Solution s;
  vector<bool> result = s.kidsWithCandies(candies, extraCandies);

  return 0;
}