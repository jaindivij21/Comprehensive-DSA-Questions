// Get Equal Substrings Within Budget
// https://leetcode.com/problems/get-equal-substrings-within-budget

#include <iostream>

using namespace std;

/*
    Function to return the maximum length of a substring of s that can be made same as t keeping the cost less than
    equal to maxCost. Approach: Sliding Window
 */
int equalSubstring(string &s, string &t, int maxCost)
{
  int start = 0, end = 0;
  int currentCost = 0;
  int maxSubstringLen = 0;

  for (; end < s.size(); end++)
  {
    currentCost += abs(s[end] - t[end]);

    while (currentCost > maxCost)
    {
      currentCost -= abs(s[start] - t[start]);
      start++;
    }

    maxSubstringLen = max(maxSubstringLen, end - start + 1);
  }

  return maxSubstringLen;
}

int main()
{
  string s1, s2;
  cin >> s1 >> s2;

  int cost;
  cin >> cost;

  cout << equalSubstring(s1, s2, cost) << endl;
}
