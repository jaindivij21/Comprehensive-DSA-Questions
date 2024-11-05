// Leetcode: Minimum Number of Changes to Make Binary String Beautiful
// https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful

#include <iostream>

using namespace std;

using namespace std;

class Solution
{
public:
  int minChanges(string &s)
  {
    int minChanges = 0;

    for (int i = 1; i < s.size(); i += 2)
    {
      if (s[i] != s[i - 1])
        minChanges++;
    }

    return minChanges;
  }
};

int main()
{
  Solution sol;
  string s = "1001";
  cout << sol.minChanges(s) << endl;

  return 0;
}