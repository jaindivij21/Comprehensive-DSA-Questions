// Leetcode: IPO
// https://leetcode.com/problems/ipo/description/
// Brute Force Solution

#include <iostream>
#include <vector>

using namespace std;

int helper(int maxProjects, vector<int> &profits, vector<int> &capital, int capitalAtHand, int currentProjects, int i)
{
  // Base Cases
  if (i >= profits.size() || currentProjects >= maxProjects)
  {
    return capitalAtHand;
  }

  // Recursive Cases
  int profitIfIncluded = 0;
  // Consider the (i)th index
  if (capitalAtHand >= capital[i])
  {
    profitIfIncluded = helper(maxProjects, profits, capital, capitalAtHand + profits[i], currentProjects + 1, i + 1);
  }
  // Don't consider the (i)th index
  int profitIfExcluded = helper(maxProjects, profits, capital, capitalAtHand, currentProjects, i + 1);

  return max(profitIfIncluded, profitIfExcluded);
}

// Brute Force Solution: Recursion to check for every case
int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
  return helper(k, profits, capital, w, 0, 0);
}

int main()
{
  int k = 2;
  int w = 0;
  vector<int> profits = {1, 2, 3};
  vector<int> capital = {0, 1, 1};

  cout << findMaximizedCapital(k, w, profits, capital) << endl;

  return 0;
}