// Leetcode: Rotate String
// https://leetcode.com/problems/rotate-string

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool rotateString(string &s, string &goal)
  {
    if (s.size() != goal.size())
      return false;

    return (s + s).contains(goal);
  }
};

int main()
{
  Solution sol;
  string s = "abcde";
  string goal = "cdeab";

  cout << sol.rotateString(s, goal) << endl;

  return 0;
}